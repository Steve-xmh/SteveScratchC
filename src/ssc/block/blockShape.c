#include "blockShape.h"

GdkRGBA fontColor  = {1,1,1,1};/**< 默认字体颜色：白色 */
GdkRGBA fontColorB = {0,0,0,0};/**< 默认字体颜色：黑色 */

GdkRGBA* getOutlineColor(GdkRGBA* base)
{
	GdkRGBA* c = gdk_rgba_copy(base);
	c->red = c->red * LERP;
	c->green = c->green * LERP;
	c->blue = c->blue * LERP;
	return c;
}

gboolean drawBlock(GtkWidget* block,cairo_t *C,gpointer data)
{
	//;print("R ");
	sscBlockShape* bs = (sscBlockShape*)data;
	guint width, height;

	GtkStyleContext *context;

	context = ssc_libs_gtk_widget_get_style_context (block);

	ssc_libs_gtk_render_background(context, C, 0, 0, width, height);
	//在这里绘制...

	//调整模块大小
	cairo_text_extents_t ex;
	ssc_libs_cairo_set_font_size(C,SSC_BF_SIZE);
	ssc_libs_cairo_select_font_face(C,"微软雅黑",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_NORMAL);
    ssc_libs_cairo_text_extents(C,bs->text,&ex);
    //print("%f\t%f\t%f\t%f\t%f\t%f\n",ex.width,ex.height,ex.x_bearing,ex.y_bearing,ex.x_advance,ex.y_advance);

    guint hOffset = 0;//对于头部模块需要一点偏移

    if(bs->shape == SSC_BT_HAT)
	{
		hOffset = 10;
		ex.width = ex.width<80?80:ex.width;
	}

    ssc_libs_gtk_widget_set_size_request(block,ex.width+12,2*ex.height+ex.y_bearing+16+SSC_BF_OUTLINEW+hOffset);

    width = ssc_libs_gtk_widget_get_allocated_width (block);
	height = ssc_libs_gtk_widget_get_allocated_height (block);

	ssc_libs_cairo_set_line_width(C,2);
    switch(bs->shape)//渲染模块
    {
	case SSC_BT_CMD://控件模块
		ssc_block_shape_draw_cmd(C,width,height);
		break;
	case SSC_BT_NUM://控件模块
		ssc_block_shape_draw_num(C,width,height);
		break;
	case SSC_BT_HAT://控件模块
		ssc_block_shape_draw_hat(C,width,height);
		break;
	default:
		ssc_block_shape_draw_cmd(C,width,height);
    }
	//取默认颜色
	if(!bs->color)
	{
		bs->color = ssc_specs_get_color_by_category_id(ssc_specs_get_category_by_block_spec(bs->text));
	}
	gdk_cairo_set_source_rgba (C, bs->color);
	ssc_libs_cairo_fill_preserve(C);
	gdk_cairo_set_source_rgba (C, getOutlineColor(bs->color));
	//cairo_set_line_width(C,2);
	ssc_libs_cairo_stroke(C);

    //打印标签

	gdk_cairo_set_source_rgba (C, &fontColor);

	ssc_libs_cairo_move_to(C,8,SSC_BF_OUTLINEW + 8 - ex.y_bearing+hOffset);
    ssc_libs_cairo_show_text(C,bs->text);

    return FALSE;
}

sscBlockShape* ssc_block_createBlock(int shape,GdkRGBA* color)
{
    sscBlockShape* bs;
    bs = (sscBlockShape*) ssc_libs_g_malloc(sizeof(sscBlockShape));//新建一个

    GtkWidget* block;
    block = ssc_libs_gtk_drawing_area_new();

    bs->widget = block;
    bs->color = color;
	bs->shape = shape;
	bs->cWidget = NULL;

    //expose-event
    ssc_libs_gtk_widget_set_size_request(block,100,50);

    ssc_libs_g_signal_connect(block,"draw",G_CALLBACK(drawBlock),bs);
    return bs;
}

sscBlockShape* ssc_block_shape_by_name(int shape,gchar* name)
{
    sscBlockShape* bs;
    bs = (sscBlockShape*) ssc_libs_g_malloc(sizeof(sscBlockShape));//新建一个

    GtkWidget* block;
    block = ssc_libs_gtk_drawing_area_new();

    bs->widget = block;
    bs->color = NULL;
    bs->text = name;
    bs->shape = shape;
	bs->cWidget = NULL;
    //expose-event
    ssc_libs_gtk_widget_set_size_request(block,100,50);

    ssc_libs_g_signal_connect(block,"draw",G_CALLBACK(drawBlock),bs);
    return bs;
}


/** \brief 用默认设置创建一个模块外形
 *
 * \return 模块指针
 *
 */

sscBlockShape* ssc_block_createBlock_by_default()
{
    sscBlockShape* bs;
    GdkRGBA* c;
    bs = (sscBlockShape*) ssc_libs_g_malloc(sizeof(sscBlockShape));//新建一个
    c = (GdkRGBA*) ssc_libs_g_malloc(sizeof(c)); //
    c->blue = 0xFF/0xFF;
    c->green = 0xFF/0x99;
    c->red = 0;


    GtkWidget* block;
    block = ssc_libs_gtk_drawing_area_new();
    //expose-event

    ssc_libs_gtk_widget_set_size_request(block,100,SSC_BF_SIZE+16);
    ssc_libs_g_signal_connect(block,"draw",G_CALLBACK(drawBlock),bs);

    bs->widget = block;
    bs->color = c;
    bs->hasLoopArrow = FALSE;
    bs->shape = SSC_BT_CMD;
	bs->text = "Undefined";//chChar("未定义");
	bs->cWidget = NULL;
    return bs;
}

/** \brief 克隆模块外形
 * 注意，只是复制了指针，结构中指针消失的话会影响到所有使用同一指针的模块！
 * \param 需要克隆的模块外形
 * \return 克隆后的模块外形
 *
 */

sscBlockShape* ssc_block_shape_clone(sscBlockShape* bs)
{
	sscBlockShape* cbs;
    cbs = (sscBlockShape*) ssc_libs_g_malloc(sizeof(sscBlockShape));//新建一个
	cbs->color = bs->color;
	cbs->isInter = bs->isInter;
	cbs->hasLoopArrow = bs->hasLoopArrow;
	cbs->dragShape = NULL;
	cbs->dx = 0;
	cbs->dy = 0;
	cbs->text = bs->text;
	cbs->shape = bs->shape;
	cbs->widget = ssc_libs_gtk_drawing_area_new();
	ssc_libs_gtk_widget_set_size_request(cbs->widget,100,50);
	ssc_libs_g_signal_connect(cbs->widget,"draw",G_CALLBACK(drawBlock),cbs);
	if(bs->cWidget)
	{
		//cbs->cWidget = g_obj;
	}else
	{
		cbs->cWidget = NULL;
	}
	return cbs;
}

/** \brief 销毁模块外形，释放内存
 *
 * \param 需要销毁的模块外形
 * \param 是否需要释放字符串
 * \return 无返回
 *
 */

void ssc_block_shape_destroy(sscBlockShape* bs,gboolean needDestroyString)
{
	if(bs->cWidget)
		ssc_libs_gtk_widget_destroy(bs->cWidget);

	if(bs->widget)
		ssc_libs_gtk_widget_destroy(bs->widget);

	if(needDestroyString)
	{
		ssc_libs_g_free(bs->text);
		bs->text = NULL;
	}
	ssc_libs_g_free(bs);
}
