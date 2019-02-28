#ifndef HEADER_SSC_BLOCK_BLOCKBASE
#define HEADER_SSC_BLOCK_BLOCKBASE

typedef struct sscBlockBase
{
    gchar* cmdName; /**< 本模块指令名称 */
    gchar* shownName; /**< 显示给用户的名称 */
    gboolean isRequesting:1; /**< 是否正在请求返回，用于暂停模块 */
    gboolean isRequester:1; /**< 是否属于返回值模块 */
    struct sscBlockBase* nextBlock; /**< 下一个模块 */
    struct sscBlockBase* subNextBlock1; /**< 模块子架下一个模块 1 */
    struct sscBlockBase* subNextBlock2; /**< 模块子架下一个模块 2 */
}sscBlockBase;

sscBlockBase* ssc_block_base_new(void);

#endif // HEADER_SSC_BLOCK_BLOCKBASE
