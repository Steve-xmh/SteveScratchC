#include "PaletteBuilder.h"

GtkFixed* of = NULL;
GtkWidget* ov = NULL;
GtkWidget* ca = NULL;

void gb(GtkGestureDrag* g,gdouble x,gdouble y,gpointer d)
{
	sscBlockShape* s = (sscBlockShape*)d;
	s->dragShape = ssc_block_shape_by_name(s->shape,s->text);

	gint wx,wy;

	gdk_window_get_origin(gtk_widget_get_window(s->widget),&(s->dx),&(s->dy));
	gdk_window_get_origin(gtk_widget_get_window(of),&(wx),&(wy));
	s->dx=s->dx-wx;
	s->dy=s->dy-wy;
	gtk_fixed_put(of,s->dragShape->widget,s->dx,s->dy);
	gtk_widget_show(s->dragShape->widget);

	gtk_widget_queue_draw(s->dragShape->widget);
}

void gu(GtkGestureDrag* g,gdouble x,gdouble y,gpointer d)
{

	sscBlockShape* s = (sscBlockShape*)d;
	gtk_fixed_move(of,s->dragShape->widget,(s->dx+(gint)x),(s->dy+(gint)y));
}

void ge(GtkGestureDrag* g,gdouble x,gdouble y,gpointer d)
{
	sscBlockShape* s = (sscBlockShape*)d;

	gint wx,wy;

	gdk_window_get_origin(gtk_widget_get_window(s->dragShape->widget),&(s->dx),&(s->dy));
	gdk_window_get_origin(gtk_widget_get_window(ca),&(wx),&(wy));

	sscBlockShape *sh = ssc_block_shape_by_name(s->shape,s->text);
	gtk_widget_show_all(sh->widget);

	print("CA:%p %p\n",ca,sh);
	print("CA:%d %d\n",s->dx - wx,s->dy - wy);

	gtk_fixed_put(ca,sh->widget,s->dx - wx,s->dy - wy);
	ssc_block_shape_destroy(s->dragShape,FALSE);
}

GtkWidget* ssc_block_list_makeList(ssc_cmdReg *cmds,int id)
{
	ssc_cmdReg cmd;
	int i = 0;
	int n = 0;
	cmd = *(cmds+i);

	GtkWidget* sw = gtk_scrolled_window_new(NULL,NULL);
	GtkWidget* bx = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
	gtk_container_set_border_width(GTK_CONTAINER(bx),5);

	textdomain("specs");
	while(cmd.spec != NULL)
	{
		if(cmd.cate == id)
		{
			GtkWidget* f;
			if (!strcmp("-",cmd.spec))//空格
			{
				f = gtk_fixed_new();
				gtk_widget_set_size_request(f,-1,10);

			}else if(!strcmp("--",cmd.spec))//分割线
			{
				f = gtk_fixed_new();
				GtkWidget* s = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
				gtk_container_add(GTK_CONTAINER(f),s);
				gtk_widget_set_size_request(f,-1,10);
			}else
			{
				f = gtk_fixed_new();
				sscBlockShape* s = ssc_block_shape_by_name(cmd.type,_(cmd.spec));
				GtkGestureDrag* ggd = gtk_gesture_drag_new(s->widget);

				g_signal_connect(ggd,"drag-begin",G_CALLBACK(gb),s);
				g_signal_connect(ggd,"drag-update",G_CALLBACK(gu),s);
				g_signal_connect(ggd,"drag-end",G_CALLBACK(ge),s);

				gtk_container_add(GTK_CONTAINER(f),s->widget);
				gtk_widget_set_size_request(f,-1,-1);
				n++;
			}
			gtk_container_add(GTK_CONTAINER(bx),f);
		}
		i++;
		cmd = *(cmds+i);
	}

	gtk_container_add(GTK_CONTAINER(sw),bx);

	print("Categorie ID %d : Blocks loaded: %d\n",id,n);
	return sw;
}

int ssc_block_list_init(GtkBuilder* b)
{
	int i = 1;
	GtkWidget* nb = gtk_builder_get_object(b,"ssc-notebook-blocks");
	of = ssc_widgets_get_compoments()->overlayFix;
	ov = ssc_widgets_get_compoments()->overlay;
	ca = ssc_widgets_get_compoments()->codeArea;
	ssc_cReg *regs,reg;
	ssc_cmdReg *cmds;
	cmds = ssc_specs_commands_get();
	regs = ssc_specs_categories_get();

	reg = *(regs+i);
	PangoFontDescription *font_description = pango_font_description_new();
	pango_font_description_set_family(font_description, NULL);//黑体
	pango_font_description_set_weight(font_description, PANGO_WEIGHT_NORMAL);
	pango_font_description_set_absolute_size(font_description, 10 * PANGO_SCALE);//设置字体大小

	while(reg.num != -1)
	{
		GtkWidget* label = gtk_label_new(reg.name);
		gtk_widget_modify_font(label,font_description);
		//gtk_label_set_angle(GTK_LABEL(label),90);
		gtk_notebook_append_page(nb,ssc_block_list_makeList(cmds,reg.num),label);
		i++;
		reg = *(regs+i);
	}

	pango_font_description_free(font_description);

	gtk_widget_set_size_request(GTK_WIDGET(nb),300,-1);

	print("Loaded %d categories\n",i);

	return 0;
}
