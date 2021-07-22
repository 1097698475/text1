#define _CRT_SECURE_NO_WARNINGS
#include"node.h"
#include<stdio.h>
#include<stdlib.h>

//typedef struct _node
//{
//	int value;
//	struct _node *next;
//}Node;

Node* add(Node* head, int number);

int main()
{
	Node *head = NULL; //������������head��û�и�next����
	int number;
	do
	{
		scanf("%d", &number);
		if (number != -1)
		{
			//��һ�֣�head�ú������裬����֪����head�ĵ�ַ���Ϳ���һֱnext��
			//head = add(head, number);//����ֻ��һ��head����Ϊ�����ı����head�Ŀ�¡
		}
	} while (number != -1);

	return 0;
}

Node* add(Node* head, int number)
{
	//add to linked_list
	Node *p = (Node*)malloc(sizeof(Node)); //����һ���ڵ㣬��������ָ��������malloc
	p->value = number;
	p->next = NULL;  //Ĭ�������β(next��null��

	//find the last ��last��������next��null
	Node *last = head; //��������head��ʼ
	if (last) //���last����null
	{
		while (last->next)  //���last����next�ͱ�������β
		{
			last = last->next;
		}
		//attach����ȥ
		last->next = p;
	}
	else  //���last����head������null)
	{
		head = p;
	}
	return head;
}