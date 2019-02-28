#include <gtk/gtk.h>
#include <glib/gi18n.h>
#include "topBarMenusFunction.h"
/*
	用于初始化顶部菜单栏
*/

GObject* ssc_topBarMenus_get(GtkBuilder* b,gchar* n)
{
	return ssc_libs_gtk_builder_get_object(b,n);
}

gboolean ssc_topBarMenus_setup(GtkBuilder* b)/**< 初始化菜单 */
{
	GObject* t;
	if(!(t = ssc_topBarMenus_get(b,"ssc-menu-new"))) return FALSE;//新建工程
	ssc_libs_g_signal_connect(t,"activate",G_CALLBACK(ssc_topBar_clicked),"new");
	if(!(t = ssc_topBarMenus_get(b,"ssc-menu-open"))) return FALSE;
	ssc_libs_g_signal_connect(t,"activate",G_CALLBACK(ssc_topBar_clicked),"open");//打开工程
	if(!(t = ssc_topBarMenus_get(b,"ssc-menu-save"))) return FALSE;
	ssc_libs_g_signal_connect(t,"activate",G_CALLBACK(ssc_topBar_clicked),"save");//保存工程
	if(!(t = ssc_topBarMenus_get(b,"ssc-menu-save-as"))) return FALSE;
	ssc_libs_g_signal_connect(t,"activate",G_CALLBACK(ssc_topBar_clicked),"save-as");//另存为
	if(!(t = ssc_topBarMenus_get(b,"ssc-menu-quit"))) return FALSE;
	ssc_libs_g_signal_connect(t,"activate",G_CALLBACK(ssc_topBar_clicked),"quit");//退出程序
	if(!(t = ssc_topBarMenus_get(b,"ssc-menu-cut"))) return FALSE;
	ssc_libs_g_signal_connect(t,"activate",G_CALLBACK(ssc_topBar_clicked),"cut");//剪切
	if(!(t = ssc_topBarMenus_get(b,"ssc-menu-copy"))) return FALSE;
	ssc_libs_g_signal_connect(t,"activate",G_CALLBACK(ssc_topBar_clicked),"copy");//复制
	if(!(t = ssc_topBarMenus_get(b,"ssc-menu-paste"))) return FALSE;
	ssc_libs_g_signal_connect(t,"activate",G_CALLBACK(ssc_topBar_clicked),"paste");//粘贴
	if(!(t = ssc_topBarMenus_get(b,"ssc-menu-delete"))) return FALSE;
	ssc_libs_g_signal_connect(t,"activate",G_CALLBACK(ssc_topBar_clicked),"delete");//删除
	if(!(t = ssc_topBarMenus_get(b,"ssc-menu-about"))) return FALSE;
	ssc_libs_g_signal_connect(t,"activate",G_CALLBACK(ssc_topBar_clicked),"about");//关于

    return TRUE;
};

