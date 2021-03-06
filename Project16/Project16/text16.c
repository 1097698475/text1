#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"

void menu()
{
	printf("******************************\n");
	printf("********   1. play   *********\n");
	printf("********   0. exit   *********\n");
	printf("******************************\n");
}

void game()
{
	printf("扫雷开始\n");
	//雷的信息储存
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };//注意是ROWS,因为边边的元素判断需要再扩充一格
	//2.排查出的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始棋盘
	initboard(mine, ROWS, COLS, '0');//输入0是？0,不是空格
	initboard(show, ROWS, COLS, '*');//show棋盘是显示给玩家的，故*
	//打印棋盘
	//displayboard(mine, ROW, COL);//注意是ROW,多的一格不需要打印出来，是初始值字符
	displayboard(show, ROW, COL);
	//布置雷
	setmine(mine,ROW,COL);//mine棋盘不是给玩家看的，里面只有0和1
	displayboard(mine, ROW, COL);
	//扫雷
	findmine(mine,show,ROW,COL);//既要操作mine数组，又要操作show数组

}

void text()
{
	int input;
	srand((unsigned int)time(NULL));//生成时间戳，注意放的位置
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
	    switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}

int main()
{
	text();
	return 0;
}