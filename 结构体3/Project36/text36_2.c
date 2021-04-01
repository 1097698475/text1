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


//#define max 100
////定义一个结构体，当前孩子序号，和下一个孩子的序号，实现闭环的前提
//struct children
//{
//	int num;  //自己的序号
//	int next; //下一个的序号
//};
//int main()
//{
//	struct children link[max]; //每个结构体包含当前和下一位，形成闭合环
//
//	//输入参数
//	printf("请输入参加游戏的人数(1-%d): ", max - 1);
//	int n;
//	scanf("%d", &n);
//	printf("请输入起始号码: ");
//	int start;
//	scanf("%d", &start);
//	printf("请输入每次所数人数: ");
//	int key;
//	scanf("%d", &key);
//
//	//建立闭合环
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		link[i].num = i;
//		if (i == n - 1)  //最后一位的下一位是第一位
//			link[i].next = 1;
//		else
//			link[i].next = i + 1;
//	}
//
//	//确定第一个参加计数的前一个孩子的号码  why?
//	int pre;
//	if (start == 1)
//		pre = n;
//	else
//		pre = start - 1;
//
//	//统计出列顺序
//	printf("孩子出列顺序为: /n");
//	//n个小孩，循环n次，最后一次输入的为最后剩下的，每次{循环1
//	//循环1{i=0，i++,i到key则标记当前num=0(用k变量，而k=上一个link.next
//	for (int count = 1; count <= n; count++)  //第count次循环
//	{
//		int i = 1; //从1开始报数
//
//		//标记谁为key
//		do
//		{
//			pre = link[pre].next; //
//			if(link[pre].num!=0)
//		}
//	}
//}

//struct text
//{
//	char name[10];
//	int score;
//};
//int main()
//{
//	//定义结构体t用于交换算法
//	struct text math[5], t;
//
//	//下面的循环用于向结构体输入数据
//	for (int i = 0; i < 5; i++)
//	{
//		printf("请输入第%d个学生的姓名：", i);
//		scanf("%s", math[i].name);
//		printf("请输入第%d个学生的成绩：", i);
//		scanf("%d", &math[i].score);
//	}
//
//	//下面的循环用于对结构体数组元素按score成员的值  由大到小  进行排序
//	//选择排序法
//	for(int i=0;i<4;i++) //从第一个数开始与剩下的数作比较，1~4，第五个数不用参与比较
//		for (int j = i + 1; j < 5; j++) //从第i+1个数开始与第i个数比较，i+1~5，
//		{
//			if (math[i].score < math[j].score)
//			{
//				t = math[i];
//				math[i] = math[j];
//				math[j] = t;  //第j个数换到第i个数，同时保证第i个数的数据还存在，放回第j个数
//			}
//		}
//
//	//下面的循环用于输出排序后的结果
//	for (int i = 0; i < 5; i++)
//	{
//		printf("第%d名->", i + 1);
//		printf("姓名：%s  成绩：%d\n", math[i].name, math[i].score);
//	}
//	return 0;
//}


//struct date
//{
//	int year;
//	int month;
//	int day;
//};
//struct student
//{
//	long id;
//	char name[10];
//	char sex;
//	char major[20];
//	struct date birthday;
//};
//int main()
//{
//	struct student stu1;//{ 20170001,"张三",'M',"计算机",{2000,10,1} };
//	stu1.id = 20170001;
//	strcpy(stu1.name, "张三");  //字符数组初始值都是0，字符串碰到0就停止
//	stu1.sex = "M";
//	strcpy(stu1.major, "计算机");
//	stu1.birthday.year = 2000;
//	stu1.birthday.month = 10;
//	stu1.birthday.day = 1;
//
//	scanf("%ld %s %c %s %d %d %d", &stu1.id, stu1.name, &stu1.sex, stu1.major, &stu1.birthday.year,
//		&stu1.birthday.month, &stu1.birthday.day);
//
//
//	printf("学号：%ld\t姓名：%s\t性别：%c\t专业：%s\t生日：%d-%d-%d", stu1.id, stu1.name, stu1.sex,
//		stu1.major, stu1.birthday.year, stu1.birthday.month, stu1.birthday.day);
//}
