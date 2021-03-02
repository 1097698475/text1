#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//测试井字棋
void menu()
{
	printf("***********************************\n");
	printf("***********************************\n");
	printf("*****  1. play       0. exit  *****\n");
	printf("***********************************\n");
	printf("***********************************\n\n\n");
}


//游戏的整个实现
void game()
{
	char ret;

	//数组存放走出的棋盘信息
	char board[ROW][COL] = { 0 };//随便选一个值
	//初始化棋盘成空格
	initboard(board, ROW, COL);
	//打印棋盘
	displayboard(board, ROW, COL);
	//下棋
	for(int i=0;;i++)
	{
		//玩家下棋
		playermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//判断玩家是否赢
		ret = iswin(board,ROW,COL);//判断游戏结束OR继续
		printf("\n\n\n");
		if (ret != 'c')
			break;
		//电脑下棋
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//判断电脑是否赢
		ret = iswin(board,ROW,COL);
		printf("\n\n\n");
		if (ret != 'c')
			break;
	}
	if (ret == '*')
	{
		printf("你赢了！\n\n\n\n\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了！\n\n\n\n\n");
	}
	else
	{
		printf("平局\n\n\n\n\n");
	}
}


void text()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("\n\n\n");
			game();
			break;
		case 0:
			printf("退出游戏\n\n");
			break;
		default:
			printf("选择错误，请重新选择！\n\n\n");
			break;
		}
	} while (input!=0);
}


int main()
{
	text();
	return 0;
}