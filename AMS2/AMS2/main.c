#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"menu.h"
#include"model.h"


int main()
{
	int nSelection = -1;

	//头界面
	printf("\n");
	printf("欢迎计费管理系统\n");
	printf("\n");

	do
	{
		printf("\n");
		//输出菜单
		outputMenu();

		//接受用户输入的菜单编号
		scanf("%d", &nSelection);

		//清除输入流缓存
		fflush(stdin);

		//todo
		switch (nSelection)
		{
		case 1:
			//printf("添加卡\n");
			add();
			break;
		case 2:
			//printf("查询卡\n");
			query();
			break;
		case 3:
			printf("上机\n");
			break;
		case 4:
			printf("下机\n");
			break;
		case 5:
			printf("充值\n");
			break;
		case 6:
			printf("退费\n");
			break;
		case 7:
			printf("查询统计\n");
			break;
		case 8:
			printf("注销卡\n");
			break;
		case 0:
			{
				exitApp();
				printf("退出\n");
				break;
			}
		default:
			{
				printf("您输入的菜单编号错误!\n");
				break;
			}
		}
	} while (nSelection != 0);
	return 0;
}