#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>

#include"menu.h"
#include"model.h"
#include"tool.h"
#include"card_service.h"
#include"card_file.h"

int main(void){
	int nSelection=-1;
	char rubbish[1000];
	int i;

	printf("\n--------欢迎进入计费管理系统--------！\n");
	printf("\n");
	printf("*****开业充值优惠多多*****\t\n*****开业期间 开卡每满100加赠50 充值每满100加赠20 上不封顶*****\n");
	printf("\n");

    initCardList();/*初始化链表*/

	do{

		outputMenu();	//输出菜单
		nSelection=-1;
		i = scanf("%d",&nSelection);

		//防止输入错的编号全盘崩掉 T.T 
		while(i==0)
		{
			 // 清空缓冲区
			 scanf("%s", rubbish); 
			 printf("\n\n请输入正确的菜单编号:\n\n ");
			 i=scanf("%d",& nSelection);
		}
	

		//根据编号执行
		switch(nSelection){
		case 1:
			add();			//添加卡
			break;
		case 2:
			 query();		//查询卡
			break;
		case 3:
		    logon();		//上机
			break;
        case 4:
			settle();		//下机
			break;
		case 5:
		    addMoney();		//充值
			break;
		case 6:				//退费
		    refundMoney();
			break;
        case 7:				//查询统计
			queryStatistics();
			break;
        case 8:				//注销
			annul();
			break;
		case 9:				//查询密码
			findpwd();
			break;
		case 10:			//修改密码
			alterpwd();
			break;
		case 0:				//退出
			exitApp();
			break;
		default:printf("\n\n请输入正确的菜单编号:");break;
		}
	}while(nSelection!=0);
	return 0;
}



