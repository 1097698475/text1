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
	Node *head = NULL; //隐含：单独的head，没有跟next相连
	int number;
	do
	{
		scanf("%d", &number);
		if (number != -1)
		{
			//第一种，head用函数赋予，这样知道了head的地址，就可以一直next了
			//head = add(head, number);//不能只传一个head，因为函数改变的是head的克隆
		}
	} while (number != -1);

	return 0;
}

Node* add(Node* head, int number)
{
	//add to linked_list
	Node *p = (Node*)malloc(sizeof(Node)); //生成一个节点，但由于是指针所以用malloc
	p->value = number;
	p->next = NULL;  //默认这个是尾(next是null）

	//find the last ，last的特征：next是null
	Node *last = head; //遍历，从head开始
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
		head = p;
	}
	return head;
}