#define _CRT_SECURE_NO_WARNINGS 


#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>


#include"model.h"
#include"service.h"
#include"tool.h"
#include"global.h"
#include"card_service.h"
#include "card_file.h"
#include "billing_file.h"

int getlength(char aa[]);		//声明函数 计算输入的密码、 卡号的位数
int id();		//声明管理员权限

//输出主菜单
void outputMenu(){
	printf("\n\n----------菜单----------\n");
	printf("1. 添加卡\n");
	printf("2. 查询卡\n");
	printf("3. 上机\n");
	printf("4. 下机\n");
	printf("5. 充值\n");
	printf("6. 退费\n");
	printf("7. 查询统计\n");
	printf("8. 注销卡\n");
	printf("9. 查询密码\n");
	printf("10. 修改密码\n");
	printf("0.退出\n");
	printf("\n请输入菜单编号：");
}



/*添加卡*/
void add()
{ 
	char pname[1000];		//输入值 防止输入的卡号、密码太长导致内存不够
	char ppwd[1000];
	float money=0.0;

	char name[18]={'0'};
	char pwd[8]={'0'};

	Card card;
	struct tm* endTime;     // 截止时间
	struct tm* startTime;   // 开卡时间

	int m = 0;	//开卡优惠
	int OKaddcard;			//添加卡结果
	int i = 0;


	printf("\n\n----------添加卡----------\n");

    printf("请输入卡号<1-18位>:");
    scanf("%s",&pname);
	
	if(getlength(pname)>18){
	printf("卡号超出18位，请重新输入\n");
	return;
	}
	else if(getlength(pname)<1){
		printf("卡号不能为空，请重新输入\n");
		return;
	}
	else{
		strcpy(name,pname);
	}

	printf("请输入密码<1-8位>：");
	scanf("%s",&ppwd);

	if(getlength(ppwd)>8){
		printf("密码超出8位，请重新输入\n");
		return ;
	}
	else if(getlength(ppwd)<1){
		printf("密码不能为空，请重新输入\n");
		return ;
	}
	else{
		strcpy(pwd, ppwd);
	}

	printf("请输入开卡金额<RMB>：");
	scanf("%f",&money);

	m = money / 100;
	money = money + m * 50;

	strcpy(card.aName,name);
	strcpy(card.aPwd, pwd);
	card.fTotalUse=0;
	card.fBalance=money;
	card.nStatus=0;
	card.nDel=0;
	card.nUseCount=0;
	card.tStart = card.tEnd = card.tLast = time(NULL); 	// 开卡时间，截止时间，最后使用时间都默认为当前时间。

	// 根据开卡时间，计算截止时间，每张卡的有效期为一年
	startTime = localtime(&card.tStart);
	endTime = localtime(&card.tEnd);
	endTime->tm_year = startTime->tm_year + 1;
	card.tEnd = mktime(endTime);

	//将卡信息保存到文件
	OKaddcard =addCard(card);
	if(OKaddcard ==FALSE){
		printf("\n\n添加失败!\n\n");
	}
	else{
		printf("\n添加成功!");
		printf("\n\n添加卡的信息如下：\n");
		printf("卡号\t\t密码\t\t状态\t\t开卡金额\n");
		printf("%s\t\t%s\t\t%d\t\t%.2f\n",card.aName,card.aPwd,card.nStatus,money);
	}

	printf("1.返回主菜单  2.继续添加卡  其他.退出系统  \n请输入编号：\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:return; break;
	case 2:add(); break;
	default:exit(0);
		break;
	}
}






