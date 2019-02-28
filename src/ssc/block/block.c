#include "block.h"

sscBlock* ssc_block_new(gchar* spec,gint type,gchar* color,GCallback* op,GArray* defaultArgs)
{
	sscBlock* sB;
	sB = ssc_libs_g_malloc(sizeof(sB));
	sB->base = ssc_block_base_new();
	sB->shape = ssc_block_shape_by_name(type,spec);
	return sB;
}

