#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<time.h>
//#define nmax 80
//#define RANGE 100

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define REPEAT 1  //����ʱ��������ظ�����
#define PMIN 0.05//P��ʾ�ô��е��׵ĸ��ʣ��Ǵ�PMIN��PMAX�𲽱任��
#define PMAX 0.25
#define PSTEP 0.001 //ÿ�θ��ʱ仯�ķ���
#define M 9//ɨ������ĳ���
#define N 9//ɨ������Ŀ���
#define T 10000 //ÿ�θ��ʱ仯ʱ���еĴ���
#define DISPLAY 0 //�Ƿ���ʾ����
#define JUSTIFY 0  //�ж�ʤ������
#define INTERVAL 1   //ͳ��ʱ������ٵ���
#define TEST 0  //�����1����ô���ڲ���ģʽ
static short area[M + 1][N + 1];//�����������������Ϊ0��û����Ϊ1
static short explore[M + 1][N + 1];//����ܿ����Ļ��棬9����δ������0-8�ֱ�������׵ĸ�����10�����Ѿ����Ϊ����
static short unknown[M + 1][N + 1];//δ֪��飬�������߼��ж�
static short suspect[M + 1][N + 1];//�����Ƿ����װ�飬�������߼��ж�
static short left_area[8];//������
static short right_area[8];//������
static short common[M][N][5][5][4];

static double density[M + 1][N + 1]; //�ܶȲ���

static int totalunknown; //�ܹ���δ֪���
static int totalmine; //�ܹ��ĵ���
static int touchmine; //�����ж�
static int unknownmine; //δ֪����
static float click;  //ģ��ʱ��
static int logictimes; //�߼�����
static int opps; //ͳ�������ֶ�ѡһ�����





//�����������
int ran(int seed)
{
	int  num;
	num = 16807 * (seed % 127773) - 2836 * (seed / 127773);
	if (num < 0) num = num + 2147483647;
	return num;
}


//��������ǲ������ڱ߽��ڲ������緵��0
int boundary(int i, int j)
{
	if (i > -1 && i<M && j>-1 && j < N) return 1;
	else return 0;
}

//�ж���������Ƿ����ڣ��ԽǷ���2�����ڷ���1������Ϊ0
int neigh(int i, int j, int i1, int j1)
{
	int distance;
	distance = (i1 - i)*(i1 - i) + (j1 - j)*(j1 - j);
	if (distance == 2) return 2;
	if (distance == 1) return 1;
	else return 0;
}


//�����������Ĺ�ͬ���֣�ע�⣺�����Ŵ������ڳ̶ȡ���0��23���ֱ�����ң����ϵ��¡�
void getcommon()
{
	int i, j, i1, j1, k;
	int p, q;


	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (i1 = 0; i1 < 5; i1++)
			{
				for (j1 = 0; j1 < 5; j1++)
				{
					if (boundary(i + i1 - 2, j + j1 - 2) == 0) continue; //���Ҫ�Ƚϵĸ����磬ֱ������
					k = 0;

					for (p = i - 1; p <= i + 1; p++)
					{
						for (q = j - 1; q <= j + 1; q++)
						{
							if (boundary(p, q) == 0) continue;  //����ܱߵĸ���г���ģ�ֱ������
							if (p == i && q == j) continue;      //���ĵĸ����Ȼ����
							if (neigh(p, q, i + i1 - 2, j + j1 - 2) != 0)
							{
								common[i][j][i1][j1][k] = p * N + q + 1;
								k++;
							}

						}

					}

				}

			}

		}

	}

}




//��ӡ�û����溯��
void printexplore()
{
	int i, j;
	printf("----------------------------------------------------------\n");
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (explore[i][j] == 9) { printf("��"); continue; }
			if (explore[i][j] == 10) { printf("��"); continue; }
			if (explore[i][j] == 0) { printf("  "); continue; }
			printf("%2d", explore[i][j]);
		}
		printf("\n");
	}
	printf("----------------------------------------------------------\n");
}
//��ӡʧ�ܽ��溯��
void printfail(int k, int l)
{
	int i, j;
	system("cls");
	printf("��%d�е�%d�����ף��㴥�����ˣ�\n", k + 1, l + 1);
	printf("���\t  ʣ������\t���ɽ���\n");
	printf("%d��%d\t     %d\t\t%d/%d\n", M, N, unknownmine, M*N - totalunknown, M*N);
	printf("----------------------------------------------------------\n");
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == k && j == l) { printf("��"); continue; }
			if (area[i][j] == 1) { printf("%2c", 11); continue; }
			if (explore[i][j] == 9) { printf("��"); continue; }
			printf("  ");
		}
		printf("\n");
	}
	printf("----------------------------------------------------------\n");
}

//��ӡunknown����
void printunknown()
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%2d", unknown[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------unknown----------------------------\n");
}

//��ӡ�ܶ�
void printdensity()
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%4.1f", density[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------density----------------------------\n");
}