/*查询卡*/
void query(){
	char name[18];
	char pname[1000];
	char nTime[20];
	Card *pCard;
	int pIndex=0;
	int i;
	int kind = 1;		//查询方式

	printf("\n\n----------查询卡----------\n");

	printf("请输入卡号<长度为1-18>:");
	scanf("%s",&pname);
	if(getlength(pname)>18)
	{printf("卡号超出18位，请重新输入\n");
	return;
	}
	else{
	strcpy(name,pname);
	}

	printf("\n精准查询编号为1 模糊查询编号为2 \n查询方式编号：");
	scanf("%d", &kind);


	//精准查询
		if (kind == 1) 
	{
		pCard = queryCard(name);
		if (pCard == NULL)
		{
			printf("未查询到此卡信息\n");
			return;
		}
		else
		{
			printf("\n\n查询到的卡信息如下：\n");
			timeToString(pCard->tLast, nTime);
			printf("卡号\t\t状态\t\t余额\t\t累计金额\t\t使用次数\t\t上次使用时间\n");
			printf("%s\t\t%d\t\t%.2f\t\t%.2f\t\t\t%d\t\t\t%s\n", pCard->aName, pCard->nStatus,  pCard->fBalance,  pCard->fTotalUse, pCard->nUseCount, nTime);
			return; 
		}

	}

	//模糊查询
	else if (kind == 2)
	{
		pCard = queryCards(name, &pIndex);
		if (pCard == NULL)
		{
			printf("未查到相关卡信息\n");
			return;
		}
		else
		{
			printf("\n\n查询到的卡信息如下：\n");
			printf("卡号\t\t状态\t\t余额\t\t累计金额\t\t使用次数\t\t上次使用时间\n");
			for (i = 0; i < pIndex; i++)
			{
				timeToString(pCard[i].tLast, nTime);
				printf("%s\t\t%d\t\t%.2f\t\t%.2f\t\t\t%d\t\t\t%s\n", pCard[i].aName, pCard[i].nStatus, pCard[i].fBalance, pCard[i].fTotalUse, pCard[i].nUseCount, nTime);
			}
			return; 
		}
	}
	else {
		printf("输入编号错误！！！\n");
		return;
	}
}

/*上机函数*/
void logon()
{	
	char aName[18]={0};
	char aPwd[8]={0};
	int nResult=0;		//上级结果
	LogonInfo* pInfo=NULL;
	char aTime[TIMELENGTH]={0};

	printf("\n----------上机----------\n");

	printf("\n请输入卡号（长度为1-18）：");
	scanf("%s",&aName);
	printf("请输入密码（长度为1-8）：");
	scanf("%s",&aPwd);

	pInfo=(LogonInfo*)malloc(sizeof(LogonInfo));

	nResult=doLogon(aName,aPwd,pInfo);		//上机

	switch(nResult)
	{
	case 0:
	{
		printf("上机失败\n");
		break;
	}
    case 1:
	{
		printf("\n上机成功\n\n上机信息如下\n");
		printf("卡号\t余额\t上机时间\n");
		timeToString(pInfo->tLogon,aTime);
		printf("%s\t%.2f\t%s\n",pInfo->aCardName,pInfo->fBalance,aTime);
		break;
	}
	default:
	{
		break;
	}		
	}
}


/*下机*/
void settle()
{
	char aName[18]={0};
	char aPwd[8]={0};
	int nResult=0;
	char aTime1[TIMELENGTH]={0};
	char aTime2[TIMELENGTH]={0};
	SettleInfo *pInfo=NULL;

	printf("\n----------下机----------\n");

	printf("\n请输入卡号（长度为1-18）：");
	scanf("%s",&aName);
	printf("请输入密码（长度为1-8）：");
	scanf("%s",&aPwd);

	printf("\n");

	pInfo=(SettleInfo*)malloc(sizeof(SettleInfo));
	nResult=doSettle(aName,aPwd,pInfo);
	switch(nResult)
	{
	case 0:
	{
		printf("下机失败\n");
		break;
	}

    case 1:
	{
		timeToString(pInfo->tStart, aTime1);
		timeToString(pInfo->tEnd, aTime2);
		printf("\n----------下机信息如下----------\n");
		printf("卡号\t消费金额\t余额\t上机时间\t\t下机时间\n");
		printf("%s\t%.2f\t%.2f\t%s\t%s\n", pInfo->aCardName, pInfo->fAmount, pInfo->fBalance, aTime1, aTime2);
		break;
	}
	default:

	{
		break;
	}		
	}

}


/*充值*/
void addMoney()
{
	char aName[18] = {0};
	char aPwd[8] = {0};

	printf("\n\n----------充值----------\n");


	printf("\n请输入账号：");
	scanf("%s",aName);
	printf("请输入密码：");
	scanf("%s",aPwd);
	if(TRUE == Recharge(aName,aPwd))
	{
		printf("充值成功\n");
	}
	else
	{
		printf("充值失败\n");
	}
}



//退费
void refundMoney()
{

	char aName[18] = {0};
	char aPwd[8] = {0};

	printf("\n\n----------退费----------\n");

	printf("\n请输入账号：");
	scanf("%s",aName);
	printf("请输入密码：");
	scanf("%s",aPwd);
	if(TRUE == Refund(aName,aPwd))
	{
		printf("退费成功\n");
	}
	else
	{
		printf("退费失败\n");
	}

}




