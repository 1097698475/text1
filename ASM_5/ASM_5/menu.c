#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"model.h"
#include"card_service.h"
#include"tool.h"
#include"card_file.h"
#include"de.h"
#include"billing_file.h"
#include"billing_service.h"
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
		printf("9.管理员选项\n");
		printf("0.退出\n");
		printf("请选择菜单编号:\n");
	}
	void add()
	{
		int k=0;
		struct Card card;  //导入结构体
		char aName[32]={'0'};
		char aPwd[16]={'0'};
		int aNamesize=0;
		int aPwdsize=0;
			struct tm* endTime;     // 截止时间
	struct tm* startTime;   // 开卡时间
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
		strcpy(card.aName, aName);
		strcpy(card.aPwd, aPwd);
		printf("*卡片信息已保存完成*\n");
		}
		printf("请输入开卡金额：\n");
		scanf("%f",&card.fBalance);
		card.fTotalUse=card.fBalance;
		card.nDel=0;
		card.nUseCount=0;
		card.tStart=card.tLastUse=card.tEnd=time(NULL);
		card.nStatus=0;
	startTime = localtime(&card.tStart);
	endTime = localtime(&card.tEnd);
	endTime->tm_year = startTime->tm_year + 1;
	card.tEnd = mktime(endTime);
		printf("*******information*******\n");
		printf("卡号\t密码\t状态\t余额\n");
		printf("%s\t%s\t%d\t%0.1f\r\n",card.aName,card.aPwd,card.nStatus,card.fBalance);//“\r是回车(CR) ,将当前位置移到本行开头,ASCII码值(十进制)为013。 区别: 1、是否换行 '\r' 回车,回到当前行的行首,而不会换到下一行,如果接着输出的话,本行以前的内容会被逐一覆盖
		printf("是否仅为测试此程序（是否添加进文件）（是（1），否（0））");
		scanf("%d",&k);
		if(k==1){
		if(FALSE == saveCard(&card, CARDPATH))
		printf("添加卡信息失败！\n");
		else
		printf("添加卡信息成功！\n");
		}
		else
		{
		if(FALSE == addCard(card))
		printf("不在文件中添加卡信息失败！\n");
		else
		printf("不在文件中添加卡信息成功！\n");
		}
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
		if(Output[i]=='\0'){
			break;
		}
	}
}



void query()
{
		char aName[18]={0};
		Card card;
		int pIndex=0;
	char aTime[20]={0};
	int j=0;
	int l=0;
	int k=0;
	struct tm *startTime;//开卡时间
	struct tm *endTime;//截止时间
	Card *pCard=NULL;
	Card acard[50]={0};
	FILE* fp = NULL;  // 文件结构体指针
	int i=0;
	printf("请选择模糊查询（0）or精准查询（1）or判断存在（2）：");
	scanf("%d",&i);
	if(i==2)
	{
 printf("请输入卡号(长度为1~18)：");
 scanf("%s",card.aName);
 if(TRUE == isExsit(card.aName, CARDPATH))
 {
 printf("卡信息文件%s中，有%s卡信息。\n",CARDPATH,card.aName);
 }
 else 
printf("卡信息文件%s中，无%s卡信息。\n",CARDPATH,card.aName);
	}
	if(i==1)
	{
	printf("请输入查询卡号：\n");
	scanf("%s",aName);
	pCard = queryCard(aName);
	if(pCard==NULL)
	{
		printf("无该卡信息请再次核对卡号！\n");
	}
	else{
		timeToString(pCard->tLastUse,aTime);//将字符串转化为可视时间
	startTime=localtime(&pCard->tStart);//注意localtime参数要是指针类所以要变成地址
	endTime=localtime(&pCard->tEnd);
	endTime->tm_year=startTime->tm_year+1;//时限为一年
	pCard->tEnd=mktime(endTime);
	printf("**********查询到的卡信息如下**********\n");
	printf("卡号\t状态\t余额\t累计使用\t使用次数\t最后使用时间\t\t时限(年)\n");
	printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\t%d\n",pCard->aName,pCard->nStatus,pCard->fBalance,pCard->fTotalUse,pCard->nUseCount,aTime,1);
	}
	}
	else if(i==0)
	{
		printf("请输入查询卡号：\n");
		scanf("%s",aName);
		pCard=queryCards(aName,&pIndex);
		if(pCard==NULL||pIndex==0)
	{
		printf("无该卡信息请再次核对卡号！\n");
	}
	else{
	printf("**********查询到的卡信息如下**********\n");
	printf("卡号\t状态\t余额\t累计使用\t使用次数\t最后使用时间\t\t时限(年)\n");
	for(l=0;l<pIndex;l++)
	{
	timeToString(pCard[l].tLastUse,aTime);//将字符串转化为可视时间
	printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\t%d\n",pCard[l].aName,pCard[l].nStatus,pCard[l].fBalance,pCard[l].fTotalUse,pCard[l].nUseCount,aTime,1);
	}
	}
	}
}
void master()
{
	Card temp;
	Card card;
	FILE* fp = NULL; 
	struct tm* endTime;     // 截止时间
	struct tm* startTime;   // 开卡时间
	int nIndex=0;
	int c=0; // 文件结构体指针
	printf("卡信息文件%s中，有%d条卡信息。\n",CARDPATH,getCardCount(CARDPATH));
  // 以只读的方式打开文件
  if((fp = fopen(CARDPATH, "rb")) == NULL)
  {
    return FALSE;
  }

  while(!feof(fp))
  {
    if(fread(&temp, sizeof(Card), 1, fp) !='\0')
    {
      ShowCard(temp);
    }
  }
  fclose(fp);
  printf("是否更新卡内容(1：更新，0：不更新)：\n");
  scanf("%d",&c);
  if(c==1)
  {
	 printf("更新文件%s中第几条记录：",CARDPATH);
	 scanf("%d", &nIndex);
	printf("请输入更新内容：\n");
	printf("请输入卡号(长度为1~18)：");
	scanf("%s", card.aName);
	printf("请输入密码(长度为1~8)：");
	scanf("%s", card.aPwd);
	 printf("请输入开卡金额(RMB)：");
	scanf("%f", &card.fBalance);
	 card.fTotalUse = card.fBalance;    // 添加卡时，累计金额等于开卡金额
	 card.nDel = 0;                     // 删除标识
	 card.nStatus = 0;                  // 卡状态
	 card.nUseCount = 0;                // 使用次数
	card.tStart = card.tEnd = card.tLastUse = time(NULL); 
 startTime = localtime(&card.tStart);
 endTime = localtime(&card.tEnd);
 endTime->tm_year = startTime->tm_year + 1;
 card.tEnd = mktime(endTime);
 updateCard(&card, CARDPATH, nIndex);
  }
  else if(c==0)
  {
	  printf("不执行更新操作\n");
  }
}

