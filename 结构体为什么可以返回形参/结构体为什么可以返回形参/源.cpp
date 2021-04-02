#include<stdio.h>

typedef struct text
{
	char name[20];
	int score;
}text;

void input(text stu[], int n);
text scantop(text stu[], int n);
int main()
{
	text stu[5];

	//输入五组数据
	input(stu, 5);

	//找出成绩最高的那一组，并存入结构体top中
	text top = scantop(stu, 5);

	//打印
	printf("第一名：%s\t%d", top.name, top.score);

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
text scantop(text stu[], int n)
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
	return stu[0];   //不是形参吗，为什么返回还正确
}
