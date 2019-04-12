#include "SSCCore.h"

// 一次只能有一个核心
static SSCCore *currentCore;

void ssc_core_init(GError **err)
{
	currentCore = g_new(SSCCore,1);
	currentCore->status = SSC_CORE_STATUS_RUNNING;
	currentCore->mainThread_q = g_async_queue_new_full(g_free);
	g_mutex_init(&currentCore->mainThread_q_m);
	currentCore->mainThread = g_thread_try_new(NULL,ssc_core_main,NULL,err);
	if (!currentCore->mainThread)
	{
		return;
	}
}

void *ssc_core_main(gpointer data)
{
	info("[Core] Core is ready!\n");
	while(currentCore->status)
	{
		GPtrArray *command = ssc_core_get_command();
		if(command)
		{
			switch(*(int*)g_ptr_array_index(command,0))
			{
			case SSC_CORE_COMMAND_OPEN_PROJECT:
				info("[Core] Opening project: %s\n",(gchar*)g_ptr_array_index(command,1));
				break;
			default:
				warn("[Core] Unknown command: %d\n",*(int*)g_ptr_array_index(command,1));
			}
			g_ptr_array_free(command,TRUE); // 释放成员指针
		}
		g_usleep(1000);
	}
	return NULL;
}

GPtrArray *ssc_core_get_command()
{
	g_mutex_lock(&currentCore->mainThread_q_m);
	guint *dataNum = (guint*)g_async_queue_try_pop(currentCore->mainThread_q);
	GPtrArray *data = NULL;
	if (dataNum)
	{
		data = g_ptr_array_new();
		guint i;
		for (i = 0; i<*dataNum; i++)
		{
			g_ptr_array_add(data,g_async_queue_try_pop(currentCore->mainThread_q));
		}
	}
	g_free(dataNum);
	g_mutex_unlock(&currentCore->mainThread_q_m);
	return data;
}

// 指令格式：指令数量,指令类型,指针(参数)...
void ssc_core_push_command(guint dataNum,...)
{
	va_list arg = NULL;
	va_start(arg,dataNum);

	g_mutex_lock(&currentCore->mainThread_q_m);

	guint *dNum = g_malloc(sizeof(dNum));
	*dNum = dataNum;
	g_async_queue_push(currentCore->mainThread_q,dNum);

	for(int i = 0; i < dataNum; i++)
	{
		gpointer a = va_arg(arg,gpointer);
		g_async_queue_push(currentCore->mainThread_q,a);
	}

	g_mutex_unlock(&currentCore->mainThread_q_m);
}