//查询统计
void queryStatistics()
{
	int i = 0;	//查询or统计
	int ii = 0; //统计内容
	char fname[18] = { 0 };
	char tstart[TIMELENGTH] = { 0 };
	char tend[TIMELENGTH] = { 0 };
	char tlast[TIMELENGTH] = { 0 };
	Card* pcard = NULL;


	printf("\n\n----------查询统计----------\n");

	if (id() == FALSE)
	{
		return;
	}
	
	printf("1.查询  2.统计\n 请输入编号：\n");
	scanf("%d",&i);
	
	if (i == 1)
	{
		printf("请输入查询卡号：");
		scanf("%s", fname);
		pcard = queryCard(&fname);
		if (pcard == NULL) printf("查询失败！\n");

		timeToString(pcard->tStart, tstart);
		timeToString(pcard->tEnd, tend);
		timeToString(pcard->tLast, tlast);
		printf("卡号\t 密码\t 卡状态\t使用次数\t 累计金额\t 余额\t 删除标识（0-未删除，1-已删除）\n");
		printf("%s\t %s\t %d\t  %d\t\t  %.2f\t\t %.2f\t\t %d\n",
			pcard->aName,pcard->aPwd,pcard->nStatus,pcard->nUseCount,pcard->fTotalUse,pcard->fBalance,pcard->nDel);
		printf("\n开卡时间\t\t\t 截止时间\t\t\t 最后使用时间\n");
		printf("%s\t\t %s\t\t %s\n", tstart, tend, tlast);
	}
	else if (i == 2)
	{
		printf("1.卡信息数量\n2.计费信息数量\n0.退出\n请输入编号：");
		scanf("%d", &ii);

		switch (ii)
		{
		case 0:
		{
			return;
			break;
		}
		case 1:
		{
			printf("%d", getCardCount(CARDPATH));
			break;
		}
		case 2:
		{
			printf("%d", getBillingCount(BILLINGPATH));
			break;
		}

		default: {
			printf("错误的编号\n");
			break;
		}
		}

	}
	else {
		printf("错误的编号\n");
	}

	return; 
}



//注销卡
void annul()
{
	char aName[32] = {0};
	char aPwd[20] = {0};

	printf("\n\n----------注销卡----------\n");

	if (id() == FALSE)
	{
		return;
	}


	printf("\n请输入卡号：");
	scanf("%s",aName);
	printf("请输入密码：");
	scanf("%s",aPwd);


	if(TRUE == Cancel(aName,aPwd))
	{
		printf("注销成功\n");
	}
	else
	{
		printf("注销失败\n");
	}

}



//查询密码
void findpwd()
{
	char name[18];
	char pname[1000];
	Card* qCard;

	printf("\n\n----------查询密码----------\n");

	if (id() == FALSE)
	{
		return;
	}

	printf("请输入卡号<长度为1-18>:");
	scanf("%s", &pname);
	if (getlength(pname) > 18)
	{
		printf("卡号超出18位，请重新输入\n");
		return;
	}
	else {
		strcpy(name, pname);
	}

	qCard = queryCard(name);
	if (qCard == NULL)
	{
		printf("查询密码失败！\n");
		return;
	}
	else
	{
		printf("\n\n查询到该卡的密码如下：\n");
		printf("卡号\t\t密码\n");
		printf("%s\t\t%s\n", qCard->aName, qCard->aPwd);
		return;
	}
}



//修改密码
void alterpwd()
{
	if (okalterpwd() == TRUE)
	{
		printf("修改成功\n");
	}
	else printf("修改失败\n");

	return;
}




//退出
void exitApp()
{
	releaseCardList();/*释放链表空间*/
	exit(0);
}



//计算长度

int getlength(const char* pInfo)
{
	int nSize = 0;
	char c = '\0';

	do {
		c = *(pInfo + nSize);
		nSize++;
	} while (c != '\0');	//计算输入字符串的个数

	return nSize;
}




//管理员权限
int id()
{
	printf("为保证账户安全，请输入该系统管理员的用户名和密码进行验证\n");
	int idname = 0;
	int idpwd = 0;

	printf("用户名<长度0-6>：");
	scanf("%d", &idname);
	printf("密码<长度0-6>：");
	scanf("%d", &idpwd);

	if (idname != 2020 || idpwd != 2020)
	{
		printf("\n用户名/密码错误，无权限访问！\n");
		return FALSE;
	}
	else {
		return TRUE;
	}

}
