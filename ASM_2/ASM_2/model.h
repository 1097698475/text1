#define _CRT_SECURE_NO_WARNINGS 

#ifndef MODEL_H
#define MODEL_H
#include<time.h>
typedef struct Card
{
	char aName[18];  //卡号
	char aPwd[8];  //密码

	int nStatus;   //卡状态(0-未上机，1-正上机，2-已注销，3-失效)
	float fTotalUse;  //累计使用
	int nUseCount;    //使用次数
	float fBalance;    //余额
	int nDel;          //删除标记



	time_t tStart;  //开卡时间
	time_t tEnd;  //截止时间
	time_t tLastUse;  //最后使用时间
}Card;
#endif