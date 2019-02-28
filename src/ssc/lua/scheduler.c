
// Lua 程序调度器
// 从而实现多线程

#include "scheduler.h"

GList *sscLuaTasksList = NULL;
sscLuaTask *curTask = NULL;

sscLuaTask* ssc_lua_get_cur_task()
{
	return curTask;
}

void ssc_lua_enqueue_task(lua_State* L,clock_t ct)
{
	sscLuaTask* task = ssc_libs_g_malloc(sizeof(sscLuaTask));
	task->coro = L;
	task->time = ct;
	sscLuaTasksList = ssc_libs_g_list_sort(ssc_libs_g_list_prepend(sscLuaTasksList,task),ssc_lua_sort_task);
	//print("[Lua][Scheduler] Added new task: %p\tWill call at %d\n",L,ct);
}

void ssc_lua_iteration()
{
    clock_t now = clock();
    //print("[Lua][Scheduler] Task length: %d\n",g_list_length(sscLuaTasksList));
    if(ssc_libs_g_list_length(sscLuaTasksList) != 0)
	{
		curTask = (sscLuaTask*)(sscLuaTasksList->data);
		//print("[Lua][Scheduler] %d \t %d\n",curTask->time,now);
		if(curTask->time <= now)
		{
            int ret;
            sscLuaTasksList = ssc_libs_g_list_remove(sscLuaTasksList,curTask); // 只是移除链接而已
            //print("[Lua][Scheduler] Runing task: %p\n",curTask->coro);
            ret = lua_resume(curTask->coro,NULL,0);
            if (ret == LUA_OK) // 完美结束
			{
				//lua_close(curTask->coro);
				lua_gc(ssc_lua_get_mainP(),LUA_GCCOLLECT,NULL);
			}else if(ret != LUA_YIELD) // 出错了
			{
				print("[Lua][Scheduler] One lua thread has onto error: %d\n"
					   "[Lua][Scheduler] Reason: ",ret);
				switch(ret)
				{
					case LUA_ERRRUN: // 1
						{
							print("Runtime Error\n");
							break;
						}
					case LUA_ERRSYNTAX: // 2
						{
							print("Runtime Error\n");
							break;
						}
					case LUA_ERRMEM: // 3
						{
							print("Memory Error\n");
							break;
						}
					case LUA_ERRGCMM: // 4
						{
							print("Running __GC meta-function Error\n");
							break;
						}
					case LUA_ERRERR: // 5
						{
							print("Error Function Error\n");
							break;
						}
					case LUA_ERRFILE: // 6
						{
							print("File Error\n");
							break;
						}
					default:
						{
							print("Unknown Error\n");
						}
				}
				if (lua_tostring(curTask->coro,-1))
				{
					luaL_traceback(curTask->coro,curTask->coro,lua_tostring(curTask->coro,-1),1);
				}else
				{
					luaL_traceback(curTask->coro,curTask->coro,NULL,1);
				}
				print(lua_tostring(curTask->coro,-1));
			}// 如果还是让除了的话则不动，因为等待函数已经重新指示排队了
			ssc_libs_g_free(curTask); // 释放任务结构，但是某种情况下没有关闭状态机
		}
	}
}

void ssc_lua_sort_now()
{
	sscLuaTasksList = ssc_libs_g_list_sort(sscLuaTasksList,ssc_lua_sort_task);
}

gint ssc_lua_sort_task(gpointer pa,gpointer pb)
{
	sscLuaTask *a,*b;
	a = (sscLuaTask*)pa;
	b = (sscLuaTask*)pb;

	if(a->time < b->time)//把执行时间早的往前排
		return -1;
	else if(a->time > b->time)
		return 1;
	else
		return 0;
}
