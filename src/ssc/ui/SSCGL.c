#include "SSCGL.h"

// "realize"
void ssc_ui_gl_init(GtkWidget *area)
{
	gtk_gl_area_make_current(GTK_GL_AREA(area));

	if (gtk_gl_area_get_error (GTK_GL_AREA(area)) != NULL)
	{
		error("There is something wrong on initialing OpenGL.\n");
		return;
	}
#ifdef DEBUG
	gchar *renderer = (gchar*)glGetString(GL_RENDERER);
	gchar *version = (gchar*)glGetString(GL_VERSION);
	printf(
		"OpenGL Log:\n"
		"Using renderer: %s\n"
		"Using OpenGL version: %s\n"
		,renderer,version);
#endif


}

gboolean ssc_ui_gl_draw(GtkWidget *area,GdkGLContext *context)
{
    // 开始 GL 操作
	glClearColor(1,1,1,0);
	glClear (GL_COLOR_BUFFER_BIT);

	return TRUE;
}
