#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<time.h>
#include"model.h"
#include"card_service.h"
#include<string.h>
#include"tool.h"
int getSize(char *pInfo);
void copy(const char Input[], char Output[], int size);
void outputMenu()
{
	printf("----------�˵�----------\n");
	printf("1.��ӿ�\n");
	printf("2.��ѯ��\n");
	printf("3.�ϻ�\n");
	printf("4.�»�\n");
	printf("5.��ֵ\n");
	printf("6.�˷�\n");
	printf("7.��ѯͳ��\n");
	printf("8.ע����\n");
	printf("0.�˳�\n");
	printf("��ѡ��˵����:\n");
}
