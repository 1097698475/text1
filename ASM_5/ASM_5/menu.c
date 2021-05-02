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
		printf("----------�˵�----------\n");
		printf("1.��ӿ�\n");
		printf("2.��ѯ��\n");
		printf("3.�ϻ�\n");
		printf("4.�»�\n");
		printf("5.��ֵ\n");
		printf("6.�˷�\n");
		printf("7.��ѯͳ��\n");
		printf("8.ע����\n");
		printf("9.����Աѡ��\n");
		printf("0.�˳�\n");
		printf("��ѡ��˵����:\n");
	}
	void add()
	{
		int k=0;
		struct Card card;  //����ṹ��
		char aName[32]={'0'};
		char aPwd[16]={'0'};
		int aNamesize=0;
		int aPwdsize=0;
			struct tm* endTime;     // ��ֹʱ��
	struct tm* startTime;   // ����ʱ��
		int a=1;
		printf("----------add----------\n");
		do{
			a=1;
			printf("�����뿨�ţ�������18λ����\n");
			scanf("%s",aName);
			printf("���������루������8λ����\n");
			scanf("%s",aPwd);
			aNamesize=getSize(aName);
			aPwdsize=getSize(aPwd);
			if(aNamesize>18 || aPwdsize>8)   //�ж��ַ�����
			{
				printf("���Ż����볬���涨��������������\n");
				printf("\n");
				a=0;
			}
			}while(a==0);
		if(a=1)
		{
		strcpy(card.aName, aName);
		strcpy(card.aPwd, aPwd);
		printf("*��Ƭ��Ϣ�ѱ������*\n");
		}
		printf("�����뿪����\n");
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
		printf("����\t����\t״̬\t���\n");
		printf("%s\t%s\t%d\t%0.1f\r\n",card.aName,card.aPwd,card.nStatus,card.fBalance);//��\r�ǻس�(CR) ,����ǰλ���Ƶ����п�ͷ,ASCII��ֵ(ʮ����)Ϊ013�� ����: 1���Ƿ��� '\r' �س�,�ص���ǰ�е�����,�����ỻ����һ��,�����������Ļ�,������ǰ�����ݻᱻ��һ����
		printf("�Ƿ��Ϊ���Դ˳����Ƿ���ӽ��ļ������ǣ�1������0����");
		scanf("%d",&k);
		if(k==1){
		if(FALSE == saveCard(&card, CARDPATH))
		printf("��ӿ���Ϣʧ�ܣ�\n");
		else
		printf("��ӿ���Ϣ�ɹ���\n");
		}
		else
		{
		if(FALSE == addCard(card))
		printf("�����ļ�����ӿ���Ϣʧ�ܣ�\n");
		else
		printf("�����ļ�����ӿ���Ϣ�ɹ���\n");
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
	struct tm *startTime;//����ʱ��
	struct tm *endTime;//��ֹʱ��
	Card *pCard=NULL;
	Card acard[50]={0};
	FILE* fp = NULL;  // �ļ��ṹ��ָ��
	int i=0;
	printf("��ѡ��ģ����ѯ��0��or��׼��ѯ��1��or�жϴ��ڣ�2����");
	scanf("%d",&i);
	if(i==2)
	{
 printf("�����뿨��(����Ϊ1~18)��");
 scanf("%s",card.aName);
 if(TRUE == isExsit(card.aName, CARDPATH))
 {
 printf("����Ϣ�ļ�%s�У���%s����Ϣ��\n",CARDPATH,card.aName);
 }
 else 
printf("����Ϣ�ļ�%s�У���%s����Ϣ��\n",CARDPATH,card.aName);
	}
	if(i==1)
	{
	printf("�������ѯ���ţ�\n");
	scanf("%s",aName);
	pCard = queryCard(aName);
	if(pCard==NULL)
	{
		printf("�޸ÿ���Ϣ���ٴκ˶Կ��ţ�\n");
	}
	else{
		timeToString(pCard->tLastUse,aTime);//���ַ���ת��Ϊ����ʱ��
	startTime=localtime(&pCard->tStart);//ע��localtime����Ҫ��ָ��������Ҫ��ɵ�ַ
	endTime=localtime(&pCard->tEnd);
	endTime->tm_year=startTime->tm_year+1;//ʱ��Ϊһ��
	pCard->tEnd=mktime(endTime);
	printf("**********��ѯ���Ŀ���Ϣ����**********\n");
	printf("����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t���ʹ��ʱ��\t\tʱ��(��)\n");
	printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\t%d\n",pCard->aName,pCard->nStatus,pCard->fBalance,pCard->fTotalUse,pCard->nUseCount,aTime,1);
	}
	}
	else if(i==0)
	{
		printf("�������ѯ���ţ�\n");
		scanf("%s",aName);
		pCard=queryCards(aName,&pIndex);
		if(pCard==NULL||pIndex==0)
	{
		printf("�޸ÿ���Ϣ���ٴκ˶Կ��ţ�\n");
	}
	else{
	printf("**********��ѯ���Ŀ���Ϣ����**********\n");
	printf("����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t���ʹ��ʱ��\t\tʱ��(��)\n");
	for(l=0;l<pIndex;l++)
	{
	timeToString(pCard[l].tLastUse,aTime);//���ַ���ת��Ϊ����ʱ��
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
	struct tm* endTime;     // ��ֹʱ��
	struct tm* startTime;   // ����ʱ��
	int nIndex=0;
	int c=0; // �ļ��ṹ��ָ��
	printf("����Ϣ�ļ�%s�У���%d������Ϣ��\n",CARDPATH,getCardCount(CARDPATH));
  // ��ֻ���ķ�ʽ���ļ�
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
  printf("�Ƿ���¿�����(1�����£�0��������)��\n");
  scanf("%d",&c);
  if(c==1)
  {
	 printf("�����ļ�%s�еڼ�����¼��",CARDPATH);
	 scanf("%d", &nIndex);
	printf("������������ݣ�\n");
	printf("�����뿨��(����Ϊ1~18)��");
	scanf("%s", card.aName);
	printf("����������(����Ϊ1~8)��");
	scanf("%s", card.aPwd);
	 printf("�����뿪�����(RMB)��");
	scanf("%f", &card.fBalance);
	 card.fTotalUse = card.fBalance;    // ��ӿ�ʱ���ۼƽ����ڿ������
	 card.nDel = 0;                     // ɾ����ʶ
	 card.nStatus = 0;                  // ��״̬
	 card.nUseCount = 0;                // ʹ�ô���
	card.tStart = card.tEnd = card.tLastUse = time(NULL); 
 startTime = localtime(&card.tStart);
 endTime = localtime(&card.tEnd);
 endTime->tm_year = startTime->tm_year + 1;
 card.tEnd = mktime(endTime);
 updateCard(&card, CARDPATH, nIndex);
  }
  else if(c==0)
  {
	  printf("��ִ�и��²���\n");
  }
}

void logon()
{
	char aTime[20]={0};
	int n = 0;
	LogonInfo *pInfo=NULL;
	Card* pCard=NULL;
	int result=0;
	//�����û�����Ŀ���Ϣ
	char aName[20]={0};
	char aPwd[8]={0};
	pInfo=(LogonInfo*)malloc(sizeof(LogonInfo));
	printf("----------logon----------\n");
	printf("�����뿨�ţ�");
	scanf("%s",aName);
	printf("���������룺");
	scanf("%s",aPwd);
	printf("\n");
	result=check(aName,aPwd,pInfo);
	pCard=dologon(aName,aPwd);
	timeToString(pCard->tLastUse,aTime);
	switch(result)
	{
	case 0:printf("�ϻ�ʧ��\n");break;
	case 1:
		{
			printf("**********�ϻ���Ϣ����**********\n");
			printf("����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t���ʹ��ʱ��\t\tʱ��(��)\n");
			printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\t%d\n",pCard->aName,pCard->nStatus,pCard->fBalance,pCard->fTotalUse,pCard->nUseCount,aTime,1);
			break;
		}
	case 2:	printf("�Ѿ���ɹ��ϻ�����\n");break;
	case 3:printf("����\n");break;
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
	printf("�������»����ţ�");
	scanf("%s",aName);
	printf("�������»������룺");
	scanf("%s",aPwd);
	nResult=doSettle(aName,aPwd,pInfo);
	printf("********�»���Ϣ����********\n");
	switch(nResult)
	{
	case 0:
		{
			printf("�»�ʧ��\n");
			break;
		}
	case 1:
		{
			printf("�»��ɹ�\n");
			printf("����\t����\t���\t�ϻ�ʱ��\t\t�»�ʱ��\n");
			timeToString(pInfo->tStart,aStartTime);
			timeToString(pInfo->tEnd,aEndTime);
			printf("%s\t%0.1f\t%0.1f\t%s\t%s\n",pInfo->aCardName,pInfo->fAmount,pInfo->fBalance,pInfo->tStart,pInfo->tEnd);
			break;
		}
	case 4:
		{
			printf("δ�ϻ�\n");
			break;
		}
	case 5:
		{
			printf("����\n");
			break;
		}
	}
}

void exitAPP()
{
	releasecardList();
	releaseBillingList();
}