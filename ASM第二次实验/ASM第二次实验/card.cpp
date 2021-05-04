#define _CRT_SECURE_NO_WARNINGS//Ïû³ýscanf¾¯¸æ
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "card.h"
#include "time.h"
Card* addCard(Card *card, char no[], char pwd[], float balance) {
	Card *t, *s = card;
	t = (Card*)malloc(sizeof(Card));
	strcpy(t->aName, no);
	strcpy(t->aPwd, pwd);
	t->nStatus = 0;
	t->tStart = time(0);
	t->tEnd = time(0) + 60 * 60 * 24 * 365;
	t->fTotalUse = 0;
	t->fBalance = balance;
	t->tLast = time(0);
	t->nUseCount = 0;
	t->nDel = 0;
	t->next = s->next;
	s->next = t;
	return card;
}
Card* initial() {
	Card *card;
	card = (Card*)malloc(sizeof(Card));
	card->next = NULL;
	return card;
}
Card* queryCard(Card *card, char no[]) {
	Card *t = card;
	int flag = 0;
	for (; t != NULL; t = t->next) {
		if (strcmp(t->aName, no) == 0) {
			flag = 1;
			break;
		}
	}
	if (flag) return t;
	else return NULL;
}
