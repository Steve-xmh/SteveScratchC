#include "UIEvents.h"

gboolean ssc_ui_setup_events(GError **err)
{
	g_signal_connect(ssc_ui_get_widget_main_window(),"destroy",gtk_main_quit,NULL);

	// 菜单
	g_signal_connect(ssc_ui_get_widget_menu_about(),"activate",G_CALLBACK(ssc_ui_show_about),NULL);
	g_signal_connect(ssc_ui_get_widget_menu_open(),"activate",G_CALLBACK(ssc_ui_open_project),NULL);
	g_signal_connect(ssc_ui_get_widget_stage_fullscreen_button(),"clicked",G_CALLBACK(ssc_ui_change_fullscreen),NULL);

	// Lua
	g_signal_connect(ssc_ui_get_widget_command_bar(),"activate",G_CALLBACK(ssc_ui_do_string),NULL);

	// 接收 Core 指令
	g_timeout_add(10,ssc_ui2core_event,NULL);

	return TRUE;
}

gboolean ssc_ui_gl_event(gpointer area)
{
	gtk_widget_queue_draw((GtkWidget*)area);
	return TRUE;
}

void ssc_ui_do_string(GtkEntry *entry, gpointer data)
{
	ssc_lua_dostring(gtk_entry_get_text(entry));
}

void ssc_ui_change_fullscreen(GtkButton *button, gpointer data)
{
	static gboolean isFullscreen;
	static gboolean inited;
	static GtkWidget *win;
	static GtkWidget *root;
	static GtkWidget *stage;
	static GtkWidget *stageParent;
	isFullscreen = !isFullscreen;
	if(!inited)
	{
		win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_container_set_border_width(GTK_CONTAINER(win),5);
		stage = ssc_ui_get_widget_stage_part();
		stageParent = gtk_widget_get_parent(stage);
		root = gtk_widget_get_toplevel(stage);
		gtk_widget_set_realized(stage,TRUE);
		inited = TRUE;
	}
	g_object_ref((gpointer)stage);
	if(isFullscreen)
	{
		gtk_container_remove(GTK_CONTAINER(stageParent),stage);
		gtk_container_add(GTK_CONTAINER(win),stage);
		gtk_widget_show(win);
		gtk_widget_hide(root);
		gtk_window_fullscreen(GTK_WINDOW(win));
	}else
	{
		gtk_container_remove(GTK_CONTAINER(win),stage);
		gtk_container_add(GTK_CONTAINER(stageParent),stage);
		gtk_widget_show(root);
		gtk_widget_hide(win);
		gtk_window_fullscreen(GTK_WINDOW(win));
	}
	g_object_unref((gpointer)stage);
}

void ssc_ui_show_about(GtkMenuItem *item, gpointer data)
{
	GtkWidget *msg = gtk_about_dialog_new();
	const gchar *str[] = {"SteveXMH","Alex Cui","SinanGentoo",NULL};

	static GdkPixbuf *logo;
	if(!logo)
	{
		GError *err = NULL;
		logo = gdk_pixbuf_new_from_file("icons/icon256.png",&err);
		if(!logo)
		{
			error("Can't open logo image: %s\n",err->message);
		}
	}
	gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(msg),str);
	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(msg),"SteveScratchC");
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(msg),"A Scratch-like Editor made by C.");
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(msg),"https://github.com/Steve-xmh/SteveScratchC");
	gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(msg),"Github");
	gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(msg),logo);

	gtk_dialog_run(GTK_DIALOG(msg));
	gtk_widget_destroy(msg);
}

void ssc_ui_open_project(GtkMenuItem *item, gpointer data)
{
	GtkFileChooserNative *file = gtk_file_chooser_native_new("请选择一个 Scratch 工程",GTK_WINDOW(ssc_ui_get_widget_main_window()),GTK_FILE_CHOOSER_ACTION_OPEN,NULL,NULL);

	GtkFileFilter *filter = gtk_file_filter_new();
	GtkFileFilter *allFilter = gtk_file_filter_new();

	gtk_file_filter_set_name(filter,"Scratch 工程文件");
	gtk_file_filter_set_name(allFilter,"所有文件");

	gtk_file_filter_add_pattern(filter,"*.sb");
	gtk_file_filter_add_pattern(filter,"*.sb2");
	gtk_file_filter_add_pattern(filter,"*.sb3");
	gtk_file_filter_add_pattern(allFilter,"*.*");

	gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(file),filter);
	gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(file),allFilter);

	gint ret = gtk_native_dialog_run(GTK_NATIVE_DIALOG(file));

	if(ret == GTK_RESPONSE_ACCEPT)
	{
		gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file));
		SSC_CMD(cmd,SSC_CORE_COMMAND_OPEN_PROJECT);
		ssc_core_push_command(2,cmd,filename);
	}

	g_object_unref(file);
}
