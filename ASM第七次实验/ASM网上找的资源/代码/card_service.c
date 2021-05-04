#define _CRT_SECURE_NO_WARNINGS 


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"global.h"
#include"card_file.h"
#include"model.h"
#include"menu.h"


int getCard();

//全局变量
Card ncard[50];
int i;
lpCardNode cardList;
lpCardNode head;
lpCardNode p,q;



/* 初始化链表*/
int initCardList()
{
	head=(lpCardNode)malloc(sizeof(CardNode));
	head->next=NULL;
	cardList=head;
	return TRUE;
}



/*释放结点*/
void releaseCardList()
{    p=cardList;

	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
}



/*添加卡*/
int addCard(Card card)
{	
	return saveCard(&card,CARDPATH);
}



/*精确查询卡*/
Card *queryCard(const char* pName)
{
	lpCardNode cardNode = NULL;
	int nIndex = 0;

	if (getCard() == FALSE)
	{
		return FALSE;
	}

	cardNode = cardList->next;

	while (cardNode != NULL)
	{
		if (strcmp(cardNode->cardData.aName, pName) == 0 )
		{
			return &cardNode->cardData;
		}
		cardNode = cardNode->next;
	}

	return NULL;
}



/*模糊查询*/
Card* queryCards(const char name[], int* pIndex)
{

	Card* pCard = NULL;
	p = head;

	//从文件中获取卡信息
	if (getCard() == FALSE)
	{
		return NULL;
	}

	while (p != NULL)
	{
		if (strstr(p->cardData.aName, name) != NULL)
		{
			(*pIndex)++;
			pCard = (Card*)realloc(pCard, (*pIndex) * (sizeof(Card)));
			pCard[(*pIndex - 1)] = p->cardData;
		}
		p = p->next;
	}

	return pCard;
}


//将文件中的卡信息保存在链表里面
int getCard()
{
	Card* pCard = NULL;
	int i = 0;
	int nCount = 0;
	p = NULL;
	q = NULL;

	if(cardList != NULL){
		releaseCardList();						//清空链表，保证链表只有要导入的文件信息
	}
	initCardList();
	
	nCount = getCardCount(CARDPATH);			//获取卡信息数量

	pCard = (Card*)malloc(sizeof(Card)* nCount);//动态分配内存

	if(pCard == NULL)							//卡信息数量为0或分配内存失败 返回FALSE
	{
		return FALSE;
	}
	if(readCard(pCard,CARDPATH) == FALSE)		//读取文件	
	{	
		free(pCard);
		pCard = NULL;
		return FALSE;
	}
	for(i = 0,p = cardList;i < nCount;i++)		//保存卡信息
	{
		q = (lpCardNode)malloc(sizeof(CardNode));
		if(q == NULL)
		{
			free(pCard);
			return FALSE;
		}
		memset(q, 0, sizeof(CardNode));
		q->cardData = pCard[i];
		q->next = NULL;

		p->next = q;
		p = q;
	}
/*	free(pCard);   pCard =	NULL;*/
	return TRUE;
}





/*根据卡号，密码查询，并返回在链表中的位置*/
Card *checkCard(const char *pName,const char* pPwd,int *pIndex)
{
	lpCardNode cardNode=NULL;
	int nIndex=0;
		
	if(getCard()==FALSE)
	{
		return NULL;
	}

	cardNode=cardList->next;

	while(cardNode!=NULL)
	{
		if(strcmp(cardNode->cardData.aName,pName)==0&&(strcmp(cardNode->cardData.aPwd,pPwd)==0))
		{
			*pIndex=nIndex;
			return &cardNode->cardData; 
		}
		cardNode=cardNode->next;
		nIndex++;
	}

	return NULL;
}



//充值
int Recharge(const char* pName,const char* pPwd)
{
	lpCardNode cardNode = NULL;
	float addmon = 0;
	int nIndex = 0;
	int m = 0;		//充值优惠
	Money sMoney;//

	//获取文件中的卡信息
	if(FALSE == getCard())
	{
		return FALSE; 
	}

	cardNode = cardList->next;
	//遍历链表，判断能否进行充值
	while(cardNode != NULL)
	{
		if(strcmp(cardNode->cardData.aName,pName) == 0 && strcmp(cardNode->cardData.aPwd,pPwd) == 0&&(cardNode->cardData.nStatus !=2))
		{
			printf("请输入充值的金额：");
			scanf("%f",&addmon);

			//开业优惠
			m = addmon / 100;
			addmon += m * 20;

			//更新结构体的卡余额
			cardNode->cardData.fBalance += addmon;

			//更新文件的卡信息
			if(updateCard(&cardNode->cardData,CARDPATH,nIndex) == FALSE)
			{
				return FALSE;
			}           

			//组装充值信息
			strcpy(sMoney.aCardName, cardNode->cardData.aName);
			sMoney.tTime = time(NULL);
			sMoney.nStatus = 0;
			sMoney.fMoney = cardNode->cardData.fBalance;
			sMoney.nDel = 0;

			//将充值记录保存到文件
			saveMoney(&sMoney, MONEYPATH);

			return TRUE;

		}
		cardNode = cardNode->next;
		nIndex++;
	}
	return FALSE;
}


