#include "SSCProject.h"

void ssc_core_load_project(gchar *fileAdd)
{
	info("[Core]Opening project: %s\n",g_locale_from_utf8(fileAdd,-1,NULL,NULL,NULL));
	{
		SSC_CMD(cmd,SSC_UI_SET_PROCESS);
		SSC_CMD_D(p,-1.0);
		ssc_core_ui_push_command(3,cmd,p,g_strdup("Loading Project..."));
	}
    unzFile file = unzOpen(g_locale_from_utf8(fileAdd,-1,NULL,NULL,NULL));

    if(!file)
	{
		error("[Core]Can't open project! Cannot be opened or doesn't exist.\n");
		return;
	}

    unz_file_info fileInfo;
	gchar str[256];

    if(unzGoToFirstFile(file)==UNZ_OK)
    {
        do
        {
			gchar *processLabel[] = {"Find file: ",NULL,NULL};
			unzGetCurrentFileInfo(file,&fileInfo,str,sizeof(str),NULL,0,NULL,0);
			processLabel[1] = str;
			info("[Core]Find file in project: %s\n",str);
			SSC_CMD(cmd,SSC_UI_SET_PROCESS);
			SSC_CMD_D(p,-1.0);
			ssc_core_ui_push_command(3,cmd,p,g_strdupv(processLabel));
        }
        while(unzGoToNextFile(file)!=UNZ_END_OF_LIST_OF_FILE);
    }

	SSC_CMD(cmd,SSC_UI_HIDE_PROCESS);
	ssc_core_ui_push_command(1,cmd);

    unzClose(file);
}
