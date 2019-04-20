/*
 * Libs.c/Libs.h
 * 所有引用库的组合头文件
 * 如果需要引用库文件的话请先在此处包含后再包含此头文件到你的头文件即可
 */

#ifndef HEADER_LIBS
#define HEADER_LIBS

// 标准库
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

// GTK+ 3.0
// 禁止使用已弃用的模块
#define GTK_DISABLE_DEPRECATED
#include <gtk/gtk.h>

// Lua
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

// MiniZIP
#include <unzip.h>
#include <zip.h>

// epoxy
#include <epoxy/gl.h>

// printf 转换
#ifdef DEBUG
#define print(...) printf(__VA_ARGS__) // 日常输出
#define info(...) printf("[SSC][Info]" __VA_ARGS__) // 信息
#define warn(...) printf("[SSC][Warn]" __VA_ARGS__) // 警告，用于会有
#define error(...) printf("[SSC][Error]" __VA_ARGS__) // 错误，你懂的
#else
#define print(...)
#define info(...)
#define warn(...)
#define error(...)
#endif

#endif
