#ifndef MENU_H
#define MENU_H


void outputMenu();			//������˵�

void add();					//1 ��ӿ�

void query();				//2 ��ѯ

void logon();				//3 �ϻ�

void settle();				//4�»�

void addMoney();			//5 ��ֵ

void refundMoney();			//6 �˷�

void queryStatistics();		//7 ��ѯͳ��

void annul();				//8 ע��

void findpwd();				//9 �һ�����

void alterpwd();			//10 �޸�����

void exitApp();				//0 �˳�

int getlength(const char* pInfo);
//int getlength(char aa[]);		//�������� ������������롢 ���ŵ�λ��

int id();		//��������ԱȨ��


#endif