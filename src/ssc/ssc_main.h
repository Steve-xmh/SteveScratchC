
#ifndef HEADER_SSC_SSC_MAIN
#define HEADER_SSC_SSC_MAIN

#include "block/blockBase.h"
#include "lua/lua.h"
#include "lua/commandBar.h"
#include "ssc_widgets.h"
#include "stage/stageRender.h"

void ssc_main_quit(void); /**< 离开 SSC 主循环，退出程序 */
gboolean ssc_main_running(void); /**< SSC 是否正在运行 */
void ssc_main_run(void); /**< 运行 SSC 主循环 */

#endif // HEADER_SSC_SSC_MAIN
