#define _CRT_SECURE_NO_WARNINGS 


#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>


#include"model.h"
#include"service.h"
#include"tool.h"
#include"global.h"
#include"card_service.h"
#include "card_file.h"
#include "billing_file.h"

int getlength(char aa[]);		//�������� ������������롢 ���ŵ�λ��
int id();		//��������ԱȨ��

//������˵�
void outputMenu(){
	printf("\n\n----------�˵�----------\n");
	printf("1. ��ӿ�\n");
	printf("2. ��ѯ��\n");
	printf("3. �ϻ�\n");
	printf("4. �»�\n");
	printf("5. ��ֵ\n");
	printf("6. �˷�\n");
	printf("7. ��ѯͳ��\n");
	printf("8. ע����\n");
	printf("9. ��ѯ����\n");
	printf("10. �޸�����\n");
	printf("0.�˳�\n");
	printf("\n������˵���ţ�");
}



/*��ӿ�*/
void add()
{ 
	char pname[1000];		//����ֵ ��ֹ����Ŀ��š�����̫�������ڴ治��
	char ppwd[1000];
	float money=0.0;

	char name[18]={'0'};
	char pwd[8]={'0'};

	Card card;
	struct tm* endTime;     // ��ֹʱ��
	struct tm* startTime;   // ����ʱ��

	int m = 0;	//�����Ż�
	int OKaddcard;			//��ӿ����
	int i = 0;


	printf("\n\n----------��ӿ�----------\n");

    printf("�����뿨��<1-18λ>:");
    scanf("%s",&pname);
	
	if(getlength(pname)>18){
	printf("���ų���18λ������������\n");
	return;
	}
	else if(getlength(pname)<1){
		printf("���Ų���Ϊ�գ�����������\n");
		return;
	}
	else{
		strcpy(name,pname);
	}

	printf("����������<1-8λ>��");
	scanf("%s",&ppwd);

	if(getlength(ppwd)>8){
		printf("���볬��8λ������������\n");
		return ;
	}
	else if(getlength(ppwd)<1){
		printf("���벻��Ϊ�գ�����������\n");
		return ;
	}
	else{
		strcpy(pwd, ppwd);
	}

	printf("�����뿪�����<RMB>��");
	scanf("%f",&money);

	m = money / 100;
	money = money + m * 50;

	strcpy(card.aName,name);
	strcpy(card.aPwd, pwd);
	card.fTotalUse=0;
	card.fBalance=money;
	card.nStatus=0;
	card.nDel=0;
	card.nUseCount=0;
	card.tStart = card.tEnd = card.tLast = time(NULL); 	// ����ʱ�䣬��ֹʱ�䣬���ʹ��ʱ�䶼Ĭ��Ϊ��ǰʱ�䡣

	// ���ݿ���ʱ�䣬�����ֹʱ�䣬ÿ�ſ�����Ч��Ϊһ��
	startTime = localtime(&card.tStart);
	endTime = localtime(&card.tEnd);
	endTime->tm_year = startTime->tm_year + 1;
	card.tEnd = mktime(endTime);

	//������Ϣ���浽�ļ�
	OKaddcard =addCard(card);
	if(OKaddcard ==FALSE){
		printf("\n\n���ʧ��!\n\n");
	}
	else{
		printf("\n��ӳɹ�!");
		printf("\n\n��ӿ�����Ϣ���£�\n");
		printf("����\t\t����\t\t״̬\t\t�������\n");
		printf("%s\t\t%s\t\t%d\t\t%.2f\n",card.aName,card.aPwd,card.nStatus,money);
	}

	printf("1.�������˵�  2.������ӿ�  ����.�˳�ϵͳ  \n�������ţ�\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:return; break;
	case 2:add(); break;
	default:exit(0);
		break;
	}
}






