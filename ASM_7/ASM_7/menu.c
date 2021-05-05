#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"model.h"
#include"service.h"
#include"card_service.h"
#include"tool.h"
#include"global.h"
#include"card_file.h"

int checklength(char aa[]);

void ad()
{
	printf("----------------------------五一活动----------------------------\n");
	printf("2020.05.01至2020.05.07本店举办为期一周的国庆活动，推出以下返利活动：\n");
	printf("一次性充值(开卡)>=100元将额外赠送10元\n");
	printf("一次性充值（开卡）>=300元将额外赠送50元\n");
	printf("一次性充值（开卡）>=500元将额外赠送150元\n");
	printf("\t\t\t\t\t\t\t\t2020.4.24\n");
	printf("*************************(*^▽^*)********************************\n");
}

void outputMenu(){
	printf("\n\n----------菜单----------\n");
	printf("1.添加卡\n");
	printf("2.查询卡(管)\n");
	printf("3.上机\n");
	printf("4.下机\n");
	printf("5.充值\n");
	printf("6.退费\n");
	printf("7.挂失卡(管)\n");
	printf("8.注销卡\n");
	printf("9.修改密码\n");
	printf("10.找回密码\n");
	printf("11.激活卡(管)\n");
	printf("0.退出*\n");
	printf("请输入菜单编号：");
}

/*添加卡*/
void add()
{ 
	char name[18]={'0'};
	char pname[1000];
	char password[8]={'0'};
	char ppassword[1000];
	char id[20]={'0'};
	char pid[1000];
	float money=0.0;
	int nlength=0;
	int plength=0;
	Card card;
	struct tm* endTime;     // 截止时间
	struct tm* startTime;   // 开卡时间
	int success;
	Card *pCard=NULL;
	Card *pId=NULL;
	printf("\n----------添加卡----------\n");
    printf("请输入卡号<1-18位>:");
    scanf("%s",&pname);
	if(checklength(pname)>18){
	printf("卡号超出18位，请重新输入\n");
	return;
	}
	else if(checklength(pname)<1){
		printf("卡号不能为空，请重新输入\n");
		return;
	}
	else
	{
		strcpy(name,pname);
	}
	pCard=queryCard(name);
	if(pCard!=NULL)
	{
		printf("此用户名已被使用,请重新操作！");
		return;
	}
	printf("请输入密码<1-8位>：");
	scanf("%s",&ppassword);
	if(checklength(ppassword)>8){
	printf("密码超出8位，请重新输入\n");
    return ;
	}
	else if(checklength(ppassword)<1){
		printf("密码不能为空，请重新输入\n");
    return ;
}
	else
	{strcpy(password,ppassword);
	}
	printf("请输入绑定身份证号:");
    scanf("%s",&pid);
	
	if(checklength(pid)!=18){
	printf("身份证号输入错误，请重新输入\n");
	return;
	}
	else
	{
		strcpy(id,pid);
	}
	pId=queryId(id);
	if(pId!=NULL)
	{
		printf("此身份证已被绑定,请重新操作！");
		return;
	}
	printf("请输入开卡金额<RMB>：");
	scanf("%f",&money);
	if(money<100)
	{
		card.fBalance=money;
	}
	if(money>=100&&money<300)
	{
		card.fBalance=money+10;
	}
	if(money>=300&&money<500)
	{
		card.fBalance=money+50;
	}
	if(money>=500)
	{
		card.fBalance=money+150;
	}
	strcpy(card.aName,name);
	strcpy(card.aPwd,password);
	strcpy(card.aId,id);
	card.fTotalUse=0;
	card.nStatus=0;
	card.nDel=0;
	card.nUseCount=0;
	card.tStart = card.tEnd = card.tLast = time(NULL); 
	// 开卡时间，截止时间，最后使用时间都默认为当前时间。
	// 根据开卡时间，计算截止时间，每张卡的有效期为一年
	startTime = localtime(&card.tStart);
	endTime = localtime(&card.tEnd);
	endTime->tm_year = startTime->tm_year + 1;
	card.tEnd = mktime(endTime);
	success=addCard(card);
	if(success==FALSE){
	printf("\n\n添加失败!\n\n");
	}
	else{
	printf("\n添加成功!");
	printf("\n\n添加卡的信息如下\n");
	printf("卡号\t\t密码\t\t状态\t\t开卡金额\n");
	if(money<100)
	printf("%s\t\t%s\t\t%d\t\t%.2f\n",card.aName,card.aPwd,card.nStatus,money);
	if(money>=100&&money<300)
	printf("%s\t\t%s\t\t%d\t\t%.2f\n",card.aName,card.aPwd,card.nStatus,money+10);
	if(money>=300&&money<500)
	printf("%s\t\t%s\t\t%d\t\t%.2f\n",card.aName,card.aPwd,card.nStatus,money+50);
	if(money>=500)
	printf("%s\t\t%s\t\t%d\t\t%.2f\n",card.aName,card.aPwd,card.nStatus,money+150);
	}
}

