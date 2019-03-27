/** ScratchStage.c/ScratchStage.h
 *
 *  SSCScratchObj 的子类
 *  存储了角色的信息并提供了方便的操作函数
 *
 */

#ifndef HEADER_SSC_CORE_SCRATCHSTAGE
#define HEADER_SSC_CORE_SCRATCHSTAGE

#include "../../../Libs.h"
#include "ScratchObj.h"

typedef enum SSCScratchSpriteRotationStyle
{
	NONE = 0; 	/** 不允许旋转，固定在 90 度（存储度数不变） */
	NORMAL; 	/** 任意旋转，度数依 direction 属性而定 */
	LEFTRIGHT;  /** 只允许左右旋转，0-180 度为朝右，-180-0 度为朝左，如果在 0 度和 180 度时则默认朝右 */
}SSCScratchSpriteRotationStyle;

typedef struct SSCScratchSprite
{
	SSCScratchObj parent_instance;
	// 分割线 ---------------
	gdouble scratchX;								/** 角色所在的中心水平位置，以舞台中心为原点 */
	gdouble scratchY;								/** 角色所在的中心垂直位置，以舞台中心为原点 */
	gdouble direction;								/** 角色的当前角度，以度为单位，90度为朝右 */
	SSCScratchSpriteRotationStyle rotationStyle;	/** 角色的旋转方式，具体请参考 SSCScratchSpriteRotationStyle 枚举 */
	
	gboolean isDraggable;							/** 是否可以在播放时被鼠标拖拽 */
	
} SSCScratchSprite; /** ScratchSprite 对象 */

typedef struct SSCScratchSpriteClass
{
	SSCScratchObjClass parent_class;
} SSCScratchSpriteClass;

#define SSC_SCRATCH_SPRITE_TYPE (ssc_scratch_sprite_get_type())
#define SSC_SCRATCH_SPRITE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), SSC_SCRATCH_SPRITE_TYPE, SSCScratchSprite))
#define SSC_SCRATCH_SPRITE_CLASS(class) (G_TYPE_CHECK_CLASS_CAST((class), SSC_SCRATCH_SPRITE_TYPE, SSCScratchSpriteClass))
#define SSC_IS_SCRATCH_SPRITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), SSC_SCRATCH_SPRITE_TYPE))

GType ssc_scratch_sprite_get_type(void);
SSCScratchSprite *ssc_scratch_sprite_new(void);

#endif