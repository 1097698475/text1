#ifndef MENU_H
#define MENU_H


void outputMenu();			//输出主菜单

void add();					//1 添加卡

void query();				//2 查询

void logon();				//3 上机

void settle();				//4下机

void addMoney();			//5 充值

void refundMoney();			//6 退费

void queryStatistics();		//7 查询统计

void annul();				//8 注销

void findpwd();				//9 找回密码

void alterpwd();			//10 修改密码

void exitApp();				//0 退出

int getlength(const char* pInfo);
//int getlength(char aa[]);		//声明函数 计算输入的密码、 卡号的位数

int id();		//声明管理员权限


#endif