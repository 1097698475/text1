define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdbool.h>

//下面三种方法是同一个功能：给结构体的成员赋值or改变
struct point
{
	int x;
	int y;
};
struct point* getstruct(struct point *);
void output(struct point);
void print(const struct point*);
int main()
{
	struct point text = { 0,0 };
	//第一版
	getstruct(&text);
	output(text);//思考：一定要分两步吗？

	//第二版优化版