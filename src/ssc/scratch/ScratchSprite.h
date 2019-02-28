#ifndef HEADER_SSC_SCRATCH_SCRATCHSPRITE
#define HEADER_SSC_SCRATCH_SCRATCHSPRITE

#include "../../ssc_libs.h"

typedef struct sscScratchSprite
{
	gchar* name;			/**< 角色的名称 */
	gdouble scratchX;		/**< 角色的横坐标 */
	gdouble scratchY;		/**< 角色的纵坐标 */
	gdouble driection;		/**< 角度，默认朝右 */
	gboolean isDraggable;	/**< 是否可拖动 */
    gboolean penIsDown;		/**< 笔是否落下 */
    gdouble penWidth;		/**< 笔的粗细 */

}sscScratchSprite; 			/**< SSC 角色类 */

#endif // HEADER_SSC_SCRATCH_SCRATCHSPRITE
