#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include "model.h"
#include "global.h"
#include "moneyfile.h"

//将充值、退费信息保存到文件
int saveMoney(const Money* pMoney, const char* pPath)
{
	FILE* fp = NULL;

	//以追加的方式打开一个文件
	if ((fp = fopen(pPath, "ab")) == NULL)
	{
		//只写的方式创建一个文件 打开
		if ((fp = fopen(pPath, "wb")) == NULL)
		{
			return FALSE;
		}
	}

	//将充值、退费信息保存到文件中
	//fwrite指针-要输出数据的地址 要写入的字节数 要进行写入size字节的数据项的个数 目标文件指针
	fwrite(pMoney, sizeof(Money), 1, fp);

	//关闭文件
	fclose(fp);

	return TRUE;
}
