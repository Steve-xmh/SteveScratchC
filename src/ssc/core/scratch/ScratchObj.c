#include "ScratchObj.h"

G_DEFINE_TYPE(SSCScratchObj, ssc_scratch_obj, G_TYPE_OBJECT);

static void ssc_scratch_obj_init(SSCScratchObj *s)
{
    s->objName = NULL;
    s->objType = JUST_OBJ;
    s->variables = g_ptr_array_new();
    s->lists = g_ptr_array_new();
    s->scripts = g_ptr_array_new();
    s->scriptsComments = g_ptr_array_new();
    s->sounds = g_ptr_array_new();
    s->costumes = g_ptr_array_new();
    s->currentCostumeIndex = g_ptr_array_new();
    s->volume = 1;
    s->instrument = 0;

    s->localVariables = g_ptr_array_new();
    s->localLists = g_ptr_array_new();
}

static void ssc_scratch_obj_class_init(SSCScratchObjClass *s)
{

}

SSCScratchObj* ssc_scratch_obj_new()
{
    return (SSCScratchObj*)g_object_new(SSC_SCRATCH_OBJ_TYPE,NULL);
}

