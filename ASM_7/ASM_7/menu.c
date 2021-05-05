#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"model.h"
#include"service.h"
#include"card_service.h"
#include"tool.h"
#include"global.h"
#include"card_file.h"

int checklength(char aa[]);

void ad()
{
	printf("----------------------------��һ�----------------------------\n");
	printf("2020.05.01��2020.05.07����ٰ�Ϊ��һ�ܵĹ������Ƴ����·������\n");
	printf("һ���Գ�ֵ(����)>=100Ԫ����������10Ԫ\n");
	printf("һ���Գ�ֵ��������>=300Ԫ����������50Ԫ\n");
	printf("һ���Գ�ֵ��������>=500Ԫ����������150Ԫ\n");
	printf("\t\t\t\t\t\t\t\t2020.4.24\n");
	printf("*************************(*^��^*)********************************\n");
}

void outputMenu(){
	printf("\n\n----------�˵�----------\n");
	printf("1.��ӿ�\n");
	printf("2.��ѯ��(��)\n");
	printf("3.�ϻ�\n");
	printf("4.�»�\n");
	printf("5.��ֵ\n");
	printf("6.�˷�\n");
	printf("7.��ʧ��(��)\n");
	printf("8.ע����\n");
	printf("9.�޸�����\n");
	printf("10.�һ�����\n");
	printf("11.���(��)\n");
	printf("0.�˳�*\n");
	printf("������˵���ţ�");
}

/*��ӿ�*/
void add()
{ 
	char name[18]={'0'};
	char pname[1000];
	char password[8]={'0'};
	char ppassword[1000];
	char id[20]={'0'};
	char pid[1000];
	float money=0.0;
	int nlength=0;
	int plength=0;
	Card card;
	struct tm* endTime;     // ��ֹʱ��
	struct tm* startTime;   // ����ʱ��
	int success;
	Card *pCard=NULL;
	Card *pId=NULL;
	printf("\n----------��ӿ�----------\n");
    printf("�����뿨��<1-18λ>:");
    scanf("%s",&pname);
	if(checklength(pname)>18){
	printf("���ų���18λ������������\n");
	return;
	}
	else if(checklength(pname)<1){
		printf("���Ų���Ϊ�գ�����������\n");
		return;
	}
	else
	{
		strcpy(name,pname);
	}
	pCard=queryCard(name);
	if(pCard!=NULL)
	{
		printf("���û����ѱ�ʹ��,�����²�����");
		return;
	}
	printf("����������<1-8λ>��");
	scanf("%s",&ppassword);
	if(checklength(ppassword)>8){
	printf("���볬��8λ������������\n");
    return ;
	}
	else if(checklength(ppassword)<1){
		printf("���벻��Ϊ�գ�����������\n");
    return ;
}
	else
	{strcpy(password,ppassword);
	}
	printf("����������֤��:");
    scanf("%s",&pid);
	
	if(checklength(pid)!=18){
	printf("���֤�������������������\n");
	return;
	}
	else
	{
		strcpy(id,pid);
	}
	pId=queryId(id);
	if(pId!=NULL)
	{
		printf("�����֤�ѱ���,�����²�����");
		return;
	}
	printf("�����뿪�����<RMB>��");
	scanf("%f",&money);
	if(money<100)
	{
		card.fBalance=money;
	}
	if(money>=100&&money<300)
	{
		card.fBalance=money+10;
	}
	if(money>=300&&money<500)
	{
		card.fBalance=money+50;
	}
	if(money>=500)
	{
		card.fBalance=money+150;
	}
	strcpy(card.aName,name);
	strcpy(card.aPwd,password);
	strcpy(card.aId,id);
	card.fTotalUse=0;
	card.nStatus=0;
	card.nDel=0;
	card.nUseCount=0;
	card.tStart = card.tEnd = card.tLast = time(NULL); 
	// ����ʱ�䣬��ֹʱ�䣬���ʹ��ʱ�䶼Ĭ��Ϊ��ǰʱ�䡣
	// ���ݿ���ʱ�䣬�����ֹʱ�䣬ÿ�ſ�����Ч��Ϊһ��
	startTime = localtime(&card.tStart);
	endTime = localtime(&card.tEnd);
	endTime->tm_year = startTime->tm_year + 1;
	card.tEnd = mktime(endTime);
	success=addCard(card);
	if(success==FALSE){
	printf("\n\n���ʧ��!\n\n");
	}
	else{
	printf("\n��ӳɹ�!");
	printf("\n\n��ӿ�����Ϣ����\n");
	printf("����\t\t����\t\t״̬\t\t�������\n");
	if(money<100)
	printf("%s\t\t%s\t\t%d\t\t%.2f\n",card.aName,card.aPwd,card.nStatus,money);
	if(money>=100&&money<300)
	printf("%s\t\t%s\t\t%d\t\t%.2f\n",card.aName,card.aPwd,card.nStatus,money+10);
	if(money>=300&&money<500)
	printf("%s\t\t%s\t\t%d\t\t%.2f\n",card.aName,card.aPwd,card.nStatus,money+50);
	if(money>=500)
	printf("%s\t\t%s\t\t%d\t\t%.2f\n",card.aName,card.aPwd,card.nStatus,money+150);
	}
}

