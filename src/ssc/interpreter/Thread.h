#ifndef HEADER_SSC_THREAD
#define HEADER_SSC_THREAD

#include "../block/block.h"

typedef struct sscThread
{
	void* target;
	sscBlock* topBlock;
	void* tmpObj;
	int startDelayCount;

	sscBlock* block;
	int isLoop:1;
	int firstTime:1;
	int tmp;


}sscThread;	/**< 存储每个线程的状态结构 */

#endif // HEADER_SSC_THREAD
