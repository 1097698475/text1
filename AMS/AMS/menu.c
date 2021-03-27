#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include"model.h"          //�������ݶ���ͷ�ļ�
#include"card_service.h"   //

int getSize(const char *pInfo);
void outputMenu()
{
	//�˵�
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
	printf("������˵�����(0-8) :  ");  //��ʾ������

}

void add()
{
	Card card;
	char aName[32] = { '\0' };
	char aPwd[20] = { '\0' };
	int nNameSize = 0;
	int nPwdSize = 0;
	printf("----------��ӿ�----------\n");
	printf("�����뿨�ţ�");
	scanf("%s", card.aName);  //���ü�&  ��ΪaName�����飬��������ʾ��ַ
	printf("���������룺");
	scanf("%s", card.aPwd);

	//�жϿ��Ż����볤��
	nNameSize = getSize(aName);
	nPwdSize = getSize(aPwd);
	if (nNameSize > 18 || nPwdSize > 8)
	{
		printf("���Ż����볬���涨����\n");
	}


	printf("�����뿪����");
	//printf("553");
	scanf("%f", &card.fBalance);
	printf("\n");
	//printf("333");
	card.fTotalUse = card.fBalance;
	card.nUseCount = 0;
	card.nStatus = 0;
	card.nDel = 0;
	card.tStart = card.tEnd = card.tLast = time(NULL);  //���ڵ�ǰʱ��

	//��ӿ���Ϣ
	addCard(card);

	//�������Ϣ
	printf("����\t����\t��״̬\t���\n");
	printf("%s\t%s\t%d\t%.1f\n",card.aName,card.aPwd,card.nStatus,card.fBalance);
}

int getSize(const char *pInfo)
{
	int nSize = 0;
	while (*(pInfo + nSize) != '\0')
	{
		nSize++;
	}
	return nSize;
}

void quary()//��Ӧ2��ѯ����
{
	char aName[18] = { 0 };
	Card* pCard = NULL;  //pCardָ���ϴ���ӵĿ�,����ʱ��->
	printf("�������ѯ�Ŀ��ţ�");
	scanf("%s", aName);
	pCard = queryCard(aName);

	//��ʾ
	printf("��ѯ���Ŀ���Ϣ����");
	printf("����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");
	printf("%s\t%d\t%.1f\t%.1f\t%d\t%d\n",pCard->aName,pCard->nStatus,pCard->fBalance,pCard->fTotalUse,pCard->nUseCount,pCard->tLast);
}