#include "SSCLua.h"

static lua_State *luaState;

void ssc_lua_dostring(const gchar *str)
{
	if(!luaState){return;}
	luaL_dostring(luaState,str);
}

void ssc_lua_init(GError **err)
{
#ifdef _LUAJIT_H
	info("[Lua]Using LuaJIT!" "\n");
	info("[Lua]"LUAJIT_VERSION "\n");
	info("[Lua]"LUAJIT_COPYRIGHT "\n");
#endif // _LUAJIT_H
	info("[Lua]Lua version: " LUA_RELEASE "\n");
	info("[Lua]" LUA_COPYRIGHT "\n");
	info("[Lua]" LUA_AUTHORS "\n");
	luaState = luaL_newstate();
	if(!luaState)
	{
		g_set_error(err,0,0x1,"无法启动 Lua");
		return;
	}
	luaL_openlibs(luaState);
	info("[Lua]Lua is Ready!\n");
}

lua_State *ssc_lua_get_state(){return luaState;}