//��ӡunknown����
void printsuspect()
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%2d", suspect[i][j]);
		}
		printf("\n");
	}
	printf("----------------------suspect-----------------------------\n");
}

//��ӡ��������Ŀ���Ǵ�ӡ�����׵ķֲ�ͼ
void printarea()
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (area[i][j] == 0) { printf("  "); continue; }
			printf("%2d", area[i][j]);
		}
		printf("\n");
	}
	printf("---------------------------------------------------------\n");
}

//��ʾ��������ʾ��Ļ��ɨ�׽���
void display()
{
	int i;

	if (DISPLAY == 1)
	{
		printf("���\t  ʣ������\t���ɽ���\n");
		printf("%d��%d\t    %3d \t %3d/%d\n", M, N, unknownmine, M*N - totalunknown, M*N);
		printexplore();
		for (i = 0; i < 234567891; i++);

	}
}





//����һ�鱻���ɻ򱻱�Ǻ�����Χ��8��ͼ���Լ�1
void modunknown(int i, int j)
{
	if (i > 0 && j > 0)   unknown[i - 1][j - 1]--;
	if (i > 0)  unknown[i - 1][j]--;
	if (i > 0 && j < N - 1)  unknown[i - 1][j + 1]--;
	if (j > 0)  unknown[i][j - 1]--;
	if (j < N - 1)  unknown[i][j + 1]--;
	if (i < N - 1 && j>0)  unknown[i + 1][j - 1]--;
	if (i < N - 1)  unknown[i + 1][j]--;
	if (i < N - 1 && j < N - 1)  unknown[i + 1][j + 1]--;
}



//���ܺ���������һ���ض��Ŀ飬�����ܱ߷�����׵ĸ���
int count(int i, int j)
{
	int number = 0;
	if (i == M - 1 && j == N - 1) return area[i - 1][j] + area[i - 1][j - 1] + area[i][j - 1];
	if (i == M - 1 && j == 0) return area[i - 1][j] + area[i - 1][j + 1] + area[i][j + 1];
	if (i == 0 && j == N - 1) return area[i + 1][j] + area[i + 1][j - 1] + area[i][j - 1];
	if (i == 0 && j == 0) return area[i][j + 1] + area[i + 1][j + 1] + area[i + 1][j];
	if (i == 0 && j % (N - 1) != 0) return area[i][j - 1] + area[i][j + 1] + area[i + 1][j - 1] + area[i + 1][j] + area[i + 1][j + 1];
	if (i == M - 1 && j % (N - 1) != 0) return area[i][j - 1] + area[i][j + 1] + area[i - 1][j - 1] + area[i - 1][j] + area[i - 1][j + 1];
	if (j == 0 && i % (M - 1) != 0) return area[i - 1][j] + area[i + 1][j] + area[i - 1][j + 1] + area[i][j + 1] + area[i + 1][j + 1];
	if (j == N - 1 && i % (M - 1) != 0) return area[i + 1][j] + area[i - 1][j] + area[i + 1][j - 1] + area[i - 1][j - 1] + area[i][j - 1];
	return area[i - 1][j - 1] + area[i][j - 1] + area[i + 1][j - 1] + area[i - 1][j] + area[i + 1][j] + area[i - 1][j + 1] + area[i][j + 1] + area[i + 1][j + 1];
}

//���ɺ���
void exploit(int i, int j, int flag)
{

	if (boundary(i, j) == 0) return;
	if (explore[i][j] != 9) return; //Խ���߾������Ѿ������ɹ��ģ����迪�ɡ�
	if (flag == 1 && DISPLAY == 1) { system("cls"); printf("ɨ�׽�����...\n"); display(); }
	//  if (flag==1) {click+=1;}
	if (area[i][j] == 1)
	{
		if (TEST == 1)
		{
			printf("�㴥����!\n");
			printf("%d��%d��\n", i + 1, j + 1);
			printf("δ֪����%d��ʣ�����%d\n", totalunknown, unknownmine);
			printexplore();
			printarea();
			printunknown();
			printdensity();
			exit(0);
		}

		if (DISPLAY == 1) printfail(i, j);
		touchmine = 1;
		return;
	}
	totalunknown--;
	explore[i][j] = count(i, j);
	modunknown(i, j);
	if (explore[i][j] == 0)
	{
		exploit(i - 1, j - 1, 2);
		exploit(i - 1, j, 2);
		exploit(i - 1, j + 1, 2);
		exploit(i, j - 1, 2);
		exploit(i, j + 1, 2);
		exploit(i + 1, j - 1, 2);
		exploit(i + 1, j, 2);
		exploit(i + 1, j + 1, 2);
	}
}

