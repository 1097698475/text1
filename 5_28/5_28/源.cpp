#define _CRT_SECURE_NO_WARNINGS 
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
	output(*getstruct(&text));//������getstruct�������ص�pָ�룬��text�ṹ������Ȼ���ٴ���output

	print(getstruct(&text));//���ṹ�޸ĳ�Աʱ������ָ��ȶ����µĽṹ����Ҫ�ã�ǰ�߿���������������

}
struct point* getstruct(struct point *p)
{
	scanf("%d", &p->x);//ΪʲôҪ��-> ?��Ϊ���ü�ͷ���벻�˽ṹ����ĳ�Ա
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