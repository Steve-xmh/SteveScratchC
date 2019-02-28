#ifndef HEADER_SSC_LUA_SSC_LUA
#define HEADER_SSC_LUA_SSC_LUA

#include <unistd.h>

#ifdef WINDOWS
#include <windows.h> //用于等待函数中
#endif // WINDOWS

#include <time.h>
#include <math.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include "../../config.h"
#include "../../main.h"
#include "scheduler.h"

// 类

#include "classes/SSCBlock.h"
#include "classes/SSCStage.h"

typedef struct
{
	char* str;
	lua_CFunction fun;
}sscL_cReg;

void ssc_lua_setOutput(GtkWidget* w);
gboolean ssc_lua_refresh_output(gpointer user_data);
//gboolean ssc_lua_refresh_output(GtkWidget* widget,GdkFrameClock* fc,gpointer user_data);
int ssc_msgBox(lua_State *L);

void ssc_lua_traceback(lua_State* L);
void ssc_lua_dostring(gchar* str);
lua_State* ssc_lua_get_mainP();
int ssc_lua_setup();

#endif // HEADER_SSC_LUA_SSC_LUA
