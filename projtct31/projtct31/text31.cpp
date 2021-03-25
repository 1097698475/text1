#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define nmax 6


#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int a[nmax][nmax];
	int max[nmax], min[nmax];
	/*for (int i = 0; i < n; i++) {
		max[i] = 0;
		min[i] = 9999;
	}*/
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) //此时i为行，j为列
		{
			if (j == 0)
				max[i] = a[i][j];
			if (max[i] < a[i][j]) 
			{
				max[i] = a[i][j];  //每行最大值
			}
		}
		//		printf("max[%d] %d\n",i,max[i]);
		for (int j = 0; j < n; j++) //此时i为列，j为行
		{
			if (j == 0)
				min[i] = a[j][i];
			if (min[i] > a[j][i]) 
			{
				min[i] = a[j][i];  //每列最大值，注意j,i
			}
		}
		//		printf("min[%d] %d\n",i,min[i]);
	}
	//	for(int i=0;i<n;i++){
	//		printf("max %d	min %d\n",max[i],min[i]);
	//	}
	int flag = 0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (max[i] == min[j]) //如果这一行的最大值等于
			{
				printf("%d %d\n", i, j);
				flag++;
			}
		}
	}
	if (flag == 0) 
	{
		printf("NONE");
	}
}



//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i, j, arr[nmax][nmax];  //i为行下标，j为列下标
//	int flag = 0;  //找到了则为1   或者用goto语句
//
//	//给二维数组赋值
//	for (i = 0; i < n; i++)
//		for (j = 0; j < n; j++)
//			scanf("%d", &arr[i][j]);
//
//	int line=0, row=0;
//	//先找出每一行最大元素，再看该元素所对的列是否是最小
//	for (i = 0; i < n; i++)
//	{
//		//找出每一行的最大元素a[line][row]
//		int max = arr[i][0]; 
//		int ifrow = 0;
//		int ifline = i;
//		for (j = 0; j < n; j++)
//		{
//			if (max < arr[ifline][j])
//			{
//				ifrow = j;  // 此时第i行的最大元素为arr[i][ifrow]
//				max = arr[ifline][ifrow];
//			}
//		}
//		for (int k = 0; k < n; k++)
//		{
//			int count = 0;
//			if (arr[k][ifrow] < arr[ifline][ifrow])
//			{
//				count++;
//			}
//			if (k == n - 1 && count == n - 1)
//			{
//				line = ifline;
//				row = ifrow;
//				flag = 1;
//			}
//		}
//		if (flag)
//			break;
//	}
//	printf("%d %d",line,row);
//	return 0;
//}

//int main()
//{
//	int arr[100], index,i, j, n;
//	scanf("%d", &n);
//	int temp;
//	for (i = 0; i < n; i++)
//		scanf("%d", &arr[i]);
//	for (i = 0; i < n - 1; i++) //选择排序只能排八次,因为要下一个元素比较
//	{
//		index = i;  //用index代替下标
//		int max = arr[i];  //假设第i个元素是最大值
//
//		for (j = i + 1; j < n; j++) //i的下一个元素开始，与i元素比较
//		{
//			if (arr[j] > arr[index]) //如果 比 下标为index个元素大，则互换位置
//			{
//				temp = arr[index];
//				arr[index] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%d", arr[i]);
//		if (i < n - 1)
//			printf(" ");
//	}
//	return 0;
//}