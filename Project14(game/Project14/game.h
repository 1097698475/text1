#pragma once
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//声明
void initboard(char board[ROW][COL], int row, int col);
void displayboard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);

//告诉我们四种状态
//玩家WIN    *(后面会讲为什么这样
//电脑WIN    #
//平局       q
//继续       c
char iswin(char board[ROW][COL], int row, int col);
