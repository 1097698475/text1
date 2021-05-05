#define _CRT_SECURE_NO_WARNINGS
#include<time.h>

#ifndef MODEL_H
#define MODEL_H


typedef struct Card
{
	//开头字母是变量类型

	char aName[18];   // 卡号
	char aPwd[8];     // 卡密码

	int nStatus;      // 卡状态   0未上机  1正在上机   2已注销   3失效
	float fAmount;    // 累计使用
	int nUseCount;    // 使用次数
	float fBalance;   // 余额
	float fTotalUse;  //积累金额
	int nDel;         // 删除标记   0未删除    1已删除


	time_t tStart;    // 开卡时间
	time_t tEnd;      // 截止时间
	time_t tLast;     // 最后使用时间

}Card;

typedef struct CardNode
{
	Card data;               //结点数据区
	struct CardNode* next;   //指向下一个结点的指针

}CardNode, *lpCardNode;

#endif

