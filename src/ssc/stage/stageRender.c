#include "stageRender.h"
GtkWidget* ssc_stage = NULL;
cairo_surface_t* sketchPad = NULL;
gboolean ssc_stage_render(GtkWidget* stage,cairo_t *C,gpointer data)
{
    guint w,h;
    GdkRGBA c;
	GtkStyleContext *content;//使用默认主题的配色描边

	content = ssc_libs_gtk_widget_get_style_context(stage);
	w = ssc_libs_gtk_widget_get_allocated_width(stage);
	h = ssc_libs_gtk_widget_get_allocated_height(stage);

	ssc_libs_gtk_render_background(content,C,0,0,w,h);

    ssc_libs_cairo_set_line_width(C,2);
    ssc_libs_cairo_move_to(C,0,0);
    ssc_libs_cairo_line_to(C,w,0);
    ssc_libs_cairo_line_to(C,w,h);
    ssc_libs_cairo_line_to(C,0,h);

    ssc_libs_cairo_set_source_rgb(C,1,1,1);
	ssc_libs_cairo_fill(C);

    //画一个 SVG 图像

	if (sketchPad)
	{
		ssc_libs_cairo_move_to(C,0,0);
		ssc_libs_cairo_set_source_surface(C,sketchPad,0,0);
		ssc_libs_cairo_paint(C);
	}

	RsvgHandle* svg;
	/*
	svg = ssc_libs_rsvg_handle_new_from_file("ScratchCat.svg",NULL);

	if (svg)
	{
		ssc_libs_cairo_translate(C,480/2-48,320/2-50.5);
		ssc_libs_rsvg_handle_render_cairo(svg,C);
	}

    ssc_libs_rsvg_handle_close(svg,NULL);
    ssc_libs_g_object_unref(svg);
	*/

	ssc_libs_cairo_move_to(C,0,0);
    ssc_libs_cairo_line_to(C,w,0);
    ssc_libs_cairo_line_to(C,w,h);
    ssc_libs_cairo_line_to(C,0,h);
    ssc_libs_cairo_close_path(C);
	ssc_libs_gtk_style_context_get_border_color(content,ssc_libs_gtk_style_context_get_state(content),&c);
    gdk_cairo_set_source_rgba(C,&c);
    ssc_libs_cairo_stroke(C);

	return FALSE;

}
//
gboolean ssc_stage_conf(GtkWidget *widget, GdkEvent *event, gpointer data)
{
	cairo_surface_t* newsp = ssc_libs_gdk_window_create_similar_surface(ssc_libs_gtk_widget_get_window(widget),
																	CAIRO_CONTENT_COLOR_ALPHA,
																	ssc_libs_gtk_widget_get_allocated_width(widget),
																	ssc_libs_gtk_widget_get_allocated_height(widget));
	if(sketchPad)//如果有旧的画板的话，把旧画板的内容黏贴复制过来
	{
		cairo_t* cr = ssc_libs_cairo_create(newsp);
		ssc_libs_cairo_set_source_surface(cr,sketchPad,0,0);
		ssc_libs_cairo_paint(cr);
		ssc_libs_cairo_surface_destroy(sketchPad);
		sketchPad = NULL;
	}
	sketchPad = newsp;
	ssc_widgets_get_compoments()->stageSketchPad = newsp;
	print("Sketchpad ready.\n");
	return FALSE;
}

void ssc_stage_c(GtkWidget *widget, gpointer data)
{
	ssc_stage_conf(widget,NULL,data);
}

gboolean ssc_stage_init(gpointer* stage)
{
	if(GTK_IS_DRAWING_AREA(stage) || GTK_IS_LAYOUT(stage))
	{
		ssc_stage = GTK_WIDGET(stage);
		ssc_libs_g_signal_connect(stage,"draw",G_CALLBACK(ssc_stage_render),NULL);
		ssc_libs_g_signal_connect(stage,"configure-event",G_CALLBACK(ssc_stage_conf),NULL);
		ssc_libs_g_signal_connect(stage,"show",G_CALLBACK(ssc_stage_c),NULL);
		ssc_stage_conf(GTK_WIDGET(stage),NULL,NULL);
		ssc_libs_gtk_widget_set_events(stage,ssc_libs_gtk_widget_get_events(stage)
								| GDK_STRUCTURE_MASK
								);
		print("Setup stage component.\n");
	}else{
		print("[Warn] Unknown stage component.\n");
	}
}

