#define _CRT_SECURE_NO_WARNINGS
#include"Set.h"
#include<iostream>
using namespace std;
enum Operation{ADD,REMOVE,ISIN};  //枚举几个选择

int Go_on(Operation op)  //这个是一个函数，嵌套进一个循环，不同的operation显示不同的提示，之后才输入选择
{
	int flag;  //存 是否 的变量
	switch (op)
	{
	case ADD:
		cout << "继续添加? (是->1/否->0): ";
		break;
	case REMOVE:
		cout << "继续删除? (是->1/否->0): ";
		break;
	case ISIN:
		cout << "继续判断? (是->1/否->0): ";
		break;
	default:
		cout << "不是三种操作之一！";
		return 0;  //不能进入下面的cin，而是直接返回Go_on函数开头
	}

	cin >> flag;
	return flag;
}

int main()
{
	int element;  //元素（大小）
	set s;  //集合
	Initialize(&s);  //初始化集合

	//以下是添加元素 循环添加，结合Go_on函数判断是否终止循环
	while (Go_on(ADD))  //为1时继续，为0时终止
	{
		cout << "输入待添加元素: ";
		cin >> element;  //前面已对element做了定义
		Add(element, &s);
	}

	//以下是删除元素
	while (Go_on(REMOVE))
	{
		cout << "输入待删除元素: ";
		cin >> element;
		Add(element, &s);
	}

	//以下是判断元素
	while (Go_on(ISIN))
	{
		cout << "输入待判断元素: ";
		cin >> element;
		if (Isin(element, &s))  //若有，则Isin函数返回1
			cout << "元素" << element << "在集合中。" << endl;
		else
			cout << "元素" << element << "不在集合中。" << endl;
	}
	return 0;
}