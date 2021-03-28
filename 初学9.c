#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define nmax 50

//int main()
//{
//	int i, j, str[nmax][nmax];
//	for (i = 0; i < 3; i++)
//		for (j = 0; j < 3; j++)
//			scanf("%d", &str[i][j]);
//	int linesum[nmax], rowsum[nmax];
//	linesum[i]=
//}




//int main()
//{
//	int n, str[nmax][nmax], index=0, i, len;
//	scanf("%d", &n);
//	for (i = 0; i < n+1; i++)
//	{
//		gets(str[i]);
//	}
//	len = strlen(str[0]);
//	for (i = 0; i < n; i++)
//	{
//		if (len < strlen(str[i]))
//		{
//			len = strlen(str[i]);
//			index = i;
//		}
//	}
//	printf("the longest string is %s\n", str[index]);
//	return 0;
//}


//int main()
//{
//	int n, arr[nmax][nmax], index;
//	int i, len;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s", arr[i]);
//	}
//	len = strlen(arr[0]);
//	index = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (len < strlen(arr[i]))
//		{
//			len = strlen(arr[i]);
//			index = i;
//		}
//	}
//	printf("the longest string is %s\n", arr[index]);
//	return 0;
//}


//int main()
//{
//	char str[nmax];
//	int i = 0, len;
//	do {
//		str[i] = getchar();
//	} while (str[i] != '\n');
//	len = strlen(str);
//	for (i = 0;i<len; i++)
//	{
//		putchar(str[i]);
//		if ((str[i] >= 'a'&&str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z'))
//			str[i] = str[i] + 4;
//		if ((str[i] > 'Z'&&str[i] <= 'Z+4') || str[i] > 'z')
//			str[i] = str[i] - 26;
//	}
//	str[i] = '\0';
//	printf("\n");
//	puts(str);
//	return 0;
//}



//int main()
//{
//	char arr[nmax];
//	gets(arr);
//	int i, j, len;
//	len = strlen(arr);
//	for (i = 0, j = len - 1; i < len / 2; i++, j--)
//	{
//		if (arr[i] != arr[j])
//			break;
//	}
//	if (i == len / 2)
//		printf("yes");
//	else
//		printf("no");
//}


//int main()
//{
//	char str[nmax];
//	int i, len;
//	gets(str);
//	len = strlen(str);
//	for (i = 0; i < len / 2; i++)
//	{
//		if (str[i] != str[len - 1 - i])
//			break;
//	}
//	if (i == len / 2)
//		printf("yes");
//	else
//		printf("no");
//}


//int main()
//{
//	int n, m;//前选手，后评委
//	int i, j;//前选手，后评委
//	int score[nmax][nmax], sum[nmax] = { 0 }, final[nmax];
//	int min, max;
//	scanf("%d %d", &n, &m);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &score[i][j]);
//			sum[i] = sum[i] + score[i][j];
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		min = score[i][0];
//		max = score[i][0];
//		for (j = 0; j < m; j++)
//		{
//			if (score[i][j] > max)
//				max = score[i][j];
//			if (score[i][j] < min)
//				min = score[i][j];
//		}
//		final[i] = (sum[i] - max - min) / (m - 2);
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%d", final[i]);
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int n, arr[nmax][nmax], i, j;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n ; j++)
//		{
//			if (j == 0)
//				arr[i][j] = 1;
//			else if (j > i)
//				arr[i][j] = 0;
//			else
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			if(arr[i][j]!=0)
//				printf("%d ",arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int cfunction(int i)
//{
//	int b;
//}
//void yanghui(int arr[nmax], int i)
//{
//	int a;
//	for (a = 0; a < i; a++)
//		arr[a] = cfunction(i);
//}
//int main()
//{
//	int n, i, j;
//	scanf("%d", &n);
//	int arr[nmax];
//	for (i = 1; i <= n; i++)
//	{
//		yanghui(arr,i);
//		for (j = 0; j < i; j++)
//		{
//			printf("%d ", arr[j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//int main()
//{
//	int n, a[nmax][nmax], b[nmax][nmax], t;
//	scanf("%d", &n);
//	int i, j;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//	for (i = 0; i < n; i++)
//		for (j = 0; j < n; j++)
//			b[j][i] = a[i][j];
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//			printf("%d ", b[i][j]);
//		printf("\n");
//	}
//	/*for (i = 0; i < n; i++)
//	{
//		for (j = n; j >= i; j--)
//		{
//			t = a[i][j];
//			a[i][j] = a[j][i];
//			a[j][i] = t;
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%d ",a[i][j]);
//		}
//		printf("\n");
//	}*/
//}


