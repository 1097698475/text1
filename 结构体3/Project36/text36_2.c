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


//#define max 100
////����һ���ṹ�壬��ǰ������ţ�����һ�����ӵ���ţ�ʵ�ֱջ���ǰ��
//struct children
//{
//	int num;  //�Լ������
//	int next; //��һ�������
//};
//int main()
//{
//	struct children link[max]; //ÿ���ṹ�������ǰ����һλ���γɱպϻ�
//
//	//�������
//	printf("������μ���Ϸ������(1-%d): ", max - 1);
//	int n;
//	scanf("%d", &n);
//	printf("��������ʼ����: ");
//	int start;
//	scanf("%d", &start);
//	printf("������ÿ����������: ");
//	int key;
//	scanf("%d", &key);
//
//	//�����պϻ�
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		link[i].num = i;
//		if (i == n - 1)  //���һλ����һλ�ǵ�һλ
//			link[i].next = 1;
//		else
//			link[i].next = i + 1;
//	}
//
//	//ȷ����һ���μӼ�����ǰһ�����ӵĺ���  why?
//	int pre;
//	if (start == 1)
//		pre = n;
//	else
//		pre = start - 1;
//
//	//ͳ�Ƴ���˳��
//	printf("���ӳ���˳��Ϊ: /n");
//	//n��С����ѭ��n�Σ����һ�������Ϊ���ʣ�µģ�ÿ��{ѭ��1
//	//ѭ��1{i=0��i++,i��key���ǵ�ǰnum=0(��k��������k=��һ��link.next
//	for (int count = 1; count <= n; count++)  //��count��ѭ��
//	{
//		int i = 1; //��1��ʼ����
//
//		//���˭Ϊkey
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
//	//����ṹ��t���ڽ����㷨
//	struct text math[5], t;
//
//	//�����ѭ��������ṹ����������
//	for (int i = 0; i < 5; i++)
//	{
//		printf("�������%d��ѧ����������", i);
//		scanf("%s", math[i].name);
//		printf("�������%d��ѧ���ĳɼ���", i);
//		scanf("%d", &math[i].score);
//	}
//
//	//�����ѭ�����ڶԽṹ������Ԫ�ذ�score��Ա��ֵ  �ɴ�С  ��������
//	//ѡ������
//	for(int i=0;i<4;i++) //�ӵ�һ������ʼ��ʣ�µ������Ƚϣ�1~4������������ò���Ƚ�
//		for (int j = i + 1; j < 5; j++) //�ӵ�i+1������ʼ���i�����Ƚϣ�i+1~5��
//		{
//			if (math[i].score < math[j].score)
//			{
//				t = math[i];
//				math[i] = math[j];
//				math[j] = t;  //��j����������i������ͬʱ��֤��i���������ݻ����ڣ��Żص�j����
//			}
//		}
//
//	//�����ѭ��������������Ľ��
//	for (int i = 0; i < 5; i++)
//	{
//		printf("��%d��->", i + 1);
//		printf("������%s  �ɼ���%d\n", math[i].name, math[i].score);
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
//	struct student stu1;//{ 20170001,"����",'M',"�����",{2000,10,1} };
//	stu1.id = 20170001;
//	strcpy(stu1.name, "����");  //�ַ������ʼֵ����0���ַ�������0��ֹͣ
//	stu1.sex = "M";
//	strcpy(stu1.major, "�����");
//	stu1.birthday.year = 2000;
//	stu1.birthday.month = 10;
//	stu1.birthday.day = 1;
//
//	scanf("%ld %s %c %s %d %d %d", &stu1.id, stu1.name, &stu1.sex, stu1.major, &stu1.birthday.year,
//		&stu1.birthday.month, &stu1.birthday.day);
//
//
//	printf("ѧ�ţ�%ld\t������%s\t�Ա�%c\tרҵ��%s\t���գ�%d-%d-%d", stu1.id, stu1.name, stu1.sex,
//		stu1.major, stu1.birthday.year, stu1.birthday.month, stu1.birthday.day);
//}
