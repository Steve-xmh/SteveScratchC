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
	while(currentCore->status)
	{
		gpointer *command = ssc_core_get_command();
		if(command)
		{
			info("[Core] Get a command:\n");
			guint i = 0;
			while(*(command+i))
			{
				info("[Core][%d] %p",i,*(command+i));
				g_free(*(command+i));
				i++;
			}
			g_free(command);
		}
		g_usleep(16000);
	}
	return NULL;
}

gpointer* ssc_core_get_command()
{
	g_mutex_lock(&currentCore->mainThread_q_m);
	guint *dataNum = (guint*)g_async_queue_try_pop(currentCore->mainThread_q);
	gpointer *data = NULL;
	if (dataNum)
	{
		data = g_new(gpointer,*dataNum+1);
		guint i;
		for (i = 0; i<*dataNum; i++)
		{
			data[i] = g_async_queue_try_pop(currentCore->mainThread_q);
			if(!data[i]) break;
		}
		data[i+1] = NULL;
	}
	g_mutex_unlock(&currentCore->mainThread_q_m);
	return data;
}

// 指令格式：指令数量,指针...
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
		printf("F:%p\t",a);
	}

	g_mutex_unlock(&currentCore->mainThread_q_m);
}

