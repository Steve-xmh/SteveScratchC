#include "SSCUI.h"

static GtkBuilder *loadedBuilder; // 存放已经加载的页面
static GtkWidget *mainWindow; // 主窗口

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
	}
	else{return;}
}

GtkWidget *ssc_ui_get_widget_main_window(){return mainWindow;}