//退费
int Refund(const char* pName,const char* pPwd)
{
	lpCardNode cardNode = NULL;
	float charge = 0;
	Money sMoney;//
	int nIndex = 0;

	//获取文件中的卡信息
	if(FALSE == getCard())
	{
		return FALSE; 
	}

	cardNode = cardList->next;
	//遍历链表，判断能否进行退费
	while(cardNode != NULL)
	{
		if(strcmp(cardNode->cardData.aName,pName) == 0 && strcmp(cardNode->cardData.aPwd,pPwd) == 0)
		{
			printf("退费金额：%.1f\n",cardNode->cardData.fBalance);
			
			//更新链表中的信息
			cardNode->cardData.fBalance = 0.0;

			//可以退费，更新文件卡信息
			if(updateCard(&cardNode->cardData,CARDPATH,nIndex) == FALSE)
			{
				return FALSE;
			}

			//组装退费信息
			strcpy(sMoney.aCardName, cardNode->cardData.aName);
			sMoney.tTime = time(NULL);
			sMoney.nStatus = 1;
			sMoney.fMoney = cardNode->cardData.fBalance;
			sMoney.nDel = 0;

			//将退费记录保存到文件
			saveMoney(&sMoney, MONEYPATH);

			return TRUE;

		}
		cardNode = cardNode->next;
		nIndex++;
	}
	return FALSE;
}


//注销
int Cancel(const char* pName,const char* pPwd)
{
	lpCardNode cardNode = NULL;
	int nIndex = 0;

	//获取文件中的卡信息
	if(FALSE == getCard())
	{
		return FALSE; 
	}

	cardNode = cardList->next;
	//遍历链表，判断能否进行注销
	while(cardNode != NULL)
	{
		if(strcmp(cardNode->cardData.aName,pName) == 0 && strcmp(cardNode->cardData.aPwd,pPwd) == 0)
		{
			//只有状态为未使用的卡才能注销，注销卡余额应大于0
			if(cardNode->cardData.nStatus != 0)
			{
				return FALSE;
			}
			if(cardNode->cardData.fBalance < 0)
			{
				return FALSE;
			}
			//更新链表中的信息
			printf("\n卡号：\t退费金额\n");
			printf("%s\t%.2f\n",cardNode->cardData.aName,cardNode->cardData.fBalance);

			cardNode->cardData.nStatus = 2;
			cardNode->cardData.fBalance = 0.0;

			//可注销，更新文件卡信息
			if(updateCard(&cardNode->cardData,CARDPATH,nIndex) == TRUE)
			{
				return TRUE;
			}                             
			
		}
		cardNode = cardNode->next;
		nIndex++;
	}
	return FALSE;
}


//修改密码
int okalterpwd()
{
	char name[18] = { 0 };
	char pwd1[8] = { 0 };
	char pwd2[8] = { 0 };

	lpCardNode cardNode = NULL;
	float charge = 0;
	int nIndex = 0;

	printf("\n\n--------修改密码--------\n");
	printf("\n请输入卡号<长度1-18>：");
	scanf("%s", name);
	printf("请输入原密码<长度1-8>：");
	scanf("%s", pwd1);

	//获取文件中的卡信息
	if (FALSE == getCard())
	{
		return FALSE;
	}

	cardNode = cardList->next;
	//遍历链表
	while (cardNode != NULL)
	{
		if (strcmp(cardNode->cardData.aName, name) == 0 && strcmp(cardNode->cardData.aPwd, pwd1) == 0)
		{
			printf("请输入新密码<长度1-8>：");
			scanf("%s", pwd2);
			//判断输入的新密码是否符合要求
			if (getlength(pwd2) > 8) {
				printf("密码超出8位，请重新输入\n");
				return;
			}
			else if (getlength(pwd2) < 1) {
				printf("密码不能为空，请重新输入\n");
				return;
			}
			
			//更新链表中的信息
			strcpy(cardNode->cardData.aPwd, pwd2);

			//可以修改密码，更新文件卡信息
			if (updateCard(&cardNode->cardData, CARDPATH, nIndex) == TRUE)
			{
				return TRUE;
			}

		}
		cardNode = cardNode->next;
		nIndex++;
	}
	return FALSE;

}