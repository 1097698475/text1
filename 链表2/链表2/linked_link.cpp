#define _CRT_SECURE_NO_WARNINGS
#include"node.h"
#include<stdio.h>
#include<stdlib.h>

//typedef struct _node
//{
//	int value;
//	struct _node *next;
//}Node;

typedef struct _list
{
	Node* head;
	//Node* tail;
}List;

void add(List *pList, int number);
void print(List *pList);

int main()
{
	List list;
	list.head = NULL;
	int number;
	do
	{
		scanf("%d", &number);
		if (number != -1)
		{
			add(&list, number);
		}
	} while (number != -1);

	//��������value
	print(&list);

	//�ҳ��ض���value
	scanf("%d", &number);
	Node *p;
	int isFound = 0;
	for (p = list.head; p; p = p->next)
	{
		if (p->value == number)
		{
			printf("find it!\n");
			isFound = 1;
			break;
		}
	}
	if (isFound == 0)
	{
		printf("have not found!\n");
	}

	//ɾ���ض��Ľڵ�
	Node *q;
	for (q = NULL, p = list.head; p; q = p, p = p->next)
	{
		if (p->value == number)//how do we find the bundary?
		{//��ֵ��ߵ�ָ�벻����null����head����Ҫ�ҵ�������һ��ʼҪhead
			if (q)
			{
				q->next = p->next;
			}
			else
			{
				list.head = p->next;
			}
			free(p);
			break;
		}
	}

	//ɾ������
	for (p = list.head; p; p = q)
	{
		q = p->next;
		free(p);
	}

	return 0;
}

void add(List *pList, int number)
{
	//add to linked_list
	Node *p = (Node*)malloc(sizeof(Node)); //����һ���ڵ㣬��������ָ��������malloc
	p->value = number;
	p->next = NULL;  //Ĭ�������β(next��null��

	//find the last ��last��������next��null
	Node *last = pList->head; //��������head��ʼ
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
		pList->head = p;
	}
}

void print(List *pList)
{
	Node *p;
	for (p = pList->head; p; p = p->next)
	{
		printf("%d\t", p->value);
	}
	printf("\n");
}