#ifndef HEADER_SSC_CORE_SSCCORE
#define HEADER_SSC_CORE_SSCCORE

#include "../../Libs.h"


#define SSC_CORE_CMD(val,cmd) int* val = (int*)g_malloc(sizeof(int));*val = cmd;/**< 简易的指令生成 */
#define SSC_CORE_COMMAND_OPEN_PROJECT 1 /**< 打开工程 */

#define SSC_CORE_STATUS_STOPED 0
#define SSC_CORE_STATUS_NEEDSTOP 1
#define SSC_CORE_STATUS_RUNNING 2

typedef struct
{
	gint status;
	GThread *mainThread;
	GMutex mainThread_q_m;
	GAsyncQueue *mainThread_q;
}SSCCore;

void ssc_core_init(GError**);	/**< 核心端初始化 */
void *ssc_core_main(gpointer);	/**< 核心端主函数 */
GPtrArray *ssc_core_get_command(void);	/**< 在核心端接收指令，以指针数组类型返回 */
void ssc_core_push_command(guint dataNum,...);	/**< 向核心发送指令，注意每个参数均为一层数组！格式：指令参数数量；指令类型（SSC_CORE_COMMAND）；指令参数... */
#endif // HEADER_SSC_CORE_SSCCORE
