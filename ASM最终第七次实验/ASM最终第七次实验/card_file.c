#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"model.h"
#include"global.h"
#include"tool.h"


//保存卡信息到文件
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
	fprintf(fp, "\n%s##%s##%d##%s##%s##%.1f##%s##%d##%.1f##%d\n", pCard->aName, pCard->aPwd, pCard->nStatus,
		startTime, endTime, pCard->fTotalUse, lastTime, pCard->nUseCount, pCard->fBalance, pCard->nDel);
	//关闭文件
	fclose(fp);
	return TRUE;
}



//解析函数
Card praseCard(char* pBuf)
{
	Card card;
	const char *delims = "##";			//分隔符
	char flag[10][20] = { 0 };			//存放解析后的信息 一个变量对应一个元素
	int index = 0;
	char *buf = NULL;
	char *str = NULL;

	buf = pBuf;			//第一次调用函数strtok时，buf为解析字符串
	while ((str = strtok(buf, delims)) != NULL)
	{
		strcpy(flag[index], str);	//将一个字符串分解为一组字符串
		buf = NULL;		//后面调用函数时，第一次参数为NULL
		index++;
	}
	strcpy(card.aName, flag[0]);				//卡号-字符串复制
	strcpy(card.aPwd, flag[1]);				//卡密码
	card.nStatus = atoi(flag[2]);			//卡状态-字符串转换为数字
	card.tStart = stringToTime(flag[3]);	//开卡时间-时间类型转换
	card.tEnd = stringToTime(flag[4]);		//截止时间
	card.fTotalUse = (float)atof(flag[5]);	//累计金额-强制数据类型转换、字符串转换为数字
	card.tLast = stringToTime(flag[6]);		//上次使用时间
	card.nUseCount = atoi(flag[7]);			//使用次数
	card.fBalance = (float)atof(flag[8]);	//余额
	card.nDel = atoi(flag[9]);				//删除标识

	return card;		//返回卡信息结构体-已经将文件中的信息、解析保存
}


//读取文件
int readCard(Card* pCard, const char* pPath)
{
	FILE* fp = NULL;
	int i = 0;
	char aBuf[CARDCHARNUM] = { 0 };				//存放读取到的文件信息（一行)
	//打开文件
	fp = fopen(pPath, "r");
	if (fp == NULL)
	{
		return FALSE;
	}
	//读取文件
	while (!feof(fp))
	{
		memset(aBuf, 0, CARDCHARNUM);				//初始化新申请的内存
		if ((fgets(aBuf, CARDCHARNUM, fp)) != NULL)
		{
			if (strlen(aBuf) > 0)				//读取的这一行文件信息不为空-表示没到文件尾
			{
				pCard[i] = praseCard(aBuf);		//解析文件中的信息保存到卡信息结构体
				i++;
			}
		}
	}


	//关闭文件
	fclose(fp);
	return TRUE;
}





//获取卡信息的数量
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



//更新文件中的卡信息
int updateCard(const Card* pCard, const char* pPath, int nIndex)
{
	FILE* fp = NULL;					//指向文件的指针
	int nLine = 0;						//读到的行数
	char aBuf[CARDCHARNUM] = { 0 };		//保存读取到的那一行信息
	long lPosition = 0;					//定位
	char startTime[TIMELENGTH] = { 0 };	//保存转换后的字符串格式时间
	char endTime[TIMELENGTH] = { 0 };
	char lastTime[TIMELENGTH] = { 0 };

	fp = fopen(pPath, "rb+");			//用只读的方式打开文件
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

	fseek(fp, lPosition, 0);				//定位卡信息

	timeToString(pCard->tStart, startTime);
	timeToString(pCard->tEnd, endTime);
	timeToString(pCard->tLast, lastTime);

	//写入文件-更新卡信息
	fprintf(fp, "\n%s##%s##%d##%s##%s##%.1f##%s##%d##%.1f##%d\n", pCard->aName, pCard->aPwd, pCard->nStatus,
		startTime, endTime, pCard->fTotalUse, lastTime, pCard->nUseCount, pCard->fBalance, pCard->nDel);

	fclose(fp);							//关闭文件
	return TRUE;
}
