#ifndef HEADER_SSC_LUA_SSCLUA
#define HEADER_SSC_LUA_SSCLUA

#include "../../Libs.h"
#include "../ui/SSCUI.h"

void ssc_lua_dostring(const gchar *str);
void ssc_lua_init(GError **err);
lua_State *ssc_lua_get_state(void);

#endif // HEADER_SSC_LUA_SSCLUA
