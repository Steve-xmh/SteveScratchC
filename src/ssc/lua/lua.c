/*
	这里提供了让 Lua 与 SSC 交互的接口
	都会在 lua 中的 ssc 库中存放
*/
#include "lua.h"

#define lgetEnd() ssc_libs_gtk_text_buffer_get_end_iter(consoleWidget,&end)
#define lprint(s) ssc_libs_gtk_text_buffer_insert(consoleWidget,&end,s,-1) //ssc_libs_g_async_queue_push(sTunnel,s)

GtkTextBuffer* consoleWidget = NULL;
GtkTextView* consoleView = NULL;
GtkTextTag* error = NULL;
GtkTextTag* msg = NULL;
GtkTextMark* mark = NULL;
GtkTextIter end;

void ssc_lua_setOutput(GtkWidget* w)
{
	consoleView = GTK_TEXT_VIEW(w);
    consoleWidget = ssc_libs_gtk_text_view_get_buffer(GTK_TEXT_VIEW(w));
    if (consoleWidget)
    {
		/*
        ssc_libs_gtk_text_buffer_create_tag (consoleWidget, "[LUA]",
                                    "weight", PANGO_WEIGHT_NORMAL,
                                    "foreground","blue",
                                    NULL,NULL);
		*/

        ssc_libs_gtk_text_buffer_get_end_iter(consoleWidget,&end);
        error = ssc_libs_gtk_text_buffer_create_tag(consoleWidget,"err","foreground","red",NULL);
        msg = ssc_libs_gtk_text_buffer_create_tag(consoleWidget,"msg","foreground","blue",NULL);
        ssc_libs_gtk_text_buffer_insert_with_tags(consoleWidget,&end,SSC_FULLNAME,-1,msg,NULL);
        ssc_libs_gtk_text_buffer_insert_with_tags(consoleWidget,&end,_(" Lua Console\nAll output from lua will be shown here.\n" LUA_COPYRIGHT "\n" LUA_AUTHORS "\n"),-1,msg,NULL);
        mark = ssc_libs_gtk_text_buffer_create_mark(consoleWidget,"scroll",&end,TRUE);
    }else{
		consoleView = NULL;
		print("WARNING: Console was no ready.\n");
    }
}

void ssc_lua_traceback(lua_State* L)/**< 回收错误信息 */
{
	lprint(lua_tostring(L,-1));
	luaL_traceback(L,L,lua_tostring(L,-1),1);
	lprint(lua_tostring(L,-1));
	lprint("\n");
}

/** \brief 延迟程序执行，以秒为单位
 *
 * \param 等待时间，以秒为单位，不得小于 0
 * \return 无返回
 *
 */


int ssc_lua_wait(lua_State *L)
{
	double sec = luaL_checknumber(L,1);
	if (sec <= 0)
	{
		lua_pushstring(L,"Wait time shouldn't be lower than 0.");
		lua_error(L);
		return 0;
	}
    ssc_lua_enqueue_task(L,clock()+sec*CLOCKS_PER_SEC);
	//ssc_libs_g_usleep(sec * 1000000);// 微秒还行
	return lua_yield(L,0);
}

/** \brief 重定向 lua 的 print() 函数，先输出到 SSC 自己的控制台窗口
*
* \param 内容
*
* \return 无返回
*
*/

int ssc_lua_print(lua_State *L)
{
    int nargs = lua_gettop(L);
    print("[Lua] ");

	lgetEnd();
	for (int i=1; i <= nargs; ++i)
	{

		gchar* str = luaL_tolstring(L,i,NULL);
		print(str);
		print("\t");
		lprint(str);
		lprint("\t");
	}

	lprint("\n");
    print("\n");

		ssc_libs_gtk_text_buffer_move_mark (consoleWidget, mark, &end);
		ssc_libs_gtk_text_view_scroll_mark_onscreen(consoleView,mark);

    return 0;
}

/** \brief 控制台清屏
 *
 *  \return 无返回
 *
 */


int ssc_lua_cls(lua_State *L)
{
    if (consoleWidget)
	{
		ssc_libs_gtk_text_buffer_set_text(consoleWidget,"",0);
	};
    return 0;
};

/** \brief 退出程序
 *
 */


int ssc_lua_exit(lua_State *L)
{
	ssc_main_quit();
	return 0;
};

/** \brief 弹出一个信息框
 *
 * \param 标题
 * \param 内容，可添加参数
 * \return 无返回
 *
 */

int ssc_lua_msgBox(lua_State *L)
{
    int argl = lua_gettop(L);
    if (argl != 1)
    {
        lua_pushstring(L,"No message string in it");
        lua_error(L);
        return 0;
    }
    GtkWidget *msg;
    msg = ssc_libs_gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,lua_tostring(L,1));
    ssc_libs_gtk_dialog_run(GTK_DIALOG(msg));
    ssc_libs_gtk_widget_destroy(msg);
    return 0;
};

sscL_cReg sscClasses[] =
{
	{"SSCBlock",ssc_class_block_setup},
	{"SSCStage",ssc_class_stage_setup},
	{NULL,NULL}
};

luaL_Reg sscLib[] =
{
    {"msgBox",ssc_lua_msgBox},
    {"cls",ssc_lua_cls},
    {"exit",ssc_lua_exit},
    {NULL,NULL}
};

luaL_Reg globalFun[] =
{
    {"print",ssc_lua_print},
    {"wait",ssc_lua_wait},
    {NULL,NULL}
};

int luaopen_ssc(lua_State *L)
{
    luaL_newlib(L,sscLib);
    return 1;
}

lua_State* ssc_lua_get_mainP()
{
	return luaP;
}

int ssc_lua_setup()
{
	luaP = luaL_newstate();
	lua_State* L = luaP;

	if(L == NULL)
    {
        print("[ERROR] Can't initialize lua runtime.\n");
        return -1;
    };

	print("Lua State opened, loading library...\n");
    luaL_openlibs(L);
    print("Using lua version: %s\n",LUA_VERSION);

    print("Loading SteveScratchC Lua Library...\n");
    //luaL_requiref(L,"ssc",sscLib,1);

    luaL_newlib(L,sscLib);
    lua_setglobal(L,"ssc");
    lua_getglobal(L,"ssc");

    // 注册类
	print("Registing classes...\n");

	int i = 0;
	while(sscClasses[i].str)
	{
        print("Registing class \"%s\"\t",sscClasses[i].str);
        lua_CFunction cf = sscClasses[i].fun;
        if(cf)
		{
            if(cf(L)!=TRUE)
			{
				print("ERROR: Something wrong in the setup function!\n");
				return -3;
			}
		}else{
			print("ERROR: Not setup function!\n");
			return -2;
		}
		print("Finished\n");
		i++;
	}

	print("Registed %d classes\n",i);
	lua_pop(L,1);
	//重定义打印函数
    lua_getglobal(L, "_G");
    luaL_setfuncs(L, globalFun, 0);
    lua_pop(L,1);

    print("Loaded SteveScratchC Lua Library.\n");
    return 0;
};