/*��ѯ��*/
void query(){
	char name[18];
	char pname[1000];
	char nTime[20];
	Card *pCard;
	int pIndex=0;
	int i;
	int kind = 1;		//��ѯ��ʽ

	printf("\n\n----------��ѯ��----------\n");

	printf("�����뿨��<����Ϊ1-18>:");
	scanf("%s",&pname);
	if(getlength(pname)>18)
	{printf("���ų���18λ������������\n");
	return;
	}
	else{
	strcpy(name,pname);
	}

	printf("\n��׼��ѯ���Ϊ1 ģ����ѯ���Ϊ2 \n��ѯ��ʽ��ţ�");
	scanf("%d", &kind);


	//��׼��ѯ
		if (kind == 1) 
	{
		pCard = queryCard(name);
		if (pCard == NULL)
		{
			printf("δ��ѯ���˿���Ϣ\n");
			return;
		}
		else
		{
			printf("\n\n��ѯ���Ŀ���Ϣ���£�\n");
			timeToString(pCard->tLast, nTime);
			printf("����\t\t״̬\t\t���\t\t�ۼƽ��\t\tʹ�ô���\t\t�ϴ�ʹ��ʱ��\n");
			printf("%s\t\t%d\t\t%.2f\t\t%.2f\t\t\t%d\t\t\t%s\n", pCard->aName, pCard->nStatus,  pCard->fBalance,  pCard->fTotalUse, pCard->nUseCount, nTime);
			return; 
		}

	}

	//ģ����ѯ
	else if (kind == 2)
	{
		pCard = queryCards(name, &pIndex);
		if (pCard == NULL)
		{
			printf("δ�鵽��ؿ���Ϣ\n");
			return;
		}
		else
		{
			printf("\n\n��ѯ���Ŀ���Ϣ���£�\n");
			printf("����\t\t״̬\t\t���\t\t�ۼƽ��\t\tʹ�ô���\t\t�ϴ�ʹ��ʱ��\n");
			for (i = 0; i < pIndex; i++)
			{
				timeToString(pCard[i].tLast, nTime);
				printf("%s\t\t%d\t\t%.2f\t\t%.2f\t\t\t%d\t\t\t%s\n", pCard[i].aName, pCard[i].nStatus, pCard[i].fBalance, pCard[i].fTotalUse, pCard[i].nUseCount, nTime);
			}
			return; 
		}
	}
	else {
		printf("�����Ŵ��󣡣���\n");
		return;
	}
}

