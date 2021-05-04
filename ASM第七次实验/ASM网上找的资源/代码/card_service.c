#define _CRT_SECURE_NO_WARNINGS 


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"global.h"
#include"card_file.h"
#include"model.h"
#include"menu.h"


int getCard();

//ȫ�ֱ���
Card ncard[50];
int i;
lpCardNode cardList;
lpCardNode head;
lpCardNode p,q;



/* ��ʼ������*/
int initCardList()
{
	head=(lpCardNode)malloc(sizeof(CardNode));
	head->next=NULL;
	cardList=head;
	return TRUE;
}



/*�ͷŽ��*/
void releaseCardList()
{    p=cardList;

	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
}



/*��ӿ�*/
int addCard(Card card)
{	
	return saveCard(&card,CARDPATH);
}



/*��ȷ��ѯ��*/
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



/*ģ����ѯ*/
Card* queryCards(const char name[], int* pIndex)
{

	Card* pCard = NULL;
	p = head;

	//���ļ��л�ȡ����Ϣ
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


//���ļ��еĿ���Ϣ��������������
int getCard()
{
	Card* pCard = NULL;
	int i = 0;
	int nCount = 0;
	p = NULL;
	q = NULL;

	if(cardList != NULL){
		releaseCardList();						//���������֤����ֻ��Ҫ������ļ���Ϣ
	}
	initCardList();
	
	nCount = getCardCount(CARDPATH);			//��ȡ����Ϣ����

	pCard = (Card*)malloc(sizeof(Card)* nCount);//��̬�����ڴ�

	if(pCard == NULL)							//����Ϣ����Ϊ0������ڴ�ʧ�� ����FALSE
	{
		return FALSE;
	}
	if(readCard(pCard,CARDPATH) == FALSE)		//��ȡ�ļ�	
	{	
		free(pCard);
		pCard = NULL;
		return FALSE;
	}
	for(i = 0,p = cardList;i < nCount;i++)		//���濨��Ϣ
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





/*���ݿ��ţ������ѯ���������������е�λ��*/
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



//��ֵ
int Recharge(const char* pName,const char* pPwd)
{
	lpCardNode cardNode = NULL;
	float addmon = 0;
	int nIndex = 0;
	int m = 0;		//��ֵ�Ż�
	Money sMoney;//

	//��ȡ�ļ��еĿ���Ϣ
	if(FALSE == getCard())
	{
		return FALSE; 
	}

	cardNode = cardList->next;
	//���������ж��ܷ���г�ֵ
	while(cardNode != NULL)
	{
		if(strcmp(cardNode->cardData.aName,pName) == 0 && strcmp(cardNode->cardData.aPwd,pPwd) == 0&&(cardNode->cardData.nStatus !=2))
		{
			printf("�������ֵ�Ľ�");
			scanf("%f",&addmon);

			//��ҵ�Ż�
			m = addmon / 100;
			addmon += m * 20;

			//���½ṹ��Ŀ����
			cardNode->cardData.fBalance += addmon;

			//�����ļ��Ŀ���Ϣ
			if(updateCard(&cardNode->cardData,CARDPATH,nIndex) == FALSE)
			{
				return FALSE;
			}           

			//��װ��ֵ��Ϣ
			strcpy(sMoney.aCardName, cardNode->cardData.aName);
			sMoney.tTime = time(NULL);
			sMoney.nStatus = 0;
			sMoney.fMoney = cardNode->cardData.fBalance;
			sMoney.nDel = 0;

			//����ֵ��¼���浽�ļ�
			saveMoney(&sMoney, MONEYPATH);

			return TRUE;

		}
		cardNode = cardNode->next;
		nIndex++;
	}
	return FALSE;
}


//�˷�
int Refund(const char* pName,const char* pPwd)
{
	lpCardNode cardNode = NULL;
	float charge = 0;
	Money sMoney;//
	int nIndex = 0;

	//��ȡ�ļ��еĿ���Ϣ
	if(FALSE == getCard())
	{
		return FALSE; 
	}

	cardNode = cardList->next;
	//���������ж��ܷ�����˷�
	while(cardNode != NULL)
	{
		if(strcmp(cardNode->cardData.aName,pName) == 0 && strcmp(cardNode->cardData.aPwd,pPwd) == 0)
		{
			printf("�˷ѽ�%.1f\n",cardNode->cardData.fBalance);
			
			//���������е���Ϣ
			cardNode->cardData.fBalance = 0.0;

			//�����˷ѣ������ļ�����Ϣ
			if(updateCard(&cardNode->cardData,CARDPATH,nIndex) == FALSE)
			{
				return FALSE;
			}

			//��װ�˷���Ϣ
			strcpy(sMoney.aCardName, cardNode->cardData.aName);
			sMoney.tTime = time(NULL);
			sMoney.nStatus = 1;
			sMoney.fMoney = cardNode->cardData.fBalance;
			sMoney.nDel = 0;

			//���˷Ѽ�¼���浽�ļ�
			saveMoney(&sMoney, MONEYPATH);

			return TRUE;

		}
		cardNode = cardNode->next;
		nIndex++;
	}
	return FALSE;
}


//ע��
int Cancel(const char* pName,const char* pPwd)
{
	lpCardNode cardNode = NULL;
	int nIndex = 0;

	//��ȡ�ļ��еĿ���Ϣ
	if(FALSE == getCard())
	{
		return FALSE; 
	}

	cardNode = cardList->next;
	//���������ж��ܷ����ע��
	while(cardNode != NULL)
	{
		if(strcmp(cardNode->cardData.aName,pName) == 0 && strcmp(cardNode->cardData.aPwd,pPwd) == 0)
		{
			//ֻ��״̬Ϊδʹ�õĿ�����ע����ע�������Ӧ����0
			if(cardNode->cardData.nStatus != 0)
			{
				return FALSE;
			}
			if(cardNode->cardData.fBalance < 0)
			{
				return FALSE;
			}
			//���������е���Ϣ
			printf("\n���ţ�\t�˷ѽ��\n");
			printf("%s\t%.2f\n",cardNode->cardData.aName,cardNode->cardData.fBalance);

			cardNode->cardData.nStatus = 2;
			cardNode->cardData.fBalance = 0.0;

			//��ע���������ļ�����Ϣ
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


//�޸�����
int okalterpwd()
{
	char name[18] = { 0 };
	char pwd1[8] = { 0 };
	char pwd2[8] = { 0 };

	lpCardNode cardNode = NULL;
	float charge = 0;
	int nIndex = 0;

	printf("\n\n--------�޸�����--------\n");
	printf("\n�����뿨��<����1-18>��");
	scanf("%s", name);
	printf("������ԭ����<����1-8>��");
	scanf("%s", pwd1);

	//��ȡ�ļ��еĿ���Ϣ
	if (FALSE == getCard())
	{
		return FALSE;
	}

	cardNode = cardList->next;
	//��������
	while (cardNode != NULL)
	{
		if (strcmp(cardNode->cardData.aName, name) == 0 && strcmp(cardNode->cardData.aPwd, pwd1) == 0)
		{
			printf("������������<����1-8>��");
			scanf("%s", pwd2);
			//�ж�������������Ƿ����Ҫ��
			if (getlength(pwd2) > 8) {
				printf("���볬��8λ������������\n");
				return;
			}
			else if (getlength(pwd2) < 1) {
				printf("���벻��Ϊ�գ�����������\n");
				return;
			}
			
			//���������е���Ϣ
			strcpy(cardNode->cardData.aPwd, pwd2);

			//�����޸����룬�����ļ�����Ϣ
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