#define _CRT_SECURE_NO_WARNINGS//消除scanf警告
#include"stdio.h"
#include"stdlib.h"
#include "string.h"
#include"menu.h"
#include"card.h"
Card *card = initial();
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
		printf("0.退出\n");
		printf("请输入0-8数字来进行选择\n");
		scanf("%c", &i);
		switch (i) {
		case '0': {
			exit(0);
			break;
		}
		case '1': {
			add();
			break;
		}
		case '2': {
			query();
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

void add() {
	system("cls");
	printf("以下为添加卡的菜单界面\n");
	printf("请输入卡号(长度1-18):\n");
	char no[50];
	scanf("%s", no);
	while (strlen(no) > 18 || queryCard(card, no) != NULL) {
		if (strlen(no) > 18) printf("卡号超过18位，请重新输入卡号(长度1-18):\n");
		else printf("该卡号已存在请重新输入卡号(长度1-18):\n");
		scanf("%s", no);
	}
	char pwd[30];
	printf("请输入密码(长度1-8):\n");
	scanf("%s", pwd);
	while (strlen(pwd) > 8) {
		printf("密码超过8位，请重新输入密码(长度1-8):\n");
		scanf("%s", pwd);
	}
	float balance;
	printf("请输入开卡金额(人民币):\n");
	scanf("%f", &balance);
	printf("添加卡的信息如下:\n");
	printf("卡号\t密码\t状态\t金额\n");
	printf("%s\t%s\t0\t%.1f\n", no, pwd, balance);
	addCard(card, no, pwd, balance);
	int i;
	printf("1.继续添加\n");
	printf("2.返回上级菜单\n");
	printf("0.退出\n");
	scanf("%d", &i);
	switch (i) {
	case 0: {
		exit(0); break;
	}
	case 1: {
		add(); break;
	}
	case 2: {
		break;
	}
	}
}

void query() {
	system("cls");
	printf("以下为查询卡的菜单界面\n");
	printf("请输入卡号(长度1-18):\n");
	char no[50];
	scanf("%s", no);
	while (strlen(no) > 18 || queryCard(card, no) == NULL) {
		if (strlen(no) > 18) printf("卡号超过18位，请重新输入卡号(长度1-18):\n");
		else printf("该卡号不存在请重新输入卡号(长度1-18):\n");
		scanf("%s", no);
	}
	Card *t = queryCard(card, no);
	printf("查询卡的信息如下:\n");
	printf("卡号\t密码\t状态\t金额\n");
	printf("%s\t%s\t%d\t%.1f\n", t->aName, t->aPwd, t->nStatus, t->fBalance);
	int i;
	printf("1.继续查询\n");
	printf("2.返回上级菜单\n");
	printf("0.退出\n");
	scanf("%d", &i);
	switch (i) {
	case 0: {
		exit(0); break;
	}
	case 1: {
		query(); break;
	}
	case 2: {
		break;
	}
	}
}
