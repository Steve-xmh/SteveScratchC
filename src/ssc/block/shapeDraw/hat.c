#include "hat.h"

void ssc_block_shape_draw_hat(cairo_t *C,guint w,guint h)
{
	ssc_libs_cairo_move_to(C,SSC_BF_OUTLINEW,12+SSC_BF_OUTLINEW);
	ssc_libs_cairo_line_to(C,SSC_BF_OUTLINEW,4+SSC_BF_OUTLINEW);
	ssc_libs_cairo_line_to(C,4+SSC_BF_OUTLINEW,SSC_BF_OUTLINEW);
	ssc_libs_cairo_line_to(C,70+SSC_BF_OUTLINEW,SSC_BF_OUTLINEW);
	ssc_libs_cairo_line_to(C,80+SSC_BF_OUTLINEW,10+SSC_BF_OUTLINEW);
	ssc_libs_cairo_line_to(C,w-4-SSC_BF_OUTLINEW,10+SSC_BF_OUTLINEW);
	ssc_libs_cairo_line_to(C,w-SSC_BF_OUTLINEW,14+SSC_BF_OUTLINEW);

	ssc_libs_cairo_line_to(C,w-SSC_BF_OUTLINEW,h-8-SSC_BF_OUTLINEW);
    ssc_libs_cairo_line_to(C,w-4-SSC_BF_OUTLINEW,h-4-SSC_BF_OUTLINEW);
    ssc_libs_cairo_line_to(C,w-4-SSC_BF_OUTLINEW,h-4-SSC_BF_OUTLINEW);
    ssc_libs_cairo_line_to(C,24+SSC_BF_OUTLINEW,h-4-SSC_BF_OUTLINEW);
    ssc_libs_cairo_line_to(C,20+SSC_BF_OUTLINEW,h-SSC_BF_OUTLINEW);
    ssc_libs_cairo_line_to(C,12+SSC_BF_OUTLINEW,h-SSC_BF_OUTLINEW);
    ssc_libs_cairo_line_to(C,8+SSC_BF_OUTLINEW,h-4-SSC_BF_OUTLINEW);
    ssc_libs_cairo_line_to(C,4+SSC_BF_OUTLINEW,h-4-SSC_BF_OUTLINEW);
    ssc_libs_cairo_line_to(C,SSC_BF_OUTLINEW,h-8-SSC_BF_OUTLINEW);
    ssc_libs_cairo_line_to(C,SSC_BF_OUTLINEW,4+SSC_BF_OUTLINEW);
	ssc_libs_cairo_line_to(C,4+SSC_BF_OUTLINEW,SSC_BF_OUTLINEW);
}
