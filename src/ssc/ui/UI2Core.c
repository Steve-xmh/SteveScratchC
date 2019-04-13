#include "UI2Core.h"

gboolean ssc_ui2core_event(gpointer data)
{
	while(1)
	{
		GPtrArray *command = ssc_core_ui_get_command();
		if(command)
		{
			switch(*(int*)g_ptr_array_index(command,0))
			{
			case SSC_UI_SET_PROCESS:
				{
					gtk_stack_set_visible_child(GTK_STACK(ssc_ui_get_widget_main_stack()),ssc_ui_get_widget_loading_widget());
					double pos = *(double*)g_ptr_array_index(command,1);
					if(pos == -1.0)
					{
						gtk_progress_bar_pulse(GTK_PROGRESS_BAR(ssc_ui_get_widget_process_bar()));
					}else{
						gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(ssc_ui_get_widget_process_bar()),pos>1.0?1.0:pos<0.0?0.0:pos);
					}
					if(!g_ptr_array_index(command,2))
					{
						gtk_label_set_text(GTK_LABEL(ssc_ui_get_widget_process_bar_label()),g_strdup((gchar*)g_ptr_array_index(command,2)));
					}
				}
				break;
			case SSC_UI_HIDE_PROCESS:
				{
					gtk_stack_set_visible_child(GTK_STACK(ssc_ui_get_widget_main_stack()),ssc_ui_get_widget_overlay());
				}
				break;
			default:
				warn("Unknown UI command %d\n",*(int*)g_ptr_array_index(command,0));
			}
			g_ptr_array_free(command,TRUE);
		}else{
			break;
		}
	}
	return TRUE;
}

