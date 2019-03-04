#ifndef HEADER_SSC_SCRATCH_EDITINGSCOBJ
#define HEADER_SSC_SCRATCH_EDITINGSCOBJ

#include "../../ssc_libs.h"
#include "ScratchSprite.h"

sscScratchSprite* ssc_editing_obj_get(); /**< 获取用户正在编辑的角色结构, NULL 则为选中了舞台 */

void ssc_editing_obj_get() /**< 设置用户正在编辑的角色结构，如果为 NULL 则为舞台 */



#endif // HEADER_SSC_SCRATCH_EDITINGSCOBJ
