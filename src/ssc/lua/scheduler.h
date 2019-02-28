#ifndef HEADER_SSC_LUA_SCHEDULER
#define HEADER_SSC_LUA_SCHEDULER

#include <time.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include "../../config.h" //所有宏配置在这里

typedef struct sscLuaTask
{
	lua_State* coro;	/**< 线程指针 */
	clock_t time;		/**< 时间队列，用于排序 */
}sscLuaTask;			/**< Lua 线程结构 */

sscLuaTask* ssc_lua_get_cur_task(void);
void ssc_lua_enqueue_task(lua_State* L,clock_t ct);
void ssc_lua_iteration(void);
gint ssc_lua_sort_task(gpointer pa,gpointer pb);

#endif // HEADER_SSC_LUA_SCHEDULER
