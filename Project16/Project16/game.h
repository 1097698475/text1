#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#include<stdio.h>
#define EASY 80

void initboard(char board[ROWS][COLS], int rows, int cols,char set);
void displayboard(char board[ROWS][COLS], int row, int col);//�����boardҲҪROWS����Ϊԭ���趨����ROWS��
void setmine(char board[ROWS][COLS], int row, int col);
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//����׵���Ϣ    �Ų�������׵���Ϣ�ٴ�ӡ����