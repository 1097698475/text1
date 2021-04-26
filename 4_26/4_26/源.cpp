#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
// 如果不使用using namespace std; 则需要在指令cout endl前面加上std::如下
int main()
{
	std::cout << "hello world" << std::endl;0
	return 0;
}


//using namespace std;  // c++中的类和函数实在命名空间std声明的，所以需要用的话就需要“”作声明
//					  // 表示要用到命名空间std中的内容
//int main()
//{
//	cout << "hello world" << endl;
//	// cout是输出流对象，<<是“插入运算符”的意思，与cout配合使用，表示输出xxx
//	// 该指令也将endl(换行）插入到cout输出流，而c++将输出流cout的内容输出到系统指定的设备。
//	return 0;
//}