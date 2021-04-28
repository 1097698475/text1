#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Set.h"
using namespace std;

//初始化集合，即把count变成0，不对data集合数字做改变
void Initialize(set* pset)  //pset是preset,之前创建的集合 的意思
{
	pset->count = 0;  
}

//判断元素elem是否在集合数组里，数组没有初始化，需要操作Add多次才可能elem已在集合里
int Isin(int elem, set* pset)
{
	int i;
	for ( i = 0; i < pset->count&&pset->data[i] != elem; i++);
	// i小于集合现有的元素个数，同时判断data[i]与elem相同吗？相同则跳出循环并记录此时的data位置i，
	if (i < pset->count)
		return 1;  //说明data有元素和elem一样，返回1
	else
		return 0;  //i>=count,说明data没有元素和elem一样
}

//添加元素到集合下一位
void Add(int elem, set* pset)
{
	if(pset->count<MAXLENGTH)
		if (Isin(elem, pset)!=1)
		{
			pset->data[pset->count] = elem;  //数组元素刚好比数组元素个数小1
			(pset->count)++;
		}
}

//删除元素，要判断是否有该元素
void Remove(int elem, set* pset)
{
	int i;
	for (i = 0; i < pset->count&&pset->data[i] != elem; i++);
	// i小于集合现有的元素个数，同时判断data[i]与elem相同吗？相同则跳出循环并记录此时的data位置i，
	if (i < pset->count)
	{
		//与待删除元素相同的地方用集合最后一个元素代替
		pset->data[i] = pset->data[pset->count - 1];
		(pset->count)--;   //最后还把集合个数减1，因为最后一个元素已经赋给前面了，最后一个位置没用了
						   //这样刚好符合i为最后一个元素的情况
	}
	else
		cout << "待删除元素" << elem << "不在集合中。" << endl;
}
