#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//���Ծ�����
void menu()
{
	printf("***********************************\n");
	printf("***********************************\n");
	printf("*****  1. play       0. exit  *****\n");
	printf("***********************************\n");
	printf("***********************************\n\n\n");
}


//��Ϸ������ʵ��
void game()
{
	char ret;

	//�������߳���������Ϣ
	char board[ROW][COL] = { 0 };//���ѡһ��ֵ
	//��ʼ�����̳ɿո�
	initboard(board, ROW, COL);
	//��ӡ����
	displayboard(board, ROW, COL);
	//����
	for(int i=0;;i++)
	{
		//�������
		playermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = iswin(board,ROW,COL);//�ж���Ϸ����OR����
		printf("\n\n\n");
		if (ret != 'c')
			break;
		//��������
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = iswin(board,ROW,COL);
		printf("\n\n\n");
		if (ret != 'c')
			break;
	}
	if (ret == '*')
	{
		printf("��Ӯ�ˣ�\n\n\n\n\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ�ˣ�\n\n\n\n\n");
	}
	else
	{
		printf("ƽ��\n\n\n\n\n");
	}
}


void text()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("\n\n\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n\n\n");
			break;
		}
	} while (input!=0);
}


int main()
{
	text();
	return 0;
}