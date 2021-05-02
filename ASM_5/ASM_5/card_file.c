#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>    // �����ļ��ṹ��ͷ�ļ�
#include <string.h>   // �����ַ�����ͷ�ļ�
#include <stdlib.h>   // ����standard library��׼��ͷ�ļ�
#include"tool.h"
#include"de.h"
#include"model.h"
int saveCard(const Card* pCard, const char* pPath)
{
	FILE* fp = NULL;   // �ļ��ṹ��ָ��
	
	// ��׷�ӵ�ģʽ���ļ��������ʧ�ܣ�����ֻд��ģʽ���ļ�
	if((fp = fopen(pPath,"ab")) == NULL)
	{
		if((fp = fopen(pPath,"wb")) == NULL)
		{
			return FALSE;
		}
	}
	
	fwrite(pCard, sizeof(Card), 1, fp);
	
	// �ر��ļ�
	fclose(fp);
	return TRUE;
}
void inputCard(Card card)// ���뿨��Ϣ
{
	char aName[32] = {0};   // ����Ŀ���
	char aPwd[20] = {0};    // ���������           
	struct tm* endTime;     // ��ֹʱ��
	struct tm* startTime;   // ����ʱ��
	printf("----------��ӿ�----------\n");
	// ��ʾ����������Ŀ���
	printf("�����뿨��(����Ϊ1~18)��");
	scanf("%s", aName);
	// ������Ŀ��ű��浽���ṹ����
	strcpy(card.aName, aName);
	// ��ʾ��������������
	printf("����������(����Ϊ1~8)��");
	scanf("%s", aPwd);
	// ����������뱣�浽���ṹ����
	strcpy(card.aPwd, aPwd);
	printf("�����뿪�����(RMB)��");
	scanf("%f", &card.fBalance);
	card.fTotalUse = card.fBalance;    // ��ӿ�ʱ���ۼƽ����ڿ������
	card.nDel = 0;                     // ɾ����ʶ
	card.nStatus = 0;                  // ��״̬
	card.nUseCount = 0;                // ʹ�ô���
	card.tStart = card.tEnd = card.tLastUse = time(NULL); 
	// ����ʱ�䣬��ֹʱ�䣬���ʹ��ʱ�䶼Ĭ��Ϊ��ǰʱ�䡣
	// ���ݿ���ʱ�䣬�����ֹʱ�䣬ÿ�ſ�����Ч��Ϊһ��
	startTime = localtime(&card.tStart);
	endTime = localtime(&card.tEnd);
	endTime->tm_year = startTime->tm_year + 1;
	card.tEnd = mktime(endTime);
}

void ShowCard(Card card)// ��ʾ����Ϣ
{ char aLastTime[50];
 // ������ı�ͷ
 printf("����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");
   timeToString(card.tLastUse, aLastTime);
   printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n", card.aName, card.nStatus, card.fBalance, 
  card.fTotalUse, card.nUseCount, aLastTime);

}

int updateCard(const Card* pCard, const char* pPath, int nIndex)
{
  FILE* fp = NULL;    // �ļ�ָ��
  int nLine = 0;      // �ļ�����Ϣ��
  long lPosition = 0; // �ļ�λ�ñ��
  Card bBuf;
  // �Զ�дģʽ���ļ������ʧ�ܣ�����FALSE
  if((fp = fopen(pPath, "rb+")) == NULL)
  {
    return FALSE;
  }
  while((!feof(fp)) && (nLine < nIndex-1))
  {
    if(fread(&bBuf, sizeof(Card), 1, fp) != 0)
    {
      // ��ȡ�ļ���ʶλ��
      lPosition = ftell(fp);
      nLine++;
    }
  }
  // �Ƶ��ļ���ʶλ��
  fseek(fp, lPosition, 0);
  fwrite(pCard, sizeof(Card), 1, fp);  
  fclose(fp);
  return TRUE;
}

int getCardCount(const char* pPath)
{
  FILE* fp = NULL;  // �ļ�ָ��
  int nIndex = 0;   // ����Ϣ����
  Card* pCard = (Card*)malloc(sizeof(Card));

  // ��ֻ��ģʽ���ļ�
  if((fp = fopen(pPath, "rb")) == NULL)
  {
    return 0;
  }

  // ���ж�ȡ�ļ����ݣ���ȡ���ļ��������ǿ���Ϣ��
  while(!feof(fp))
  {
    if(fread(pCard, sizeof(Card), 1, fp) != 0)
    {
      nIndex++;
    }
  }

  // �ر��ļ�
  fclose(fp);
  free(pCard);
  return nIndex;
}
int isExsit(const char* pNum, const char* pPath)
{
  FILE* fp = NULL;  // �ļ��ṹ��ָ��
  char aName[18]={0};   // ��Ŷ�ȡ���Ŀ���

  // ��ֻ���ķ�ʽ���ļ�
  if((fp = fopen(pPath, "rb")) == NULL)
  {
    return FALSE;
  }

  // ѭ����ȡ�ļ�������ȡ���ļ���βʱ����
  while(!feof(fp))
  {
    // ��ȡ���ţ����ȽϿ����Ƿ�Ϊ��ǰ���ҵĿ���
    if(fread(aName, sizeof(aName), 1, fp) != 0)
    {
      if(strcmp(aName, pNum) == 0)
      {
        fclose(fp);
        return TRUE;
      }
      else
      {
        // �Ƶ���һ����¼
        fseek(fp, sizeof(Card) - sizeof(aName), SEEK_CUR);
      }
    }
  }
  fclose(fp);
  return FALSE;
}


