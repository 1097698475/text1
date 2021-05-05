#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<string.h>

#include"model.h"          //�������ݶ���ͷ�ļ�
#include"card_service.h"   //
#include"tool.h"
#include"global.h"


int getSize(const char *pInfo);
//void copy(const char aInput[], char aOutput[], int nSize);


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
	Card card;                  //����Ϣ
	char aName[32] = { '\0' };   //���뿨��
	char aPwd[20] = { '\0' };    //��������
	int nNameSize = 0;          
	int nPwdSize = 0;           
	struct tm* endTime;         //����ʱ��
	struct tm* startTime;       //��ֹʱ��

	printf("----------��ӿ�----------\n");

	//��ʾ��������
	printf("�����뿨��(����Ϊ1~18����");
	scanf("%s", aName);  //���ü�&  ��ΪaName�����飬��������ʾ��ַ

	//�ж�����Ŀ����Ƿ����Ҫ��
	nNameSize = getSize(aName);
	if (nNameSize > 18)
	{
		printf("����Ŀ��ų��ȳ������ֵ��\n");
		return;
	}

	//�����ű��浽���ṹ��
	strcpy(card.aName, aName);  //�滻��copy����

	//��ʾ��������
	printf("���������루����Ϊ1~8����");
	scanf("%s", aPwd);

	//�ж���������볤���Ƿ����Ҫ��
	nPwdSize = getSize(aPwd);
	if (nPwdSize > 8)
	{
		printf("��������볤�ȳ������ֵ!\n");
		return;   //return ����Ҫ������
	}

	//����������뱣�浽���������
	strcpy(card.aPwd, aPwd);


	printf("�����뿪����RMB)��");
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
	printf("�����ɹ���\n\n");
	

	//�������Ϣ
	printf("\n");
	printf("------------��ӿ���Ϣ����-----------\n");
	printf("����\t����\t��״̬\t���\n");
	printf("%s\t%s\t%d\t%.1f\n\n", card.aName, card.aPwd, card.nStatus, card.fBalance);
}

int getSize(const char *pInput)
{
	int nSize = 0;
	while (*(pInput + nSize) != '\0')
	{
		nSize++;
	}
	return nSize;
}
//void copy(const char aInput[], char aOutput[], int nSize)
//{
//	int i = 0;
//	for (i = 0; i < nSize; i++)
//	{
//		aOutput[i] = aInput[i];
//		if (aOutput[i] == 0)
//		{
//			break;
//		}
//	}
//}

void query()//��Ӧ2��ѯ����
{
	char aName[18] = { 0 };
	char aLastTime[20] = { 0 };
	Card* pCard = NULL;  //pCardָ���ϴ���ӵĿ�,����ʱ��->
	int nIndex = 0;
	int i = 0;

	//��ʾ����������Ŀ���Ϣ
	printf("�������ѯ�Ŀ��ţ�");
	scanf("%s", aName);

	//��ѯ��
	pCard = queryCards(aName,&nIndex);

	//���pCardΪNULL,��ʾû�иÿ���Ϣ
	if (pCard == NULL || nIndex == 0)
	{
		printf("û�иÿ�����Ϣ��\n");
	}
	else
	{
		//������ı�ͷ
		printf("����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");
		for (i = 0; i < nIndex; i++)
		{
			//��ʱ��ת��Ϊ�ַ���
			timeToString(pCard[i].tLast, aLastTime);

			//��ʾ
			printf("%s\t%d\t%.1f\t%.1f\t\t%d\t\t%s", pCard[i].aName, pCard[i].nStatus, pCard[i].fBalance,
				pCard[i].fTotalUse, pCard[i].nUseCount, aLastTime);
		}
	}
}

void exitApp()
{
	releaseCardList();
}