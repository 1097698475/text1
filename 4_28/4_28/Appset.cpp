#define _CRT_SECURE_NO_WARNINGS
#include"Set.h"
#include<iostream>
using namespace std;
enum Operation{ADD,REMOVE,ISIN};  //ö�ټ���ѡ��

int Go_on(Operation op)  //�����һ��������Ƕ�׽�һ��ѭ������ͬ��operation��ʾ��ͬ����ʾ��֮�������ѡ��
{
	int flag;  //�� �Ƿ� �ı���
	switch (op)
	{
	case ADD:
		cout << "�������? (��->1/��->0): ";
		break;
	case REMOVE:
		cout << "����ɾ��? (��->1/��->0): ";
		break;
	case ISIN:
		cout << "�����ж�? (��->1/��->0): ";
		break;
	default:
		cout << "�������ֲ���֮һ��";
		return 0;  //���ܽ��������cin������ֱ�ӷ���Go_on������ͷ
	}

	cin >> flag;
	return flag;
}

int main()
{
	int element;  //Ԫ�أ���С��
	set s;  //����
	Initialize(&s);  //��ʼ������

	//���������Ԫ�� ѭ����ӣ����Go_on�����ж��Ƿ���ֹѭ��
	while (Go_on(ADD))  //Ϊ1ʱ������Ϊ0ʱ��ֹ
	{
		cout << "��������Ԫ��: ";
		cin >> element;  //ǰ���Ѷ�element���˶���
		Add(element, &s);
	}

	//������ɾ��Ԫ��
	while (Go_on(REMOVE))
	{
		cout << "�����ɾ��Ԫ��: ";
		cin >> element;
		Add(element, &s);
	}

	//�������ж�Ԫ��
	while (Go_on(ISIN))
	{
		cout << "������ж�Ԫ��: ";
		cin >> element;
		if (Isin(element, &s))  //���У���Isin��������1
			cout << "Ԫ��" << element << "�ڼ����С�" << endl;
		else
			cout << "Ԫ��" << element << "���ڼ����С�" << endl;
	}
	return 0;
}