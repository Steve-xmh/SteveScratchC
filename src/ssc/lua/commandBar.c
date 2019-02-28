#include "lua.h"
#include <string.h>
#include <stdlib.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

void ssc_commandBar_activate(GtkWidget* bar,gpointer data)
{
	//print("DOSTRING\n");
	const gchar* str = ssc_libs_gtk_entry_get_text(GTK_ENTRY(bar));

	/*
	gchar* memstr = calloc(strlen(str)+1,sizeof(gchar));
	if (!memstr)
	{
		print("[ERROR] Memory Error on doString!\n");
		return -1;
	}
	strcpy(memstr,str);*/
	//print("CPS %s\n",memstr);
    //ssc_lua_dostring(memstr);
	// 多线程测试
    //g_thread_new(NULL,(GThreadFunc)ssc_lua_dostring,memstr);

	lua_State* nL = ssc_lua_get_mainP(); // 获取虚拟机
	lua_State* L = lua_newthread(nL); // 创建线程
	luaL_loadstring(L,str); // 加载文本脚本
	ssc_lua_enqueue_task(L,clock()); // 排队执行线程
	print("[Lua] dostring: %s\n",str);

};

