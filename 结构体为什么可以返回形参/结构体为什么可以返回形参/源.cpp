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

	//������������
	input(stu, 5);

	//�ҳ��ɼ���ߵ���һ�飬������ṹ��top��
	text top = scantop(stu, 5);

	//��ӡ
	printf("��һ����%s\t%d", top.name, top.score);

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
text scantop(text stu[], int n)
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
	return stu[0];   //�����β���Ϊʲô���ػ���ȷ
}
