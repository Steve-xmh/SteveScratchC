#include "Main.h"

int main(int argn, char* argv[])
{
    gtk_init(&argn,&argv);
    ssc_init();

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

// 在此处放入初始化函数
int ssc_init()
{
    info("Initaling SteveScratchC!\n");
    return 0;
}