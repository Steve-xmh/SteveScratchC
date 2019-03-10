#include "ScratchStage.h"

G_DEFINE_TYPE(SSCScratchStage, ssc_scratch_stage, G_TYPE_OBJECT);

static void ssc_scratch_stage_init(SSCScratchStage *s)
{
    s->newPenStrokes = NULL;
    s->penActivity = FALSE;
    s->penLayer = NULL;
    s->tempoBPM = 60;
    print("Created one new ScStage!\n");
}

static void ssc_scratch_stage_class_init(SSCScratchStageClass *s)
{

}

static SSCScratchStage* ssc_scratch_stage_new()
{
    return (SSCScratchStage*)g_object_new(SSC_SCRATCH_STAGE_TYPE,NULL);
}
