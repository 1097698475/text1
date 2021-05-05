#define _CRT_SECURE_NO_WARNINGS
#include "model.h"     //�������ݶ���ͷ�ļ�
#include<string.h>     //�����ַ�����ͷ�ļ�
#include"global.h"     //����ȫ�ֶ���ͷ�ļ�
#include<stdlib.h>     //������̬�ڴ溯��
#include"card_file.h"


Card aCard[50];   //����Ϣ�ṹ������
int nCount = 0;   // ����Ϣʵ�ʸ���

lpCardNode cardList = NULL;

//��ʼ������
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

//�ͷ�
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

	////�����ݱ��浽�����
	//cur = (lpCardNode)malloc(sizeof(CardNode));
	//if (cur != NULL)
	//{
	//	cur->data = card;
	//	cur->next = NULL;

	//	//���������ҵ����һ�����
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

Card* queryCards(const char* pName, int* pIndex)  //ģ����ѯ
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