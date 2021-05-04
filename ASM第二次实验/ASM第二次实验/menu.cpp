#define _CRT_SECURE_NO_WARNINGS//����scanf����
#include"stdio.h"
#include"stdlib.h"
#include "string.h"
#include"menu.h"
#include"card.h"
Card *card = initial();
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
		printf("0.�˳�\n");
		printf("������0-8����������ѡ��\n");
		scanf("%c", &i);
		switch (i) {
		case '0': {
			exit(0);
			break;
		}
		case '1': {
			add();
			break;
		}
		case '2': {
			query();
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

void add() {
	system("cls");
	printf("����Ϊ��ӿ��Ĳ˵�����\n");
	printf("�����뿨��(����1-18):\n");
	char no[50];
	scanf("%s", no);
	while (strlen(no) > 18 || queryCard(card, no) != NULL) {
		if (strlen(no) > 18) printf("���ų���18λ�����������뿨��(����1-18):\n");
		else printf("�ÿ����Ѵ������������뿨��(����1-18):\n");
		scanf("%s", no);
	}
	char pwd[30];
	printf("����������(����1-8):\n");
	scanf("%s", pwd);
	while (strlen(pwd) > 8) {
		printf("���볬��8λ����������������(����1-8):\n");
		scanf("%s", pwd);
	}
	float balance;
	printf("�����뿪�����(�����):\n");
	scanf("%f", &balance);
	printf("��ӿ�����Ϣ����:\n");
	printf("����\t����\t״̬\t���\n");
	printf("%s\t%s\t0\t%.1f\n", no, pwd, balance);
	addCard(card, no, pwd, balance);
	int i;
	printf("1.�������\n");
	printf("2.�����ϼ��˵�\n");
	printf("0.�˳�\n");
	scanf("%d", &i);
	switch (i) {
	case 0: {
		exit(0); break;
	}
	case 1: {
		add(); break;
	}
	case 2: {
		break;
	}
	}
}

void query() {
	system("cls");
	printf("����Ϊ��ѯ���Ĳ˵�����\n");
	printf("�����뿨��(����1-18):\n");
	char no[50];
	scanf("%s", no);
	while (strlen(no) > 18 || queryCard(card, no) == NULL) {
		if (strlen(no) > 18) printf("���ų���18λ�����������뿨��(����1-18):\n");
		else printf("�ÿ��Ų��������������뿨��(����1-18):\n");
		scanf("%s", no);
	}
	Card *t = queryCard(card, no);
	printf("��ѯ������Ϣ����:\n");
	printf("����\t����\t״̬\t���\n");
	printf("%s\t%s\t%d\t%.1f\n", t->aName, t->aPwd, t->nStatus, t->fBalance);
	int i;
	printf("1.������ѯ\n");
	printf("2.�����ϼ��˵�\n");
	printf("0.�˳�\n");
	scanf("%d", &i);
	switch (i) {
	case 0: {
		exit(0); break;
	}
	case 1: {
		query(); break;
	}
	case 2: {
		break;
	}
	}
}
