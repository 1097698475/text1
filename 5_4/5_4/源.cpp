#include<iostream>
using namespace std;

int main()
{
	int *p1 , *p2 ;
	int x = 1, y = 2;
	p1 = &x;
	p2 = &y;
	printf("%d\n", sizeof(p1));
	printf("%p\n", p1);
	printf("%p\n", p2);
	//printf("%p\n", &x);
}