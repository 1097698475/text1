#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"menu.h"
#include"model.h"


int main()
{
	int nSelection = -1;

	//ͷ����
	printf("\n");
	printf("��ӭ�Ʒѹ���ϵͳ\n");
	printf("\n");

	do
	{
		printf("\n");
		//����˵�
		outputMenu();

		//�����û�����Ĳ˵����
		scanf("%d", &nSelection);

		//�������������
		fflush(stdin);

		//todo
		switch (nSelection)
		{
		case 1:
			//printf("��ӿ�\n");
			add();
			break;
		case 2:
			//printf("��ѯ��\n");
			query();
			break;
		case 3:
			printf("�ϻ�\n");
			break;
		case 4:
			printf("�»�\n");
			break;
		case 5:
			printf("��ֵ\n");
			break;
		case 6:
			printf("�˷�\n");
			break;
		case 7:
			printf("��ѯͳ��\n");
			break;
		case 8:
			printf("ע����\n");
			break;
		case 0:
			{
				exitApp();
				printf("�˳�\n");
				break;
			}
		default:
			{
				printf("������Ĳ˵���Ŵ���!\n");
				break;
			}
		}
	} while (nSelection != 0);
	return 0;
}