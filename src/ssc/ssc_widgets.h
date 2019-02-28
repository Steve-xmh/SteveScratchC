#ifndef HEADER_SSC_SSC_WIDGETS
#define HEADER_SSC_SSC_WIDGETS

#include <gtk/gtk.h>
#include <cairo.h>
#include <glib/gi18n.h>
#include "../chineseEncode.h"
#include "../config.h"
#include "lua/commandBar.h"
#include "lua/lua.h"
#include "widget/topBarMenus.h"
#include "block/blockShape.h"
#include "widget/widgetEvents.h"
#include "scratch/PaletteBuilder.h"

/** 用于处理窗口创建等函数 */

typedef struct sscCompoments /**< 用于存放 SSC 窗口所需组件以供其他模块使用 */
{
    int isInited; /**< 是否初始化成功 */
    GtkWidget* window; /**< 窗口组件 */
    GtkWidget* stage; /**< 舞台组件 */
    cairo_surface_t* stageSketchPad; /**< 舞台画板表面 */
    GtkWidget* luaConsole; /**< Lua 控制台组件 */
    GtkWidget* commandBar; /**< Lua 指令框组件 */
    GtkWidget* overlay; /**< 覆盖组件，用于显示拖动物体 */
    GtkWidget* overlayFix; /**< 覆盖组件容器，用于固定拖动物体 */
    GtkWidget* spriteList; /**< 角色列表 */
    GtkWidget* codeArea; /**< 代码区 */
    GtkBuilder* builder; /**< UI构造组件 */
}sscCompoments;

/** \brief 初始化窗口所有组件及其本身
 *
 * \return 返回一个结构，存放所有必需的组件
 *
 */
sscCompoments* ssc_widgets_get_compoments(void);
struct sscCompoments* ssc_widgets_init();
#endif // HEADER_SSC_SSC_WIDGETS
