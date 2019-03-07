/** ScratchObj.c/ScratchObj.h
 *
 *  SSCScratchStage 和 SSCScratchSprite 的父类
 *  存储了两个对象所共有的信息
 *
 */

#ifndef HEADER_SSC_CORE_SCRATCHOBJ
#define HEADER_SSC_CORE_SCRATCHOBJ

#include "../../Libs.h"

typedef enum SSCScratchObjType
{
	SPRITE = 1,  /** 角色对象 */
	SPRITECLONE, /** 克隆体对象 */
	STAGE,		 /** 舞台对象 */
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
	GPtrArray *currentCostumeIndex;	/** 对象的名称 */
	gdouble volume;					/** 对象音量 */
	guint instrument;				/** 对象使用的乐器 */
	// 分割线 ---------------
	GPtrArray localVariables;		/** 对象的局部变量，针对角色克隆体使用 */
	GPtrArray localLists;			/** 对象的局部链表，针对角色克隆体使用 */
} SSCScratchObj;					/** ScratchObj 对象 */

typedef struct SSCScratchObjClass
{
	GObject parent_class;
}

G_DEFINE_TYPE(SSCSCratchObj,ssc_scratch_obj,G_TYPE_OBJECT);

#endif // HEADER_SSC_CORE_SCRATCHOBJ
