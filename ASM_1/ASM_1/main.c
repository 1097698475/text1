#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include"menu.h"  //�û��Զ��庯��
#include<time.h>
#include"tool.h"
#include<string.h>

int main() 
{
	int nSelection = -1;
	printf("��ӭ�����Ʒѹ���ϵͳ\n");
	do
	{
		outputMenu();
		scanf("%d", &nSelection);
		switch (nSelection)
		{
		case 1:
		{
			printf("��ӿ�\n");
			break;
		}
		case 2:
		{
			printf("��ѯ��\n");
			break;
		}
		case 3:printf("�ϻ�\n"); break;
		case 4:printf("�»�\n"); break;
		case 5:printf("��ֵ\n"); break;
		case 6:printf("�˷�\n"); break;
		case 7:printf("��ѯͳ��\n"); break;
		case 8:printf("ע����\n"); break;
		case 0:printf("�˳�\n"); break;
		default:printf("����Ĳ˵���Ŵ���\n"); break;
		}
		printf("\n");
	} while (nSelection != 0);
	system("pause");
	return 0;
}