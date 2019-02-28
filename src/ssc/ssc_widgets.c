#include "ssc_widgets.h"

//窗口显示
void show()
{

};

void ssc_widget_style_add(GtkContainer* c,GtkWidget* w,gpointer p)
{
	ssc_libs_gtk_style_context_add_provider(ssc_libs_gtk_widget_get_style_context(w),p,G_MAXUINT);
    if (GTK_IS_CONTAINER(w))
		ssc_libs_g_signal_connect(w,"add",G_CALLBACK(ssc_widget_style_add),p)
		ssc_libs_gtk_container_forall(GTK_CONTAINER(w),(GtkCallback)ssc_widget_style,p);
}

void ssc_widget_style(GtkWidget *w,GtkStyleProvider* p)
{
    ssc_libs_gtk_style_context_add_provider(ssc_libs_gtk_widget_get_style_context(w),p,G_MAXUINT);
    if (GTK_IS_CONTAINER(w))
		ssc_libs_g_signal_connect(w,"add",G_CALLBACK(ssc_widget_style_add),p)
		ssc_libs_gtk_container_forall(GTK_CONTAINER(w),(GtkCallback)ssc_widget_style,p);
}

GObject* ssc_get_window_component(GtkBuilder* b,gchar* n)
{
	GObject* o = ssc_libs_gtk_builder_get_object(b,n);
	if (!o)
	{
		GtkWidget* msg = ssc_libs_gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"\n读取窗口布局文件失败：\n无法找到窗口对象：%s\n请不要随意修改布局文件 SSCWindow.glade ！",n);
		ssc_libs_gtk_window_set_position(GTK_WINDOW(msg),GTK_WIN_POS_CENTER);
		ssc_libs_gtk_dialog_run(GTK_DIALOG(msg));
		ssc_libs_gtk_widget_destroy(msg);
		ssc_libs_gtk_main_quit();
	}
	print("Loaded widget: %s\n",n);
	return o;
}

//从设备结构中初始化信号
int ssc_widgets_init_events(struct sscCompoments* c)
{
	//-2 未成功-信号初始化
	GtkWidget* t;
	t = c->window;
	g_signal_connect(t,"destroy",G_CALLBACK(ssc_widget_event_window_destroy),NULL);
	ssc_libs_gtk_window_set_position(GTK_WINDOW(t),GTK_WIN_POS_CENTER);
	return 0;
}

sscCompoments* com = NULL;

sscCompoments* ssc_widgets_get_compoments()
{
	return com;
}

