#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdio.h>
//void swap(int x, int y)
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//
//}
//
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("a=%d b=%d\n", a, b);
//	swap(a, b);
//	printf("a=%d,b=%d", a, b);
//}


//int get_max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	int max=get_max(a, b);
//	printf("max is %d", max);
//	return 0;
//}


//int get_add(int x, int y)
//{
//	int z;
//	z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	int add=get_add(a, b);
//	printf("add is %d", add);
//}


//int main()
//{
//	char arr1[] = "bit";
//	char arr2[] = "xxxxxxxxxx";
//	strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//}

//int main()
//{
//	char input[20];
//	system("shutdown -s -t 60");
//	while (0)
//	{
//		printf("请注意，你的电脑将在一分钟内关机，如果输入：我是猪，就取消关机\n");
//		scanf("%s", input);
//		if (strcmp(input, "我是猪") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}//用goto也行！
//	}
//	return 0;
//}


//void menu()
//{
//	printf("***********************************\n");
//	printf("***      1.play     0.exit      ***\n");
//	printf("***********************************\n");
//}
//void game()
//{
//	int guess;
//	printf("开始游戏\n");
//	rand();
//	int ret = rand()%100+1;
//	//printf("%d\n", ret);
//	for (int i = 0;; i++)
//	{
//		printf("请猜数字(数字在1~100）：");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了\n");
//			printf("\n");
//			printf("\n");
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了\n");
//			printf("\n");
//			printf("\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对了！\n");
//			printf("\n");
//			printf("\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//		printf("\n");
//		printf("\n");
//
//	} while (input);
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		int j = 1;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1,b = 1; a <= 100; a++)
//	{
//		if (b >= 20 )
//			break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}


//int main()
//{
//	int n;
//	int i;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		int j, m = 0;
//		for (j = 1; j <= i; j++)
//		{
//			if (i%j == 0)
//				m++;
//		}
//		if (m == 2)
//			printf("%d ", i);
//	}
//}

//int main()
//{
//	int x = 3;
//	int y = 3;
//	switch (x % 2)
//	{
//	case 1:
//		switch (y)
//		{
//		case 0:
//			printf("first");
//		case 1:
//			printf("second");
//			break;
//		default:
//			printf("hello");
//		}
//	case 2:
//		printf("third");
//	}
//	return 0;
//}


//#define nmax 1000
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int num[nmax];
//	int *p;
//	for(i=0;i<n;i++)
//}


//#include<stdio.h>
////非递归做法
//int main()
//{
//	int n, x, y, z, month = 1;;
//	scanf("%d", &n);
//
//	x = 0, z = y = 1;
//	while (z < n)
//	{
//		z = x + y;
//		x = y;
//		y = z;
//		month++;
//	}
//
//	printf("%d", month);
//
//	return 0;
//}


//int main()
//{
//	printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
//	int i,num;
//	for (i = 0; i < 5; i++)
//	{
//		scanf("%d", &num);
//		if (num == 1)
//			printf("price = 3.00\n");
//		else if (num == 2)
//			printf("price = 2.50\n");
//		else if (num == 3)
//			printf("price = 4.10\n");
//		else if (num == 4)
//			printf("price = 10.20\n");
//		else if (num == 0)
//			break;
//		else
//		{
//			printf("price = 0.00\n");
//			break;
//		}
//	}
//}


//int main()
//{
//	int letter=0, blank=0, digit=0, other=0;
//	char a[10];
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%c", &a[i]);
//		if ((a[i] >= 'A'&&a[i] <= 'Z') || (a[i] >= 'a'&&a[i] <= 'z'))
//			letter++;
//		else if (a[i] == ' ' || a[i]=='\n')
//			blank++;
//		else if (a[i] >= '0'&&a[i] <= '9')
//			digit++;
//		else
//			other++;
//	}
//	printf("letter = %d, blank = %d, digit = %d, other = %d", letter, blank, digit, other);
//}


//#define nmax 1000
//int main()
//{
//	int n, i, num[nmax],*p,max,nummax;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//		scanf("%d", &num[i]);
//	p = num;
//	max = num[0];
//	nummax = 1;
//	for (i = 0; i < n; i++)
//	{
//		if (*(p + i) > max)
//		{
//			max = *(p + i);
//			nummax = i;
//		}
//	}
//	printf("%d %d", max,nummax);
//}


//int main()
//{
//	char str[1000];
//	gets_s(str);
//	int count = 0;
//	int i = 0, j, flag = 1;//flag为1是说明已经计数单词后面的空格
//	while (str[i] != '\0')
//	{
//		if (str[i] == ' '&&flag == 0)
//		{
//			count++;
//			flag = 1;
//		}
//		else if (str[i] != ' ')
//		{
//			if (str[i + 1] == '\0') {
//				count++;
//			}
//			flag = 0;
//		}
//		i++;
//	}
//	printf("%d\n", count);
//	return 0;
//}


//int main()
//{
//	char str[1000];
//	int word = 1;
//	gets_s(str);
//	for (int i = 0;; i++)
//	{
//		if (str[i-1] == ' '||str[i]!=' ')
//			word++;
//		if (str[i] == '\n')
//			break;
//	}
//	printf("%d", word);
//}


//int main()
//{
//	int x, y,flag=0;
//	char fuhao;
//	scanf("%d%c", &x, &fuhao);
//	for (int i = 0;; i++)
//	{
//		if (fuhao == '=')
//			break;
//		switch (fuhao)
//		{
//		case '+':
//			scanf("%d", &y);
//			x = x + y;
//			break;
//		case '-':
//			scanf("%d", &y);
//			x = x - y;
//			break;
//		case '*':
//			scanf("%d", &y);
//			x = x * y;
//			break;
//		case '/':
//			scanf("%d", &y);
//			if (y == 0)
//			{
//				flag = 1;
//				break;
//			}
//			x = x / y;
//			break;
//		default:
//			flag = 1;
//			break;
//		}
//		scanf("%c", &fuhao);
//	}
//	if (flag == 1)
//		printf("ERROR");
//	else
//		printf("%d", x);
//}


//int main()
//{
//	int i, num[10], max, min,*p,mink,maxk;
//	printf("请输入十个数字：");
//	p = &num[0];
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &num[i]);//或者*(p+i)
//	}
//	min = *p;
//	max = *p;
//	for (i = 0; i < 10; i++)
//	{
//		if (min > *(p + i))
//		{
//			mink = i+1;
//			min = *(p + i);
//		}
//		if (max < *(p + i))
//		{
//			max = *(p + i);
//			maxk = i+1;
//		}
//	}
//	printf("最大数是%d,在第%d个位置\n", max, maxk);
//	printf("最小数是%d,在第%d个位置", min, mink);
//}


//#define nmax 100
//int main()
//{
//	int n,pai,*p,i,num[nmax],k;
//	printf("please input the totoal of numbers:");
//	scanf("%d", &n);
//	p = &num[0];
//	for (i = 0; i < n; i++)
//	{
//		*(p + i) = 1 + i;
//	}
//	i = 0, pai = 0, k=0;
//	for (pai = 0; pai < n-1;)//n-1次
//	{
//		if (*(p + i) != 0)
//			k++;
//		if (k == 3)
//		{
//			*(p + i) = 0;
//			k = 0;
//			pai++;
//		}
//		i++;
//		if (i == 50)
//			i = 0;
//
//	}
//	for (i = 0;; i++)
//	{
//		if (*(p + i) != 0)
//		{
//			printf("%d is left", *(p + i));
//			break;
//		}
//	}
//}