#include "ScratchStage.h"

G_DEFINE_TYPE(SSCScratchStage, ssc_scratch_stage, SSC_SCRATCH_OBJ_TYPE);

static void ssc_scratch_stage_init(SSCScratchStage *s)
{
    SSC_SCRATCH_OBJ(s)->objType = STAGE;
    s->newPenStrokes = NULL;
    s->penActivity = FALSE;
    s->penLayer = NULL;
    s->tempoBPM = 60;
}

static void ssc_scratch_stage_class_init(SSCScratchStageClass *s)
{
    
}

SSCScratchStage* ssc_scratch_stage_new()
{
    return (SSCScratchStage*)g_object_new(SSC_SCRATCH_STAGE_TYPE,NULL);
}
