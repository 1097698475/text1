#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"model.h"
#include"global.h"
#include"tool.h"


//���濨��Ϣ���ļ�
int saveCard(const Card* pCard, const char* pPath)
{
	FILE* fp = NULL;
	char startTime[20] = { 0 };
	char endTime[20] = { 0 };
	char lastTime[20] = { 0 };

	//���ļ�

	if ((fp = fopen(pPath, "a")) == NULL)
	{
		fp = fopen(pPath, "w");
		if (fp == NULL)
		{
			return FALSE;
		}

	}
	timeToString(pCard->tStart, startTime);
	timeToString(pCard->tEnd, endTime);
	timeToString(pCard->tLast, lastTime);
	//������д���ļ�
	fprintf(fp, "\n%s##%s##%d##%s##%s##%.1f##%s##%d##%.1f##%d\n", pCard->aName, pCard->aPwd, pCard->nStatus,
		startTime, endTime, pCard->fTotalUse, lastTime, pCard->nUseCount, pCard->fBalance, pCard->nDel);
	//�ر��ļ�
	fclose(fp);
	return TRUE;
}



//��������
Card praseCard(char* pBuf)
{
	Card card;
	const char *delims = "##";			//�ָ���
	char flag[10][20] = { 0 };			//��Ž��������Ϣ һ��������Ӧһ��Ԫ��
	int index = 0;
	char *buf = NULL;
	char *str = NULL;

	buf = pBuf;			//��һ�ε��ú���strtokʱ��bufΪ�����ַ���
	while ((str = strtok(buf, delims)) != NULL)
	{
		strcpy(flag[index], str);	//��һ���ַ����ֽ�Ϊһ���ַ���
		buf = NULL;		//������ú���ʱ����һ�β���ΪNULL
		index++;
	}
	strcpy(card.aName, flag[0]);				//����-�ַ�������
	strcpy(card.aPwd, flag[1]);				//������
	card.nStatus = atoi(flag[2]);			//��״̬-�ַ���ת��Ϊ����
	card.tStart = stringToTime(flag[3]);	//����ʱ��-ʱ������ת��
	card.tEnd = stringToTime(flag[4]);		//��ֹʱ��
	card.fTotalUse = (float)atof(flag[5]);	//�ۼƽ��-ǿ����������ת�����ַ���ת��Ϊ����
	card.tLast = stringToTime(flag[6]);		//�ϴ�ʹ��ʱ��
	card.nUseCount = atoi(flag[7]);			//ʹ�ô���
	card.fBalance = (float)atof(flag[8]);	//���
	card.nDel = atoi(flag[9]);				//ɾ����ʶ

	return card;		//���ؿ���Ϣ�ṹ��-�Ѿ����ļ��е���Ϣ����������
}


//��ȡ�ļ�
int readCard(Card* pCard, const char* pPath)
{
	FILE* fp = NULL;
	int i = 0;
	char aBuf[CARDCHARNUM] = { 0 };				//��Ŷ�ȡ�����ļ���Ϣ��һ��)
	//���ļ�
	fp = fopen(pPath, "r");
	if (fp == NULL)
	{
		return FALSE;
	}
	//��ȡ�ļ�
	while (!feof(fp))
	{
		memset(aBuf, 0, CARDCHARNUM);				//��ʼ����������ڴ�
		if ((fgets(aBuf, CARDCHARNUM, fp)) != NULL)
		{
			if (strlen(aBuf) > 0)				//��ȡ����һ���ļ���Ϣ��Ϊ��-��ʾû���ļ�β
			{
				pCard[i] = praseCard(aBuf);		//�����ļ��е���Ϣ���浽����Ϣ�ṹ��
				i++;
			}
		}
	}


	//�ر��ļ�
	fclose(fp);
	return TRUE;
}





//��ȡ����Ϣ������
int getCardCount(const char* pPath)
{
	FILE* fp = NULL;
	int nCount = 0;
	char aBuf[CARDCHARNUM] = { 0 };
	//���ļ�
	fp = fopen(pPath, "r");
	if (fp == NULL)
	{
		return FALSE;
	}
	//��ȡ�ļ�
	while (!feof(fp))
	{
		memset(aBuf, 0, CARDCHARNUM);
		if ((fgets(aBuf, CARDCHARNUM, fp)) != NULL)
		{
			if (strlen(aBuf) > 0)
			{
				nCount++;
			}
		}
	}


	//�ر��ļ�
	fclose(fp);
	return nCount;
}



//�����ļ��еĿ���Ϣ
int updateCard(const Card* pCard, const char* pPath, int nIndex)
{
	FILE* fp = NULL;					//ָ���ļ���ָ��
	int nLine = 0;						//����������
	char aBuf[CARDCHARNUM] = { 0 };		//�����ȡ������һ����Ϣ
	long lPosition = 0;					//��λ
	char startTime[TIMELENGTH] = { 0 };	//����ת������ַ�����ʽʱ��
	char endTime[TIMELENGTH] = { 0 };
	char lastTime[TIMELENGTH] = { 0 };

	fp = fopen(pPath, "rb+");			//��ֻ���ķ�ʽ���ļ�
	if (fp == NULL)
	{
		return FALSE;
	}
	//�����ļ�,�ҵ�������¼�����и���
	while (!feof(fp) && nLine < nIndex)
	{
		if (fgets(aBuf, CARDCHARNUM, fp) != NULL)
		{
			lPosition = ftell(fp);
			nLine++;
		}
	}

	fseek(fp, lPosition, 0);				//��λ����Ϣ

	timeToString(pCard->tStart, startTime);
	timeToString(pCard->tEnd, endTime);
	timeToString(pCard->tLast, lastTime);

	//д���ļ�-���¿���Ϣ
	fprintf(fp, "\n%s##%s##%d##%s##%s##%.1f##%s##%d##%.1f##%d\n", pCard->aName, pCard->aPwd, pCard->nStatus,
		startTime, endTime, pCard->fTotalUse, lastTime, pCard->nUseCount, pCard->fBalance, pCard->nDel);

	fclose(fp);							//�ر��ļ�
	return TRUE;
}
