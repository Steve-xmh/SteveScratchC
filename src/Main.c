#include "Main.h"

int main(int argn, char* argv[])
{
    gtk_init(&argn,&argv);
    if(ssc_init()) return -1;
    gtk_widget_show_all(ssc_ui_get_widget_main_window());
    gtk_main();
    return 0;
}

// 用于报错退出
static void ssc_report_error(GError *err)
{
	error("Init: %d (0x%X)\t%s\n",err->code,err->code,g_locale_from_utf8(err->message,-1,NULL,NULL,NULL));
	GtkWidget *dialog = gtk_message_dialog_new_with_markup(NULL,GTK_DIALOG_MODAL | GTK_DIALOG_USE_HEADER_BAR,GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,
															"<b>警告</b>：\n"
															"发生了初始化错误， SteveScratchC 没有正常启动\n"
															"错误代码：%d (0x%X)\n"
															"错误信息：%s",
															err->code,
															err->code,
															err->message);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
	return;
}

// 建议的初始化代码
// 需要保证你的函数原型为 void(GError**)
// 这样方便程序自动报错退出
#define SSC_INIT_CHECK(fun)\
do {\
if (err) g_error_free(err); \
err = NULL;\
fun(&err); \
if(err != NULL){ssc_report_error(err);return -1;}\
}while(0)

// 在此处放入初始化函数
int ssc_init()
{
	GError *err = NULL;
    info("Initaling SteveScratchC!\n");

	SSC_INIT_CHECK(ssc_ui_init);
	SSC_INIT_CHECK(ssc_core_init);

    return 0;
}
