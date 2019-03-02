#include "blockBase.h"

sscBlockBase* ssc_block_base_new()
{
	sscBlockBase* bb = g_malloc(sizeof(sscBlockBase));
	bb->cmdName = NULL;
	bb->isRequester = FALSE;
	bb->isRequesting = FALSE;
	bb->nextBlock = NULL;
	bb->shownName = NULL;
	bb->subNextBlock1 = NULL;
	bb->subNextBlock2 = NULL;
	return bb;
}