//int main()
//{
//	int man[10], out[9], count = 0;
//	int m, i=0, a;//m为循环报截止的数，a为包的数
//	scanf("%d", &m);
//	for (i = 0;i<10; i++)//给每个人1~10编号
//	{
//		man[i] = i + 1;
//	}
//	for(a=1,i=0;a<=m;a++)//1~m循环报数
//	{
//		if (man[i] != 0)//报到m的人编号变为0，之后不参与报数，且记到out数组
//		{
//			if (a == m)
//			{
//				man[i] = 0;
//				a = 0;
//				count++;
//				//out[1] = i + 1;
//			}
//		}
//		i++;
//		if (i > 9)
//			i = i - 10;
//		if (count == 9)
//			break;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		if (man[i] != 0)
//			printf("%d ", man[i]);
//	}
//	return 0;
//}


//int main()
//{
//	char ch;
//	FILE* fp;
//	fp = fopen("c:\\uesr\\data.txt", "w");
//	if (fp == NULL)
//	{
//		printf("文件打开失败，退出程序运行\n");
//		exit(0);
//	}
//	while ((ch = getchar()) != '\n')
//		fputc(ch, fp);
//	fclose(fp);
//	return 0;
//}


//int main()
//{
//	int x, X[4], y, Y[4], i, j, k = 0, A, B, flag;
//	srand(time(0));
//	Y[0] = (int)rand() % 9 + 1;
//	for (i = 1; i < 4; i++)
//	{
//		do {
//			flag = 0;
//			Y[i] = (int)rand() % 10;
//			for (j = 0; j < i; j++)
//				if (Y[i] == Y[j])
//					flag = 1;
//		} while (flag);
//	}
//	y = 1000 * Y[0] + 100 * Y[1] + 10 * Y[2] + Y[3];
//	printf("%d\n", y);
//	do {
//		A = 0, B = 0;
//		scanf("%d", &x);
//		X[0] = x / 1000;
//		X[1] = x / 100 % 10;
//		X[2] = x / 10 % 10;
//		X[3] = x % 10;
//		for (i = 0; i < 4; i++)
//			for (j = 0; j < 4; j++)
//				if (X[i] == Y[j])
//				{
//					if (i == j)
//						A++;
//					else
//						B++;
//				}
//		printf("%dA%dB\n", A, B);
//		k++;
//	} while (x != y);
//	printf("you tried %d times", k);
//	return 0;
//}


//int main()
//{
//	int x, X[4], i, j, flag, A, B, text, TEXT[4], count = 0;
//	srand(time(0));
//	X[0] = rand() % 9+1;
//	for (i = 1; i < 4; i++)
//	{
//		do 
//		{
//			flag = 0;
//			X[i] = rand() % 10;
//			for (j = 0; j < i; j++)
//				if (X[i] == X[j])
//					flag = 1;
//		} while (flag);
//	}
//	x = 1000 * X[0] + 100 * X[1] + 10 * X[2] + X[3];
//	printf("%d\n", x);
//	do
//	{
//		A = 0, B = 0;
//		scanf("%d", &text);
//		TEXT[0] = text % 1000;
//		TEXT[1] = text/100 % 10;
//		TEXT[2] = text / 10 % 10;
//		TEXT[3] = text % 10;
//		for (i = 0; i < 4; i++)
//		{
//			for (j = 0; j < 4; j++)
//			{
//				if (X[i] == TEXT[j])
//				{
//					if (i == j)
//						A++;
//					else
//						B++;
//				}
//			}
//		}
//		printf("%dA%dB\n", A, B);
//		count++;
//	} while (A != 4);
//	printf("you tried %d times", count);
//	return 0;
//}


//#define N 15
//int main()
//{
//	int i, j, k;
//	int a[N];
//	srand(time(0));
//	for(i = 0; i < N; i++)
//	{
//		a[i] = rand() % 100 + 1;
//		prrintf("%d ", a[i]);
//	}
//	printf("\n");
//	for (i = 1; i < N; i++)
//	{
//		k = a[i];
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (a[j] > k)
//				a[j + 1] = a[j];
//			else
//				break;
//		}
//	}
//}


