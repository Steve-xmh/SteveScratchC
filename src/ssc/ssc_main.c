#include "ssc_main.h"

gboolean ssc_running = TRUE;

void ssc_main_quit()
{
	ssc_running = FALSE;
}

gboolean ssc_main_running()
{
	return ssc_running;
}

void ssc_main_run()
{
	ssc_running = TRUE;
	do{
		if(gtk_events_pending())
			gtk_main_iteration();
        ssc_lua_iteration();
	}while(ssc_main_running());
	//gtk_main_quit();
}
