#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Set.h"
using namespace std;

//��ʼ�����ϣ�����count���0������data�����������ı�
void Initialize(set* pset)  //pset��preset,֮ǰ�����ļ��� ����˼
{
	pset->count = 0;  
}

//�ж�Ԫ��elem�Ƿ��ڼ������������û�г�ʼ������Ҫ����Add��βſ���elem���ڼ�����
int Isin(int elem, set* pset)
{
	int i;
	for ( i = 0; i < pset->count&&pset->data[i] != elem; i++);
	// iС�ڼ������е�Ԫ�ظ�����ͬʱ�ж�data[i]��elem��ͬ����ͬ������ѭ������¼��ʱ��dataλ��i��
	if (i < pset->count)
		return 1;  //˵��data��Ԫ�غ�elemһ��������1
	else
		return 0;  //i>=count,˵��dataû��Ԫ�غ�elemһ��
}

//���Ԫ�ص�������һλ
void Add(int elem, set* pset)
{
	if(pset->count<MAXLENGTH)
		if (Isin(elem, pset)!=1)
		{
			pset->data[pset->count] = elem;  //����Ԫ�ظպñ�����Ԫ�ظ���С1
			(pset->count)++;
		}
}

//ɾ��Ԫ�أ�Ҫ�ж��Ƿ��и�Ԫ��
void Remove(int elem, set* pset)
{
	int i;
	for (i = 0; i < pset->count&&pset->data[i] != elem; i++);
	// iС�ڼ������е�Ԫ�ظ�����ͬʱ�ж�data[i]��elem��ͬ����ͬ������ѭ������¼��ʱ��dataλ��i��
	if (i < pset->count)
	{
		//���ɾ��Ԫ����ͬ�ĵط��ü������һ��Ԫ�ش���
		pset->data[i] = pset->data[pset->count - 1];
		(pset->count)--;   //��󻹰Ѽ��ϸ�����1����Ϊ���һ��Ԫ���Ѿ�����ǰ���ˣ����һ��λ��û����
						   //�����պ÷���iΪ���һ��Ԫ�ص����
	}
	else
		cout << "��ɾ��Ԫ��" << elem << "���ڼ����С�" << endl;
}
