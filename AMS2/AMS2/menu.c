#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<string.h>

#include"model.h"          //导入数据定义头文件
#include"card_service.h"   //
#include"tool.h"
#include"global.h"


int getSize(const char *pInfo);
//void copy(const char aInput[], char aOutput[], int nSize);


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
	Card card;                  //卡信息
	char aName[32] = { '\0' };   //输入卡号
	char aPwd[20] = { '\0' };    //输入密码
	int nNameSize = 0;          
	int nPwdSize = 0;           
	struct tm* endTime;         //开办时间
	struct tm* startTime;       //截止时间

	printf("----------添加卡----------\n");

	//提示输入密码
	printf("请输入卡号(长度为1~18）：");
	scanf("%s", aName);  //不用加&  因为aName是数组，数组名表示地址

	//判断输入的卡号是否符合要求
	nNameSize = getSize(aName);
	if (nNameSize > 18)
	{
		printf("输入的卡号长度超过最大值！\n");
		return;
	}

	//将卡号保存到卡结构中
	strcpy(card.aName, aName);  //替换了copy函数

	//提示输入密码
	printf("请输入密码（长度为1~8）：");
	scanf("%s", aPwd);

	//判断输入的密码长度是否符合要求
	nPwdSize = getSize(aPwd);
	if (nPwdSize > 8)
	{
		printf("输入的密码长度超过最大值!\n");
		return;   //return 很重要！！！
	}

	//将输入的密码保存到卡结果体中
	strcpy(card.aPwd, aPwd);


	printf("请输入开卡金额（RMB)：");
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
	printf("开卡成功！\n\n");
	

	//输出卡信息
	printf("\n");
	printf("------------添加卡信息如下-----------\n");
	printf("卡号\t密码\t卡状态\t余额\n");
	printf("%s\t%s\t%d\t%.1f\n\n", card.aName, card.aPwd, card.nStatus, card.fBalance);
}

int getSize(const char *pInput)
{
	int nSize = 0;
	while (*(pInput + nSize) != '\0')
	{
		nSize++;
	}
	return nSize;
}
//void copy(const char aInput[], char aOutput[], int nSize)
//{
//	int i = 0;
//	for (i = 0; i < nSize; i++)
//	{
//		aOutput[i] = aInput[i];
//		if (aOutput[i] == 0)
//		{
//			break;
//		}
//	}
//}

void query()//对应2查询功能
{
	char aName[18] = { 0 };
	char aLastTime[20] = { 0 };
	Card* pCard = NULL;  //pCard指向上次添加的卡,访问时用->
	int nIndex = 0;
	int i = 0;

	//提示并接收输入的卡信息
	printf("请输入查询的卡号：");
	scanf("%s", aName);

	//查询卡
	pCard = queryCards(aName,&nIndex);

	//如果pCard为NULL,表示没有该卡信息
	if (pCard == NULL || nIndex == 0)
	{
		printf("没有该卡的信息！\n");
	}
	else
	{
		//输入表格的表头
		printf("卡号\t状态\t余额\t累计使用\t使用次数\t上次使用时间\n");
		for (i = 0; i < nIndex; i++)
		{
			//将时间转换为字符串
			timeToString(pCard[i].tLast, aLastTime);

			//显示
			printf("%s\t%d\t%.1f\t%.1f\t\t%d\t\t%s", pCard[i].aName, pCard[i].nStatus, pCard[i].fBalance,
				pCard[i].fTotalUse, pCard[i].nUseCount, aLastTime);
		}
	}
}

void exitApp()
{
	releaseCardList();
}