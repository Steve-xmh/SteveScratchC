#ifndef HEADER_SSC_BLOCK_BLOCKSHAPE
#define HEADER_SSC_BLOCK_BLOCKSHAPE

#include <math.h>
#include "../../chineseEncode.h"
#include "shapeDraw/shapes.h"
#include "../ssc_specs.h"

#define SSC_BF_SIZE 12 				/**< 模块字体大小 */
#define SSC_BF_OUTLINEW 2			/**< 模块描边宽度 */

// 普通形状
#define SSC_BT_RECT 1 				/**< 文本框 */
#define SSC_BT_BOOL 2 				/**< 布尔框 */
#define SSC_BT_NUM 3 				/**< 数字框 */
#define SSC_BT_CMD 4 				/**< 命令模块 */
#define SSC_BT_FINAL_CMD 5 			/**< 无底命令模块 */
#define SSC_BT_OUTLINE_CMD 6 		/**< 框线命令模块 */
#define SSC_BT_HAT 7 				/**< 头部命令模块 */
#define SSC_BT_HAT_PROC 8 			/**< 自定义头部命令模块 */

// C字形状
#define SSC_BT_LOOP 9 				/**< 循环模块 */
#define SSC_BT_LOOP_FINAL 10 		/**< 无底循环模块 */

// E字形状
#define SSC_BT_IFELSE 11 			/**< 判断模块 */

#define LERP 0.9

typedef struct sscColor
{
    guint r:8;/**< 红色范围，0xFF-0x00 */
    guint g:8;/**< 绿色范围，0xFF-0x00 */
    guint b:8;/**< 蓝色范围，0xFF-0x00 */
} sscColor;	/**< 十六进制版本的颜色结构 */

typedef struct sscDColor
{
    gdouble r;/**< 红色范围，1.0-0 */
    gdouble g;/**< 绿色范围，1.0-0 */
    gdouble b;/**< 蓝色范围，1.0-0 */

} sscDColor;	/**< 小数版本的颜色结构 */

//48,40
typedef struct sscBlockShape
{
    GdkRGBA* color;				/**< 模块颜色，一般可取自同一指针 */
    gboolean hasLoopArrow:1;	/**< 是否有循环的箭头图案 */
    gboolean isInter:1;			/**< 是否为模块内的控件 */
    guint shape:4;				/**< 模块样式，具体查找宏定义 SSC_BT_* */
    gchar* text;				/**< 模块标签文本 */
    GtkWidget* widget;			/**< 模块本体 */
    struct sscBlockShape* dragShape;	/**< 模块拖动体 */
    gint dx;					/**< 拖动的原点 X 轴 */
    gint dy;					/**< 拖动的原点 Y 轴 */
    gint x;					/**< 拖动的原点 Y 轴 */
    gint y;					/**< 拖动的原点 Y 轴 */
    GtkWidget* cWidget;			/**< 模块控制控件 */
    //sscBlockShape* parent;	/**< 父模块，用于设置背景色 */
} sscBlockShape;			/**< 模块外形结构 */

gboolean drawBlock(GtkWidget* block,cairo_t *C,gpointer data);
sscBlockShape* ssc_block_createBlock(int shape,GdkRGBA* color);
sscBlockShape* ssc_block_shape_by_name(int shape,gchar* name);
sscBlockShape* ssc_block_createBlock_by_default(void);
sscBlockShape* ssc_block_shape_clone(sscBlockShape* bs);
void ssc_block_shape_destroy(sscBlockShape* bs,gboolean needDestroyString);

#endif // HEADER_SSC_BLOCK_BLOCKSHAPE
