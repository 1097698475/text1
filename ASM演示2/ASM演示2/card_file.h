#ifndef CARD_FILE_H
#define CARD_FILE_H
#include"model.h"



int saveCard(const Card *pCard,const char* pPath);//����Ϣ���浽�ļ�

int readCard(Card* pCard,const char* pPath);//��ȡ����Ϣ

Card praseCard(char* pBuf);//�������� �ļ������Ϣ���ַ���

int getCardCount(const char* pPath);//��ȡ����Ϣ�ļ��п���Ϣ������

int updateCard(const Card* pCard,const char* pPath,int nIndex);//�����ļ���Ŀ���Ϣ



#endif