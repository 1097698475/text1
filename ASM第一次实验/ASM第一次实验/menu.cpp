#define _CRT_SECURE_NO_WARNINGS//消除scanf警告
#include"stdio.h"
#include"stdlib.h"
#include"menu.h"
void outputmenu() {
	do {
		char i;
		printf("以下为本账户管理系统的菜单界面\n");
		printf("1.添加卡\n");
		printf("2.查询卡\n");
		printf("3.上机\n");
		printf("4.下机\n");
		printf("5.充值\n");
		printf("6.退费\n");
		printf("7.查询统计\n");
		printf("8.注销卡\n");
		printf("请输入1-8数字来进行选择，输入0退出\n");
		scanf("%c", &i);
		switch (i) {
		case '0': {
			exit(0);
			break;
		}
		case '1': {
			system("cls");
			printf("以下为添加卡的菜单界面\n");
			system("pause");
			/*
			添加卡
			*/
			break;
		}
		case '2': {
			system("cls");
			printf("以下为查询卡的菜单界面\n");
			system("pause");
			/*
			查询卡
			*/
			break;
		}
		case '3': {
			system("cls");
			printf("以下为上机的菜单界面\n");
			system("pause");
			/*
			上机
			*/
			break;
		}
		case '4': {
			system("cls");
			printf("以下为下机的菜单界面\n");
			system("pause");
			/*
			下机
			*/
			break;
		}
		case '5': {
			system("cls");
			printf("以下为充值的菜单界面\n");
			system("pause");
			/*
			充值
			*/
			break;
		}
		case '6': {
			system("cls");
			printf("以下为退费的菜单界面\n");
			system("pause");
			/*
			退费
			*/
			break;
		}
		case '7': {
			system("cls");
			printf("以下为查询统计的菜单界面\n");
			system("pause");
			/*
			查询统计
			*/
			break;
		}
		case '8': {
			system("cls");
			printf("以下为注销卡的菜单界面\n");
			system("pause");
			/*
			注销
			*/
			break;
		}
		default: {
			system("cls");
			printf("请输入正确的1-8数字\n");
			break;
		}
		}
	} while (1);
}

