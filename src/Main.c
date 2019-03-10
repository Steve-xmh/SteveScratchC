#include "Main.h"

int main(int argn, char* argv[])
{
    gtk_init(&argn,&argv);
    ssc_init();

    print("Press any button to exit...\n");
    getchar();
    return 0;
}

// 在此处放入初始化函数
int ssc_init()
{
    info("Initaling SteveScratchC!\n");
    SSCScratchStage* st = ssc_scratch_stage_new();
    g_object_unref(st);
    return 0;
}