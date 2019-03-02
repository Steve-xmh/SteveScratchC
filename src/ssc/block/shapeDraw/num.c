#include "num.h"
void ssc_block_shape_draw_num(cairo_t *C,guint w,guint h)
{
	cairo_move_to(C,4+SSC_BF_OUTLINEW,SSC_BF_OUTLINEW);
	cairo_line_to(C,w-4-SSC_BF_OUTLINEW,SSC_BF_OUTLINEW);
	cairo_line_to(C,w-SSC_BF_OUTLINEW,4+SSC_BF_OUTLINEW);
	cairo_line_to(C,w-SSC_BF_OUTLINEW,h-4-SSC_BF_OUTLINEW);
	cairo_line_to(C,w-4-SSC_BF_OUTLINEW,h-SSC_BF_OUTLINEW);
	cairo_line_to(C,4+SSC_BF_OUTLINEW,h-SSC_BF_OUTLINEW);
	cairo_line_to(C,SSC_BF_OUTLINEW,h-4-SSC_BF_OUTLINEW);
	cairo_line_to(C,SSC_BF_OUTLINEW,4+SSC_BF_OUTLINEW);
	cairo_line_to(C,4+SSC_BF_OUTLINEW,SSC_BF_OUTLINEW);
}
