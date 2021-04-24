#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include"menu.h"  //用户自定义函数
#include<time.h>
#include"tool.h"
#include<string.h>

int main() 
{
	int nSelection = -1;
	printf("欢迎来到计费管理系统\n");
	do
	{
		outputMenu();
		scanf("%d", &nSelection);
		switch (nSelection)
		{
		case 1:
		{
			printf("添加卡\n");
			break;
		}
		case 2:
		{
			printf("查询卡\n");
			break;
		}
		case 3:printf("上机\n"); break;
		case 4:printf("下机\n"); break;
		case 5:printf("充值\n"); break;
		case 6:printf("退费\n"); break;
		case 7:printf("查询统计\n"); break;
		case 8:printf("注销卡\n"); break;
		case 0:printf("退出\n"); break;
		default:printf("输入的菜单序号错误！\n"); break;
		}
		printf("\n");
	} while (nSelection != 0);
	system("pause");
	return 0;
}