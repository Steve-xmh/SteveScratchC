#ifndef HEADER_SSC_CONFIG
#define HEADER_SSC_CONFIG

#include "version.h"

// 删除调试信息加快速度
#ifdef DEBUG
#define print(...) printf(__VA_ARGS__)
#else
#define print(...)
#endif // DEBUG

#define VER(A,B,C,D) #A "." #B "." #C "." #D

#define SSC_VERSION SSC_VER_STATUS_SHORT " v" SSC_VER_FULLVERSION_STRING  /**< 版本 */
#define SSC_NAME "SteveScratchC" /**< 名称 */
#define SSC_FULLNAME SSC_NAME " " SSC_VERSION /**< 完整的名称（标题） */

#define SSC_COPYRIGHT "Copyright 2019 by SteveXMH, All right reserved."

#define SSC_DONATERS_LIST_ON_AFDIAN {\
_("司南"), \
_("害怕稽"), \
_("Sparrow"), \
_("CuteSheep233"), \
_("爱发电用户_xTGB"), \
_("AlexCui"), \
NULL \
}

#define SSC_WINDOW_MINWIDTH 1000 /**< 最小宽度 */
#define SSC_WINDOW_MINHEIGHT 700 /**< 最小长度 */

#endif // HEADER_SSC_CONFIG
