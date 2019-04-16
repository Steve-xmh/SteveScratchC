/*
 * UI2Core.c/UI2Core.h
 * 处理从核心端传回的指令
 */

#ifndef HEADER_SSC_UI_UI2CORE
#define HEADER_SSC_UI_UI2CORE

#include "../../Libs.h"

#include "SSCUI.h"

#include "../core/SSCCore.h"

gboolean ssc_ui2core_event(gpointer data);
gboolean ssc_ui2core_draw_event(gpointer data);

#endif // HEADER_SSC_UI_UI2CORE
