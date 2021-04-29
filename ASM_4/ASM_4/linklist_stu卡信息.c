#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<string.h> 
typedef struct STUDENT {
	int num, fbalance;
	char name[50];
	struct STUDENT* next;
} STUDENT;
typedef struct STUDENT* Link;    //定义链表指针结构类型

STUDENT* Create();//单链表的建立
STUDENT* Insert(STUDENT* phead, STUDENT* pnew);//节点的插入操作
STUDENT* Delete(STUDENT* phead, char n[]);//节点的查找及删除
int DelAll(STUDENT* phead);//链表删除
 

int main() {
	int i=0;
	int l=0; 
	char n[50]={0};
	STUDENT* pHead = Create();
	STUDENT* pStu = pHead;
	printf("*********卡信息如下*********\n");
	while (pStu != NULL)
	{
		printf("卡号\t\t密码\t\t开卡金额\t\t\n");
		printf("%s\t\t %d\t\t %d\n", pStu->name, pStu->num, pStu->fbalance);
		pStu = pStu->next;
	}
	printf("是否需要插入卡（是（1），否（0）)：");
	scanf("%d",&i);
	while(i==1)
	{ 
		STUDENT* pnew = (STUDENT*)malloc(sizeof(STUDENT));
	printf("输入卡的卡号：");
		scanf("%s", pnew->name);
	printf("输入卡的密码：");
	scanf("%d", &pnew->num);
	printf("输入开卡金额：");
	scanf("%d", &pnew->fbalance);
	pnew->next = NULL;
	pHead = Insert(pHead, pnew);
		printf("是否还需要插入卡（是（1），否（0）)：");
	scanf("%d",&i);
}
	pStu = pHead;
		printf("*********卡信息如下*********\n");
	while (pStu != NULL)
	{
			printf("卡号\t\t密码\t\t开卡金额\t\t\n");
		printf("%s\t\t %d\t\t %d\n", pStu->name, pStu->num, pStu->fbalance);
		pStu = pStu->next;
	}
	printf("是否需要删除卡（是（1），否（0）)：");
	scanf("%d",&l);
	while(l==1)
	{
		printf("请输入删除卡号：\n");
		scanf("%s",n);
	pHead = Delete(pHead, n);
	printf("是否还需要删除卡（是（1），否（0）)：");
	scanf("%d",&l);
}
	pStu = pHead;
		printf("*********卡信息如下*********\n");
	while (pStu != NULL)
	{
		printf("卡号\t\t密码\t\t开卡金额\t\t\n");
		printf("%s\t\t %d\t\t %d\n", pStu->name, pStu->num, pStu->fbalance);
		pStu = pStu->next;
	}
	DelAll(pHead);
}

//单链表的建立
STUDENT* Create()
{
	STUDENT* pnew, * pend, * phead;
	phead = NULL;
	pend = NULL;
	do
	{
		if ((pnew = (STUDENT*)malloc(sizeof(STUDENT))) == NULL)
		{
			printf("堆区内存已经用完！\n");
			exit(1);
		}
		printf("输入卡的卡号（为0则结束建表！）：");
		scanf("%s", pnew->name);
		if (strcmp(pnew->name,"0")==0)
			break;
		printf("输入卡的密码：");
		scanf("%d", &pnew->num);
		printf("输入开卡金额：");
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

//节点的插入操作
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
//节点的查找及删除
STUDENT* Delete(STUDENT* phead, char n[])
{
	STUDENT* pcur, * pdel;
	if (phead == NULL)
	{
		printf("链表为空，不需要做删除操作！\n");
		return phead;
	}
	if (strcmp(phead->name,n)==0)
	{
		pcur = phead;
		phead = phead->next;
		printf("卡号为%s的卡被删掉！！！\n\n", pcur->name);
		free(pcur);
		return phead;
	}
	for (pcur = phead; pcur->next != NULL; pcur = pcur->next)
	{
		if (strcmp(pcur->next->name,n)==0)
		{
			pdel = pcur->next;
			pcur->next = pdel->next;
			printf("\n卡号为%s的卡被删掉！！！\n",pdel->name);
			free(pdel);
			return phead;
		}
	}
	printf("链表中没有卡号为%s的卡！\n", n);
	return phead;
}
//链表删除
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