/*��ѯ��*/
void query(){
	int j=0;
	char aname[18];
	char apwd[8];
	char name[18];
	char pname[1000];
	char password[8];
	char ppassword[1000];
	char nTime[20];
	Card *qCard;
	int pIndex=0;
	int i;
	int k=-1;
	//lpCardNode pCard;
	printf("�˹��ܽ��������Ա����\n");
	printf("���������Ա�˺ţ�");
	scanf("%s",aname);
	printf("���������Ա���룺");
	scanf("%s",apwd);
	k=manager(aname,apwd);
	if(k==1)
	{
	printf("\n----------��ѯ��---------\n");
	printf("������о�ȷ��ѯ������1��ģ����ѯ������2��");
	scanf("%d",&j);
	if(j!=1&&j!=2)
	{
		printf("�޴˹��ܣ��Զ�Ϊ����ת���˵���\n");
	}
	else
	{
	printf("�������ѯ�Ŀ���<����Ϊ1-18>:");
	scanf("%s",pname);
	if(checklength(pname)>18)
	{printf("���ų���18λ������������\n");
	return;
	}
	else{
	strcpy(name,pname);
	}
	

	//     ��ȷ��ѯ
	if(j==1)
	{
	qCard=queryCard(name);
	if(qCard==NULL)
	{
		printf("δ��ѯ���˿���Ϣ\n");
	}
	else
	{
		printf("\n��ѯ���Ŀ���Ϣ���£�\n");
		timeToString(qCard->tLast,nTime);
		printf("����\t\t״̬\t\t�ۼ�ʹ��\t\t���\t\tʹ�ô���\t\t�ϴ�ʹ��ʱ��\n");
		printf("%s\t\t%d\t\t%.2f\t\t\t%.2f\t\t%d\t\t\t%s\n",qCard->aName,qCard->nStatus,qCard->fTotalUse,qCard->fBalance,qCard->nUseCount,nTime);
	}
	}
	/*ģ����ѯ*/
	if(j==2)
	{
	qCard=queryCards(name,&pIndex);
	if(qCard==NULL)
	{
		printf("δ�鵽��ؿ���Ϣ\n");
	}
	else
	{
		printf("\n��ѯ���Ŀ���Ϣ���£�\n");
		printf("����\t\t״̬\t\t���\t\t�ۼ�ʹ��\t\tʹ�ô���\t\t�ϴ�ʹ��ʱ��\n");
		for(i=0;i<pIndex;i++)
		{
		timeToString(qCard[i].tLast,nTime);
		printf("%s\t\t%d\t\t%.2f\t\t%.2f\t\t\t%d\t\t\t%s\n",qCard[i].aName,qCard[i].nStatus,qCard[i].fBalance,qCard[i].fTotalUse,qCard[i].nUseCount,nTime);
		}
	}
	}
	}
	}
	if(k!=1)
	{
		printf("����Ա�˺Ż������������,�޷����д˲�����");
	}
	
}

