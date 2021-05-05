#define _CRT_SECURE_NO_WARNINGS
#include "model.h"

#ifndef CARD_FILE_H
#define CARD_FILE_H

int addCard(Card card);
Card* queryCard(const char* pName);
void releaseCardList();
Card* queryCards(const char* pName, int* pIndex);


#endif