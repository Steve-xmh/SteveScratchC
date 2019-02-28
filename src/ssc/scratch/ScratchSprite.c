#include "ScratchSprite.h"

sscScratchSprite* ssc_scratch_sprite_new(gchar* name)
{
    sscScratchSprite *ns;
    ns = (sscScratchSprite*)ssc_libs_g_malloc(sizeof(sscScratchSprite));

	if(!ns)
	{
		perror("[SSC][ERROR] Create ScratchSprite failed ");
		return NULL;
	}

    if (name)
	{
		ns->name = "Sprite1";
	}
	else
	{
		ns->name = name;
	}

    ns->driection = 90;
    ns->scratchX = 0;
    ns->scratchY = 0;
    ns->isDraggable = FALSE;
    ns->penIsDown = FALSE;
    ns->penWidth = 1;

    return ns;
}

void ssc_scratch_sprite_render(sscScratchSprite* s,cairo_t *C)
{

}


