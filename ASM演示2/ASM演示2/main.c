#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>

#include"menu.h"
#include"model.h"
#include"tool.h"
#include"card_service.h"
#include"card_file.h"

int main(void){
	int nSelection=-1;
	char rubbish[1000];
	int i;

	printf("\n--------��ӭ����Ʒѹ���ϵͳ--------��\n");
	printf("\n");
	printf("*****��ҵ��ֵ�Żݶ��*****\t\n*****��ҵ�ڼ� ����ÿ��100����50 ��ֵÿ��100����20 �ϲ��ⶥ*****\n");
	printf("\n");

    initCardList();/*��ʼ������*/

	do{

		outputMenu();	//����˵�
		nSelection=-1;
		i = scanf("%d",&nSelection);

		//��ֹ�����ı��ȫ�̱��� T.T 
		while(i==0)
		{
			 // ��ջ�����
			 scanf("%s", rubbish); 
			 printf("\n\n��������ȷ�Ĳ˵����:\n\n ");
			 i=scanf("%d",& nSelection);
		}
	

		//���ݱ��ִ��
		switch(nSelection){
		case 1:
			add();			//��ӿ�
			break;
		case 2:
			 query();		//��ѯ��
			break;
		case 3:
		    logon();		//�ϻ�
			break;
        case 4:
			settle();		//�»�
			break;
		case 5:
		    addMoney();		//��ֵ
			break;
		case 6:				//�˷�
		    refundMoney();
			break;
        case 7:				//��ѯͳ��
			queryStatistics();
			break;
        case 8:				//ע��
			annul();
			break;
		case 9:				//��ѯ����
			findpwd();
			break;
		case 10:			//�޸�����
			alterpwd();
			break;
		case 0:				//�˳�
			exitApp();
			break;
		default:printf("\n\n��������ȷ�Ĳ˵����:");break;
		}
	}while(nSelection!=0);
	return 0;
}



