#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>   // �����ļ�����ͷ�ļ�
#include <stdlib.h>  // ������̬�ڴ����ͷ�ļ�
#include <time.h> 
#include"model.h"
#define FALSE 0
#define TRUE  1
#define BILLINGPATH "billing.dat" // �Ʒ���Ϣ����·��

int saveBilling(const Billing* pBilling, const char* pPath)  //����������Ϣ
{
	FILE* fp = NULL;   // �ļ��ṹ��ָ��

	// ��׷�ӷ�ʽ��һ���������ļ�
	if ((fp = fopen(pPath, "ab")) == NULL)
	{
		// �����׷�ӷ�ʽʧ�ܣ�����ֻд��ʽ����һ���ļ�����
		if ((fp = fopen(pPath, "wb")) == NULL)
		{
			return FALSE;
		}
	}

	// ���Ʒ���Ϣ���浽�ļ���
	fwrite(pBilling, sizeof(Billing), 1, fp);

	// �ر��ļ�
	fclose(fp);

	return TRUE;
}

int readBilling(Billing* pBilling, const char* pPath)  //��ȡ������Ϣ
{
	FILE* fp = NULL;  // �ļ��ṹ��ָ��
	int nIndex = 0;

	// ��ֻ����ʽ���ļ��������ʧ�ܣ����ȡʧ��
	if ((fp = fopen(pPath, "rb")) == NULL)
	{
		return FALSE;
	}

	// �����ļ��Ŀ�ͷ
	fseek(fp, 0, SEEK_SET);


	// ��ȡ�ļ�����
	while (!feof(fp))
	{
		if (fread(&pBilling[nIndex], sizeof(Billing), 1, fp) != 0)
		{
			nIndex++;
		}
	}

	// �ر��ļ�
	fclose(fp);

	return TRUE;
}
/*************************************************
[������] getBillingCount
[����]  ��ȡ�ļ��мƷ���Ϣ����
[����]  pPath: ����Ʒ���Ϣ�ļ�·��
[����ֵ] int:�Ʒ���Ϣ����
*************************************************/
int getBillingCount(const char* pPath)
{
	FILE* fp = NULL;
	int nCount = 0;
	Billing* pBilling = (Billing*)malloc(sizeof(Billing));

	// ��ֻ����ʽ���ļ��������ʧ�ܣ����ȡʧ��
	if ((fp = fopen(pPath, "rb")) == NULL)
	{
		return 0;
	}

	// ��ȡ�ļ�����
	while (!feof(fp))
	{
		if (fread(pBilling, sizeof(Billing), 1, fp) != 0)
		{
			nCount++;
		}
	}

	// �ر��ļ�
	fclose(fp);
	free(pBilling);
	return nCount;
}


//���Ա������Ѽ�¼ 
int saveBillingTest()
{
	Billing billing;  // �Ʒ���Ϣ
	// ������Ѽ�¼
	char aName[18] = { 0 };    // �ϻ�����
	printf("----------�ϻ�----------\n");
	printf("�������ϻ�����(����Ϊ1~18):");
	scanf("%s", billing.aCardName);              // �ϻ�����
	billing.tStart = time(NULL);                 // �ϻ�ʱ��
	billing.tEnd = 0;                            // �»�ʱ��
	billing.nStatus = 0;                         // ����״̬
	billing.fAmount = 0;                         // ���ѽ��
	billing.nDel = 0;                            // ɾ����ʶ

	// ���Ʒ���Ϣ���浽�ļ���
	return saveBilling(&billing, BILLINGPATH);
}

int updateBilling(Billing *pBilling,char *pPath,int nIndex)
{
  FILE* fp = NULL;    // �ļ�ָ��
  int nLine = 0;      // �ļ�����Ϣ��
  long lPosition = 0; // �ļ�λ�ñ��
  Billing bBuf;
  // �Զ�дģʽ���ļ������ʧ�ܣ�����FALSE
  if((fp = fopen(pPath, "rb+")) == NULL)
  {
    return FALSE;
  }
  while((!feof(fp)) && (nLine < nIndex-1))
  {
    if(fread(&bBuf, sizeof(Billing), 1, fp) != 0)
    {
      // ��ȡ�ļ���ʶλ��
      lPosition = ftell(fp);
      nLine++;
    }
  }
  // �Ƶ��ļ���ʶλ��
  fseek(fp, lPosition, 0);
  fwrite(pBilling, sizeof(Billing), 1, fp);  
  fclose(fp);
  return TRUE;
}