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
	printf("ɨ�׿�ʼ\n");
	//�׵���Ϣ����
	//1.���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };//ע����ROWS,��Ϊ�߱ߵ�Ԫ���ж���Ҫ������һ��
	//2.�Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ����
	initboard(mine, ROWS, COLS, '0');//����0�ǣ�0,���ǿո�
	initboard(show, ROWS, COLS, '*');//show��������ʾ����ҵģ���*
	//��ӡ����
	//displayboard(mine, ROW, COL);//ע����ROW,���һ����Ҫ��ӡ�������ǳ�ʼֵ�ַ�
	displayboard(show, ROW, COL);
	//������
	setmine(mine,ROW,COL);//mine���̲��Ǹ���ҿ��ģ�����ֻ��0��1
	displayboard(mine, ROW, COL);
	//ɨ��
	findmine(mine,show,ROW,COL);//��Ҫ����mine���飬��Ҫ����show����

}

void text()
{
	int input;
	srand((unsigned int)time(NULL));//����ʱ�����ע��ŵ�λ��
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
	    switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}

int main()
{
	text();
	return 0;
}