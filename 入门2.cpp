#include<stdio.h>

int MAX(int x,int y)
{
	if(x>y)
	return x;
	else
	return y;
}

int main()

{
	int num1=10;
	int num2=20;
	int max;
	max=MAX(num1,num2);
	printf("max=%d\n",max);
	return 0; 
	
//	int num1=10;
//	int num2=20;
//	if(num1<num2)
//	printf("较大值为%d\n",num2);
//	else
//	printf("较小值为%d\n",num1);
//	return 0;
		//char a='0';
	//printf("%c\n",a);
	//char b='\0';
	//printf("%c\n",b);
	//char c='abcde';
	//printf("%c\n",c);
//	int d=33;
//	printf("%s\n",d);
//	return 0;
	
		//int arr[10]={0};
//	int sz;
//	sz=sizeof(arr)/sizeof(arr[0]);
//	printf("%d\n",sz);
//	return 0;
}


//{
//	int a=5%2;
//	printf("%d",a);
//}
//{
//	int arr[6]={1,2,3,4,5,6};
//	int i=0;
//	while(i<6)
//	{
//		printf("%d\n",arr[i]);
//		i++;
//	}
//	return 0;
//}



//	int arr[10]={1,2,3,4,5,6,7,8,9,10};
//	printf("%d\n",arr[5]);
//	return 0;
//}
//{
//	int input = 0;
//	printf("do you want to study?(1/0) ");
//	scanf("%d",&input);
//	if(input == 1)
//	printf("good guy!\n");
//	else
//	printf("ss");
//	return 0;

//int line=0;
//printf("join\n")；
//while(line<2000)
//{
//	printf("strike a line\n")；
//	line++; 
//}
//printf("top ")；
//return 0; 
//}

