#define _CRT_SECURE_NO_WARNINGS
#include "model.h"     //包含数据定义头文件
#include<string.h>     //包含字符处理头文件
#include"global.h"     //包含全局定义头文件
#include<stdlib.h>     //包含动态内存函数
#include"card_file.h"


Card aCard[50];   //卡信息结构体数组
int nCount = 0;   // 卡信息实际个数

lpCardNode cardList = NULL;

//初始化链表
int initCardList()
{
	lpCardNode head = NULL;

	head = (lpCardNode)malloc(sizeof(CardNode));

	if (head != NULL)
	{
		head->next = NULL;
		cardList = head;
		return TRUE;
	}
	return FALSE;
}

//释放
void releaseCardList()
{
	lpCardNode cur;
	if (cardList != NULL)
	{
		while (cardList->next != NULL)
		{
			cur = cardList->next;
			free(cur);
			cur = NULL;
		}
	}
}


int addCard(Card card)
{
	return saveCard(&card, CARDPATH);

	//lpCardNode cur = NULL;

	//if (cardList == NULL)
	//{
	//	initCardList();
	//}

	////将数据保存到结点中
	//cur = (lpCardNode)malloc(sizeof(CardNode));
	//if (cur != NULL)
	//{
	//	cur->data = card;
	//	cur->next = NULL;

	//	//遍历链表找到最后一个结点
	//	while (cardList->next != NULL)
	//	{
	//		cardList = cardList->next;
	//	}
	//	cardList->next = cur;
	//	return TRUE;
	//}
	//return FALSE;
}

Card* queryCard(const char* pName)
{
	lpCardNode cur = NULL;
	if (cardList != NULL)
	{
		cur = cardList->next;
		while (cur != NULL)
		{
			if (strcmp(cur->data.aName, pName) == 0)
			{
				return &cur->data;
			}
			cur = cur->next;
		}
	}
	return NULL;
}

Card* queryCards(const char* pName, int* pIndex)  //模糊查询
{
	lpCardNode cur = NULL;
	Card* pCard = (Card*)malloc(sizeof(Card));
	if (pCard == NULL)
	{
		return NULL;
	}
	if (cardList != NULL)
	{
		cur = cardList->next;
		while (cur != NULL)
		{
			if (strstr(cur->data.aName, pName) !=NULL)
			{
				pCard[*pIndex] = cur->data;
				(*pIndex)++;

				pCard = (Card*)realloc(pCard, ((*pIndex) + 1) * sizeof(Card));
			}
			cur = cur->next;
		}
	}
	return pCard;
}