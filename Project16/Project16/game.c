#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//��ӡ�к�
	printf("  ");
	for (i = 1; i <= col; i++)
		printf(" %d ", i);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		//��ӡ�к�
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
}

void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY;
	while (count != 0)
	{
		int x = rand() % row+1;//1--9
		int y = rand() % col+1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//'1'-'0'=1 ��Ϊ'1'=49,'0'=48       '3'-'0'=3
int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;
	while(win<row*col-EASY)
	{
		printf("�������Ų��׵����꣺");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����Ϸ�
			//1.����
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				displayboard(mine, row, col);//�൱�ڰѴ𰸴�ӡ������
				break;
			}
			else//������
			{
				//����x,y������Χ�м�����
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				displayboard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("��������Ƿ�������������\n");
		}
	}
	if (win == row * col - EASY)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		displayboard(show, row, col);
	}
}