void makeclear(int i, int j)
{
	//   printf("make clear %d %d\n",i,j);
	if (boundary(i, j) == 0) return;
	if (explore[i - 1][j - 1] == 9) exploit(i - 1, j - 1, 1);
	if (explore[i - 1][j] == 9) exploit(i - 1, j, 1);
	if (explore[i - 1][j + 1] == 9) exploit(i - 1, j + 1, 1);
	if (explore[i][j - 1] == 9) exploit(i, j - 1, 1);
	if (explore[i][j + 1] == 9) exploit(i, j + 1, 1);
	if (explore[i + 1][j - 1] == 9) exploit(i + 1, j - 1, 1);
	if (explore[i + 1][j] == 9) exploit(i + 1, j, 1);
	if (explore[i + 1][j + 1] == 9) exploit(i + 1, j + 1, 1);

}

//������Χ������
void calcsuspect(int i, int j)
{
	int a = 0;
	if (explore[i - 1][j - 1] == 10) a++;
	if (explore[i - 1][j] == 10) a++;
	if (explore[i - 1][j + 1] == 10) a++;
	if (explore[i][j - 1] == 10) a++;
	if (explore[i][j + 1] == 10) a++;
	if (explore[i + 1][j - 1] == 10) a++;
	if (explore[i + 1][j] == 10) a++;
	if (explore[i + 1][j + 1] == 10) a++;
	suspect[i][j] = a;
}



void modsuspect(int i, int j)
{
	// printf("modsuspect%d %d\n",i,j);

	calcsuspect(i - 1, j - 1);
	if (suspect[i - 1][j - 1] == explore[i - 1][j - 1]) makeclear(i - 1, j - 1);
	calcsuspect(i - 1, j);
	if (suspect[i - 1][j] == explore[i - 1][j]) makeclear(i - 1, j);
	calcsuspect(i - 1, j + 1);
	if (suspect[i - 1][j + 1] == explore[i - 1][j + 1]) makeclear(i - 1, j + 1);
	calcsuspect(i, j - 1);
	if (suspect[i][j - 1] == explore[i][j - 1]) makeclear(i, j - 1);
	calcsuspect(i, j + 1);
	if (suspect[i][j + 1] == explore[i][j + 1]) makeclear(i, j + 1);
	calcsuspect(i + 1, j - 1);
	if (suspect[i + 1][j - 1] == explore[i + 1][j - 1]) makeclear(i + 1, j - 1);
	calcsuspect(i + 1, j);
	if (suspect[i + 1][j] == explore[i + 1][j]) makeclear(i + 1, j);
	calcsuspect(i + 1, j + 1);
	if (suspect[i + 1][j + 1] == explore[i + 1][j + 1]) makeclear(i + 1, j + 1);
}


//�ѵ�i�е�j�б�ǳɵ���
void mark(int i, int j)
{
	explore[i][j] = 10;
	modsuspect(i, j);
	modunknown(i, j);
	unknownmine--;
	totalunknown--;
}


// �����׵�δ֪��Ŀ�͵�����Ŀ��ͬʱ������Χȫ������ϵ���
void markall(int i, int j)
{
	if (explore[i - 1][j - 1] == 9) { mark(i - 1, j - 1); }
	if (explore[i - 1][j] == 9) { mark(i - 1, j); }
	if (explore[i - 1][j + 1] == 9) { mark(i - 1, j + 1); }
	if (explore[i][j - 1] == 9) { mark(i, j - 1); }
	if (explore[i][j + 1] == 9) { mark(i, j + 1); }
	if (explore[i + 1][j - 1] == 9) { mark(i + 1, j - 1); }
	if (explore[i + 1][j] == 9) { mark(i + 1, j); }
	if (explore[i + 1][j + 1] == 9) { mark(i + 1, j + 1); }
}









//���ض�������д�����ǰ��������ΪҪ�����ĵ�����1����ȫ���򿪣�2����ȫ�����
void handle(int i, int j, int i1, int j1, int flag)
{
	//  printf("����ִ��%d����\n",flag);
	int p, q, k = 0;
	for (p = i - 1; p < i + 2; p++)
	{
		for (q = j - 1; q < j + 2; q++)
		{
			if (p == i && q == j) continue;
			if (neigh(p, q, i1, j1) != 0 || boundary(p, q) == 0) continue;
			if (flag == 1) exploit(p, q, 1);
			if (flag == 2 && explore[p][q] == 9) mark(p, q);

		}
	}

}





