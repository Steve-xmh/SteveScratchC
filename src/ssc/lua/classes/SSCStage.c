#include "SSCStage.h"

luaL_Reg ssc_class_stage_func[] =
{
	{"point",ssc_class_stage_paint},
	{"clear",ssc_class_stage_clear},
	{NULL,NULL}
};

int ssc_class_stage_paint(lua_State *L)
{
    int argn = lua_gettop(L);
	double x,y,r,g,b,a = 0;

	GdkRectangle re;

    if (argn == 2)
	{
		x = luaL_checknumber(L,1);
		y = luaL_checknumber(L,2);
		r = g = b = 0.0;
		a = 1.0;
	}else if(argn == 5)
	{
		x = luaL_checknumber(L,1);
		y = luaL_checknumber(L,2);
		r = luaL_checknumber(L,3);
		g = luaL_checknumber(L,4);
		b = luaL_checknumber(L,5);
		a = 1.0;
	}else if(argn == 6)
	{
		x = luaL_checknumber(L,1);
		y = luaL_checknumber(L,2);
		r = luaL_checknumber(L,3);
		g = luaL_checknumber(L,4);
		b = luaL_checknumber(L,5);
		a = luaL_checknumber(L,6);
	}else
	{
		lua_error(L);
		return 0;
	}
	//print("Draw in %dx%d with r%f\tg %f\tb %f\ta %f\n",re.x,re.y,r,g,b,a);

	sscCompoments* com = ssc_widgets_get_compoments();
	cairo_surface_t* sf = com->stageSketchPad;
	cairo_t* cr = ssc_libs_cairo_create(sf);
	ssc_libs_cairo_set_source_rgba(cr,r,g,b,a);
	ssc_libs_cairo_rectangle(cr,x,y,1,1);
	ssc_libs_cairo_fill(cr);
	ssc_libs_cairo_destroy(cr);
	if(ssc_libs_gtk_widget_get_window (com->stage))
	gdk_window_invalidate_rect (ssc_libs_gtk_widget_get_window (com->stage),
                              NULL,
                              FALSE);

	//ssc.stage.paint(50,50,0,1,0,0.5)
	return 0;
}

int ssc_class_stage_clear(lua_State *L)
{
	sscCompoments* com = ssc_widgets_get_compoments();
	cairo_surface_t* sf = com->stageSketchPad;
	cairo_t* cr = ssc_libs_cairo_create(sf);
	ssc_libs_cairo_set_operator(cr,CAIRO_OPERATOR_CLEAR);
	ssc_libs_cairo_paint (cr);
	ssc_libs_cairo_destroy(cr);
	if(ssc_libs_gtk_widget_get_window (com->stage))
	gdk_window_invalidate_rect (ssc_libs_gtk_widget_get_window (com->stage),
                              NULL,
                              FALSE);
	return 0;
}

int ssc_class_stage_setup(lua_State* L)
{
	//SCCT
	luaL_newlib(L,ssc_class_stage_func);
	lua_setfield(L,-2,SCCT);

	return TRUE;
}
