#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include<time.h>
//#pragma once
//
//#ifndef MODEL_H
//#define MODEL_H
//
//
//#endif


typedef struct Card
{
	//��ͷ��ĸ�Ǳ�������

	char aName[18];   // ���֤��
	char aPwd[8];     // ����

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

