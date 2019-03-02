#ifndef HEADER_SSC_SPECS
#define HEADER_SSC_SPECS

#include "../ssc_libs.h"
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include "block/blockShape.h"

typedef struct ssc_cReg {
	gint num;
	gchar* name;
	gchar* colorStr;
	GdkRGBA* color;
} ssc_cReg; /**< 注册类型表 */

typedef struct ssc_cmdReg {
	gchar* spec;
	gint type;
	gint cate;
	void* op;	/**<  */
} ssc_cmdReg;/**< 模块类型表 */

ssc_cReg* ssc_specs_categories_get();
ssc_cmdReg* ssc_specs_commands_get();
GdkRGBA* ssc_specs_get_color_by_category_name(gchar* name);
GdkRGBA* ssc_specs_get_color_by_category_id(gint* id);
gint ssc_specs_get_category_by_block_spec(gchar* spec);

#endif // HEADER_SSC_SPECS
