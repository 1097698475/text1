#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include"model.h"          //导入数据定义头文件
#include"card_service.h"   //

int getSize(const char *pInfo);
void outputMenu()
{
	//菜单
	printf("----------菜单----------\n");
	printf("1.添加卡\n");
	printf("2.查询卡\n");
	printf("3.上机\n");
	printf("4.下机\n");
	printf("5.充值\n");
	printf("6.退费\n");
	printf("7.查询统计\n");
	printf("8.注销卡\n");
	printf("0.退出\n");
	printf("请输入菜单项编号(0-8) :  ");  //提示输入编号

}

void add()
{
	Card card;
	char aName[32] = { '\0' };
	char aPwd[20] = { '\0' };
	int nNameSize = 0;
	int nPwdSize = 0;
	printf("----------添加卡----------\n");
	printf("请输入卡号：");
	scanf("%s", card.aName);  //不用加&  因为aName是数组，数组名表示地址
	printf("请输入密码：");
	scanf("%s", card.aPwd);

	//判断卡号或密码长度
	nNameSize = getSize(aName);
	nPwdSize = getSize(aPwd);
	if (nNameSize > 18 || nPwdSize > 8)
	{
		printf("卡号或密码超过规定长度\n");
	}


	printf("请输入开卡金额：");
	//printf("553");
	scanf("%f", &card.fBalance);
	printf("\n");
	//printf("333");
	card.fTotalUse = card.fBalance;
	card.nUseCount = 0;
	card.nStatus = 0;
	card.nDel = 0;
	card.tStart = card.tEnd = card.tLast = time(NULL);  //等于当前时间

	//添加卡信息
	addCard(card);

	//输出卡信息
	printf("卡号\t密码\t卡状态\t余额\n");
	printf("%s\t%s\t%d\t%.1f\n",card.aName,card.aPwd,card.nStatus,card.fBalance);
}

int getSize(const char *pInfo)
{
	int nSize = 0;
	while (*(pInfo + nSize) != '\0')
	{
		nSize++;
	}
	return nSize;
}

void quary()//对应2查询功能
{
	char aName[18] = { 0 };
	Card* pCard = NULL;  //pCard指向上次添加的卡,访问时用->
	printf("请输入查询的卡号：");
	scanf("%s", aName);
	pCard = queryCard(aName);

	//显示
	printf("查询到的卡信息如下");
	printf("卡号\t状态\t余额\t累计使用\t使用次数\t上次使用时间\n");
	printf("%s\t%d\t%.1f\t%.1f\t%d\t%d\n",pCard->aName,pCard->nStatus,pCard->fBalance,pCard->fTotalUse,pCard->nUseCount,pCard->tLast);
}