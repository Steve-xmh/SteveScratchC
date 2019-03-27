#include "SSCGlade.h"

static GtkBuilder *builder;
static GError *lastError;

void ssc_glade_init()
{
    builder = NULL;
    lastError = NULL;
}

void ssc_glade_load_file(GString *str)
{

}

GError *ssc_glade_get_load_error()
{
    return lastError;
}
