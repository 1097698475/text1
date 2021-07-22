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

	//输出链表的value
	print(&list);

	//找出特定的value
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

	//删除特定的节点
	Node *q;
	for (q = NULL, p = list.head; p; q = p, p = p->next)
	{
		if (p->value == number)//how do we find the bundary?
		{//赋值左边的指针不能是null，若head就是要找到对象，则一开始要head
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

	//删除链表
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
	Node *p = (Node*)malloc(sizeof(Node)); //生成一个节点，但由于是指针所以用malloc
	p->value = number;
	p->next = NULL;  //默认这个是尾(next是null）

	//find the last ，last的特征：next是null
	Node *last = pList->head; //遍历，从head开始
	if (last) //如果last不是null
	{
		while (last->next)  //如果last还有next就表明不是尾
		{
			last = last->next;
		}
		//attach接上去
		last->next = p;
	}
	else  //如果last就是head（就是null)
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