//�߼�����������Ʒ�еľ�������
void logic(int i, int j, int i1, int j1)
{

	int common_unknown, left_unknown, right_unknown;
	int common_mine, left_mine, right_mine;
	int common_guess; //��ͬ����²�ĵ�����Ŀ
	int k, l, p, q, num;
	click++;
	logictimes++;

	common_unknown = 0;
	common_mine = 0;
	k = 0;
	l = 0;
	num = (i - i1) * 5 + (j - j1);


	//   printf("�߼���ʼ%d,%d,%d,%d\n",i+1,j+1,i1+1,j1+1);

	for (k = 0; k < 4; k++)
	{
		l = common[i][j][i1 - i + 2][j1 - j + 2][k];
		if (l == 0) continue;
		p = (l - 1) / N;
		q = (l - 1) % N;

		if (explore[p][q] == 10) common_mine++;
		if (explore[p][q] == 9)  common_unknown++;
	}


	//���Ƕ��壬i,jΪ��ߣ�i1,j1Ϊ�ұ�
	left_unknown = unknown[i][j] - common_unknown;
	right_unknown = unknown[i1][j1] - common_unknown;
	left_mine = suspect[i][j] - common_mine;
	right_mine = suspect[i1][j1] - common_mine;
	if (left_unknown + right_unknown == 0) return;



	//��߻��ұ����еĵط���������
	if (explore[i1][j1] - right_mine == explore[i][j] - left_mine)
	{
		if (left_unknown == 0)  handle(i1, j1, i, j, 1);
		if (right_unknown == 0)   handle(i, j, i1, j1, 1);
	}
	//��߻��ұ����еĵط�������

	if (explore[i1][j1] - right_mine - right_unknown == explore[i][j] - left_mine - left_unknown)
	{
		if (left_unknown == 0)  handle(i1, j1, i, j, 2);
		if (right_unknown == 0)   handle(i, j, i1, j1, 2);
	}
	// �ж����ȫ���ף��ұ߶�����
	if (explore[i][j] - explore[i1][j1] == left_mine + left_unknown)
	{
		handle(i1, j1, i, j, 1);
		handle(i, j, i1, j1, 2);
	}
	//�ұ�ȫ���ף���߶�����     
	if (explore[i1][j1] - explore[i][j] == right_mine + right_unknown)
	{
		handle(i1, j1, i, j, 2);
		handle(i, j, i1, j1, 1);
	}
}

//��һ���ض��ĸ����ֵ��ף�����1��ʾ������ˣ������ʾû�б����
int dist_density(int i, int j)
{
	int p, q, temp;
	temp = explore[i][j] - suspect[i][j];
	//����Ҫ���۳��ĵ���

	if (temp == 0 || temp == unknownmine) return 0;

	for (p = i - 1; p < i + 2; p++)
	{
		for (q = j - 1; q < j + 2; q++)
		{
			if ((p == i && q == j) || boundary(p, q) == 0) continue;
			if (density[p][q] != 0) { return 0; }
		}

	}


	//ʣ�µľ�̯�ֵ�δ֪����
	for (p = i - 1; p < i + 2; p++)
	{
		for (q = j - 1; q < j + 2; q++)
		{
			if ((p == i && q == j) || boundary(p, q) == 0) continue;
			if (explore[p][q] == 9) { density[p][q] = temp * 1.0 / unknown[i][j]; }
		}

	}
	return 1;
}




int makeclear()
{
	int i, j, temp1, temp2, flag = 0;
	temp1 = totalunknown; //ʣ�µ�δ֪�����
	temp2 = unknownmine; //ʣ�µ�δ֪������
	//��ʼ���������ܶ�ȫ��0
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			density[i][j] = 0;
		}
	}

	//����ܶ�
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (unknown[i][j] > 0 && explore[i][j] < 9)
			{
				if (dist_density(i, j) == 1)
				{
					//	  	if(i==0 && j==1) printf("kaka %d %d %d\n",unknown[i][j],explore[i][j],suspect[i][j]);
					//		 if(i==0 && j==1) printexplore();
					temp1 -= unknown[i][j];
					temp2 -= (explore[i][j] - suspect[i][j]);
				}
			}

		}
	}
	//���ʣ�����ȫ�����ֱ꣬�Ӱ�û�е�ȫ����
	if (temp2 == 0)
	{
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (explore[i][j] == 9 && density[i][j] == 0) { exploit(i, j, 1); flag = 1; }
			}
		}

	}
	//���ʣ�������δ֪������ȣ�ֱ�Ӱ�û�е�ȫ���
	if (temp2 == temp1)
	{
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (explore[i][j] == 9 && density[i][j] == 0) { mark(i, j); flag = 1; }
			}
		}

	}



	return flag;

}




// ��������Ŀ��ʣ������ʱ��չ��clearall����
int clearall()
{
	int i, j, flag = 0;
	if (unknownmine == 0) //�����׶�֪���ˣ���ֱ��ʤ��
	{
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (explore[i][j] == 9) exploit(i, j, 1);
			}
		}
		return 1;
	}
	else
	{

		if (makeclear() == 1)  return 1;
	}

	return 0;
}


