/*
 * SSCUI.c/SSCUI.h
 * 用于提供 UI 的操作接口
 */

#ifndef HEADER_SSC_UI_SSCUI
#define HEADER_SSC_UI_SSCUI

#include "../../Libs.h"

#include "UIEvents.h"

GtkBuilder *ssc_ui_get_builder(void);
void ssc_ui_init(GError **err);

GtkWidget *ssc_ui_get_widget_main_window(void);
GtkWidget *ssc_ui_get_widget_menu_about(void);
GtkWidget *ssc_ui_get_widget_menu_open(void);
GtkWidget *ssc_ui_get_widget_main_stack(void);
GtkWidget *ssc_ui_get_widget_process_bar(void);
GtkWidget *ssc_ui_get_widget_process_bar_label(void);
GtkWidget *ssc_ui_get_widget_loading_widget(void);
GtkWidget *ssc_ui_get_widget_overlay(void);
GtkWidget *ssc_ui_get_widget_gl_area(void);

#endif // HEADER_SSC_UI_SSCUI