/*�ϻ�����*/
void logon()
{	
	char aName[18]={0};
	char aPwd[8]={0};
	int nResult=0;
	LogonInfo* pInfo=NULL;
	char aTime[TIMELENGTH]={0};
	printf("\n----------�ϻ�----------\n");
	printf("�������ϻ����ţ�����Ϊ1-18����");
	scanf("%s",&aName);
	printf("�������ϻ����루����Ϊ1-8����");
	scanf("%s",&aPwd);
	pInfo=(LogonInfo*)malloc(sizeof(LogonInfo));
	nResult=doLogon(aName,aPwd,pInfo);
	switch(nResult)
	{
	case 0:
		printf("�ϻ�ʧ��\n");
		break;

    case 1:
		printf("����\t���\t�ϻ�ʱ��\n");
		timeToString(pInfo->tLogon,aTime);
		printf("%s\t%.2f\t%s\n",pInfo->aCardName,pInfo->fBalance,aTime);
		break;
	case 2:
		printf("�ÿ������ϻ������Ѿ�ע��\n");
		break;
	case 3:
		printf("������\n");
		break;
	case 4:
		printf("�˿��Ѿ���ʧ\n");
		break;
	default:
		{
			break;
		}
		
	}


	
}
/*�»�*/
void settle()
{
	char aName[18]={0};
	char aPwd[8]={0};
	int nResult=0;
	char aTime1[TIMELENGTH]={0};
	char aTime2[TIMELENGTH]={0};
	SettleInfo *pInfo=NULL;
	printf("\n----------�»�----------\n");
	printf("�������»����ţ�����Ϊ1-18����");
	scanf("%s",&aName);
	printf("�������»����루����Ϊ1-8����");
	scanf("%s",&aPwd);
	pInfo=(SettleInfo*)malloc(sizeof(SettleInfo));
	nResult=doSettle(aName,aPwd,pInfo);
	switch(nResult)
	{
	case 0:
		printf("δ�鵽�ÿ��ϻ���Ϣ���»�ʧ��\n");
		break;

    case 1:
		timeToString(pInfo->tEnd,aTime2);
		printf("\n----------�»���Ϣ����----------\n");
		printf("����\t����\t���\t�»�ʱ��\n");
		printf("%s\t%.2f\t%.2f\t%s\n",pInfo->aCardName,pInfo->fAmount,pInfo->fBalance,aTime2);
		break;
	case 2:
		printf("δ�鵽�ÿ��ϻ���Ϣ���»�ʧ��\n");
		break;

	default:
		{
			break;
		}
		
	}

}


/*��ֵ*/
void addMoney()
{
	char aName[18] = {0};
	char aPwd[8] = {0};
	printf("\n----------��ֵ----------\n");
	printf("�������˺ţ�");
	scanf("%s",aName);
	printf("���������룺");
	scanf("%s",aPwd);
	if(TRUE == Recharge(aName,aPwd))
	{
		printf("��ֵ�ɹ�\n");
	}
	else
	{
		printf("��ֵʧ��\n");
	}
}



void refundMoney(){
	char aName[18] = {0};
	char aPwd[8] = {0};
	printf("\n----------�˷�----------\n");
	printf("�������˺ţ�");
	scanf("%s",aName);
	printf("���������룺");
	scanf("%s",aPwd);
	if(TRUE == Refund(aName,aPwd))
	{
		printf("�˷ѳɹ�\n");
	}
	else
	{
		printf("�˷�ʧ��\n");
	}

}
void master()
{
	int Index=0;
	char aname[18];
	char apwd[8];
	char aName[18] = {0};
	char aPwd[8] = {0};
	Card *temp;
	Card card;
	Card *pCard;
	int nIndex=0;
	int c=0; // �ļ��ṹ��ָ��
	int k=-1;
	struct tm* endTime;     // ��ֹʱ��
	struct tm* startTime;   // ����ʱ��
	FILE* fp = NULL; 
	printf("�˹��ܽ��������Ա����\n");
	printf("���������Ա�˺ţ�");
	scanf("%s",aname);
	printf("���������Ա���룺");
	scanf("%s",apwd);
	k=manager(aname,apwd);
	if(k==1)
	{
	printf("\n--------��ʧ��--------\n");
	 printf("�����뿨��(����Ϊ1~18)��");
	 scanf("%s",aName);
	 printf("����������(����Ϊ1~8)��");
	 scanf("%s",aPwd);
	 temp=checkCard(aName,aPwd,&nIndex);
	  if(temp==NULL)
	 {
		 printf("�˺Ż������������\n");
	 }
	  else
	  {
	 if(temp->nStatus==2||temp->nStatus==3)
	 {
		printf("�˿��Ѿ�ע����ʧЧ���ܽ��д˲�����");
	 }
	 else
	 {
		 temp->nStatus=4;
		 printf("��ʧ�ɹ�����ʧ�ڼ��޷����г����������һ�в�����");
		updateCard(temp, CARDPATH, nIndex);
	 }
	  }
	}
	if(k!=1)
	{
		printf("����Ա�˺Ż������������,�޷����д˲�����");
	}
}
void annul(){
	char aName[32] = {0};
	char aPwd[20] = {0};
	printf("\n----------ע��----------\n");
	printf("\n�������˺ţ�");
	scanf("%s",aName);
	printf("\n���������룺");
	scanf("%s",aPwd);
	if(TRUE == Cancel(aName,aPwd))
	{
		printf("ע���ɹ�\n");
	}
	else
	{
		printf("ע��ʧ��\n");
	}

}

