#include "SSCUI.h"

static GtkBuilder *loadedBuilder; // 存放已经加载的页面

static GtkWidget *mainWindow; // 主窗口
static GtkWidget *menuAbout; // 关于菜单项
static GtkWidget *menuOpen; // 打开菜单项
static GtkWidget *buttonSSCN; // 切换至社区网络
static GtkWidget *mainStack; // 主堆栈
static GtkWidget *processBar; // 进度条
static GtkWidget *processBarLabel; // 进度条文本
static GtkWidget *loadingWidget; // 进度条文本
static GtkWidget *sscOverlay; // 进度条文本

static gchar *loadObjFailedMsg = "Can't load widget \"%s\" in glade file.";

GtkBuilder *ssc_ui_get_builder()
{
	return loadedBuilder;
}

// 加载指定控件并赋值到一个变量中， obj 为变量名称， name 为控件名称
#define SSC_UI_GET_OBJ(obj,name)\
obj=GTK_WIDGET(gtk_builder_get_object(loadedBuilder,name));if(!obj){g_set_error(err,0,0x1,loadObjFailedMsg,name);return;}

void ssc_ui_init(GError **err)
{
	loadedBuilder = gtk_builder_new();

	if(gtk_builder_add_from_file(loadedBuilder,"SSCWindow.glade",err))
	{
		SSC_UI_GET_OBJ(mainWindow,"ssc-main-window");
		SSC_UI_GET_OBJ(menuAbout,"ssc-menu-about");
		SSC_UI_GET_OBJ(menuOpen,"ssc-menu-open");
		SSC_UI_GET_OBJ(buttonSSCN,"ssc-sscn-button");
		SSC_UI_GET_OBJ(mainStack,"ssc-main-stack");
		SSC_UI_GET_OBJ(processBar,"ssc-loading-bar");
		SSC_UI_GET_OBJ(processBarLabel,"ssc-loading-bar-label");
		SSC_UI_GET_OBJ(loadingWidget,"ssc-loading-widget");
		SSC_UI_GET_OBJ(sscOverlay,"ssc-overlay");
		if (ssc_ui_setup_events(err)) // 设置事件
		{

		}
		else{return;}
	}
	else{return;}
}

GtkWidget *ssc_ui_get_widget_main_window(){return mainWindow;}
GtkWidget *ssc_ui_get_widget_menu_about(){return menuAbout;}
GtkWidget *ssc_ui_get_widget_menu_open(){return menuOpen;}
GtkWidget *ssc_ui_get_widget_main_stack(){return mainStack;}
GtkWidget *ssc_ui_get_widget_process_bar(){return processBar;}
GtkWidget *ssc_ui_get_widget_process_bar_label(){return processBarLabel;}
GtkWidget *ssc_ui_get_widget_loading_widget(){return loadingWidget;}
GtkWidget *ssc_ui_get_widget_overlay(){return sscOverlay;}
