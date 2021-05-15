#ifndef CARD_FILE_H
#define CARD_FILE_H
#include"model.h"



int saveCard(const Card *pCard,const char* pPath);//卡信息保存到文件

int readCard(Card* pCard,const char* pPath);//读取卡信息

Card praseCard(char* pBuf);//解析函数 文件里的信息→字符串

int getCardCount(const char* pPath);//获取卡信息文件中卡信息的数量

int updateCard(const Card* pCard,const char* pPath,int nIndex);//更新文件里的卡信息



#endif