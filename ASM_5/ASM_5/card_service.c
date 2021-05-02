#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<time.h>
#include"model.h"
#include<string.h>
#include"global.h"
#include"card_file.h"
#include"de.h"
#include"billing_service.h"
#include"billing_file.h"
Card aCard[50];
int nCount=0;
lpCardNode cardList=NULL;

void releasecardList()
{
	lpCardNode cur;
	if(cardList!=NULL)
	{
		while(cardList->next!=NULL)
		{
			cur=cardList->next;
			free(cur);
			cur=NULL;
		}
	}
}

int initcardList()
{
	lpCardNode head=NULL;
	head=(lpCardNode)malloc(sizeof(CardNode));
	if(head!=NULL){
		head->next=NULL;
		cardList=head;
		return TRUE;
	}
	return FALSE;
}

int addCard(Card card)
{
	lpCardNode node=NULL;
	lpCardNode cur=NULL;
	if(cardList==NULL)
	{
		initcardList();
	}
	cur=(lpCardNode)malloc(sizeof(CardNode));
	if(cur==NULL)
	{
		return FALSE;
	}
		cur->data=card;
		cur->next=NULL;      //遍历找到链表最后
		node=cardList;
	while(node->next!=NULL)
	{
		node=node->next;
	}
	node->next=cur;
	return TRUE;
}
Card* queryCard(const char *pName)
{
	lpCardNode cur=NULL;
	if(cardList!=NULL)
	{
		cur=cardList->next;
		while(cur!=NULL)
		{
			if(strcmp(cur->data.aName,pName)==0)
			{
				return &cur->data;
			}
			cur=cur->next;
		}
	}
	return NULL;
}
Card* queryCards(const char *pName,int *pIndex)
{
		lpCardNode cur=NULL;
		Card* pCard=(Card*)malloc(sizeof(Card));
		if(pCard==NULL)
		{
			return NULL;
		}
	if(cardList!=NULL)
	{
		cur=cardList->next;
		while(cur!=NULL)
		{
			if(strstr(cur->data.aName,pName)!=NULL)           //注意strstr这个函数
			{
				pCard[*pIndex]=cur->data;
				(*pIndex)++;          //注意是指针++而不是指针的值++，*p++是指下一个地址(*p)++是指将*p所指的数据的值加一
				pCard=(Card*)realloc(pCard,((*pIndex)+1)*sizeof(Card));
			}
			cur=cur->next;
		}
	}
	return pCard;
}

int check(const char *pName,const char *pPwd,LogonInfo *pLongInfo)
{
	int nIndex=0;
	Billing billing;
	//获取文件中卡信息判断是否能进行上机
	lpCardNode cardNode=NULL;
	cardNode=cardList->next;
	if(cardNode->data.nStatus!=0)  //如果已上机或者余额不足则不能上机
	{
		return WRONG;
	}
	if(cardNode->data.fBalance<=0)  //如果已上机或者余额不足则不能上机
	{
		return POOR;
	}
	if(strcmp(cardNode->data.aName,pName)==0 && strcmp(cardNode->data.aPwd,pPwd)==0)
	{
		if(FALSE!=updateCard(&cardNode->data,CARDPATH,nIndex))
		{
			strcpy(billing.aCardName,pName);
			if(TRUE==addBilling(billing))
			{
				strcpy(pLongInfo->aCardName,pName);
				pLongInfo->fBalance=cardNode->data.fBalance;
				pLongInfo->tLogon=billing.tStart;
				return TRUE;
			}
		}
	cardNode=cardNode->next;
	nIndex++;
	}
	return FALSE;
}

Card* dologon(const char *pName,const char *pPwd)
	{
	int nIndex=0;
	Billing billing;
	//获取文件中卡信息判断是否能进行上机
	lpCardNode cardNode=NULL;
	cardNode=cardList->next;
	if(cardNode->data.nStatus!=0)  //如果已上机或者余额不足则不能上机
	{
		return NULL;
	}
	if(cardNode->data.fBalance<=0)  //如果已上机或者余额不足则不能上机
	{
		return NULL;
	}
	if(strcmp(cardNode->data.aName,pName)==0 && strcmp(cardNode->data.aPwd,pPwd)==0)
	{
		cardNode->data.nStatus=1;
		cardNode->data.nUseCount++;
		cardNode->data.tLastUse=time(NULL);
		return &cardNode->data;
		}
	cardNode=cardNode->next;
	nIndex++;
	return NULL;
}
Card* dologonn(const char *pName,const char *pPwd)
	{
	int nIndex=0;
	Billing billing;
	//获取文件中卡信息判断是否能进行上机
	lpCardNode cardNode=NULL;
	cardNode=cardList->next;
	if(strcmp(cardNode->data.aName,pName)==0 && strcmp(cardNode->data.aPwd,pPwd)==0)
	{
		cardNode->data.tLastUse=time(NULL);
		return &cardNode->data;
		}
	cardNode=cardNode->next;
	nIndex++;
	return NULL;
}
double getAmount(time_t t)
{
	int nSec;
	int nMin;
	int nCount;
	double dbAmount;
	time_t tEnd=time(NULL);
	nSec=tEnd-t;
	nMin=nSec/60;
	if(nMin/UNIT==0)
	{
		nCount=nMin/UNIT;
	}
	else
	{
		nCount=nMin/UNIT+1;
	}
	dbAmount=nCount*CHARGE;
	return dbAmount;
}

int doSettle(const char *pName,const char *pPwd,SettleInfo *pInfo)
{
	Card *pCard=NULL;
	Billing *pBilling=NULL;
	int nIndex=0;
	int nPosition=0;
	double dbAmount=0.0;
	double fBalance=0.0;
	pCard=dologonn(pName,pPwd);
	if(pCard==NULL)
	{
		return FALSE;
	}
	if(pCard->nStatus!=1)
	{
		return UNUSE;
	}
	pBilling=queryBilling(pName,&nPosition);
	if(pBilling==NULL)
	{
		return FALSE;
	}
	dbAmount=getAmount(pBilling->tStart);
	fBalance=pCard->fBalance-dbAmount;
	if(fBalance<0)
	{
		return LACK;
	}
	strcpy(pInfo->aCardName,pName);
	pInfo->fAmount=dbAmount;
	pInfo->fBalance=fBalance;
	pInfo->tStart=pBilling->tStart;
	pInfo->tEnd=time(NULL);
	pCard->fBalance=fBalance;
	pCard->nStatus=0;
	pCard->tLastUse=time(NULL);
	updateCard(pCard,CARDPATH,nIndex);
	pBilling->fAmount=dbAmount;
	pBilling->nStatus=1;
	pBilling->tEnd=time(NULL);
	updateBilling(pBilling,BILLINGPATH,nPosition);
	return TRUE;
}





