#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct text
{
	char name[20];
	int score;
}text;

void input(text stu[], int n);
text* findtop(text stu[], int n);
int main()
{
	text math[5];

	//输入
	input(math, 5);

	text *top;//用该指针接受函数返回的指针
	top = findtop(math, 5);

	printf("第一名：%s\t%d", top->name, top->score);

	return 0;
}
void input(text stu[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("请输入第%d个学生的姓名：", i + 1);
		scanf("%s", stu[i].name);
		printf("请输入第%d个学生的成绩：", i + 1);
		scanf("%d", &stu[i].score);
	}
}
text* findtop(text stu[], int n)
{
	text temp;
	//因为结构体可以直接赋值，所以交换两个结构体即可
	for (int i = 0; i < 4; i++)  //第一个结构体开始，1~4，第五个不用选择排序
	{
		for (int j = i + 1; j < 5; j++) //第i个开始向接下来的结构体比较一直到第五个
		{
			if (stu[i].score < stu[j].score) //如果前者小于后者，就交换
			{
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
		
			}
		}
	}
	return &stu[0];   //不是形参吗，为什么返回还正确
}


//text scantop(text stu[], int n);
//int main()
//{
//	text stu[5];
//	
//	//输入五组数据
//	input(stu, 5);
//
//	//找出成绩最高的那一组，并存入结构体top中
//	text top = scantop(stu, 5);
//
//	//打印
//	printf("第一名：%s\t%d", top.name, top.score);
//
//	return 0;
//}
//void input(text stu[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("请输入第%d个学生的姓名：", i + 1);
//		scanf("%s", stu[i].name);
//		printf("请输入第%d个学生的成绩：", i + 1);
//		scanf("%d", &stu[i].score);
//	}
//}
//text scantop(text stu[], int n)
//{
//	text temp;
//	//因为结构体可以直接赋值，所以交换两个结构体即可
//	for (int i = 0; i < 4; i++)  //第一个结构体开始，1~4，第五个不用选择排序
//	{
//		for (int j = i + 1; j < 5; j++) //第i个开始向接下来的结构体比较一直到第五个
//		{
//			if (stu[i].score < stu[j].score) //如果前者小于后者，就交换
//			{
//				temp = stu[i];
//				stu[i] = stu[j];
//				stu[j] = temp;
//	
//			}
//		}
//	}
//	return stu[0];   //不是形参吗，为什么返回还正确
//}


//typedef struct text
//{
//	char name[20];
//	int score;
//}text;
//
//void input(text stu[], int n);
//void sort(text stu[], int n);
//void output(text stu[], int n);
//
//int main()
//{
//	text stu[5];  //五名学生
//
//	//输入这5名学生的成绩（有提示，有回车
//	//在函数里循环，而不是在main里循环（可以试试后者，错误
//	input(stu, 5);
//
//	//排序，成绩高的排在前面（选择排序
//	sort(stu, 5);
//
//	//打印排序好的这五名
//	output(stu, 5);
//}
//void input(text stu[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("请输入第%d个学生的姓名：", i + 1);
//		scanf("%s", stu[i].name);
//		printf("请输入第%d个学生的成绩：", i + 1);
//		scanf("%d", &stu[i].score);
//	}
//}
//void sort(text stu[], int n)
//{
//	text temp;
//	//因为结构体可以直接赋值，所以交换两个结构体即可
//	for (int i = 0; i < 4; i++)  //第一个结构体开始，1~4，第五个不用选择排序
//	{
//		for (int j = i + 1; j < 5; j++) //第i个开始向接下来的结构体比较一直到第五个
//		{
//			if (stu[i].score < stu[j].score) //如果前者小于后者，就交换
//			{
//				temp = stu[i];
//				stu[i] = stu[j];
//				stu[j] = temp;
//
//			}
//		}
//	}
//}
//void output(text stu[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("第%d名\t%s\t%d\n", i + 1, stu[i].name, stu[i].score);
//	}
//}


//void show(text *);
//int main()
//{
//	text math = { "李雷",85 };
//
//	text english = { "韩梅梅",95 };
//
//	text *pte = &english;
//
//	show(&math);
//	show(pte);
//}
//void show(text *p)
//{
//	printf("%s的成绩为%d\n", p->name, p->score);
//}


//struct text
//{
//	char name[10];
//	int score;
// };
//void show_stu(struct text*);
//int main()
//{
//	struct text stu1 = { "王雷",80 };
//	struct text stu2 = { "张宇",90 };
//	struct text *p1 = &stu2;
//	show_stu(&stu1);
//	show_stu(p1);
//}
//void show_stu(struct text *p)
//{
//	printf("%s的成绩为%d\n", p->name, p->score);
//}



//int  main()
//{
//	struct text stu1 = { "王雷",85 };
//	show_stu(stu1);
//	return 0;
//}
//void show_stu(struct text stu1)
//{
//	printf("%s %d", stu1.name, stu1.score);
//}

//struct text
//{
//	char name[20];
//	int score;
//};
//int main()  //用结构体指针遍历结构体
//{
//	struct text math[10] = { "张三",85,"李四",92 }, *p;
//	p = math;
//	for (; (*p).score != 0; p++)  //因为数组，结构体初始化是0
//	{
//		printf("name is %s. ", p->name);
//		printf("score is %d.\n", p->score);
//	}
//	return 0;
//}