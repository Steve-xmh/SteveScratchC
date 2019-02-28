#include "SSCBlock.h"

luaL_Reg ssc_class_block_func[] =
{
	{"new",ssc_class_block_new},
	{"destroy",ssc_class_block_destroy},
	{NULL,NULL}
};

int ssc_class_block_new(lua_State* L)
{

	luaL_setmetatable(L,SCC);
	lua_newuserdata(L,sizeof(int));
	lua_setmetatable(L,-2);
	return 1;
}

int ssc_class_block_destroy(lua_State* L)
{
	return 0;
}

int ssc_class_block_setup(lua_State* L)
{
	//SCCT
	luaL_newlib(L,ssc_class_block_func);
	lua_setfield(L,-2,SCCT);

	return TRUE;
}
