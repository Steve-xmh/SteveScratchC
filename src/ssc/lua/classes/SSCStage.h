#ifndef HLC_SSCSTAGE
#define HLC_SSCSTAGE

#include "../../ssc_widgets.h"

// 预编译定义
#undef SCC
#define SCC "SSCStage" 	/**< 类名称 */
#undef SCCT
#define SCCT "stage" 	/**< 类表名 */

int ssc_class_stage_paint(lua_State* L);
int ssc_class_stage_clear(lua_State* L);
int ssc_class_stage_setup(lua_State*);

#endif // HLC_SSCSTAGE
