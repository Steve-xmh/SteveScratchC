#include "LuaScheduler.h"

typedef struct
{
	clock_t resumeTime;
	lua_State *thread;
} LuaThread;

GPtrArray *threads;
gboolean needSort;


void ssc_lua_step()
{
	clock_t curTime = clock();
	while(threads->len > 0)
	{
		LuaThread *thread = (LuaThread*)g_ptr_array_index(threads,0);
		if(thread->resumeTime >= curTime)
		{
			g_ptr_array_remove_index(threads,0);
			int status = lua_resume(thread->thread,0);
			switch(status)
			{
			case LUA_OK:
				break;
			case LUA_YIELD:
				break;
			case LUA_ERRRUN:
			case LUA_ERRMEM:
			case LUA_ERRERR:
				break;
			}
		}else
		{
			break;
		}
	}
}
