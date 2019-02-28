#include "ssc_libs.h"

void ssc_libs_ssc_libs_gtk_init(int* argc,char*** argv)
{
	ssc_libs_gtk_init(argc,argv);
}

gpointer ssc_libs_g_malloc(gsize n_bytes)
{
	return g_malloc(n_bytes);
}

gulong ssc_libs_g_signal_connect(gpointer a,const gchar *b,GCallback c,gpointer d)
{
	return g_signal_connect(a,b,c,d);
}

void ssc_libs_g_object_unref(gpointer a)
{
	g_object_unref(a);
}

void ssc_libs_gtk_widget_show_all(GtkWidget* w)
{
	gtk_widget_show_all(w);
}

void ssc_libs_gtk_widget_destroy(GtkWidget* w)
{
	gtk_widget_destroy(w);
}

GtkStyleContext* ssc_libs_gtk_widget_get_style_context(GtkWidget* w)
{
	return gtk_widget_get_style_context(w);
}

GtkWidget* ssc_libs_gtk_drawing_area_new()
{
	return gtk_drawing_area_new();
}

GdkWindow* ssc_libs_gtk_widget_get_window(GtkWidget* w)
{
	return gtk_widget_get_window(w);
}