/*查询卡*/
void query(){
	int j=0;
	char aname[18];
	char apwd[8];
	char name[18];
	char pname[1000];
	char password[8];
	char ppassword[1000];
	char nTime[20];
	Card *qCard;
	int pIndex=0;
	int i;
	int k=-1;
	//lpCardNode pCard;
	printf("此功能仅允许管理员操作\n");
	printf("请输入管理员账号：");
	scanf("%s",aname);
	printf("请输入管理员密码：");
	scanf("%s",apwd);
	k=manager(aname,apwd);
	if(k==1)
	{
	printf("\n----------查询卡---------\n");
	printf("如需进行精确查询请输入1；模糊查询请输入2：");
	scanf("%d",&j);
	if(j!=1&&j!=2)
	{
		printf("无此功能，自动为您跳转至菜单！\n");
	}
	else
	{
	printf("请输入查询的卡号<长度为1-18>:");
	scanf("%s",pname);
	if(checklength(pname)>18)
	{printf("卡号超出18位，请重新输入\n");
	return;
	}
	else{
	strcpy(name,pname);
	}
	

	//     精确查询
	if(j==1)
	{
	qCard=queryCard(name);
	if(qCard==NULL)
	{
		printf("未查询到此卡信息\n");
	}
	else
	{
		printf("\n查询到的卡信息如下：\n");
		timeToString(qCard->tLast,nTime);
		printf("卡号\t\t状态\t\t累计使用\t\t余额\t\t使用次数\t\t上次使用时间\n");
		printf("%s\t\t%d\t\t%.2f\t\t\t%.2f\t\t%d\t\t\t%s\n",qCard->aName,qCard->nStatus,qCard->fTotalUse,qCard->fBalance,qCard->nUseCount,nTime);
	}
	}
	/*模糊查询*/
	if(j==2)
	{
	qCard=queryCards(name,&pIndex);
	if(qCard==NULL)
	{
		printf("未查到相关卡信息\n");
	}
	else
	{
		printf("\n查询到的卡信息如下：\n");
		printf("卡号\t\t状态\t\t余额\t\t累计使用\t\t使用次数\t\t上次使用时间\n");
		for(i=0;i<pIndex;i++)
		{
		timeToString(qCard[i].tLast,nTime);
		printf("%s\t\t%d\t\t%.2f\t\t%.2f\t\t\t%d\t\t\t%s\n",qCard[i].aName,qCard[i].nStatus,qCard[i].fBalance,qCard[i].fTotalUse,qCard[i].nUseCount,nTime);
		}
	}
	}
	}
	}
	if(k!=1)
	{
		printf("管理员账号或密码输入错误,无法进行此操作！");
	}
	
}

