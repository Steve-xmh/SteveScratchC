#ifndef HEADER_SSC_LIBS
#define HEADER_SSC_LIBS

#include <gtk/gtk.h>
#include <glib/gi18n.h>
#include <cairo.h>

/**
本库包含了所有使用了 LGPL 协议保护的函数的闭包函数，
您可以修改此处的代码来重定义链接库的工作。
*/


void ssc_libs_ssc_libs_gtk_init(int* argc,char*** argv);
gpointer ssc_libs_g_malloc(gsize n_bytes);
gulong ssc_libs_g_signal_connect(gpointer a,const gchar *b,GCallback c,gpointer d);
void ssc_libs_g_object_unref(gpointer a);
void ssc_libs_gtk_widget_destroy(GtkWidget* w);
void ssc_libs_gtk_widget_show_all(GtkWidget* w);
GtkStyleContext* ssc_libs_gtk_widget_get_style_context(GtkWidget* w);
GtkWidget* ssc_libs_gtk_drawing_area_new(void);
GdkWindow* ssc_libs_gtk_widget_get_window(GtkWidget* w);

#endif // HEADER_SSC_LIBS

