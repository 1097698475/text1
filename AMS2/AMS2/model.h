#define _CRT_SECURE_NO_WARNINGS
#include<time.h>

#ifndef MODEL_H
#define MODEL_H


typedef struct Card
{
	//��ͷ��ĸ�Ǳ�������

	char aName[18];   // ����
	char aPwd[8];     // ������

	int nStatus;      // ��״̬   0δ�ϻ�  1�����ϻ�   2��ע��   3ʧЧ
	float fAmount;    // �ۼ�ʹ��
	int nUseCount;    // ʹ�ô���
	float fBalance;   // ���
	float fTotalUse;  //���۽��
	int nDel;         // ɾ�����   0δɾ��    1��ɾ��


	time_t tStart;    // ����ʱ��
	time_t tEnd;      // ��ֹʱ��
	time_t tLast;     // ���ʹ��ʱ��

}Card;

typedef struct CardNode
{
	Card data;               //���������
	struct CardNode* next;   //ָ����һ������ָ��

}CardNode, *lpCardNode;

#endif