/*上机函数*/
void logon()
{	
	char aName[18]={0};
	char aPwd[8]={0};
	int nResult=0;
	LogonInfo* pInfo=NULL;
	char aTime[TIMELENGTH]={0};
	printf("\n----------上机----------\n");
	printf("请输入上机卡号（长度为1-18）：");
	scanf("%s",&aName);
	printf("请输入上机密码（长度为1-8）：");
	scanf("%s",&aPwd);
	pInfo=(LogonInfo*)malloc(sizeof(LogonInfo));
	nResult=doLogon(aName,aPwd,pInfo);
	switch(nResult)
	{
	case 0:
		printf("上机失败\n");
		break;

    case 1:
		printf("卡号\t余额\t上机时间\n");
		timeToString(pInfo->tLogon,aTime);
		printf("%s\t%.2f\t%s\n",pInfo->aCardName,pInfo->fBalance,aTime);
		break;
	case 2:
		printf("该卡正在上机或者已经注销\n");
		break;
	case 3:
		printf("卡余额不足\n");
		break;
	case 4:
		printf("此卡已经挂失\n");
		break;
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
	printf("请输入下机卡号（长度为1-18）：");
	scanf("%s",&aName);
	printf("请输入下机密码（长度为1-8）：");
	scanf("%s",&aPwd);
	pInfo=(SettleInfo*)malloc(sizeof(SettleInfo));
	nResult=doSettle(aName,aPwd,pInfo);
	switch(nResult)
	{
	case 0:
		printf("未查到该卡上机信息，下机失败\n");
		break;

    case 1:
		timeToString(pInfo->tEnd,aTime2);
		printf("\n----------下机信息如下----------\n");
		printf("卡号\t消费\t余额\t下机时间\n");
		printf("%s\t%.2f\t%.2f\t%s\n",pInfo->aCardName,pInfo->fAmount,pInfo->fBalance,aTime2);
		break;
	case 2:
		printf("未查到该卡上机信息，下机失败\n");
		break;

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
	printf("\n----------充值----------\n");
	printf("请输入账号：");
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



void refundMoney(){
	char aName[18] = {0};
	char aPwd[8] = {0};
	printf("\n----------退费----------\n");
	printf("请输入账号：");
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
void master()
{
	int Index=0;
	char aname[18];
	char apwd[8];
	char aName[18] = {0};
	char aPwd[8] = {0};
	Card *temp;
	Card card;
	Card *pCard;
	int nIndex=0;
	int c=0; // 文件结构体指针
	int k=-1;
	struct tm* endTime;     // 截止时间
	struct tm* startTime;   // 开卡时间
	FILE* fp = NULL; 
	printf("此功能仅允许管理员操作\n");
	printf("请输入管理员账号：");
	scanf("%s",aname);
	printf("请输入管理员密码：");
	scanf("%s",apwd);
	k=manager(aname,apwd);
	if(k==1)
	{
	printf("\n--------挂失卡--------\n");
	 printf("请输入卡号(长度为1~18)：");
	 scanf("%s",aName);
	 printf("请输入密码(长度为1~8)：");
	 scanf("%s",aPwd);
	 temp=checkCard(aName,aPwd,&nIndex);
	  if(temp==NULL)
	 {
		 printf("账号或密码输入错误！\n");
	 }
	  else
	  {
	 if(temp->nStatus==2||temp->nStatus==3)
	 {
		printf("此卡已经注销或失效不能进行此操作！");
	 }
	 else
	 {
		 temp->nStatus=4;
		 printf("挂失成功，挂失期间无法进行除激活以外的一切操作！");
		updateCard(temp, CARDPATH, nIndex);
	 }
	  }
	}
	if(k!=1)
	{
		printf("管理员账号或密码输入错误,无法进行此操作！");
	}
}
void annul(){
	char aName[32] = {0};
	char aPwd[20] = {0};
	printf("\n----------注销----------\n");
	printf("\n请输入账号：");
	scanf("%s",aName);
	printf("\n请输入密码：");
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

void revise()
{
	char aName[18]={0};
	char password[8];
	char ppassword[1000];
	int nIndex=0;
	Card *pCard;
	printf("\n--------修改密码-------\n");
		//查询密码
	printf("请输入卡号：");
	scanf("%s",aName);
	printf("请输入原始密码<长度为1-8>:");
	scanf("%s",password);
	pCard=checkCard(aName,password,&nIndex);	
	if(pCard!=NULL)
	{
		if(pCard->nStatus==4)
		{
			printf("此卡已经挂失无法进行操作");
		}
		else
		{
			printf("请输入新密码：");
			scanf("%s",ppassword);
		if(checklength(ppassword)>8)
		{
			printf("密码超出8位，请重新输入\n");
			return;
		}
		else
		{
			strcpy(pCard->aPwd,ppassword);
			updateCard(pCard,CARDPATH,nIndex);
		}
		}
	}
	if(pCard==NULL)
	{
		printf("卡号或密码输入错误！\n");
	}
}



void find()
{
	char aName[18]={0};
	char aId[20]={0};
	Card *pCard=NULL;
	int i=-1;
	printf("\n--------找回密码-------\n");
	printf("请输入卡号：");
	scanf("%s",aName);
	printf("请输入本卡绑定身份证号：");
	scanf("%s",aId);
	i=doFind(aName,aId);
	if(i==1)
	{
		pCard=queryCard(aName);
		if(pCard->nStatus==4)
	{
		printf("此卡已经挂失无法进行操作");
	}
		else
		{
		printf("您的密码为：%s",pCard->aPwd);
		}
	}
	if(i!=1)
	{
		printf("卡号与身份证信息不符，无法查询！");
	}
}


void refresh()
{
	int Index=0;
	char aname[18];
	char apwd[8];
	char aName[18] = {0};
	char aPwd[8] = {0};
	Card *temp;
	Card card;
	Card *pCard;
	int nIndex=0;
	int c=0; // 文件结构体指针
	int k=-1;
	struct tm* endTime;     // 截止时间
	struct tm* startTime;   // 开卡时间
	FILE* fp = NULL; 
	printf("此功能仅允许管理员操作\n");
	printf("请输入管理员账号：");
	scanf("%s",aname);
	printf("请输入管理员密码：");
	scanf("%s",apwd);
	k=manager(aname,apwd);
	if(k==1)
	{
	printf("\n--------激活卡--------\n");
	 printf("请输入卡号(长度为1~18)：");
	 scanf("%s",aName);
	 printf("请输入密码(长度为1~8)：");
	 scanf("%s",aPwd);
	 temp=checkCard(aName,aPwd,&nIndex);
	 if(temp==NULL)
	 {
		 printf("账号或密码输入错误！\n");
	 }
	 else
	 {
	 if(temp->nStatus!=4)
	 {
		printf("此卡没有挂失不能进行此操作！\n");
	 }
	 else
	 {
		 temp->nStatus=0;
		 printf("激活成功，可以正常使用其他操作！");
		updateCard(temp, CARDPATH, nIndex);
	 }
	}
	}
	if(k!=1)
	{
		printf("管理员账号或密码输入错误,无法进行此操作！");
	}
}


void exitApp()
{
	char name[18];
	char nTime[20];
	Card *qCard;
	int i=0;
	int j=0;
	printf("隐藏查看所有资料选项（仅供测试用上线即删）：如需测试请输入1：");
	scanf("%d",&i);
	if(i==1)
	{
	printf("请输入查询的卡号<长度为1-18>:");
	scanf("%s",name);
	qCard=queryCard(name);
	if(qCard==NULL)
	{
		printf("未查询到此卡信息\n");
	}
	else
	{
		printf("\n查询到的卡信息如下：\n");
		printf("卡号\t密码\t状态\t\t累计使用\t\t余额\t\t身份证号\n");
		printf("%s\t%s\t%d\t\t%.2f\t\t\t%.2f\t\t%s\n",qCard->aName,qCard->aPwd,qCard->nStatus,qCard->fTotalUse,qCard->fBalance,qCard->aId);
	}
	}
		printf("是否退出：是（1）否（0）：");
		scanf("%d",&j);
		if(j==1)
		{
			releaseCardList();/*释放链表空间*/
			exit(0);
		}
}








int checklength(char aa[])
{
	int count =0;
	while(aa[count]!='\0'){
	count++;
	}
	return count;
}
