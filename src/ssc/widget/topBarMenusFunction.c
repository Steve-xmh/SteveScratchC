#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <glib/gi18n.h>
#include "../../main.h"
#include "../../config.h"
void ssc_topBar_clicked(GtkWidget* widget,gpointer data)
{
    if(!strcmp(data,"about"))
    {

    	gchar* donaters[] = SSC_DONATERS_LIST_ON_AFDIAN;

        //print("Showed About Dialog\n");
        /*
        ssc_libs_gtk_show_about_dialog(NULL,
                              "program-name",SSC_NAME,
                              "version",SSC_VERSION,
                              "logo-icon-name","SSC Icon",
                              "logo",gdk_pixbuf_new_from_file("icons/icon256.png",NULL),
                              "comments",_("一个由 C 语言编写而成的 Scratch 编辑器。\n"
                                           "本程序属于闭源工程！\n"
                                           "编译日期 " __DATE__ "\n"
                                           "作者 SteveXMH"),
							  "website","https://steve-xmh.github.io/SSCAPI",
							  "website-label","SSC Lua API 文档",
							  "copyright",SSC_COPYRIGHT,
                              NULL
                             );
		*/
		GtkAboutDialog* d = GTK_ABOUT_DIALOG(ssc_libs_gtk_about_dialog_new());
		ssc_libs_gtk_about_dialog_set_program_name(d,SSC_NAME);
		ssc_libs_gtk_about_dialog_set_version(d,SSC_VERSION);
		GError* err = NULL;
		GdkPixbuf* icon = gdk_pixbuf_new_from_file("icons/icon256.png",&err);
		if(err)
		{
			print("%d %s\n",err->code,err->message);
		}else{
			ssc_libs_gtk_about_dialog_set_logo(d,icon);
		}
		ssc_libs_gtk_about_dialog_set_comments(d,_("一个由 C 语言编写而成的 Scratch 编辑器。\n"));
		ssc_libs_gtk_about_dialog_set_website(d,"https://steve-xmh.github.io/SSCDoc/");
		ssc_libs_gtk_about_dialog_set_website_label(d,_("SSC 文档"));
		ssc_libs_gtk_about_dialog_set_copyright(d,SSC_COPYRIGHT);
		ssc_libs_gtk_about_dialog_add_credit_section(d,_("爱发电的赞助者们"),donaters);
		ssc_libs_gtk_dialog_run(GTK_DIALOG(d));
		ssc_libs_g_object_unref(icon);
		ssc_libs_gtk_widget_destroy(d);

    }
    else if(!strcmp(data,"quit"))
	{
		ssc_main_quit();
	}
    else
    {
        print("Clicked %s but no function is in.\n",data);
    }
};
