#include "Main.h"

int main(int argn, char* argv[])
{
    gtk_init(&argn,&argv);
    ssc_init();
    return 0;
}

// 在此处放入初始化函数
int ssc_init()
{
    info("Initaling SteveScratchC!\n");
    return 0;
}