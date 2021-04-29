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
		printf("----------�˵�----------\n");
		printf("1.��ӿ�\n");
		printf("2.��ѯ��\n");
		printf("3.�ϻ�\n");
		printf("4.�»�\n");
		printf("5.��ֵ\n");
		printf("6.�˷�\n");
		printf("7.��ѯͳ��\n");
		printf("8.ע����\n");
		printf("0.�˳�\n");
		printf("��ѡ��˵����:\n");
	}
void add()
{
	struct Card card;  //����ṹ��
	char aName[32]={'0'};
	char aPwd[16]={'0'};
	int aNamesize=0;
	int aPwdsize=0;
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
	copy(aName,card.aName,18);
	copy(aPwd,card.aPwd,8);
	printf("*��Ƭ��Ϣ�ѱ������*\n");
	}
	printf("�����뿪����\n");
	scanf("%f",&card.fBalance);
	card.fTotalUse=card.fBalance;
	card.nDel=0;
	card.nUseCount=0;
	card.tStart=card.tLastUse=card.tEnd=time(NULL);
	card.nStatus=0;
	addCard(card);
	printf("*******information*******\n");
	printf("����\t����\t״̬\t���\n");
	printf("%s\t%s\t%d\t%0.1f\r",card.aName,card.aPwd,card.nStatus,card.fBalance);//��\r�ǻس�(CR) ,����ǰλ���Ƶ����п�ͷ,ASCII��ֵ(ʮ����)Ϊ013�� ����: 1���Ƿ��� '\r' �س�,�ص���ǰ�е�����,�����ỻ����һ��,�����������Ļ�,������ǰ�����ݻᱻ��һ����
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
	struct tm *startTime;//����ʱ��
	struct tm *endTime;//��ֹʱ��
	Card *pCard=NULL;
	printf("�������ѯ���ţ�\n");
	scanf("%s",aName);
	pCard = queryCard(aName);
	timeToString(pCard->tLastUse,aTime);//���ַ���ת��Ϊ����ʱ��
	startTime=localtime(&pCard->tStart);//ע��localtime����Ҫ��ָ��������Ҫ��ɵ�ַ
	endTime=localtime(&pCard->tEnd);
	endTime->tm_year=startTime->tm_year+1;//ʱ��Ϊһ��
	pCard->tEnd=mktime(endTime);
	printf("**********��ѯ���Ŀ���Ϣ����**********\n");
	printf("����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t���ʹ��ʱ��\t\tʱ��(��)\n");
	printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\t%d\n",pCard->aName,pCard->nStatus,pCard->fBalance,pCard->fTotalUse,pCard->nUseCount,aTime,1);
}