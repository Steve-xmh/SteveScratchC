/*
 * UIEvents.c/UIEvents.h
 * 绑定控件的事件
 */

#ifndef HEADER_SSC_UI_UIEVENTS
#define HEADER_SSC_UI_UIEVENTS

#include "../../Libs.h"

#include "SSCUI.h"
#include "UI2Core.h"
#include "../core/SSCCore.h"
#include "SSCGL.h"

gboolean ssc_ui_setup_events(GError**);
void ssc_ui_show_about(GtkMenuItem *item, gpointer data);
void ssc_ui_open_project(GtkMenuItem *item, gpointer data);

#endif // HEADER_SSC_UI_UIEVENTS
