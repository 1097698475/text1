#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include "model.h"
#include "global.h"
#include "moneyfile.h"

//����ֵ���˷���Ϣ���浽�ļ�
int saveMoney(const Money* pMoney, const char* pPath)
{
	FILE* fp = NULL;

	//��׷�ӵķ�ʽ��һ���ļ�
	if ((fp = fopen(pPath, "ab")) == NULL)
	{
		//ֻд�ķ�ʽ����һ���ļ� ��
		if ((fp = fopen(pPath, "wb")) == NULL)
		{
			return FALSE;
		}
	}

	//����ֵ���˷���Ϣ���浽�ļ���
	//fwriteָ��-Ҫ������ݵĵ�ַ Ҫд����ֽ��� Ҫ����д��size�ֽڵ�������ĸ��� Ŀ���ļ�ָ��
	fwrite(pMoney, sizeof(Money), 1, fp);

	//�ر��ļ�
	fclose(fp);

	return TRUE;
}
