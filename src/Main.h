/*
 * Main.h/Main.c
 * 程序最先启动的地方
 * 需要初始化模块请将你的初始化函数放入 ssc_init 函数中
 */

#ifndef HEADER_MAIN
#define HEADER_MAIN

#include "Libs.h"

#include "ssc/core/SSCCore.h"
#include "ssc/ui/SSCUI.h"
#include "ssc/lua/SSCLua.h"
#include "ssc/core/scratch/ScratchStage.h"

int ssc_init(void); /** SteveScratchC 初始化函数 */

#endif
