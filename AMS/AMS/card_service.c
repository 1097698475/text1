#define _CRT_SECURE_NO_WARNINGS
#include "model.h"
#include<string.h>

Card aCard[50];   //卡信息结构体数组
int nCount = 0;   // 卡信息实际个数

int addCard(Card card)
{
	aCard[nCount] = card;
	nCount++;
	return nCount;
}

Card* queryCard(const char* pName)
{
	for (int i = 0; i < nCount; i++)
	{
		if (strcmp(pName, aCard[i].aName) == 0)
		{
			return &aCard[i];
		}
	}
}