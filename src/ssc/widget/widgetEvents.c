#include <gtk/gtk.h>

void ssc_widget_event_window_destroy(GtkWidget *widget,gpointer data)/**< 窗口销毁 */
{
	ssc_main_quit();
}