//�Ե�ͼ����һ��ɨ�ײ���
void cycle(int flag)
{
	int i, j, i1, j1, diff;
	if (flag == 1)
	{
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (unknown[i][j] + suspect[i][j] == explore[i][j] && explore[i][j] < 9 && unknown[i][j] != 0) { markall(i, j); click++; }
				else if (suspect[i][j] == explore[i][j] && unknown[i][j] > 0) { makeclear(i, j); click++; }
				else if (unknown[i][j] * explore[i][j] != 0 && explore[i][j] < 9) { click += 0.25; }

			}

		}

	}

	else if (flag == 2)
	{
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (explore[i][j] == 0 || explore[i][j] > 7) continue;
				if (unknown[i][j] + unknown[i + 1][j] > 4 && explore[i + 1][j] > 0 && explore[i + 1][j] < 8 && boundary(i + 1, j) != 0) logic(i, j, i + 1, j);
				if (unknown[i][j] + unknown[i][j + 1] > 4 && explore[i][j + 1] > 0 && explore[i][j + 1] < 8 && boundary(i, j + 1) != 0) logic(i, j, i, j + 1);
			}
		}
	}

	else if (flag == 3)
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (explore[i][j] > 7 || explore[i][j] == 0) continue; //�������δ֪���������Χû���ף�ֱ������
				for (i1 = i; i1 < i + 3; i1++)
				{
					for (j1 = j - 2; j1 < j + 3; j1++)
					{
						if (unknown[i][j] + unknown[i1][j1] < 5) continue;
						if (explore[i1][j1] > 7 || explore[i1][j1] == 0) continue;
						diff = (i1 - i)*N + j1 - j;
						if (diff < 2 || diff == N) continue;
						if (boundary(i1, j1) != 0)  logic(i, j, i1, j1);
					}
				}
				//	  printf("hor---%d��%d��\n",i+1,j+1);
				//	  printf("ver---%d��%d��\n",i+1,j+1);
				//������ף�̽��ʧ��
			}
		}

}


//��δ���ɵķ��������ѡ��һ��
int randomchoice(int seed)
{
	int i, j, choice;
	seed = ran(seed);
	choice = int(seed*1.0 / 2147483647 * totalunknown) + 1;
	if (totalunknown == 2 && unknownmine == 1) { opps++; }

	click += 5;
	//	if(totalunknown<(M*N/2) ) click+=20;
	//	if(totalunknown<(M*N/4) ) click+=30;

	//	printf("һ��δ֪%d,�������%d\n",totalunknown,choice);
	//	printexplore();
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (explore[i][j] == 9)
			{
				choice--;
				if (choice == 0) exploit(i, j, 1);

			}
		}
	}
	return seed;
}








//���µ�ͼ�Ĳ���
int initial(double p, int seed)
{
	int i, j, mine, firstx, firsty;
	double x;//x����0-1֮��ľ��ȳ�����
	totalunknown = M * N;
	firstx = M / 2; firsty = N / 2;

	//��������Ϊ0
	for (i = 0; i <= M; i++)
	{
		for (j = 0; j <= N; j++)
		{
			area[i][j] = 0;
		}
	}
	//������������
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			suspect[i][j] = 0;
			explore[i][j] = 9;
			unknown[i][j] = 8;   //��Χ�ĵ��ײ�֪���ĸ���
			if (i == 0 || i == M - 1 || j == 0 || j == N - 1) unknown[i][j] = 5;
			if (i == 0 && j == 0) unknown[i][j] = 3;
			if (i == 0 && j == N - 1) unknown[i][j] = 3;
			if (i == M - 1 && j == 0) unknown[i][j] = 3;
			if (i == M - 1 && j == N - 1) unknown[i][j] = 3;
		}
	}
	//���õ���
	mine = 0;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{

			if (abs(i - firstx) < 2 && abs(j - firsty) < 2) continue;
			//	  if(i==0 && j==N-1) continue;
			//	  if(i==0 && j==0) continue;
			//	  if(i==M-1 && j==0) continue;
			//	  if(i==M-1 && j==N-1) continue;
			seed = ran(seed);
			x = seed * 1.0 / 2147483647;
			if (x < p)
			{
				area[i][j] = 1; //1��������
				mine++;//��������1
			}
		}
	}




	return mine;
}