void logon()
{
	char aTime[20]={0};
	int n = 0;
	LogonInfo *pInfo=NULL;
	Card* pCard=NULL;
	int result=0;
	//接受用户输入的卡信息
	char aName[20]={0};
	char aPwd[8]={0};
	pInfo=(LogonInfo*)malloc(sizeof(LogonInfo));
	printf("----------logon----------\n");
	printf("请输入卡号：");
	scanf("%s",aName);
	printf("请输入密码：");
	scanf("%s",aPwd);
	printf("\n");
	result=check(aName,aPwd,pInfo);
	pCard=dologon(aName,aPwd);
	timeToString(pCard->tLastUse,aTime);
	switch(result)
	{
	case 0:printf("上机失败\n");break;
	case 1:
		{
			printf("**********上机信息如下**********\n");
			printf("卡号\t状态\t余额\t累计使用\t使用次数\t最后使用时间\t\t时限(年)\n");
			printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\t%d\n",pCard->aName,pCard->nStatus,pCard->fBalance,pCard->fTotalUse,pCard->nUseCount,aTime,1);
			break;
		}
	case 2:	printf("已经完成过上机操作\n");break;
	case 3:printf("余额不足\n");break;
	}
}

void settle()
{
	char aName[18]={0};
	char aPwd[8]={0};
	int nResult=-1;
	SettleInfo *pInfo=NULL;
	char aStartTime[20]={0};
	char aEndTime[20]={0};
	pInfo=(SettleInfo*)malloc(sizeof(SettleInfo));
	printf("----------settle----------\n");
	printf("请输入下机卡号：");
	scanf("%s",aName);
	printf("请输入下机卡密码：");
	scanf("%s",aPwd);
	nResult=doSettle(aName,aPwd,pInfo);
	printf("********下机信息如下********\n");
	switch(nResult)
	{
	case 0:
		{
			printf("下机失败\n");
			break;
		}
	case 1:
		{
			printf("下机成功\n");
			printf("卡号\t消费\t余额\t上机时间\t\t下机时间\n");
			timeToString(pInfo->tStart,aStartTime);
			timeToString(pInfo->tEnd,aEndTime);
			printf("%s\t%0.1f\t%0.1f\t%s\t%s\n",pInfo->aCardName,pInfo->fAmount,pInfo->fBalance,pInfo->tStart,pInfo->tEnd);
			break;
		}
	case 4:
		{
			printf("未上机\n");
			break;
		}
	case 5:
		{
			printf("余额不足\n");
			break;
		}
	}
}

void exitAPP()
{
	releasecardList();
	releaseBillingList();
}