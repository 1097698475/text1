#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>    // 包含文件结构体头文件
#include <string.h>   // 包含字符处理头文件
#include <stdlib.h>   // 包含standard library标准库头文件
#include"tool.h"
#include"de.h"
#include"model.h"
int saveCard(const Card* pCard, const char* pPath)
{
	FILE* fp = NULL;   // 文件结构体指针
	
	// 以追加的模式打开文件，如果打开失败，则以只写的模式打开文件
	if((fp = fopen(pPath,"ab")) == NULL)
	{
		if((fp = fopen(pPath,"wb")) == NULL)
		{
			return FALSE;
		}
	}
	
	fwrite(pCard, sizeof(Card), 1, fp);
	
	// 关闭文件
	fclose(fp);
	return TRUE;
}
void inputCard(Card card)// 输入卡信息
{
	char aName[32] = {0};   // 输入的卡号
	char aPwd[20] = {0};    // 输入的密码           
	struct tm* endTime;     // 截止时间
	struct tm* startTime;   // 开卡时间
	printf("----------添加卡----------\n");
	// 提示并接收输入的卡号
	printf("请输入卡号(长度为1~18)：");
	scanf("%s", aName);
	// 将输入的卡号保存到卡结构体中
	strcpy(card.aName, aName);
	// 提示并接收输入密码
	printf("请输入密码(长度为1~8)：");
	scanf("%s", aPwd);
	// 将输入的密码保存到卡结构体中
	strcpy(card.aPwd, aPwd);
	printf("请输入开卡金额(RMB)：");
	scanf("%f", &card.fBalance);
	card.fTotalUse = card.fBalance;    // 添加卡时，累计金额等于开卡金额
	card.nDel = 0;                     // 删除标识
	card.nStatus = 0;                  // 卡状态
	card.nUseCount = 0;                // 使用次数
	card.tStart = card.tEnd = card.tLastUse = time(NULL); 
	// 开卡时间，截止时间，最后使用时间都默认为当前时间。
	// 根据开卡时间，计算截止时间，每张卡的有效期为一年
	startTime = localtime(&card.tStart);
	endTime = localtime(&card.tEnd);
	endTime->tm_year = startTime->tm_year + 1;
	card.tEnd = mktime(endTime);
}

void ShowCard(Card card)// 显示卡信息
{ char aLastTime[50];
 // 输出表格的表头
 printf("卡号\t状态\t余额\t累计使用\t使用次数\t上次使用时间\n");
   timeToString(card.tLastUse, aLastTime);
   printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n", card.aName, card.nStatus, card.fBalance, 
  card.fTotalUse, card.nUseCount, aLastTime);

}

int updateCard(const Card* pCard, const char* pPath, int nIndex)
{
  FILE* fp = NULL;    // 文件指针
  int nLine = 0;      // 文件卡信息数
  long lPosition = 0; // 文件位置标记
  Card bBuf;
  // 以读写模式打开文件，如果失败，返回FALSE
  if((fp = fopen(pPath, "rb+")) == NULL)
  {
    return FALSE;
  }
  while((!feof(fp)) && (nLine < nIndex-1))
  {
    if(fread(&bBuf, sizeof(Card), 1, fp) != 0)
    {
      // 获取文件标识位置
      lPosition = ftell(fp);
      nLine++;
    }
  }
  // 移到文件标识位置
  fseek(fp, lPosition, 0);
  fwrite(pCard, sizeof(Card), 1, fp);  
  fclose(fp);
  return TRUE;
}

int getCardCount(const char* pPath)
{
  FILE* fp = NULL;  // 文件指针
  int nIndex = 0;   // 卡信息数量
  Card* pCard = (Card*)malloc(sizeof(Card));

  // 以只读模式打开文件
  if((fp = fopen(pPath, "rb")) == NULL)
  {
    return 0;
  }

  // 逐行读取文件内容，获取的文件行数就是卡信息数
  while(!feof(fp))
  {
    if(fread(pCard, sizeof(Card), 1, fp) != 0)
    {
      nIndex++;
    }
  }

  // 关闭文件
  fclose(fp);
  free(pCard);
  return nIndex;
}
int isExsit(const char* pNum, const char* pPath)
{
  FILE* fp = NULL;  // 文件结构体指针
  char aName[18]={0};   // 存放读取出的卡号

  // 以只读的方式打开文件
  if((fp = fopen(pPath, "rb")) == NULL)
  {
    return FALSE;
  }

  // 循环读取文件，当读取到文件结尾时结束
  while(!feof(fp))
  {
    // 读取卡号，并比较卡号是否为当前查找的卡号
    if(fread(aName, sizeof(aName), 1, fp) != 0)
    {
      if(strcmp(aName, pNum) == 0)
      {
        fclose(fp);
        return TRUE;
      }
      else
      {
        // 移到下一条记录
        fseek(fp, sizeof(Card) - sizeof(aName), SEEK_CUR);
      }
    }
  }
  fclose(fp);
  return FALSE;
}


