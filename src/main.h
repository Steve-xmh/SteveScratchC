#ifndef MAIN
#define MAIN

#include "ssc_libs.h"
#include "version.h"

#ifdef WINDOWS
#define OS
#endif // WINDOWS
#ifdef UNIX
#define OS
#endif // UNIX
#ifdef OSX
#define OS
#endif // OSX

#ifndef OS
#error Please define least one of these: WINDOWS,UNIX,OSX
#endif // OS

#include <stdio.h>
#include <string.h>

//Lua
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
lua_State *luaP;

//#define GETTEXT_PACKAGE "foo-app" LOCALEDIR "mo"
#include <locale.h>
#include "config.h" //所有宏配置在这里
#define LOCALEDIR "share/locale"
#include "chineseEncode.h" //用于中文编码的转换 onChar()
#include "ssc/ssc_main.h"

struct sscCompoments* SSCComponents;

void signalHandle(int id);

#endif // MAIN