void revise()
{
	char aName[18]={0};
	char password[8];
	char ppassword[1000];
	int nIndex=0;
	Card *pCard;
	printf("\n--------�޸�����-------\n");
		//��ѯ����
	printf("�����뿨�ţ�");
	scanf("%s",aName);
	printf("������ԭʼ����<����Ϊ1-8>:");
	scanf("%s",password);
	pCard=checkCard(aName,password,&nIndex);	
	if(pCard!=NULL)
	{
		if(pCard->nStatus==4)
		{
			printf("�˿��Ѿ���ʧ�޷����в���");
		}
		else
		{
			printf("�����������룺");
			scanf("%s",ppassword);
		if(checklength(ppassword)>8)
		{
			printf("���볬��8λ������������\n");
			return;
		}
		else
		{
			strcpy(pCard->aPwd,ppassword);
			updateCard(pCard,CARDPATH,nIndex);
		}
		}
	}
	if(pCard==NULL)
	{
		printf("���Ż������������\n");
	}
}



void find()
{
	char aName[18]={0};
	char aId[20]={0};
	Card *pCard=NULL;
	int i=-1;
	printf("\n--------�һ�����-------\n");
	printf("�����뿨�ţ�");
	scanf("%s",aName);
	printf("�����뱾�������֤�ţ�");
	scanf("%s",aId);
	i=doFind(aName,aId);
	if(i==1)
	{
		pCard=queryCard(aName);
		if(pCard->nStatus==4)
	{
		printf("�˿��Ѿ���ʧ�޷����в���");
	}
		else
		{
		printf("��������Ϊ��%s",pCard->aPwd);
		}
	}
	if(i!=1)
	{
		printf("���������֤��Ϣ�������޷���ѯ��");
	}
}


void refresh()
{
	int Index=0;
	char aname[18];
	char apwd[8];
	char aName[18] = {0};
	char aPwd[8] = {0};
	Card *temp;
	Card card;
	Card *pCard;
	int nIndex=0;
	int c=0; // �ļ��ṹ��ָ��
	int k=-1;
	struct tm* endTime;     // ��ֹʱ��
	struct tm* startTime;   // ����ʱ��
	FILE* fp = NULL; 
	printf("�˹��ܽ��������Ա����\n");
	printf("���������Ա�˺ţ�");
	scanf("%s",aname);
	printf("���������Ա���룺");
	scanf("%s",apwd);
	k=manager(aname,apwd);
	if(k==1)
	{
	printf("\n--------���--------\n");
	 printf("�����뿨��(����Ϊ1~18)��");
	 scanf("%s",aName);
	 printf("����������(����Ϊ1~8)��");
	 scanf("%s",aPwd);
	 temp=checkCard(aName,aPwd,&nIndex);
	 if(temp==NULL)
	 {
		 printf("�˺Ż������������\n");
	 }
	 else
	 {
	 if(temp->nStatus!=4)
	 {
		printf("�˿�û�й�ʧ���ܽ��д˲�����\n");
	 }
	 else
	 {
		 temp->nStatus=0;
		 printf("����ɹ�����������ʹ������������");
		updateCard(temp, CARDPATH, nIndex);
	 }
	}
	}
	if(k!=1)
	{
		printf("����Ա�˺Ż������������,�޷����д˲�����");
	}
}


void exitApp()
{
	char name[18];
	char nTime[20];
	Card *qCard;
	int i=0;
	int j=0;
	printf("���ز鿴��������ѡ��������������߼�ɾ�����������������1��");
	scanf("%d",&i);
	if(i==1)
	{
	printf("�������ѯ�Ŀ���<����Ϊ1-18>:");
	scanf("%s",name);
	qCard=queryCard(name);
	if(qCard==NULL)
	{
		printf("δ��ѯ���˿���Ϣ\n");
	}
	else
	{
		printf("\n��ѯ���Ŀ���Ϣ���£�\n");
		printf("����\t����\t״̬\t\t�ۼ�ʹ��\t\t���\t\t���֤��\n");
		printf("%s\t%s\t%d\t\t%.2f\t\t\t%.2f\t\t%s\n",qCard->aName,qCard->aPwd,qCard->nStatus,qCard->fTotalUse,qCard->fBalance,qCard->aId);
	}
	}
		printf("�Ƿ��˳����ǣ�1����0����");
		scanf("%d",&j);
		if(j==1)
		{
			releaseCardList();/*�ͷ�����ռ�*/
			exit(0);
		}
}








int checklength(char aa[])
{
	int count =0;
	while(aa[count]!='\0'){
	count++;
	}
	return count;
}