// 从布局文件初始化窗口
struct sscCompoments* ssc_widgets_init()
{
    struct sscCompoments *compoments = g_new(struct sscCompoments,1);
    com = compoments;
    compoments->isInited = -1;//未成功-布局初始化
	GtkBuilder* builder = ssc_libs_gtk_builder_new();
	GError* err = NULL;
	if (!ssc_libs_gtk_builder_add_from_file(builder,"SSCWindow.glade",&err))
	{
		GtkWidget* msg = ssc_libs_gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"\n读取窗口布局文件失败：\n%s\n请不要随意修改布局文件 SSCWindow.glade ！",err->message);
		ssc_libs_gtk_window_set_position(GTK_WINDOW(msg),GTK_WIN_POS_CENTER);
		ssc_libs_gtk_dialog_run(GTK_DIALOG(msg));
		ssc_libs_gtk_widget_destroy(msg);
		g_clear_error(&err);
		ssc_libs_gtk_main_quit();
		return compoments;
	}

	if(!(compoments->window		 = GTK_WIDGET(ssc_get_window_component(builder,"mainWindow")))) return compoments;		// 主窗口
	if(!(compoments->stage		 = GTK_WIDGET(ssc_get_window_component(builder,"ssc-stage")))) return compoments;		// 舞台
	if(!(compoments->luaConsole	 = GTK_WIDGET(ssc_get_window_component(builder,"ssc-console-tv")))) return compoments;	// 控制台
	if(!(compoments->commandBar	 = GTK_WIDGET(ssc_get_window_component(builder,"ssc-command-bar")))) return compoments;	// 指令栏
	if(!(compoments->overlay	 = GTK_WIDGET(ssc_get_window_component(builder,"ssc-overlay")))) return compoments;			// 覆盖框架
	if(!(compoments->spriteList	 = GTK_WIDGET(ssc_get_window_component(builder,"ssc-sprite-list")))) return compoments;	// 覆盖框架
	if(!(compoments->codeArea	 = GTK_WIDGET(ssc_get_window_component(builder,"ssc-code-area")))) return compoments;	// 代码区
	if(!(compoments->overlayFix  = GTK_WIDGET(ssc_libs_gtk_fixed_new()))) return compoments;										// 覆盖框架绝对坐标组件
	if(!(									  ssc_get_window_component(builder,"ssc-notebook"))) return compoments;		// 选择夹
	if(!(									  ssc_get_window_component(builder,"ssc-window-icon"))) return compoments;	// 图标
	if(!(									  ssc_get_window_component(builder,"ssc-header-bar"))) return compoments;	// 标题条

	ssc_libs_gtk_widget_show_all(compoments->window);

	// 窗口叠加层
	ssc_libs_gtk_overlay_add_overlay(GTK_OVERLAY(compoments->overlay),GTK_FIXED(compoments->overlayFix));
	ssc_libs_gtk_overlay_set_overlay_pass_through(GTK_OVERLAY(compoments->overlay),GTK_FIXED(compoments->overlayFix),TRUE);
	ssc_libs_gtk_overlay_reorder_overlay(GTK_OVERLAY(compoments->overlay),GTK_FIXED(compoments->overlayFix),-1);
	ssc_libs_gtk_widget_set_halign (GTK_FIXED(compoments->overlayFix), GTK_ALIGN_START);
	ssc_libs_gtk_widget_set_valign (GTK_FIXED(compoments->overlayFix), GTK_ALIGN_START);

	ssc_libs_gtk_header_bar_set_title(GTK_HEADER_BAR(ssc_get_window_component(builder,"ssc-header-bar")),SSC_FULLNAME);
	//ssc_libs_gtk_window_set_default_icon_from_file("icons/icon.ico",NULL);

	GList* icons = NULL;
	icons = g_list_prepend(icons,gdk_pixbuf_new_from_file("icons/icon16.png",NULL));
	icons = g_list_prepend(icons,gdk_pixbuf_new_from_file("icons/icon32.png",NULL));
	icons = g_list_prepend(icons,gdk_pixbuf_new_from_file("icons/icon48.png",NULL));
	icons = g_list_prepend(icons,gdk_pixbuf_new_from_file("icons/icon128.png",NULL));
	icons = g_list_prepend(icons,gdk_pixbuf_new_from_file("icons/icon256.png",NULL));

	ssc_libs_gtk_window_set_default_icon_list(icons);
	ssc_libs_gtk_widget_set_size_request(compoments->window,SSC_WINDOW_MINWIDTH,SSC_WINDOW_MINHEIGHT);
	ssc_libs_gtk_image_set_from_file(GTK_IMAGE(ssc_get_window_component(builder,"ssc-window-icon")),"icons/icon48.png");
	ssc_lua_setOutput(compoments->luaConsole);//设置 lua 输出
	g_signal_connect(compoments->commandBar,"activate",G_CALLBACK(ssc_commandBar_activate),NULL);
	ssc_stage_init(compoments->stage);// 初始化舞台
	ssc_topBarMenus_setup(builder);// 初始化顶部菜单栏
	print("P\n");
	if(compoments->isInited = ssc_block_list_init(builder)) return compoments;//初始化模块列表

    compoments->isInited = ssc_widgets_init_events(compoments);

    ssc_libs_gtk_notebook_set_current_page(GTK_NOTEBOOK(ssc_get_window_component(builder,"ssc-notebook")),0);

	// CSS
	GtkCssProvider* p = ssc_libs_gtk_css_provider_new();
	if (ssc_libs_gtk_css_provider_load_from_path(p,"SSCWindow.css",NULL))
	{
		ssc_widget_style(compoments->window,p);
		print("[CSS] Successfully loaded css style.\n");
	}else
	{
		print("[CSS] Style load failed.\n");
	}

	ssc_libs_gtk_widget_show_all(compoments->window);
    show();

    return compoments;

};

