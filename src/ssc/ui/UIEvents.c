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
	GtkFileChooserNative *file = gtk_file_chooser_native_new("请选择一个 Scratch 工程",GTK_WINDOW(ssc_ui_get_widget_main_window()),GTK_FILE_CHOOSER_ACTION_OPEN,"_Open","_Cancel");
	gtk_native_dialog_run(GTK_NATIVE_DIALOG(file));
	g_object_unref(file);
}
