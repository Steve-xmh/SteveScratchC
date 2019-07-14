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
#include "../lua/SSCLua.h"

gboolean ssc_ui_setup_events(GError**);
gboolean ssc_ui_gl_event(gpointer area);
void ssc_ui_do_string(GtkEntry *entry, gpointer data);
void ssc_ui_change_fullscreen(GtkButton *button, gpointer data);
void ssc_ui_show_about(GtkMenuItem *item, gpointer data);
void ssc_ui_open_project(GtkMenuItem *item, gpointer data);

#endif // HEADER_SSC_UI_UIEVENTS
