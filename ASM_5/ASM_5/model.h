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

typedef struct CardNode
{
	Card data;
	struct CardNode*next;
}CardNode,*lpCardNode;

typedef struct Billing
{
	float fBalance;
	float fTotalUse;
	int nUseCount;
	char aCardName[18];    // 卡号
	time_t tStart;         // 上机时间
	time_t tEnd;           // 下机时间
	float fAmount;         // 消费金额
	int nStatus;           // 消费状态，0-未结算，1-已经结算
	int nDel;              // 删除标识，0-未删除,1-删除
}Billing;

// 计费信息结点
typedef struct BillingNode
{
	Billing data;
	struct BillingNode* next;
}BillingNode, * lpBillingNode;

typedef struct LogoInfo
{
	char aCardName[18];
	time_t tLogon;
	float fBalance;
}LogonInfo;

typedef struct SettleInfo
{
	char aCardName[18];    // 卡号
	time_t tStart;         // 上机时间
	time_t tEnd;           // 下机时间
	float fAmount;         // 消费金额
	float fBalance; 
}SettleInfo;
#endif