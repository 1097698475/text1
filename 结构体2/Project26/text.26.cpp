#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include<stdbool.h>

struct point
{
	int x;
	int y;
};
struct point * getstruct(struct point *);
void output(struct point);
void print(const struct point*);
int main()
{
	struct point text = { 0,0 };
	//��һ��
	getstruct(&text);
	output(text);//˼����һ��Ҫ��������

	//�ڶ����Ż���
	output(*getstruct(&text));//������getstruct�������ص�pָ�룬��text�ṹ������Ȼ���ٴ���output
	
	print(getstruct(&text));//���ṹ�޸ĳ�Աʱ������ָ��ȶ����µĽṹ����Ҫ�ã�ǰ�߿���������������

}
struct point * getstruct(struct point *p)
{
	scanf("%d", &p->x);
	scanf("%d", &p->y);
	printf("���ղ������ˣ�%d %d\n", p->x, p->y);
	return p;
}
void output(struct point text)
{
	printf("��ӡ: %d %d\n", text.x, text.y);
}
void print(const struct point *p)
{
	printf("print������ӡ��%d %d\n", p->x, p->y);
}







//struct date
//{
//	int day;
//	int month;
//}today;
//int main()
//{
//
//}


	/*struct text
	{
		int x;
		int y;
	};
	struct text getstruct(void);
	void outstruct(struct text p1);
	int main()
	{
		struct text p1 = { 0,0 };
		p1 = getstruct();
		outstruct(p1);
		return 0;
	}
	struct text getstruct()
	{
		struct text p1;
		scanf("%d", &p1.x);
		scanf("%d", &p1.y);
		printf("%d %d\n", p1.x, p1.y);
		return p1;
	}
	void outstruct(struct text p1)
	{
		printf("%d %d", p1.x, p1.y);
	}*/


//struct text
//{
//	int x;
//	int y;
//};
//void getstruct(struct text p1);
//void outstruct(struct text p1);
//int main()
//{
//	struct text p1 = { 0,0 };
//	getstruct(p1);
//	outstruct(p1);
//	return 0;
//}
//void getstruct(struct text p1)
//{
//	scanf("%d", &p1.x);
//	scanf("%d", &p1.y);
//	printf("%d %d\n", p1.x, p1.y);
//}
//void outstruct(struct text p1)
//{
//	printf("%d %d", p1.x, p1.y);
//}




//struct date {
//	int day;
//	int month;
//	int year;
//};
//bool isleap(struct date d);
//int numberofdays(struct date d);
//int main()
//{
//	struct date today, tomorrow;
//	printf("enter today date(dd,mm,yyyy)\n");
//	scanf("%d %d %d", &today.day, &today.month, &today.year);
//	if (today.day != numberofdays(today))
//	{
//		tomorrow = today;
//		tomorrow.day = today.day + 1;
//	}
//	else if (today.month == 12)
//	{
//		tomorrow.day = 1;
//		tomorrow.month = 1;
//		tomorrow.year = today.year + 1;
//	}
//	else
//	{
//		tomorrow.day = 1;
//		tomorrow.month = today.month + 1;
//		tomorrow.year = today.year;
//	}
//	printf("tomorrow date is %d-%d-%d", tomorrow.day, tomorrow.month, tomorrow.year);
//
//
//	return 0;
//}
//int numberofdays(struct date d)
//{
//	int days;
//	int dayspermonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (d.month == 2 && isleap(d))
//		days = 29;
//	else
//		days = dayspermonth[d.month - 1];
//	return days;
//}
//bool isleap(struct date d)
//{
//	bool leap = false;
//	if ((d.year % 4 == 0 && d.day % 100 != 0) || d.year % 400 == 0)
//		leap = true;
//	return true;
//
//}