int main()
{
	int i, j, k, seed, success_seed, round, unknownlast;
	int success, trial;
	int firstx, firsty;//��һ�ε������������
	int mine, plot, groupsize, minlast;
	int start, end;
	double lastrate, p, lastp;
	int group[int((PMAX - PMIN)*M*N) + 1] = { 0 };
	int groupsucceed[int((PMAX - PMIN)*M*N) + 1] = { 0 };
	int grouptime[int((PMAX - PMIN)*M*N) + 1] = { 0 };
	int groupclick[int((PMAX - PMIN)*M*N) + 1] = { 0 };
	groupsize = int((PMAX - PMIN)*M*N) + 1;
	opps = 0;

	FILE *fp;
	FILE *fq;
	fp = fopen("data.txt", "w");
	fq = fopen("click.txt", "w");

	logictimes = 0;
	printf("����һ������ֵ\n");
	scanf("%d", &seed);
	getcommon();

	for (p = PMIN; p <= PMAX; p += PSTEP)
	{
		success = 0;
		for (trial = 1; trial <= T; trial++)
		{
			touchmine = 0;//��������Ϊ0
			seed = ran(seed);


			//seed=trial;



			mine = initial(p, seed); //���õ���
		   // if(mine!=99) continue;

			firstx = M / 2; firsty = N / 2;
			success_seed = seed;


			//�߽����Ϊ0

			// printf("һ����%d���ף�������Ϊ%4.3f\n",mine,mine*1.0/M/N);
			// printarea();
			unknownmine = mine;
			j = 1;//j���ظ�����
			click = 0; //�������
			start = clock();//��ʼ��ʱ

		add1:
			seed = success_seed;
			exploit(firstx, firsty, 1);
			//  exploit(0,0,1);
			 // exploit(0,N-1,1);
			 // exploit(M-1,0,1);
			//  exploit(M-1,N-1,1);
			  //printexplore();
			 // printsuspect();
			 // printunknown();


			for (round = 1; ; round++)
			{
				unknownlast = totalunknown;
				//	 if(trial==1) {printf("round %d, mine %d ,the unknown is %d\n",round, unknownmine, totalunknown);printexplore();}  //������

				cycle(1);//��ʽ����

			 // printexplore();
			 // printsuspect();
			 // printunknown();

		   //	 if(lastrate < 0.2) {break;}
				if (totalunknown == unknownmine) { break; } //���ʣ�µ�ȫ�ǵ��ף�˵���������
				if (totalunknown == unknownlast)
				{
					cycle(2);
				}
				if (totalunknown == unknownlast)
				{
					cycle(3);
				}
				if (totalunknown == unknownlast)
				{
					if (unknownmine < 6 && clearall() == 1)
					{

						cycle(1);
						cycle(2);
						cycle(3);
					}
					else seed = randomchoice(seed);
					//   break;

				}//�������û���κεĿ��ɣ����ʾ̽��ʧ��




				if (touchmine == 1) break;  //���ף�����Ϸ����
			}




			lastrate = (totalunknown - unknownmine)*1.0 / (M*N - mine);
			if (lastrate == 0 && j < REPEAT) { j++; goto add1; } //�����ظ�����ʱ����
			end = clock();
			//  printf("%d,%d,%d,%lf,%d\n",end,start,mine,lastrate,trial);
			plot = (mine - int(PMIN*M*N)) / INTERVAL;
			if (plot >= 0 && plot <= groupsize)  group[plot]++;
			//printf("ʣ�࿪����=%lf\n",lastrate);
			if (lastrate <= JUSTIFY)
			{
				//	 printf("%lf,%d��,�ɹ�,������%d,��߼�¼%d,��Ӧ����%d,%lf\n",p,trial,mine,minlast,k,lastp);
				//	 if(mine>minlast) {minlast=mine;k=trial,lastp=p;}
				//	 printf("������Ŀ%d,��ʱ%d��%d\n",mine,start,end);
				success++;
				if (lastrate > 0 && unknownmine > 1)
				{
					//     printf("trial %d, ʣ�������%d,ʣ��ģ��%d\n",trial,unknownmine,totalunknown);
				//		 printexplore();
				}
				if (totalunknown > 2)
				{
					//	 printexplore();
				}
				if (mine > minlast) { minlast = mine; k = trial; lastp = p; }
				if (plot >= 0 && plot < groupsize) { groupsucceed[plot]++; grouptime[plot] += (end - start); groupclick[plot] += int(click); }

			}
			else
			{
				if (TEST == 1)
				{
					//       printf("%d,������%d,ʣ��%lf,ʣ������%d,ʧ��,��߼�¼%lf,��Ӧ%d\n",trial,mine,lastrate,unknownmine,minlast,j);
				   //	if(lastrate<minlast)  {minlast=lastrate;j=trial;}

					 // 		printexplore();
				   //		printunknown();
				   //		printsuspect();
				}
			}
			if (DISPLAY == 1)
			{

				if (lastrate == 0) { system("cls"); printf("Oh,yeah!ɨ�׳ɹ�!\n"); display(); }
				else printf("ɨ��ʧ��\n");

			}



		}
		// printf("p=%lfʱ���ɹ���%lf\n",p,success*1.0/T);
		printf("��ɽ���%lf\n", (p - PMIN + PSTEP) / (PMAX - PMIN));
	}
	for (i = 0; i < groupsize; i++)
	{
		// printf("%d  %d  %d\n",i,groupsucceed[i],group[i]);
		if (group[i] != 0) { fprintf(fp, "%d\t%lf\t%lf\n", i*INTERVAL + int(PMIN*M*N), groupsucceed[i] * 1.0 / group[i], grouptime[i] * 1.0 / groupsucceed[i] / REPEAT); }
		if (group[i] != 0) { fprintf(fq, "%d\t%d\t%lf\n", i*INTERVAL + int(PMIN*M*N), groupclick[i], groupclick[i] * 1.0 / groupsucceed[i]); }
		if (group[i] != 0) { printf("%d\t%d\t%d\t%lf\t%lf\n", i*INTERVAL + int(PMIN*M*N), groupsucceed[i], group[i], groupsucceed[i] * 1.0 / group[i], grouptime[i] * 1.0 / groupsucceed[i] / REPEAT); }
		// 	   if(group[i]!=0) {printf("%d\t%d\t%lf\n", i+int(PMIN*M*N),groupclick[i],groupclick[i]*1.0/groupsucceed[i]);}
	  //	    if(group[i]!=0) {printf("%d\n",grouptime[i]);}
	}
	end = clock();
	printf("һ������%d���߼�������ʱ%d����\n", logictimes, end);
	printf("�����ֶ�ѡһ����Ϊ%d\n", opps);
	return 0;
}




