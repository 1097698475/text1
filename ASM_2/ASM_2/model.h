#define _CRT_SECURE_NO_WARNINGS 

#ifndef MODEL_H
#define MODEL_H
#include<time.h>
typedef struct Card
{
	char aName[18];  //����
	char aPwd[8];  //����

	int nStatus;   //��״̬(0-δ�ϻ���1-���ϻ���2-��ע����3-ʧЧ)
	float fTotalUse;  //�ۼ�ʹ��
	int nUseCount;    //ʹ�ô���
	float fBalance;    //���
	int nDel;          //ɾ�����



	time_t tStart;  //����ʱ��
	time_t tEnd;  //��ֹʱ��
	time_t tLastUse;  //���ʹ��ʱ��
}Card;
#endif