#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<string.h> 
typedef struct STUDENT {
	int num, fbalance;
	char name[50];
	struct STUDENT* next;
} STUDENT;
typedef struct STUDENT* Link;    //��������ָ��ṹ����

STUDENT* Create();//������Ľ���
STUDENT* Insert(STUDENT* phead, STUDENT* pnew);//�ڵ�Ĳ������
STUDENT* Delete(STUDENT* phead, char n[]);//�ڵ�Ĳ��Ҽ�ɾ��
int DelAll(STUDENT* phead);//����ɾ��
 

int main() {
	int i=0;
	int l=0; 
	char n[50]={0};
	STUDENT* pHead = Create();
	STUDENT* pStu = pHead;
	printf("*********����Ϣ����*********\n");
	while (pStu != NULL)
	{
		printf("����\t\t����\t\t�������\t\t\n");
		printf("%s\t\t %d\t\t %d\n", pStu->name, pStu->num, pStu->fbalance);
		pStu = pStu->next;
	}
	printf("�Ƿ���Ҫ���뿨���ǣ�1������0��)��");
	scanf("%d",&i);
	while(i==1)
	{ 
		STUDENT* pnew = (STUDENT*)malloc(sizeof(STUDENT));
	printf("���뿨�Ŀ��ţ�");
		scanf("%s", pnew->name);
	printf("���뿨�����룺");
	scanf("%d", &pnew->num);
	printf("���뿪����");
	scanf("%d", &pnew->fbalance);
	pnew->next = NULL;
	pHead = Insert(pHead, pnew);
		printf("�Ƿ���Ҫ���뿨���ǣ�1������0��)��");
	scanf("%d",&i);
}
	pStu = pHead;
		printf("*********����Ϣ����*********\n");
	while (pStu != NULL)
	{
			printf("����\t\t����\t\t�������\t\t\n");
		printf("%s\t\t %d\t\t %d\n", pStu->name, pStu->num, pStu->fbalance);
		pStu = pStu->next;
	}
	printf("�Ƿ���Ҫɾ�������ǣ�1������0��)��");
	scanf("%d",&l);
	while(l==1)
	{
		printf("������ɾ�����ţ�\n");
		scanf("%s",n);
	pHead = Delete(pHead, n);
	printf("�Ƿ���Ҫɾ�������ǣ�1������0��)��");
	scanf("%d",&l);
}
	pStu = pHead;
		printf("*********����Ϣ����*********\n");
	while (pStu != NULL)
	{
		printf("����\t\t����\t\t�������\t\t\n");
		printf("%s\t\t %d\t\t %d\n", pStu->name, pStu->num, pStu->fbalance);
		pStu = pStu->next;
	}
	DelAll(pHead);
}

//������Ľ���
STUDENT* Create()
{
	STUDENT* pnew, * pend, * phead;
	phead = NULL;
	pend = NULL;
	do
	{
		if ((pnew = (STUDENT*)malloc(sizeof(STUDENT))) == NULL)
		{
			printf("�����ڴ��Ѿ����꣡\n");
			exit(1);
		}
		printf("���뿨�Ŀ��ţ�Ϊ0�������������");
		scanf("%s", pnew->name);
		if (strcmp(pnew->name,"0")==0)
			break;
		printf("���뿨�����룺");
		scanf("%d", &pnew->num);
		printf("���뿪����");
		scanf("%d", &pnew->fbalance);
		if (phead == NULL)
		{
			phead = pnew;
			pend = phead;
		}
		else {
			pend->next = pnew;
			pend = pnew;
		}
	} while (pnew->num != 0);
	if (pend != NULL) {
		pend->next = NULL;
		free(pnew);
	}
	return phead;
}

//�ڵ�Ĳ������
STUDENT* Insert(STUDENT* phead, STUDENT* pnew)
{
	STUDENT* pcur;
	if (phead == NULL || phead->fbalance > pnew->fbalance)
	{
		pnew->next = phead;
		phead = pnew;
		return phead;
	}
	for (pcur = phead; pcur->next != NULL; pcur = pcur->next)
	{
		if (pcur->next->fbalance > pnew->fbalance)
		{
			pnew->next = pcur->next;
			pcur->next = pnew;
			return phead;
		}
	}
	pcur->next = pnew;
	pnew->next = NULL;
	return phead;
}
//�ڵ�Ĳ��Ҽ�ɾ��
STUDENT* Delete(STUDENT* phead, char n[])
{
	STUDENT* pcur, * pdel;
	if (phead == NULL)
	{
		printf("����Ϊ�գ�����Ҫ��ɾ��������\n");
		return phead;
	}
	if (strcmp(phead->name,n)==0)
	{
		pcur = phead;
		phead = phead->next;
		printf("����Ϊ%s�Ŀ���ɾ��������\n\n", pcur->name);
		free(pcur);
		return phead;
	}
	for (pcur = phead; pcur->next != NULL; pcur = pcur->next)
	{
		if (strcmp(pcur->next->name,n)==0)
		{
			pdel = pcur->next;
			pcur->next = pdel->next;
			printf("\n����Ϊ%s�Ŀ���ɾ��������\n",pdel->name);
			free(pdel);
			return phead;
		}
	}
	printf("������û�п���Ϊ%s�Ŀ���\n", n);
	return phead;
}
//����ɾ��
int DelAll(STUDENT* phead)
{
	if (phead == NULL)
	{
		return 0;
	}
	STUDENT* pcur, * pnext;
	pcur = phead;
	pnext = pcur->next;
	while (pcur != NULL)
	{
		free(pcur);
		pcur = NULL;
		if (pnext != NULL)
		{
			pcur = pnext;
			pnext = pnext->next;
		}
	}
	return 0;
}
