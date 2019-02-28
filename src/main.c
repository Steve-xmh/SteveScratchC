#include "main.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    langSetup();
    print("Running SteveScratchC!\n");
    // GTK 初始化
    ssc_libs_ssc_libs_gtk_init(&argc,&argv);
    //if(ssc_libs_g_thread_supported()) g_thread_init(NULL); //多线程
    //gdk_threads_init();
	print("%d\n",sizeof(sscBlockShape));
    print("Using GTK+ version: %d.%d.%d\n",GTK_MAJOR_VERSION,GTK_MINOR_VERSION,GTK_MICRO_VERSION);
    if(ssc_lua_setup())
	{
		return -1;
	}
	print("Initiating components...\n");
    SSCComponents = ssc_widgets_init();


    if (SSCComponents->isInited != 0)
    {
        print("[ERROR] Can't load window components successfully.");
        lua_close(luaP);
        return -1;
    };

    print("Components ready\n");

	//gdk_threads_enter();
    //ssc_libs_ssc_libs_gtk_main();

	ssc_main_run();

    lua_close(luaP);
    //gdk_threads_leave();
    return 0;
};

void langSetup(void)/**< 语言文字初始化 */
{
	setlocale(LC_ALL,"");
	bindtextdomain("specs","../share/locale");
	bind_textdomain_codeset("specs","UTF-8");
}

