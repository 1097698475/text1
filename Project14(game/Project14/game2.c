#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void displayboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		//1.打印一行数据
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)//最后一列不打印  |
				printf("|");
		}
		printf("\n");//打印完一行要换行
		//2.打印分割行
		if (i < row - 1)//最后一行不打印
		{
			//打印分割行
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)//最后一列不打印 | 
					printf("|");
			}
			printf("\n");//打印完一行要换行
		}
	}
}

void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走：\n");
	while (1)
	{
		printf("请输入要下的坐标: ");
		scanf("%d %d", &x, &y);
		//判断输入坐标合理性
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			//被下过的不能再下
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用！\n\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n\n");
		}
	}
}

void computermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("电脑走：\n");
	for (int i = 0;; i++)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//返回1表示棋盘满了，返回表示没满
int isfull(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;//没满
		}
	}
	return 1;//满了
}


char iswin(char board[ROW][COL], int row, int col)
{
	int i;
	//横的赢法则
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][1];//这样就不用分是电脑赢还是玩家赢
	}
	//竖的赢法则
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	//两个对角线的赢法则
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//判断是否平局
	if (1 == isfull(board, ROW, COL))
	{
		return 'q';
	}
	return 'c';
}
