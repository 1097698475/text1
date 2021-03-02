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
		//1.��ӡһ������
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)//���һ�в���ӡ  |
				printf("|");
		}
		printf("\n");//��ӡ��һ��Ҫ����
		//2.��ӡ�ָ���
		if (i < row - 1)//���һ�в���ӡ
		{
			//��ӡ�ָ���
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)//���һ�в���ӡ | 
					printf("|");
			}
			printf("\n");//��ӡ��һ��Ҫ����
		}
	}
}

void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����ߣ�\n");
	while (1)
	{
		printf("������Ҫ�µ�����: ");
		scanf("%d %d", &x, &y);
		//�ж��������������
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			//���¹��Ĳ�������
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ�ã�\n\n");
			}
		}
		else
		{
			printf("����Ƿ������������룡\n\n");
		}
	}
}

void computermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("�����ߣ�\n");
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

//����1��ʾ�������ˣ����ر�ʾû��
int isfull(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;//û��
		}
	}
	return 1;//����
}


char iswin(char board[ROW][COL], int row, int col)
{
	int i;
	//���Ӯ����
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][1];//�����Ͳ��÷��ǵ���Ӯ�������Ӯ
	}
	//����Ӯ����
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	//�����Խ��ߵ�Ӯ����
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//�ж��Ƿ�ƽ��
	if (1 == isfull(board, ROW, COL))
	{
		return 'q';
	}
	return 'c';
}
