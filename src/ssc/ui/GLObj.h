#ifndef HEADER_SSC_UI_GLOBJ
#define HEADER_SSC_UI_GLOBJ

#include "../../Libs.h"

typedef struct
{
	cairo_surface_t *imageSurface;	/**< cairo 图像句柄 */
    unsigned char *imageData;		/**< 渲染的图像数据 */
    int imageWidth;					/**< 图像宽度 */
    int imageHeight;				/**< 图像高度 */
    GMutex mutex;					/**< 互斥锁 */
}sscGLObj;

#endif // HEADER_SSC_UI_GLOBJ
