define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdbool.h>

//�������ַ�����ͬһ�����ܣ����ṹ��ĳ�Ա��ֵor�ı�
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
	//��һ��
	getstruct(&text);
	output(text);//˼����һ��Ҫ��������

	//�ڶ����Ż���