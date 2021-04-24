#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<time.h>
#include"model.h"
#include"card_service.h"
#include<string.h>
#include"tool.h"
int getSize(char *pInfo);
void copy(const char Input[], char Output[], int size);
void outputMenu()
{
	printf("----------菜单----------\n");
	printf("1.添加卡\n");
	printf("2.查询卡\n");
	printf("3.上机\n");
	printf("4.下机\n");
	printf("5.充值\n");
	printf("6.退费\n");
	printf("7.查询统计\n");
	printf("8.注销卡\n");
	printf("0.退出\n");
	printf("请选择菜单编号:\n");
}