/*�ϻ�����*/
void logon()
{	
	char aName[18]={0};
	char aPwd[8]={0};
	int nResult=0;		//�ϼ����
	LogonInfo* pInfo=NULL;
	char aTime[TIMELENGTH]={0};

	printf("\n----------�ϻ�----------\n");

	printf("\n�����뿨�ţ�����Ϊ1-18����");
	scanf("%s",&aName);
	printf("���������루����Ϊ1-8����");
	scanf("%s",&aPwd);

	pInfo=(LogonInfo*)malloc(sizeof(LogonInfo));

	nResult=doLogon(aName,aPwd,pInfo);		//�ϻ�

	switch(nResult)
	{
	case 0:
	{
		printf("�ϻ�ʧ��\n");
		break;
	}
    case 1:
	{
		printf("\n�ϻ��ɹ�\n\n�ϻ���Ϣ����\n");
		printf("����\t���\t�ϻ�ʱ��\n");
		timeToString(pInfo->tLogon,aTime);
		printf("%s\t%.2f\t%s\n",pInfo->aCardName,pInfo->fBalance,aTime);
		break;
	}
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

	printf("\n�����뿨�ţ�����Ϊ1-18����");
	scanf("%s",&aName);
	printf("���������루����Ϊ1-8����");
	scanf("%s",&aPwd);

	printf("\n");

	pInfo=(SettleInfo*)malloc(sizeof(SettleInfo));
	nResult=doSettle(aName,aPwd,pInfo);
	switch(nResult)
	{
	case 0:
	{
		printf("�»�ʧ��\n");
		break;
	}

    case 1:
	{
		timeToString(pInfo->tStart, aTime1);
		timeToString(pInfo->tEnd, aTime2);
		printf("\n----------�»���Ϣ����----------\n");
		printf("����\t���ѽ��\t���\t�ϻ�ʱ��\t\t�»�ʱ��\n");
		printf("%s\t%.2f\t%.2f\t%s\t%s\n", pInfo->aCardName, pInfo->fAmount, pInfo->fBalance, aTime1, aTime2);
		break;
	}
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

	printf("\n\n----------��ֵ----------\n");


	printf("\n�������˺ţ�");
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



//�˷�
void refundMoney()
{

	char aName[18] = {0};
	char aPwd[8] = {0};

	printf("\n\n----------�˷�----------\n");

	printf("\n�������˺ţ�");
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




//��ѯͳ��
void queryStatistics()
{
	int i = 0;	//��ѯorͳ��
	int ii = 0; //ͳ������
	char fname[18] = { 0 };
	char tstart[TIMELENGTH] = { 0 };
	char tend[TIMELENGTH] = { 0 };
	char tlast[TIMELENGTH] = { 0 };
	Card* pcard = NULL;


	printf("\n\n----------��ѯͳ��----------\n");

	if (id() == FALSE)
	{
		return;
	}
	
	printf("1.��ѯ  2.ͳ��\n �������ţ�\n");
	scanf("%d",&i);
	
	if (i == 1)
	{
		printf("�������ѯ���ţ�");
		scanf("%s", fname);
		pcard = queryCard(&fname);
		if (pcard == NULL) printf("��ѯʧ�ܣ�\n");

		timeToString(pcard->tStart, tstart);
		timeToString(pcard->tEnd, tend);
		timeToString(pcard->tLast, tlast);
		printf("����\t ����\t ��״̬\tʹ�ô���\t �ۼƽ��\t ���\t ɾ����ʶ��0-δɾ����1-��ɾ����\n");
		printf("%s\t %s\t %d\t  %d\t\t  %.2f\t\t %.2f\t\t %d\n",
			pcard->aName,pcard->aPwd,pcard->nStatus,pcard->nUseCount,pcard->fTotalUse,pcard->fBalance,pcard->nDel);
		printf("\n����ʱ��\t\t\t ��ֹʱ��\t\t\t ���ʹ��ʱ��\n");
		printf("%s\t\t %s\t\t %s\n", tstart, tend, tlast);
	}
	else if (i == 2)
	{
		printf("1.����Ϣ����\n2.�Ʒ���Ϣ����\n0.�˳�\n�������ţ�");
		scanf("%d", &ii);

		switch (ii)
		{
		case 0:
		{
			return;
			break;
		}
		case 1:
		{
			printf("%d", getCardCount(CARDPATH));
			break;
		}
		case 2:
		{
			printf("%d", getBillingCount(BILLINGPATH));
			break;
		}

		default: {
			printf("����ı��\n");
			break;
		}
		}

	}
	else {
		printf("����ı��\n");
	}

	return; 
}



//ע����
void annul()
{
	char aName[32] = {0};
	char aPwd[20] = {0};

	printf("\n\n----------ע����----------\n");

	if (id() == FALSE)
	{
		return;
	}


	printf("\n�����뿨�ţ�");
	scanf("%s",aName);
	printf("���������룺");
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



//��ѯ����
void findpwd()
{
	char name[18];
	char pname[1000];
	Card* qCard;

	printf("\n\n----------��ѯ����----------\n");

	if (id() == FALSE)
	{
		return;
	}

	printf("�����뿨��<����Ϊ1-18>:");
	scanf("%s", &pname);
	if (getlength(pname) > 18)
	{
		printf("���ų���18λ������������\n");
		return;
	}
	else {
		strcpy(name, pname);
	}

	qCard = queryCard(name);
	if (qCard == NULL)
	{
		printf("��ѯ����ʧ�ܣ�\n");
		return;
	}
	else
	{
		printf("\n\n��ѯ���ÿ����������£�\n");
		printf("����\t\t����\n");
		printf("%s\t\t%s\n", qCard->aName, qCard->aPwd);
		return;
	}
}



//�޸�����
void alterpwd()
{
	if (okalterpwd() == TRUE)
	{
		printf("�޸ĳɹ�\n");
	}
	else printf("�޸�ʧ��\n");

	return;
}




//�˳�
void exitApp()
{
	releaseCardList();/*�ͷ�����ռ�*/
	exit(0);
}



//���㳤��

int getlength(const char* pInfo)
{
	int nSize = 0;
	char c = '\0';

	do {
		c = *(pInfo + nSize);
		nSize++;
	} while (c != '\0');	//���������ַ����ĸ���

	return nSize;
}




//����ԱȨ��
int id()
{
	printf("Ϊ��֤�˻���ȫ���������ϵͳ����Ա���û��������������֤\n");
	int idname = 0;
	int idpwd = 0;

	printf("�û���<����0-6>��");
	scanf("%d", &idname);
	printf("����<����0-6>��");
	scanf("%d", &idpwd);

	if (idname != 2020 || idpwd != 2020)
	{
		printf("\n�û���/���������Ȩ�޷��ʣ�\n");
		return FALSE;
	}
	else {
		return TRUE;
	}

}
