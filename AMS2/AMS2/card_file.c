#define _CRT_SECURE_NO_WARNINGS
#include"model.h"
#include"global.h"
#include<stdio.h>
#include"tool.h"

int saveCard(const Card* pCard, const char* pPath)
{
	FILE* fp = NULL;
	char startTime[TIMELENGTH] = { 0 };   //��ʼʱ��
	char endTime[TIMELENGTH] = { 0 };     //��ֹʱ��
	char lastTime[TIMELENGTH] = { 0 };    //���ʹ��ʱ��
	//���ļ�
	if ((fp = fopen(pPath, "a")) == NULL)
	{
		fp = fopen(pPath, "w");
		if (fp == NULL)
		{
			return FALSE;
		}
	}

	//��ʱ��ת��Ϊ�ַ���
	timeToString(pCard->tStart, startTime);
	timeToString(pCard->tEnd, endTime);
	timeToString(pCard->tLast, lastTime);

	//������д���ļ�
	//��ʽΪ������##����##״̬##����ʱ��##��ֹʱ��##���۽��##���ʹ��ʱ��##ʹ�ô���##��ǰ���##ɾ����ʶ
	fprintf(fp, "%s##%s##%d##%s##%s##%.1f##%s##%d##%.1f##%d\n", pCard->aName, pCard->aPwd, pCard->nStatus,
		startTime, endTime, pCard->fTotalUse, lastTime, pCard->nUseCount, pCard->fBalance);

	//�ر��ļ�
	fclose(fp);

	return TRUE;
}

