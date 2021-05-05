#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"model.h"
#include"global.h"
#include"tool.h"

int saveCard(const Card* pCard, const char* pPath)
{
	FILE* fp = NULL;
	char startTime[20] = { 0 };
	char endTime[20] = { 0 };
	char lastTime[20] = { 0 };

	//打开文件

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
	//将数据写进文件
	fprintf(fp, "\n%s##%s##%s##%d##%s##%s##%.1f##%s##%d##%.1f##%d\n", pCard->aName, pCard->aPwd, pCard->aId, pCard->nStatus,
		startTime, endTime, pCard->fTotalUse, lastTime, pCard->nUseCount, pCard->fBalance, pCard->nDel);
	//关闭文件
	fclose(fp);
	return TRUE;
}
//解析函数
Card praseCard(char* pBuf)
{
	Card card;
	const char *delims = "##";
	char flag[11][20] = { 0 };
	int index = 0;
	char *buf = NULL;
	char *str = NULL;

	buf = pBuf;
	while ((str = strtok(buf, delims)) != NULL)
	{
		strcpy(flag[index], str);
		buf = NULL;
		index++;
	}
	strcpy(card.aName, flag[0]);
	strcpy(card.aPwd, flag[1]);
	strcpy(card.aId, flag[2]);
	card.nStatus = atoi(flag[3]);
	card.tStart = stringToTime(flag[4]);
	card.tEnd = stringToTime(flag[5]);
	card.fTotalUse = (float)atof(flag[6]);
	card.tLast = stringToTime(flag[7]);
	card.nUseCount = atoi(flag[8]);
	card.fBalance = (float)atof(flag[9]);
	card.nDel = atoi(flag[10]);

	return card;
}


int readCard(Card* pCard, const char* pPath)
{
	FILE* fp = NULL;
	int i = 0;
	char aBuf[CARDCHARNUM] = { 0 };
	//打开文件
	fp = fopen(pPath, "r");
	if (fp == NULL)
	{
		return FALSE;
	}
	//读取文件
	while (!feof(fp))
	{
		memset(aBuf, 0, CARDCHARNUM);
		if ((fgets(aBuf, CARDCHARNUM, fp)) != NULL)
		{
			if (strlen(aBuf) > 0)
			{
				pCard[i] = praseCard(aBuf);
				i++;
			}
		}
	}


	//关闭文件
	fclose(fp);
	return TRUE;
}






int getCardCount(const char* pPath)
{
	FILE* fp = NULL;
	int nCount = 0;
	char aBuf[CARDCHARNUM] = { 0 };
	//打开文件
	fp = fopen(pPath, "r");
	if (fp == NULL)
	{
		return FALSE;
	}
	//读取文件
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


	//关闭文件
	fclose(fp);
	return nCount;
}


int updateCard(const Card* pCard, const char* pPath, int nIndex)
{
	FILE* fp = NULL;
	int nLine = 0;
	char aBuf[CARDCHARNUM] = { 0 };
	long lPosition = 0;
	char startTime[TIMELENGTH] = { 0 };
	char endTime[TIMELENGTH] = { 0 };
	char lastTime[TIMELENGTH] = { 0 };

	fp = fopen(pPath, "rb+");
	if (fp == NULL)
	{
		return FALSE;
	}
	//遍历文件,找到该条记录，进行更新
	while (!feof(fp) && nLine < nIndex)
	{
		if (fgets(aBuf, CARDCHARNUM, fp) != NULL)
		{
			lPosition = ftell(fp);
			nLine++;
		}
	}

	fseek(fp, lPosition, 0);


	timeToString(pCard->tStart, startTime);
	timeToString(pCard->tEnd, endTime);
	timeToString(pCard->tLast, lastTime);
	//fwrite(&*pCard,lPosition,0,fp);
	fprintf(fp, "\n%s##%s##%s##%d##%s##%s##%.1f##%s##%d##%.1f##%d\n", pCard->aName, pCard->aPwd, pCard->aId, pCard->nStatus,
		startTime, endTime, pCard->fTotalUse, lastTime, pCard->nUseCount, pCard->fBalance, pCard->nDel);



	fclose(fp);
	return TRUE;
}
