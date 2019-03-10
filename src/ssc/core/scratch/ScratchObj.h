/** ScratchObj.c/ScratchObj.h
 *
 * SSCScratchStage 和 SSCScratchSprite 的父类 
 * 存储了它们共有的信息
 *
 */

#ifndef HEADER_SSC_CORE_SCRATCHOBJ
#define HEADER_SSC_CORE_SCRATCHOBJ

#include "../../../Libs.h"

typedef enum SSCScratchObjType
{
	JUST_OBJ = 0, /** 只是一个 Obj，不是任何子对象 */
	SPRITE, /** 一个角色本体 */
	SPRITE_CLONE, /** 一个角色克隆体 */
	STAGE, /** 一个舞台 */
} SSCScratchObjType;

typedef struct SSCScratchObj
{
	GObject parent_instance;
	// 分割线 ---------------
	GString *objName;				/** 对象的名称 */
	SSCScratchObjType objType;		/** 对象的名称 */
	GPtrArray *variables;			/** 对象的名称 */
	GPtrArray *lists;				/** 对象的名称 */
	GPtrArray *scripts;				/** 对象的名称 */
	GPtrArray *scriptsComments;		/** 对象的名称 */
	GPtrArray *sounds;				/** 对象的名称 */
	GPtrArray *costumes;			/** 对象的名称 */
	GPtrArray *currentCostumeIndex; /** 对象的名称 */
	gdouble volume;					/** 对象音量 */
	guint instrument;				/** 对象使用的乐器 */
	// 分割线 ---------------
	GPtrArray *localVariables; /** 对象的局部变量，针对角色克隆体使用 */
	GPtrArray *localLists;	 /** 对象的局部链表，针对角色克隆体使用 */
} SSCScratchObj;			   /** ScratchObj 对象 */

typedef struct SSCScratchObjClass
{
	GObjectClass parent_class;
} SSCScratchObjClass;

#define SSC_SCRATCH_OBJ_TYPE (ssc_scratch_obj_get_type())
#define SSC_SCRATCH_OBJ(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), SSC_SCRATCH_OBJ_TYPE, SSCScratchObj))
#define SSC_SCRATCH_OBJ_CLASS(class) (G_TYPE_CHECK_CLASS_CAST((class), SSC_SCRATCH_OBJ_TYPE, SSCScratchObjClass))
#define SSC_IS_SCRATCH_OBJ(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), SSC_SCRATCH_OBJ_TYPE))

GType ssc_scratch_obj_get_type(void);
SSCScratchObj *ssc_scratch_obj_new(void);

#endif