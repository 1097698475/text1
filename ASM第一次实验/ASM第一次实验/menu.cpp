#define _CRT_SECURE_NO_WARNINGS//����scanf����
#include"stdio.h"
#include"stdlib.h"
#include"menu.h"
void outputmenu() {
	do {
		char i;
		printf("����Ϊ���˻�����ϵͳ�Ĳ˵�����\n");
		printf("1.��ӿ�\n");
		printf("2.��ѯ��\n");
		printf("3.�ϻ�\n");
		printf("4.�»�\n");
		printf("5.��ֵ\n");
		printf("6.�˷�\n");
		printf("7.��ѯͳ��\n");
		printf("8.ע����\n");
		printf("������1-8����������ѡ������0�˳�\n");
		scanf("%c", &i);
		switch (i) {
		case '0': {
			exit(0);
			break;
		}
		case '1': {
			system("cls");
			printf("����Ϊ��ӿ��Ĳ˵�����\n");
			system("pause");
			/*
			��ӿ�
			*/
			break;
		}
		case '2': {
			system("cls");
			printf("����Ϊ��ѯ���Ĳ˵�����\n");
			system("pause");
			/*
			��ѯ��
			*/
			break;
		}
		case '3': {
			system("cls");
			printf("����Ϊ�ϻ��Ĳ˵�����\n");
			system("pause");
			/*
			�ϻ�
			*/
			break;
		}
		case '4': {
			system("cls");
			printf("����Ϊ�»��Ĳ˵�����\n");
			system("pause");
			/*
			�»�
			*/
			break;
		}
		case '5': {
			system("cls");
			printf("����Ϊ��ֵ�Ĳ˵�����\n");
			system("pause");
			/*
			��ֵ
			*/
			break;
		}
		case '6': {
			system("cls");
			printf("����Ϊ�˷ѵĲ˵�����\n");
			system("pause");
			/*
			�˷�
			*/
			break;
		}
		case '7': {
			system("cls");
			printf("����Ϊ��ѯͳ�ƵĲ˵�����\n");
			system("pause");
			/*
			��ѯͳ��
			*/
			break;
		}
		case '8': {
			system("cls");
			printf("����Ϊע�����Ĳ˵�����\n");
			system("pause");
			/*
			ע��
			*/
			break;
		}
		default: {
			system("cls");
			printf("��������ȷ��1-8����\n");
			break;
		}
		}
	} while (1);
}

