#ifndef HEADER_SSC_BLOCK_BLOCK
#define HEADER_SSC_BLOCK_BLOCK

#include "blockBase.h"
#include "blockShape.h"

typedef struct sscBlock
{
	sscBlockBase* base;		/**< 本体结构 */
	sscBlockShape* shape;	/**< 模块外形结构 */
	GList* subShapes;		/**< 子部件列表 */
}sscBlock;

/** \brief 创建一个新的模块结构
 *
 * \param 格式化名称
 * \param 模块类型
 * \param 颜色
 * \param 函数指针
 * \param 默认参数
 * \return 一个 sscBlock 结构指针
 *
 */

sscBlock* ssc_block_new(gchar* spec,gint type,gchar* color,GCallback* op,GArray* defaultArgs);

#endif // HEADER_SSC_BLOCK_BLOCK
