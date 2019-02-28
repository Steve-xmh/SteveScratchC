#ifndef HLC_SSCBLOCK
#define HLC_SSCBLOCK

// 预编译定义
#undef SCC
#define SCC "SSCBlock" 	/**< 类名称 */
#undef SCCT
#define SCCT "block" 	/**< 类表名 */

int ssc_class_block_new(lua_State* L);
int ssc_class_block_destroy(lua_State* L);
int ssc_class_block_setup(lua_State*);

#endif // HLC_SSCBLOCK
