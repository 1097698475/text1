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
	//scanf("%ld", &stu1.id); //����ָ�룺ʹ�ýṹ�����ֶ�
	//printf("%ld\n", stu1.id);

	stu *p = &stu1;
	//printf("%p\n", p);

	//��ָ���һ�ַ�����������&
	//scanf("%ld", &(*p).id); 
	//printf("%ld\n", (*p).id);

	//��ָ��ĵڶ��ַ�������->
	scanf("%ld", &p->id);
	printf("%ld\n", p->id);
	//printf("%p\n", p);

	return 0;
}