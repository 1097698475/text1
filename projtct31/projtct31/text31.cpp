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
		for (int j = 0; j < n; j++) //��ʱiΪ�У�jΪ��
		{
			if (j == 0)
				max[i] = a[i][j];
			if (max[i] < a[i][j]) 
			{
				max[i] = a[i][j];  //ÿ�����ֵ
			}
		}
		//		printf("max[%d] %d\n",i,max[i]);
		for (int j = 0; j < n; j++) //��ʱiΪ�У�jΪ��
		{
			if (j == 0)
				min[i] = a[j][i];
			if (min[i] > a[j][i]) 
			{
				min[i] = a[j][i];  //ÿ�����ֵ��ע��j,i
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
			if (max[i] == min[j]) //�����һ�е����ֵ����
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
//	int i, j, arr[nmax][nmax];  //iΪ���±꣬jΪ���±�
//	int flag = 0;  //�ҵ�����Ϊ1   ������goto���
//
//	//����ά���鸳ֵ
//	for (i = 0; i < n; i++)
//		for (j = 0; j < n; j++)
//			scanf("%d", &arr[i][j]);
//
//	int line=0, row=0;
//	//���ҳ�ÿһ�����Ԫ�أ��ٿ���Ԫ�����Ե����Ƿ�����С
//	for (i = 0; i < n; i++)
//	{
//		//�ҳ�ÿһ�е����Ԫ��a[line][row]
//		int max = arr[i][0]; 
//		int ifrow = 0;
//		int ifline = i;
//		for (j = 0; j < n; j++)
//		{
//			if (max < arr[ifline][j])
//			{
//				ifrow = j;  // ��ʱ��i�е����Ԫ��Ϊarr[i][ifrow]
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
//	for (i = 0; i < n - 1; i++) //ѡ������ֻ���Ű˴�,��ΪҪ��һ��Ԫ�رȽ�
//	{
//		index = i;  //��index�����±�
//		int max = arr[i];  //�����i��Ԫ�������ֵ
//
//		for (j = i + 1; j < n; j++) //i����һ��Ԫ�ؿ�ʼ����iԪ�رȽ�
//		{
//			if (arr[j] > arr[index]) //��� �� �±�Ϊindex��Ԫ�ش��򻥻�λ��
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