//int add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	printf("hehe\n");
//	int a = 10, b = 20, c;
//	c = add(a, b);
//}


//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100; i++)
//		printf("%d ", i);
//	for (i = 0; i < 100; i++)
//		printf("%d ", 10 - i);
//	return 0;
//}


//int add(int x, int y)
//{
//	int z;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret;
//	ret = add(a, b);
//	return 0;
//}


//typedef struct stu
//{
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//}stu;
//void print1(stu tmp)
//{
//	printf("name: %s\n",tmp.name);
//	printf("age: %d\n", tmp.age);
//	printf("tele: %s\n", tmp.tele);
//	printf("sex: %s\n", tmp.sex);
//}
//void print2(stu* p)
//{
//	printf("name: %s\n", p->name);
//	printf("name: %d\n", p->age);
//	printf("name: %s\n", p->tele);
//	printf("name: %s\n", p->sex);
//}
//int main()
//{
//	stu s = { "zhangshan",20,"122333","man" };
//	print1(s);
//	print2(&s);
//}


//struct s
//{
//	int a;
//	char c;
//	char arr[20];
//	double b;
//};
//struct t
//{
//	char ch[10];
//	struct s s1;
//	char* p;
//};
//int main()
//{
//	char arr[] = "hello world";
//	struct t t1 = { "hehe",{100,'w',"hehe",3.14},arr };
//	printf("%s\n", t1.ch);
//	printf("%s\n", t1.s1.arr);
//	printf("%lf\n", t1.s1.b);
//	printf("%s\n", t1.p);
//	return 0;
//}


//typedef struct stu
//{
//	char nam[20];
//	short age;
//	char tele[12];
//	char sex[5];
//}stu;
//int main()
//{
//	struct stu s1 = {""}
//	stu s2;
//}


//struct stu
//{
//	char num[5];
//	char name[10];
//	int math;
//	int english;
//}stu[5];
//int main()
//{
//	int i;
//	float aver[5];
//	for (i = 0; i < 5; i++)
//	{
//		printf("\ninput the score  of student%d:\n", i + 1);
//	} 
//}


//struct stu
//{
//	char num[5];
//	char name[10];
//	int math;
//	int english;
//};
//int main()
//{
//	struct stu stu1 = { "0001","����",85,93 };
//	printf("num:%s\n", stu1.num);
//	printf("name:%s\n", stu1.name);
//	printf("math score is %d and english score is %d\n", stu1.math, stu1.english);
//	return 0;
//}

//void addfunc()
//{
//	int answer, result;
//	int firstnum, secondnum;
//	firstnum = rand() % RANGE;
//	secondnum = rand() % RANGE;
//	printf("%d + %d = ", firstnum, secondnum);
//	while (scanf("%d", &answer) != 1)
//	{
//		printf("������Ĵ𰸲�������������������:\n");
//		getchar();//���壿
//		printf("%d + %d = ", firstnum, secondnum);
//		getchar();
//	}
//	result = firstnum + secondnum;
//	if (result == answer)
//		printf("��ȷ\n");
//	else
//		printf("��ȷ��Ϊ %d\n", result);
//}
//void showmenu()
//{
//	printf("     Сѧ��ѧѧϰϵͳ  \n");
//	printf(" --------���˵�--------\n");
//	printf("|       1 �ӷ���       |\n");
//	printf("|       2 ������       |\n");
//	printf("|       3 �˷���       |\n");
//	printf("|       4 ������       |\n");
//	printf("|       0 �˳�ϵͳ     |\n");
//}
//int main()
//{
//	int choicenum;
//	srand((unsigned int)time(NULL));
//	int choice = 1;
//	do {
//		showmenu();
//		printf("�����룺");
//		scanf("%d", &choice);
//		if (choice > 4 || choice < 0)
//		{
//			printf("�����������������!\n\n\n\n\n");
//			continue;
//		}
//		switch (choice)
//		{
//		case 1:
//			addfunc();
//			break;
//		/*case 2:
//			subfunc();
//			break;
//		case 3:
//			mulfunc();
//			break;
//		case 4:
//			divfunc();
//			break;*/
//		case 0:
//			printf("ллʹ���������ټ���");
//			break;
//		}
//	} while (choice!=0);
//	return 0;
//}


//int main()
//{
//	int a, b, c;
//	int *p1, *p2, *p;
//	p1 = &a, p2 = &b, p = &c;
//	scanf("%d %d", p1, p2);
//	*p = *p1;
//	*p1 = *p2;
//	*p2 = *p;
//	printf("%d %d", *p1, *p2);
//	return 0;
//}


