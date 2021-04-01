#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>

typedef struct student
{
	long id;
	char name[10];
	int score[2];
}stu;
int main()
{
	stu stu1;
	//scanf("%ld", &stu1.id); //不用指针：使用结构体打的字多
	//printf("%ld\n", stu1.id);

	stu *p = &stu1;
	//printf("%p\n", p);

	//用指针第一种方法，还是用&
	//scanf("%ld", &(*p).id); 
	//printf("%ld\n", (*p).id);

	//用指针的第二种方法，用->
	scanf("%ld", &p->id);
	printf("%ld\n", p->id);
	//printf("%p\n", p);

	return 0;
}