//void getsunxu(int* a[10])
//{
//	int i, j, min, t;
//	for (i = 0; i < 10; i++)
//	{
//		min = a[i];
//		for (j = i + 1; j < 10; j++)
//		{
//			if (min > a[j])
//			{
//				min = a[j];
//				a[j] = a[i];
//				a[i] = min;
//			}
//		}
//	}
//	/*for (i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}*/
//}
//int main()
//{
//	int arr[10];
//	int key, i, k, left = 0, right = 9;
//	srand(time(0));
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = rand() % 100 + 1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	scanf("%d", &key);
//	getsunxu(arr);
//	while (left <= right)
//	{
//		k = (left + right) / 2;
//		if (key == arr[k])
//			break;
//		else if (key < arr[k])
//			right = k - 1;//思考为何是k-1,而k不行：假如最后范围是1~2，为k的话，k始终为1，若key=2则始终没有结果
//		else
//			left = k + 1;
//	}
//	if (left > right)//有可能key不在数组里面
//		printf("no found");
//	else
//		printf("location:%d", k+1);
//	return 0;
//}


//int main()
//{
//	int arr[nmax];
//	int n, m;
//	int i, t,j;
//	scanf("%d %d", &n, &m);//前者为个数，后者移动格
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (j = 1; j <= m; j++)
//	{
//		t = arr[n - 1];
//		for (i = n - 1; i > 0; i--)
//		{
//			arr[i] = arr[i-1];
//		}
//		arr[0] = t;
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	int a, b, c;
//	int* pa;
//	int* pb;
//	int* p;
//	scanf("%d %d", &a, &b);
//	pa = &a;
//	pb = &b;
//	p = &c;
//	*p = *pa;
//	*pa = *pb;
//	*pb = *p;
//	/*c = a;
//	a = b;
//	b = c;*/
//	printf("%d %d", a, b);
//}


//int main()
//{
//	int n, m;
//	int a[100];
//	scanf("%d %d", &n, &m);
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", a[i]);
//	}
//	int j;
//	for (j = 1;; j++)
//	{
//
//	}
//	return 0;
//}


//int main()
//{
//	int a[100];
//	int i;
//	int st[21] = { 0 };
//	srand(time(0));
//	for(i=0;i<100;i++)
//	{
//		a[i] = rand() % 20 + 1;
//		st[a[i]]++;
//	}
//	for (i = 0; i < 100; i++)
//	{
//		printf("%3d", a[i]);
//		if ((i + 1) % 20 == 0)
//			printf("\n");
//	}
//	printf("统计结果\n");
//	for (i = 1; i < 21; i++)
//	{
//		printf("%3d", st[i]);
//	}
//	printf("\n");
//	return 0;
//}


//int main()
//{
//	char man;
//	for (man = 'a'; man <= 'd'; man++)
//	{
//		if (((man != 'a') + (man != 'b'&&man == 'c') + (man == 'a' || man == 'd') + (man != 'b'&&man == 'c')) == 2)
//			printf("guilt is %c", man);
//	}
//	return 0;
//}


//int main()
//{
//	int flag = 0;
//	char who;
//	for (who = 'a'; who <= 'd'; who++)
//	{
//		if (((who != 'a') + (who == 'c') + (who == 'd') + (who!= 'd')) == 3)
//		{
//			printf("this man is %c", who);
//			flag = 1;
//		}
//	}
//	if (flag == 0)
//		printf("cannot found");
//}


//int main()
//{
//	int flag = 0;
//	char who;
//	for (who = 'A';who <= 'D'; who++)
//	{
//		if (((who != 'A') + (who == 'C') + (who == 'D') + (who != 'D')) == 3)
//		{
//			printf("this man is %c", who);
//			flag = 1;
//		}
//	}
//	if (flag == 0)
//		printf("cannot found!");
//	return 0;
//}


//void display()
//{
//	printf("choose:\n");
//	printf("1 display circle perimeter\n");
//	printf("2 display circle area\n");
//	printf("3 display sphere area\n");
//	printf("4 display sphere volume\n");
//	printf("0 quit\n");
//	printf("your choose:");
//}
//
//int main()
//{
//	double r;
//	int choose;
//	printf("Enter radius:");
//	scanf("%lf", &r);
//	for (int i = 0;; i++)
//	{
//		display();
//		scanf("%d", &choose);
//		if (choose == 0)
//			break;
//		else
//		{
//			switch (choose)
//			{
//			case 1:
//				printf("%.3f\n", 2 * pai*r);
//				break;
//			case 2:
//				printf("%.3f\n", pai*r*r);
//				break;
//			case 3:
//				printf("%.3f\n", 4 * pai*r*r);
//				break;
//			case 4:
//				printf("%.3f\n", 4 * pai*r*r*r / 3);
//				break;
//			default:
//				printf("invalid choise!\n");
//				break;
//			}
//		}
//	}
//	return 0;
//}


