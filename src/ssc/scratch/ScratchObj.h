#ifndef HEADER_SSC_SCRATCH_SCRATCHOBJ
#define HEADER_SSC_SCRATCH_SCRATCHOBJ

#include <gtk/gtk.h>

#define SSC_OT_SPRITE 0 /**< 对象类型：角色 */
#define SSC_OT_CLONE 1 /**< 对象类型：克隆体 */
#define SSC_OT_STAGE 2 /**< 对象类型：舞台 */

typedef struct sscScratchObj
{
	guint objType:2; 			/**< 该对象类型，具体参考 SSC_OT_* */
	gchar* objName; 			/**< 对象的名称 */
	GList* variables; 			/**< 拥有的变量列表 */
	GList* scripts; 			/**< 脚本列表 */
	GList* scriptComments; 		/**< 脚本注释列表 */
	GList* sounds; 				/**< 音效列表 */
	GList* costumes; 			/**< 造型列表 */
	guint* currentCostumeIndex;	/**< 当前使用造型 */
	gdouble volume;				/**< 音效音量大小 0.0-1.0 */
	guint instrument;			/**< 乐器编号 */

	// 以下是保留变量，用于缓存以防止列表寻址造成的性能下降

	gpointer curCostumes;		/**< 当前使用的造型缓存 */

}sscScratchObj;

#endif // HEADER_SSC_SCRATCH_SCRATCHOBJ
