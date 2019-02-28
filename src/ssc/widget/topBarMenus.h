#ifndef HEADER_SSC_WIDGET_TOPBARMENUS
#define HEADER_SSC_WIDGET_TOPBARMENUS

#include <gtk/gtk.h>

GtkWidget* addMenuItem(GtkWidget*,gchar*,gchar*);
void ssc_topBarMenus_setup(GtkBuilder*);

#endif // HEADER_SSC_WIDGET_TOPBARMENUS
