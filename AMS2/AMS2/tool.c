//#define _CRT_SECURE_NO_WARNINGS
//#include<time.h>
//
//
////��time_t����ת��Ϊ�ַ������ַ�����ʽΪ"�ꡪ�¡��� ʱ����" ��ʽ���ַ���
//void timeToString(time_t t, char* pBuf)
//{
//	struct tm *pTimeInfo;  //����һ��tm���͵Ľṹ��ָ��
//
//	pTimeInfo = localtime(&t);    //���tm�ṹ���ʱ��
//	strftime(pBuf, 20, "%Y-%m-%d %H:%M",pTimeInfo);    //��ʱ��ת��Ϊ"��-��-�� ʱ-��"��ʽ�ַ���
//}