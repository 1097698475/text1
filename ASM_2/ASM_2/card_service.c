#define _CRT_SECURE_NO_WARNINGS 

#include"model.h"
#include<string.h>
#include"global.h"
Card aCard[50];
int nCount = 0;
int addCard(Card card)
{
	aCard[nCount] = card;
	nCount++;
	return True;
}
Card* queryCard(const char *pName)
{
	int i = 0;
	for (i = 0; i < nCount; i++) {
		if (strcmp(pName, aCard[i].aName) == 0) {
			return &aCard[i];
		}
	}
}