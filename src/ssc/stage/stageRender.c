#include "stageRender.h"
GtkWidget* ssc_stage = NULL;
cairo_surface_t* sketchPad = NULL;
gboolean ssc_stage_render(GtkWidget* stage,cairo_t *C,gpointer data)
{
    guint w,h;
    GdkRGBA c;
	GtkStyleContext *content;//使用默认主题的配色描边

	content = gtk_widget_get_style_context(stage);
	w = gtk_widget_get_allocated_width(stage);
	h = gtk_widget_get_allocated_height(stage);

	gtk_render_background(content,C,0,0,w,h);

    cairo_set_line_width(C,2);
    cairo_move_to(C,0,0);
    cairo_line_to(C,w,0);
    cairo_line_to(C,w,h);
    cairo_line_to(C,0,h);

    cairo_set_source_rgb(C,1,1,1);
	cairo_fill(C);

    //画一个 SVG 图像

	if (sketchPad)
	{
		cairo_move_to(C,0,0);
		cairo_set_source_surface(C,sketchPad,0,0);
		cairo_paint(C);
	}

	RsvgHandle* svg;
	/*
	svg = rsvg_handle_new_from_file("ScratchCat.svg",NULL);

	if (svg)
	{
		cairo_translate(C,480/2-48,320/2-50.5);
		rsvg_handle_render_cairo(svg,C);
	}

    rsvg_handle_close(svg,NULL);
    g_object_unref(svg);
	*/

	cairo_move_to(C,0,0);
    cairo_line_to(C,w,0);
    cairo_line_to(C,w,h);
    cairo_line_to(C,0,h);
    cairo_close_path(C);
	gtk_style_context_get_border_color(content,gtk_style_context_get_state(content),&c);
    gdk_cairo_set_source_rgba(C,&c);
    cairo_stroke(C);

	return FALSE;

}
//
gboolean ssc_stage_conf(GtkWidget *widget, GdkEvent *event, gpointer data)
{
	cairo_surface_t* newsp = gdk_window_create_similar_surface(gtk_widget_get_window(widget),
																	CAIRO_CONTENT_COLOR_ALPHA,
																	gtk_widget_get_allocated_width(widget),
																	gtk_widget_get_allocated_height(widget));
	if(sketchPad)//如果有旧的画板的话，把旧画板的内容黏贴复制过来
	{
		cairo_t* cr = cairo_create(newsp);
		cairo_set_source_surface(cr,sketchPad,0,0);
		cairo_paint(cr);
		cairo_surface_destroy(sketchPad);
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
		g_signal_connect(stage,"draw",G_CALLBACK(ssc_stage_render),NULL);
		g_signal_connect(stage,"configure-event",G_CALLBACK(ssc_stage_conf),NULL);
		g_signal_connect(stage,"show",G_CALLBACK(ssc_stage_c),NULL);
		ssc_stage_conf(GTK_WIDGET(stage),NULL,NULL);
		gtk_widget_set_events(stage,gtk_widget_get_events(stage)
								| GDK_STRUCTURE_MASK
								);
		print("Setup stage component.\n");
	}else{
		print("[Warn] Unknown stage component.\n");
	}
}

