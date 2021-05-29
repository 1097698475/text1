#define _CRT_SECURE_NO_WARNINGS 
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
	output(*getstruct(&text));//解引用getstruct函数返回的p指针，即text结构变量，然后再传到output

	print(getstruct(&text));//给结构修改成员时，传入指针比定义新的结构变量要好：前者可以适用其他函数

}
struct point* getstruct(struct point *p)
{
	scanf("%d", &p->x);//为什么要用-> ?因为不用箭头存入不了结构体里的成员
	scanf("%d", &p->y);
	printf("您刚才输入了：%d %d\n", p->x, p->y);
	return p;
}
void output(struct point text)
{
	printf("打印: %d %d\n", text.x, text.y);
}
void print(const struct point *p)
{
	printf("print函数打印：%d %d\n", p->x, p->y);
}