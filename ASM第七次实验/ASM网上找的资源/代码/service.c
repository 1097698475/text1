#define _CRT_SECURE_NO_WARNINGS 


#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#include"model.h"
#include"card_service.h"
#include"global.h"
#include"card_file.h"
#include"billing_file.h"
#include"billing_service.h"


//上机
int doLogon(const char *pName,const char* pPwd,LogonInfo *pInfo)
{
	Card *pCard =NULL;
	int nIndex=0;								//返回找到的卡所在的位置（行数）
	Billing billing;							//计费信息结构体

	pCard=checkCard(pName,pPwd,&nIndex);		//查找得到匹配的卡信息

	if(pCard==NULL){
		printf("\n无该卡信息\n");
		return FALSE;
	}
	if(pCard->nStatus!=0){
		printf("\n该卡正在上机、已经注销或失效\n");
		return FALSE;
	}
	if(pCard->fBalance<=0){
		printf("\n余额不足\n");
		return FALSE;
	}

	//更新文件中的卡信息
	pCard->nStatus=1;
	pCard->tLast=time(NULL);
	pCard->nUseCount++;
	if(updateCard(pCard,CARDPATH,nIndex)==FALSE){
		return FALSE;
	}

	//将计费信息保存到计费信息结构体、计费信息文本文件
	strcpy(billing.aCardName,pName);
	billing.tStart=time(NULL);
	billing.tEnd=0;
	billing.nStatus=0;
	billing.fAmount=0;
	billing.nDel=0;
	if(saveBilling(&billing,BILLINGPATH)==TRUE){
		strcpy(pInfo->aCardName,pName);
		pInfo->fBalance=pCard->fBalance;
		pInfo->tLogon=billing.tStart;
		
	}
	return TRUE;

}



//下机
int doSettle(const char *pName,const char* pPwd,SettleInfo *pInfo)
{
	Card *pCard =NULL;
	Billing *pBilling=NULL;
	int nIndex=0;
	int nIndex1=0;
	float cost=0;
	int costTime=0;
	float costMoney=0;

	//查询卡 返回的nindex是卡在链表的位置
	pCard=checkCard(pName,pPwd,&nIndex);

	//为空 没有该卡信息
	if (pCard == NULL)
	{
		printf("无该卡信息\n");
		return FALSE;
	}
	
	//只有正在上机的可以下机
	if(pCard->nStatus!=1)
	{
		printf("该卡未上机、已注销或失效\n");
		return FALSE;
	}

	/*更新卡信息和账单信息*/
	pCard->nStatus=0;
	
	//获取计费信息 为空则下机失败
	pBilling=checkBilling(pName,&nIndex1);
	if (pBilling == NULL)
	{
		return FALSE;
	}

	//更新计费信息
	pBilling->nStatus=1;
	pBilling->tEnd=time(NULL);
	cost=(float)difftime(pBilling->tStart,pBilling->tStart);
	costTime=(int)(cost/60)+1;

	//计算消费金额
	if(costTime%UNIT==0){
		costMoney=(int)(costTime/UNIT)*CHARGE;
	}
	else
	{
		costMoney=(int)(costTime/UNIT+1)*CHARGE;
	}

	//判断卡余额<消费金额 不可下机
	if (pCard->fBalance < costMoney)
	{
		printf("余额不足\n");
		return FALSE;
	}
		pBilling->fAmount=costMoney;
		pCard->fBalance-=costMoney;
		pCard->fTotalUse+=costMoney;

				
	if(updateBilling(pBilling,BILLINGPATH,nIndex1)==TRUE&&(updateCard(pCard,CARDPATH,nIndex)==TRUE))
	{
		strcpy(pInfo->aCardName,pName);
		pInfo->fAmount=pBilling->fAmount;
		pInfo->fBalance=pCard->fBalance;
		pInfo->tStart=pBilling->tStart;
		pInfo->tEnd=pBilling->tEnd;
	}

	return TRUE;
}



