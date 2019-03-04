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
        gtk_show_about_dialog(NULL,
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
		GtkAboutDialog* d = GTK_ABOUT_DIALOG(gtk_about_dialog_new());
		gtk_about_dialog_set_program_name(d,SSC_NAME);
		gtk_about_dialog_set_version(d,SSC_VERSION);
		GError* err = NULL;
		GdkPixbuf* icon = gdk_pixbuf_new_from_file("icons/icon256.png",&err);
		if(err)
		{
			print("%d %s\n",err->code,err->message);
		}else{
			gtk_about_dialog_set_logo(d,icon);
		}
		gtk_about_dialog_set_comments(d,_("一个由 C 语言编写而成的 Scratch 编辑器。\n"));
		//gtk_about_dialog_set_comments(d,_("This program is free software: you can redistribute it and/or modify\n it under the terms of the GNU General Public License as published by\n the Free Software Foundation, either version 3 of the License, or\n (at your option) any later version.\n"));
		gtk_about_dialog_set_website(d,"https://steve-xmh.github.io/SSCDoc/");
		gtk_about_dialog_set_website_label(d,_("SSC 文档"));
		gtk_about_dialog_set_copyright(d,SSC_COPYRIGHT);
		gtk_about_dialog_add_credit_section(d,_("爱发电的赞助者们"),donaters);
		gtk_dialog_run(GTK_DIALOG(d));
		g_object_unref(icon);
		gtk_widget_destroy(d);

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
