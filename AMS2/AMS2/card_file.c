#define _CRT_SECURE_NO_WARNINGS
#include"model.h"
#include"global.h"
#include<stdio.h>
#include"tool.h"

int saveCard(const Card* pCard, const char* pPath)
{
	FILE* fp = NULL;
	char startTime[TIMELENGTH] = { 0 };   //开始时间
	char endTime[TIMELENGTH] = { 0 };     //截止时间
	char lastTime[TIMELENGTH] = { 0 };    //最后使用时间
	//打开文件
	if ((fp = fopen(pPath, "a")) == NULL)
	{
		fp = fopen(pPath, "w");
		if (fp == NULL)
		{
			return FALSE;
		}
	}

	//将时间转换为字符串
	timeToString(pCard->tStart, startTime);
	timeToString(pCard->tEnd, endTime);
	timeToString(pCard->tLast, lastTime);

	//将数据写进文件
	//格式为：卡号##密码##状态##开卡时间##截止时间##积累金额##最后使用时间##使用次数##当前余额##删除标识
	fprintf(fp, "%s##%s##%d##%s##%s##%.1f##%s##%d##%.1f##%d\n", pCard->aName, pCard->aPwd, pCard->nStatus,
		startTime, endTime, pCard->fTotalUse, lastTime, pCard->nUseCount, pCard->fBalance);

	//关闭文件
	fclose(fp);

	return TRUE;
}

