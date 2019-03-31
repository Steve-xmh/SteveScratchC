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

	}
	return NULL;
}

gpointer* ssc_core_get_command()
{
	g_async_queue_lock(currentCore->mainThread_q);
	guint *dataNum = (guint*)g_async_queue_try_pop(currentCore->mainThread_q);
	gpointer *data = NULL;
	if (dataNum)
	{
		data = g_new(gpointer,*dataNum);
		for (guint i=0; i<*dataNum; i++)
		{
			data[i] = g_async_queue_try_pop(currentCore->mainThread_q);
			if(!data[i]) break;
		}
	}
	g_async_queue_unlock(currentCore->mainThread_q);
	return data;
}

// 指令格式：指令数量,指针...
void ssc_core_push_command(guint dataNum,...)
{
	va_list arg = NULL;
	va_start(arg,dataNum);

	g_async_queue_lock(currentCore->mainThread_q);

	guint *dNum = g_malloc(sizeof(dNum));
	*dNum = dataNum;
	g_async_queue_push(currentCore->mainThread_q,dNum);

	for(int i = 0; i < dataNum; i++)
	{
		g_async_queue_push(currentCore->mainThread_q,va_arg(arg,gpointer));
	}

	g_async_queue_unlock(currentCore->mainThread_q);
}