//int main()
//{
//	int a, b, c;
//	int*p1, *p2, *p;
//	int **p11, **p22, **pp;
//	p1 = &a;
//	p2 = &b;
//	p = &c;
//	scanf("%d %d", p1, p2);
//	p11 = &p1;
//	p22 = &p2;
//	pp = &p;
//	**pp = **p11;//**pp���壬ppΪp�ĵ�ַ��*pp��ʾp�е����ݣ���pΪc�ĵ�ַ������**ppΪ������pp�õ�p�ٽ�����p
//	**p11 = **p22;
//	**p22 = **pp;
//	printf("%d %d", a, b);
//	return 0;
//}


//int main()
//{
//	int a[3][3], i, j, b[3] = { 0 }, c[3] = { 0 };
//	int(*p)[3] = a;
//	for (i = 0; i < 3; i++)
//		for (j = 0; j < 3; j++)
//			scanf("%d", *(p + i) + j);
//	for(i=0;i<3;i++)
//		for (j = 0; j < 3; j++)
//		{
//			b[i] = b[i] + *(*(p + i) + j);
//			c[i] = c[i] + *(*(p + j) + i);
//		}
//	for (i = 0; i < 3; i++)
//		printf("%4d", b[i]);
//	printf("\n");
//	for (i = 0; i < 3; i++)
//		printf("%4d", c[i]);
//	return 0;
//}


//int main()
//{
//	int a[3][3] = { 0 }, b[3] = { 0 }, c[3] = { 0 }, i, j;
//	int(*p)[3] = a;
//	for (i = 0; i < 3; i++)
//		for (j = 0; j < 3; j++)
//			scanf("%d",*(p + i) + j);
//	for(i=0;i<3;i++)
//		for (j = 0; j < 3; j++)
//		{
//			b[i] += *(*(p + i) + j);
//			c[i] += *(*(p + j) + i); 
//		}
//	for (i = 0; i < 3; i++)
//		printf("%4d", b[i]);
//	printf("\n");
//	for (i = 0; i < 3; i++)
//		printf("%4d", c[i]);
//	return 0;
//}


//int main()
//{
//	int a[3][3] = { 0 }, b[3] = { 0 }, c[3] = { 0 };
//	int i, j;
//	int (*p)[3] = a;
//	for (i = 0; i < 3; i++)
//		for (j = 0; j < 3; j++)
//			scanf("%d", *(p + i) + j);
//	for (i = 0; i < 3; j++)
//		for (j = 0; j < 3; j++)
//		{
//			b[i] += *(*(p + i) + j);
//			c[i] += *(*(p + j) + i);
//		}
//	for (i = 0; i < 3; i++)
//	{
//		printf("%4d", b[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 3; i++)
//	{
//		printf("%4d", c[i]);
//	}
//	return 0;
//}


//int main()
//{
//	char* month[7] = { "","january","february","march","april","may","june" };
//	int n;
//	printf("please put month\n");
//	scanf("%d", &n);
//	printf("%s", *(month+n));
//}


//ָ��򻯱���
//����a[10]
//p=a+strlen(a) �ȼ���p=&a[0+strlen(a)]
//
//������a
//nΪĳ��
//��
//
//*(a+n) �������ȼ���*a[0+n]   ��������

//int main()
//{
//	//����һ��ָ�����鴢��Ӣ���·�����
//	char *month_name[13] = { "","january","february","march","april","may","june","july","august",
//							"spetember","october","november","december" };
//	int n;
//	printf("�������·�:\n");
//	scanf("%d", &n);
//	if ((n <= 12) && (n >= 1))
//	{
//		printf("%s\n", *(month_name + n));//�ȼ���*month_name[0+n]
//	}
//	else
//		printf("�������\n");
//	return 0;
//}


//int main()
//{
//	char* p;
//	char* q;
//	char a[nmax];
//	int flag = 1;
//	gets(a);
//	p = a;
//	q = &a[ 0 + strlen(a) - 1];
//	while(p < q)
//	{
//		if (*p != *q)
//		{
//			flag = 0;
//			break;
//		}
//		p++;
//		q--;
//	}
//	if (flag == 1)
//		printf("yes");
//	else
//		printf("no");
//
//	return 0;
//}


//int main()
//{
//	char a[100];
//	char* p = a;//�ȼ���char* p=&a[0]
//	char* q;
//	int flag = 1;
//	gets(a);
//	//ָ��qָ���ַ�β��
//	q = &a[0 + strlen(a) - 1];//�ȼ���q=a+strlen(a)-1
//	while (p < q)
//	{
//		if (*p != *q)
//		{
//			flag = 0;
//			break;
//		}
//		p++;
//		q--;
//	}
//	if (flag)
//		printf("yes\n");
//	else
//		printf("no");
//	return 0;
//}