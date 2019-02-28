
#ifndef HEADER_CHINESEENCODE
#define HEADER_CHINESEENCODE


/** \brief ת���ַ������빩 GTK+ ʹ��
 *
 * \param ��ת�����ַ���
 * \return ת����ɹ� GTK+ ʹ�õ��ַ���
 *
 * ������Ϊ GB2312 �������ַ���ת��Ϊ UTF-8 �����Թ� GTK+ ʹ��
 *
 */

//gchar* chChar(gchar*);
#define chChar(str) ssc_libs_g_convert(str,-1,"UTF-8","GB2312",NULL,NULL,NULL)

#endif // HEADER_CHINESEENCODE
