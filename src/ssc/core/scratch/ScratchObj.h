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
	SPRITE,		  /** 一个角色本体 */
	SPRITE_CLONE, /** 一个角色克隆体 */
	STAGE,		  /** 一个舞台 */
} SSCScratchObjType;

typedef struct SSCScratchObj
{
	GObject parent_instance;
	// 分割线 ---------------
	GString *objName;			/** 对象的名称 */
	SSCScratchObjType objType;  /** 对象的类型，具体参考 SSCScratchObjType 枚举 */
	GPtrArray *variables;		/** 对象的内置变量集 */
	GPtrArray *lists;			/** 对象的内置列表集 */
	GPtrArray *scripts;			/** 对象的脚本集 */
	GPtrArray *scriptsComments; /** 对象的脚本注释 */
	GPtrArray *sounds;			/** 对象的音效集 */
	GPtrArray *costumes;		/** 对象的造型集 */
	guint currentCostumeIndex;  /** 对象的当前造型编号 */
	gdouble volume;				/** 对象音量 */
	guint instrument;			/** 对象使用的乐器 */
	// 分割线 ---------------
	cairo_surface_t *currentCostumeCache; /** 当前的角色造型，缓存下来以免再次寻找列表浪费性能 */
} SSCScratchObj;						  /** ScratchObj 对象 */

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

/**
 * @brief 重绘一个 ScratchObj 对象，一般对 Obj 进行了旋转或者切换造型或者是切换特效的话就需要调用本函数重绘角色。
 * @param 欲进行操作的 ScratchObj 对象
 * @return 重绘是否成功，成功返回 TRUE，否则返回 FALSE。
 */
gboolean ssc_scratch_obj_draw(SSCScratchObj *s);

#endif
