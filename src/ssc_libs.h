#ifndef HEADER_SSC_LIBS
#define HEADER_SSC_LIBS

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <glib.h>
#include <glib/gi18n.h>
#include <cairo.h>

/**
本库包含了所有使用了 LGPL 协议保护的函数的闭包函数，
您可以修改此处的代码来重定义链接库的工作。
*/


void gtk_init(int* argc,char*** argv);
gpointer g_malloc(gsize n_bytes);
gulong g_signal_connect(gpointer a,const gchar *b,GCallback c,gpointer d);
void g_object_unref(gpointer a);
void gtk_widget_destroy(GtkWidget* w);
void gtk_widget_show_all(GtkWidget* w);
GtkStyleContext* gtk_widget_get_style_context(GtkWidget* w);
GtkWidget* gtk_drawing_area_new(void);
GdkWindow* gtk_widget_get_window(GtkWidget* w);
void cairo_move_to(cairo_t *C,double x,double y);
void cairo_line_to(cairo_t *C,double x,double y);
void gtk_render_background();

#endif // HEADER_SSC_LIBS

