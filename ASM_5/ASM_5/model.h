#define _CRT_SECURE_NO_WARNINGS

#ifndef MODEL_H
#define MODEL_H
#include<time.h>
typedef struct Card
{
char aName[18];  //����
char aPwd[8];  //����

int nStatus;   //��״̬(0-δ�ϻ���1-���ϻ���2-��ע����3-ʧЧ)
float fTotalUse;  //�ۼ�ʹ��
int nUseCount;    //ʹ�ô���
float fBalance;    //���
int nDel;          //ɾ�����



time_t tStart;  //����ʱ��
time_t tEnd;  //��ֹʱ��
time_t tLastUse;  //���ʹ��ʱ��
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
	char aCardName[18];    // ����
	time_t tStart;         // �ϻ�ʱ��
	time_t tEnd;           // �»�ʱ��
	float fAmount;         // ���ѽ��
	int nStatus;           // ����״̬��0-δ���㣬1-�Ѿ�����
	int nDel;              // ɾ����ʶ��0-δɾ��,1-ɾ��
}Billing;

// �Ʒ���Ϣ���
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
	char aCardName[18];    // ����
	time_t tStart;         // �ϻ�ʱ��
	time_t tEnd;           // �»�ʱ��
	float fAmount;         // ���ѽ��
	float fBalance; 
}SettleInfo;
#endif