//int main()
//{
//	char c;
//	while ((c = getchar()) != '\n')
//	{
//		if ((c >= 'a'&&c <= 'z') ||( c >= 'A'&&c <= 'Z'))
//		{
//			c = c + 4;
//			if (c > 'Z'&&c <= 'Z' + 4 || c > 'Z')
//				c = c - 26;
//		}
//		printf("%c", c);
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	int x, max;
//	int index;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		printf("No.%d:",i);
//		scanf("%d", &x);
//		if (i == 1)
//		{
//			max = x;
//			index = 1;
//			continue;
//		}
//		if (max < x)
//		{
//			max = x;
//			index = i;
//		}
//	}
//	printf("max=%d,no=%d", max, index);
//	return 0;
//}


//int main()
//{
//	int a, b;
//	int x=0, y=0;
//	int flag = 0;
//	scanf("%d %d", &a, &b);//头 脚
//	for (x = 0; x <= a; x++)
//	{
//		for (y = 0; y <= a; y++)
//		{
//			if (x + y == a && 2 * x + 4 * y == b)
//			{
//				printf("%d %d", x, y);
//				flag = 1;
//			}
//		}
//	}
//	if (flag == 0)
//		printf("there is no solving");
//	return 0;
//}


//int main()
//{
//	int n;
//	double sum = 1;
//	double i=2;
//	scanf("%d", &n);
//	while (i<=n)
//	{
//		sum = sum + 1 / i;
//		i++;
//	}
//	printf("%lf", sum);
//	return 0;
//}


//int main()
//{
//	int a;
//	int sum = 0;
//	scanf("%d", &a);
//	for (int i = 0;; i++)
//	{
//		sum = sum + a % 10;
//		a = a / 10;
//		if (a == 0)
//			break;
//	}
//	printf("%d", sum);
//	return 0;
//}

//int main()
//{
//	int a;
//	printf("%5d%4d\n", 100, 2);
//	printf("%08d\n",1234);
//	printf("%+8d\n", 1234);
//	printf("%+-8d\n", 1234);
//	printf("%2d with label\n", 5210);
//	printf("%-7s%d\n", "it's\n", 28);
//	printf("%.6s\n", "abcdABCD");
//	printf("%15f\n", 981.48);
//	printf("%7.1f\n", 981.48);
//	printf("%12.3e\n", 981.48);
//	printf("%#o\n", 12);
//
//	return 0;
//}


//int main()
//{
//	char c;
//	int x;
//	int d;
//	scanf("%d %d", &x, &d);
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <=12; i++)
//	{
//		printf("hehe\n", i);
//		arr[i] = 0;
//	}
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int n,m;
//	scanf("%d", &n);
//	int i, j, k;
//	int a1[nmax][nmax];
//	int a2[nmax] = { 1 };
//	for (k = 0; k < n; k++)
//	{
//		scanf("%d", &m);
//		for (i = 0; i < m; i++)
//			for (j = 0; j < m; j++)
//				scanf("%d", &a1[i][j]);
//		for (i = 0; i < m; i++)
//			for (j = 0; j < m; j++)
//			{
//				if (i > j&&a1[i][j] != 0)
//					a2[k] = 0;
//			}
//	}
//	for (k = 0; k < n; k++)
//	{
//		if (a2[k] == 0)
//			printf("NO\n");
//		else
//			printf("YES\n");
//	}
//	return 0;
//}



//void ifup(char arr[],int m,int* flag)
//{
//	int i, j;
//	for (i = m-1; i >0; i--)
//	{
//		for (j = 0; j < m-1; j++)
//		{
//			if (arr[i][j] != 0)
//			{
//				*flag = 0;
//				break;
//			}
//		}
//	}
//}
//int main()
//{
//	int n;//待测个数
//	int m;//矩阵横竖
//	int arr[nmax][nmax];
//	int i, j;
//	int flag[nmax];//是则1，否则0
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &m);
//		for (i = 0; i < m; i++)
//		{
//			for (j = 0; j < m; j++)
//			{
//				scanf("%d", &arr[i][j]);
//			}
//		}
//		ifup(arr,m,&flag);
//	}
//}
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//void reverse_char(char* arr)
//{
//	int left = 0;
//	int right = my_strlen(arr) - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[nmax];
//	getchar();
//	gets(arr);
//	reverse_char(arr);
//	printf("%s", arr);
//}



//int main()
//{
//	char arr[nmax];
//	char key;
//	int flag = 0;
//	scanf("%c", &key);
//	getchar();//缓冲，按回车才跳到下面,为什么注视掉这行不行？
//	gets(arr);
//	int index = -1;
//	int len = strlen(arr);
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] == key)
//			index = i;;
//	}
//	if (index == -1)
//		printf("Not Found");
//	else
//		printf("index = %d", index);
//}