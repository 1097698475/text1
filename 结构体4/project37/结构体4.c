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

	//����
	input(math, 5);

	text *top;//�ø�ָ����ܺ������ص�ָ��
	top = findtop(math, 5);

	printf("��һ����%s\t%d", top->name, top->score);

	return 0;
}
void input(text stu[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("�������%d��ѧ����������", i + 1);
		scanf("%s", stu[i].name);
		printf("�������%d��ѧ���ĳɼ���", i + 1);
		scanf("%d", &stu[i].score);
	}
}
text* findtop(text stu[], int n)
{
	text temp;
	//��Ϊ�ṹ�����ֱ�Ӹ�ֵ�����Խ��������ṹ�弴��
	for (int i = 0; i < 4; i++)  //��һ���ṹ�忪ʼ��1~4�����������ѡ������
	{
		for (int j = i + 1; j < 5; j++) //��i����ʼ��������Ľṹ��Ƚ�һֱ�������
		{
			if (stu[i].score < stu[j].score) //���ǰ��С�ں��ߣ��ͽ���
			{
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
		
			}
		}
	}
	return &stu[0];   //�����β���Ϊʲô���ػ���ȷ
}


//text scantop(text stu[], int n);
//int main()
//{
//	text stu[5];
//	
//	//������������
//	input(stu, 5);
//
//	//�ҳ��ɼ���ߵ���һ�飬������ṹ��top��
//	text top = scantop(stu, 5);
//
//	//��ӡ
//	printf("��һ����%s\t%d", top.name, top.score);
//
//	return 0;
//}
//void input(text stu[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("�������%d��ѧ����������", i + 1);
//		scanf("%s", stu[i].name);
//		printf("�������%d��ѧ���ĳɼ���", i + 1);
//		scanf("%d", &stu[i].score);
//	}
//}
//text scantop(text stu[], int n)
//{
//	text temp;
//	//��Ϊ�ṹ�����ֱ�Ӹ�ֵ�����Խ��������ṹ�弴��
//	for (int i = 0; i < 4; i++)  //��һ���ṹ�忪ʼ��1~4�����������ѡ������
//	{
//		for (int j = i + 1; j < 5; j++) //��i����ʼ��������Ľṹ��Ƚ�һֱ�������
//		{
//			if (stu[i].score < stu[j].score) //���ǰ��С�ں��ߣ��ͽ���
//			{
//				temp = stu[i];
//				stu[i] = stu[j];
//				stu[j] = temp;
//	
//			}
//		}
//	}
//	return stu[0];   //�����β���Ϊʲô���ػ���ȷ
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
//	text stu[5];  //����ѧ��
//
//	//������5��ѧ���ĳɼ�������ʾ���лس�
//	//�ں�����ѭ������������main��ѭ�����������Ժ��ߣ�����
//	input(stu, 5);
//
//	//���򣬳ɼ��ߵ�����ǰ�棨ѡ������
//	sort(stu, 5);
//
//	//��ӡ����õ�������
//	output(stu, 5);
//}
//void input(text stu[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("�������%d��ѧ����������", i + 1);
//		scanf("%s", stu[i].name);
//		printf("�������%d��ѧ���ĳɼ���", i + 1);
//		scanf("%d", &stu[i].score);
//	}
//}
//void sort(text stu[], int n)
//{
//	text temp;
//	//��Ϊ�ṹ�����ֱ�Ӹ�ֵ�����Խ��������ṹ�弴��
//	for (int i = 0; i < 4; i++)  //��һ���ṹ�忪ʼ��1~4�����������ѡ������
//	{
//		for (int j = i + 1; j < 5; j++) //��i����ʼ��������Ľṹ��Ƚ�һֱ�������
//		{
//			if (stu[i].score < stu[j].score) //���ǰ��С�ں��ߣ��ͽ���
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
//		printf("��%d��\t%s\t%d\n", i + 1, stu[i].name, stu[i].score);
//	}
//}


//void show(text *);
//int main()
//{
//	text math = { "����",85 };
//
//	text english = { "��÷÷",95 };
//
//	text *pte = &english;
//
//	show(&math);
//	show(pte);
//}
//void show(text *p)
//{
//	printf("%s�ĳɼ�Ϊ%d\n", p->name, p->score);
//}


//struct text
//{
//	char name[10];
//	int score;
// };
//void show_stu(struct text*);
//int main()
//{
//	struct text stu1 = { "����",80 };
//	struct text stu2 = { "����",90 };
//	struct text *p1 = &stu2;
//	show_stu(&stu1);
//	show_stu(p1);
//}
//void show_stu(struct text *p)
//{
//	printf("%s�ĳɼ�Ϊ%d\n", p->name, p->score);
//}



//int  main()
//{
//	struct text stu1 = { "����",85 };
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
//int main()  //�ýṹ��ָ������ṹ��
//{
//	struct text math[10] = { "����",85,"����",92 }, *p;
//	p = math;
//	for (; (*p).score != 0; p++)  //��Ϊ���飬�ṹ���ʼ����0
//	{
//		printf("name is %s. ", p->name);
//		printf("score is %d.\n", p->score);
//	}
//	return 0;
//}