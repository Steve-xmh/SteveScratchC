#ifndef HEADER_SSC_CORE_SSCCORE
#define HEADER_SSC_CORE_SSCCORE

#include "../../Libs.h"

#define SSC_CORE_COMMAND_OPEN_PROJECT 1

#define SSC_CORE_STATUS_STOPED 0
#define SSC_CORE_STATUS_NEEDSTOP 1
#define SSC_CORE_STATUS_RUNNING 2

typedef struct
{
	gint status;
	GThread *mainThread;
	GMutex mainThread_q_m;
	GAsyncQueue *mainThread_q;
}SSCCore;

void ssc_core_init(GError**);
void *ssc_core_main(gpointer);
gpointer *ssc_core_get_command(void);
void ssc_core_push_command(guint dataNum,...);

#endif // HEADER_SSC_CORE_SSCCORE
