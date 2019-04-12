#include "UIEvents.h"

gboolean ssc_ui_setup_events(GError **err)
{
	g_signal_connect(ssc_ui_get_widget_main_window(),"destroy",gtk_main_quit,NULL);

	// 菜单
	g_signal_connect(ssc_ui_get_widget_menu_about(),"activate",G_CALLBACK(ssc_ui_show_about),NULL);
	g_signal_connect(ssc_ui_get_widget_menu_open(),"activate",G_CALLBACK(ssc_ui_open_project),NULL);
	return TRUE;
}

void ssc_ui_show_about(GtkMenuItem *item, gpointer data)
{
	GtkWidget *msg = gtk_about_dialog_new();
	const gchar *str[] = {"SteveXMH","Alex Cui","SinanGentoo","Sparrow",NULL};

	gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(msg),str);
	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(msg),"SteveScratchC");
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(msg),"A Scratch-like Editor made by C.");
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(msg),"https://github.com/Steve-xmh/SteveScratchC");
	gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(msg),"Github");

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
		SSC_CORE_CMD(cmd,SSC_CORE_COMMAND_OPEN_PROJECT);
		ssc_core_push_command(2,cmd,filename);
	}

	g_object_unref(file);
}
