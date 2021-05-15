#ifndef MODEL_H
#define MODEL_H

#include<stdio.h>
#include<time.h>
#include<string.h>




//卡信息结构体
typedef struct Card
{
char aName[18];         // 卡号
char aPwd[8];           // 密码
int  nStatus;           // 卡状态(0-未上机；1-正在上机；2-已注销；3-失效)
time_t tStart;          // 开卡时间
time_t tEnd;            // 卡的截止时间 
float fTotalUse;        // 累计金额
time_t tLast;           // 最后使用时间
int nUseCount;          // 使用次数
float fBalance;         // 余额
int nDel;               // 删除标识 0-未删除,1-删除
}Card;




//卡信息结点 - 链表
typedef struct CardNode
{
	Card cardData;			//卡信息结构体
    struct CardNode *next;	//结点
}CardNode,*lpCardNode;




//计费信息结构体
typedef struct Billing {
	char aCardName[18];		//卡号
	time_t tStart;			//上机时间
	time_t tEnd;			//下机时间
	int nStatus;			//消费状态 0-未结算 1-已结算
	float fAmount;			//消费金额
	int nDel;				//删除标识 0-未删除 1-已删除
}Billing;




//计费信息结点 - 链表
typedef struct BillingNode{
  Billing BillingData;		//计费信息结构体
  struct BillingNode *next;	//结点
}BillingNode,*lpBillingNode;




//上机信息结构体
typedef struct LogonInfo{
	char aCardName[18];		//上级卡号
	float fBalance;			//上机时的卡余额
	time_t tLogon;			//上机时间
}LogonInfo;




//下机信息结构体
typedef struct SettleInfo{
    char aCardName[18];		//下机卡号
    float fAmount;			//下机时的消费金额
	float fBalance;			//下机完成的余额
	time_t tStart;			//上机时间
	time_t tEnd;			//下机时间
}SettleInfo;




//充值退费结构体
typedef struct Money
{
	char aCardName[18];		// 卡号
	time_t tTime;			// 充值退费的时间
	int nStatus;			// 状态：0-表示充值；1-表示退费
	float fMoney;		    // 充值退费金额
	int nDel;				// 删除标识，0-未删除,1-删除
}Money;




//充值退费信息结构体
typedef struct MoneyInfo
{
	char aCardName[18];	//卡号
	float fMoney;		//充值退费金额
	float fBalance;		//余额
}MoneyInfo;



#endif