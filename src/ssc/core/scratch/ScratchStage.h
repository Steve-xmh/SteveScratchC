/** ScratchStage.c/ScratchStage.h
 *
 *  SSCScratchObj 的子类
 *  存储了舞台的所有信息
 *
 */

#ifndef HEADER_SSC_CORE_SCRATCHSTAGE
#define HEADER_SSC_CORE_SCRATCHSTAGE

#include "../../../Libs.h"
#include "ScratchObj.h"

typedef struct SSCScratchStage
{
	SSCScratchObj parent_instance;
	// 分割线 ---------------
	gdouble tempoBPM;				/** 音乐节拍速度 */
	gboolean penActivity;			/** 是否有新笔迹加入，有的话则刷新舞台 */
	cairo_surface_t *newPenStrokes; /** 新笔迹的图层，用于与主图层合并 */
	cairo_surface_t *penLayer;		/** 主图层 */
									/* 因为 Cairo 自带写出 PNG 数据，故这里不移植 penLayer 成员 */
									/* 因为这里是录制功能的成员，故不提供，如有需要请发送 Issues */

} SSCScratchStage; /** ScratchStage 对象 */

typedef struct SSCScratchStageClass
{
	SSCScratchObjClass parent_class;
} SSCScratchStageClass;

#define SSC_SCRATCH_STAGE_TYPE (ssc_scratch_stage_get_type())
#define SSC_SCRATCH_STAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), SSC_SCRATCH_STAGE_TYPE, SSCScratchStage))
#define SSC_SCRATCH_STAGE_CLASS(class) (G_TYPE_CHECK_CLASS_CAST((class), SSC_SCRATCH_STAGE_TYPE, SSCScratchStageClass))
#define SSC_IS_SCRATCH_STAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), SSC_SCRATCH_STAGE_TYPE))

GType ssc_scratch_stage_get_type(void);
SSCScratchStage *ssc_scratch_stage_new(void);

#endif