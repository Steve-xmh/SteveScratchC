#include "ScratchStage.h"

GPtrArray* spriteList; /**< 用于存储已经载入的角色类 */
gpointer targetObj; /**< 当前选中的操作角色/舞台 */

gboolean ssc_scratch_stage_init()
{
	spriteList = ssc_libs_g_ptr_array_new();
	sscCompoments* c = ssc_widgets_get_compoments();
	GList* children;
	children = ssc_libs_gtk_container_get_children(GTK_CONTAINER(c->spriteList));


	return TRUE;
}



