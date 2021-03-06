#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#include<stdio.h>
#define EASY 80

void initboard(char board[ROWS][COLS], int rows, int cols,char set);
void displayboard(char board[ROWS][COLS], int row, int col);//这里的board也要ROWS，因为原来设定就是ROWS行
void setmine(char board[ROWS][COLS], int row, int col);
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//存放雷的信息    排查出来的雷的信息再打印出来