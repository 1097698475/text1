#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<time.h>
#include"model.h"
#include"card_service.h"
#include<string.h>
#include"tool.h"
int getSize(char *pInfo);
void copy(const char Input[],char Output[],int size);
void outputMenu()
	{
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
		printf("请选择菜单编号:\n");
	}
void add()
{
	struct Card card;  //导入结构体
	char aName[32]={'0'};
	char aPwd[16]={'0'};
	int aNamesize=0;
	int aPwdsize=0;
	int a=1;
	printf("----------add----------\n");
	do{
		a=1;
		printf("请输入卡号（不超过18位）：\n");
		scanf("%s",aName);
		printf("请输入密码（不超过8位）：\n");
		scanf("%s",aPwd);
		aNamesize=getSize(aName);
		aPwdsize=getSize(aPwd);
		if(aNamesize>18 || aPwdsize>8)   //判断字符长度
		{
			printf("卡号或密码超过规定长度请重新输入\n");
			printf("\n");
			a=0;
		}
	}while(a==0);
	if(a=1)
	{
	copy(aName,card.aName,18);
	copy(aPwd,card.aPwd,8);
	printf("*卡片信息已保存完成*\n");
	}
	printf("请输入开卡金额：\n");
	scanf("%f",&card.fBalance);
	card.fTotalUse=card.fBalance;
	card.nDel=0;
	card.nUseCount=0;
	card.tStart=card.tLastUse=card.tEnd=time(NULL);
	card.nStatus=0;
	addCard(card);
	printf("*******information*******\n");
	printf("卡号\t密码\t状态\t余额\n");
	printf("%s\t%s\t%d\t%0.1f\r",card.aName,card.aPwd,card.nStatus,card.fBalance);//“\r是回车(CR) ,将当前位置移到本行开头,ASCII码值(十进制)为013。 区别: 1、是否换行 '\r' 回车,回到当前行的行首,而不会换到下一行,如果接着输出的话,本行以前的内容会被逐一覆盖
}


int getSize(const char *pInfo)
{
	int size=0;
	while(*(pInfo+size)!='\0')
	{
		size++;
	}
	return size;
}


void copy(const char Input[],char Output[],int size)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		Output[i]=Input[i];
		if(Output[i]=='\0')
		{
			break;
		}
	}
}


void query()
{
	char aName[18]={0};
	char aTime[20]={0};
	struct tm *startTime;//开卡时间
	struct tm *endTime;//截止时间
	Card *pCard=NULL;
	printf("请输入查询卡号：\n");
	scanf("%s",aName);
	pCard = queryCard(aName);
	timeToString(pCard->tLastUse,aTime);//将字符串转化为可视时间
	startTime=localtime(&pCard->tStart);//注意localtime参数要是指针类所以要变成地址
	endTime=localtime(&pCard->tEnd);
	endTime->tm_year=startTime->tm_year+1;//时限为一年
	pCard->tEnd=mktime(endTime);
	printf("**********查询到的卡信息如下**********\n");
	printf("卡号\t状态\t余额\t累计使用\t使用次数\t最后使用时间\t\t时限(年)\n");
	printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\t%d\n",pCard->aName,pCard->nStatus,pCard->fBalance,pCard->fTotalUse,pCard->nUseCount,aTime,1);
}