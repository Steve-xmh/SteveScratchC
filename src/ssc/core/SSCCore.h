/*
 * SSCCore.h/SSCCore.c
 * 核心的主要程序
 */

#ifndef HEADER_SSC_CORE_SSCCORE
#define HEADER_SSC_CORE_SSCCORE

#include "../../Libs.h"

#include "SSCProject.h"

#define SSC_CMD(val,cmd) int* val = (int*)g_malloc(sizeof(int));*val = cmd;			/**< 简易的指令生成 */
#define SSC_CMD_F(val,cmd) float* val = (float*)g_malloc(sizeof(val));*val = cmd;	/**< 简易的指令生成(浮点) */
#define SSC_CMD_D(val,cmd) double* val = (double*)g_malloc(sizeof(val));*val = cmd;	/**< 简易的指令生成(双精度) */
#define SSC_CORE_COMMAND_OPEN_PROJECT (0x000001) /**< 打开工程 */

#define SSC_UI_SET_PROCESS (0x000001)	/**< 显示并设置进度条页面;进度0-1(-1);提示文本 */
#define SSC_UI_HIDE_PROCESS (0x000002)	/**< 隐藏进度条页面 */

#define SSC_CORE_STATUS_STOPED (0x0) 			/**< 线程已停止 */
#define SSC_CORE_STATUS_NEEDSTOP (0x1) 	/**< 线程响应关闭 */
#define SSC_CORE_STATUS_RUNNING (0x2) 	/**< 线程运行中 */

typedef struct
{
	gint status;

	// Core 内容

	//

	GThread *mainThread;

	GMutex mainThread_q_m; // UI端->核心端
	GAsyncQueue *mainThread_q;

	GMutex mainThread_ui_q_m; // 核心端->UI端
	GAsyncQueue *mainThread_ui_q;
}SSCCore;

void ssc_core_init(GError**);	/**< 核心端初始化 */
void *ssc_core_main(gpointer);	/**< 核心端主函数 */
GPtrArray *ssc_core_get_command(void);			/**< 在核心端接收指令，以指针数组类型返回 */
void ssc_core_push_command(guint dataNum,...);	/**< 向核心发送指令，注意每个参数均为一层数组！格式：指令参数数量；指令类型（SSC_CORE_COMMAND）；指令参数... */

GPtrArray *ssc_core_ui_get_command(void);	/**< 在UI端接收指令，以指针数组类型返回 */
void ssc_core_ui_push_command(guint dataNum,...);	/**< 向UI端发送指令，注意每个参数均为一层数组！格式：指令参数数量；指令类型（SSC_UI_COMMAND）；指令参数... */
#endif // HEADER_SSC_CORE_SSCCORE
