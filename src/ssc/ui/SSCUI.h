/* SSCUI.c/SSCUI.h
 * 用于提供 UI 的操作接口
 */

#ifndef HEADER_SSC_UI_SSCUI
#define HEADER_SSC_UI_SSCUI

#include "../../Libs.h"

GtkBuilder *ssc_ui_get_builder(void);
void ssc_ui_init(GError **err);

GtkWidget *ssc_ui_get_widget_main_window(void);

#endif // HEADER_SSC_UI_SSCUI
