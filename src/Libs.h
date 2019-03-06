/* 
 * Libs.c/Libs.h
 * 所有引用库的组合头文件
 * 如果需要引用库文件的话请先在此处包含后再包含此头文件到你的头文件即可
 */

#ifndef HEADER_LIBS
#define HEADER_LIBS

// GTK+ 3.0
// 禁止使用已弃用的模块
#define GTK_DISABLE_DEPRECATED
#include <gtk/gtk.h>

// Lua
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#endif