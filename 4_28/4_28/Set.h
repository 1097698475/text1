#define _CRT_SECURE_NO_WARNINGS

const int MAXLENGTH = 100;
struct set
{
	int data[MAXLENGTH];  //最开始的集合（可以初始化，也可以不初始化）
	unsigned count;  //count是集合元素的个数，后面同Initialize函数结合，可初始化成0 
};

void Initialize(set* pset);  //初始化集合，即把count变成0，不对data集合数字做改变
void Add(int elem, set* pset);   //添加元素到集合（集合原本是空集
void Remove(int elem, set* pset);  //删除某一元素，将最后一个元素放到该位置，再将集合元素个数-1
int Isin(int elem, set* pset);