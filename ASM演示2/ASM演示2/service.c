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


//�ϻ�
int doLogon(const char *pName,const char* pPwd,LogonInfo *pInfo)
{
	Card *pCard =NULL;
	int nIndex=0;								//�����ҵ��Ŀ����ڵ�λ�ã�������
	Billing billing;							//�Ʒ���Ϣ�ṹ��

	pCard=checkCard(pName,pPwd,&nIndex);		//���ҵõ�ƥ��Ŀ���Ϣ

	if(pCard==NULL){
		printf("\n�޸ÿ���Ϣ\n");
		return FALSE;
	}
	if(pCard->nStatus!=0){
		printf("\n�ÿ������ϻ����Ѿ�ע����ʧЧ\n");
		return FALSE;
	}
	if(pCard->fBalance<=0){
		printf("\n����\n");
		return FALSE;
	}

	//�����ļ��еĿ���Ϣ
	pCard->nStatus=1;
	pCard->tLast=time(NULL);
	pCard->nUseCount++;
	if(updateCard(pCard,CARDPATH,nIndex)==FALSE){
		return FALSE;
	}

	//���Ʒ���Ϣ���浽�Ʒ���Ϣ�ṹ�塢�Ʒ���Ϣ�ı��ļ�
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



//�»�
int doSettle(const char *pName,const char* pPwd,SettleInfo *pInfo)
{
	Card *pCard =NULL;
	Billing *pBilling=NULL;
	int nIndex=0;
	int nIndex1=0;
	float cost=0;
	int costTime=0;
	float costMoney=0;

	//��ѯ�� ���ص�nindex�ǿ��������λ��
	pCard=checkCard(pName,pPwd,&nIndex);

	//Ϊ�� û�иÿ���Ϣ
	if (pCard == NULL)
	{
		printf("�޸ÿ���Ϣ\n");
		return FALSE;
	}
	
	//ֻ�������ϻ��Ŀ����»�
	if(pCard->nStatus!=1)
	{
		printf("�ÿ�δ�ϻ�����ע����ʧЧ\n");
		return FALSE;
	}

	/*���¿���Ϣ���˵���Ϣ*/
	pCard->nStatus=0;
	
	//��ȡ�Ʒ���Ϣ Ϊ�����»�ʧ��
	pBilling=checkBilling(pName,&nIndex1);
	if (pBilling == NULL)
	{
		return FALSE;
	}

	//���¼Ʒ���Ϣ
	pBilling->nStatus=1;
	pBilling->tEnd=time(NULL);
	cost=(float)difftime(pBilling->tStart,pBilling->tStart);
	costTime=(int)(cost/60)+1;

	//�������ѽ��
	if(costTime%UNIT==0){
		costMoney=(int)(costTime/UNIT)*CHARGE;
	}
	else
	{
		costMoney=(int)(costTime/UNIT+1)*CHARGE;
	}

	//�жϿ����<���ѽ�� �����»�
	if (pCard->fBalance < costMoney)
	{
		printf("����\n");
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



