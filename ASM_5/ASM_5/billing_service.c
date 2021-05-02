#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "model.h"
#include"de.h"
#include"billing_file.h"
lpBillingNode billingList = NULL;    // �Ʒ���Ϣ����

int addBilling(Billing billing)
{
	return saveBilling(&billing, BILLINGPATH);
}

void initBillingList()
{
	lpBillingNode head = NULL;
	if (billingList == NULL)
	{
		head = (lpBillingNode)malloc(sizeof(BillingNode));

		head->next = NULL;
		billingList = head;
	}
}

void releaseBillingList()
{
	//��������
	lpBillingNode cur = billingList;
	lpBillingNode next = NULL;
	while (cur != NULL)
	{
		next = cur->next;//����ڴ��ͷ�ǰ��next��������
		free(cur); //�ͷŽ���ڴ�
		cur = next;
	}
	billingList = NULL;
}


int getBilling()
{
	int nCount = 0;   // �Ʒ���Ϣ����
	Billing* pBilling = NULL;  // �Ʒ���Ϣ
	lpBillingNode node = NULL;
	int i = 0;    // ѭ������
	lpBillingNode cur = NULL;

	// �������Ϊ�գ��ͷ�����
	if (billingList != NULL)
	{
		releaseBillingList();
	}

	// ��ʼ������
	initBillingList();

	// ��ȡ�Ʒ���Ϣ����
	nCount = getBillingCount(BILLINGPATH);

	// ��̬�����ڴ�
	pBilling = (Billing*)malloc(sizeof(Billing) * nCount);
	if (pBilling != NULL)
	{
		// ��ȡ�Ʒ���Ϣ
		if (FALSE == readBilling(pBilling, BILLINGPATH))
		{
			free(pBilling);
			return FALSE;
		}

		// ���Ʒ���Ϣ���浽������
		for (i = 0, node = billingList; i < nCount; i++)
		{
			// Ϊ��ǰ�������ڴ�
			cur = (lpBillingNode)malloc(sizeof(BillingNode));
			// �������ʧ�ܣ����ڷ���FALSEǰ����Ҫ�ͷ�pBilling���ڴ�
			if (cur == NULL)
			{
				free(pBilling);
				return FALSE;
			}

			// ��ʼ���µĿռ䣬ȫ����ֵΪ0
			memset(cur, 0, sizeof(BillingNode));

			// ��������ӵ������
			cur->data = pBilling[i];
			cur->next = NULL;

			// �������ӵ�������
			node->next = cur;
			node = cur;
		}
		free(pBilling);
		return TRUE;
	}
	return FALSE;
}
Billing* queryBilling(const char* pName, int* pIndex)
{
	lpBillingNode node = NULL;
	int nIndex = 0;

	if (FALSE == getBilling())
	{
		return NULL;
	}

	// ��������
	node = billingList->next;
	while (node != NULL)
	{
		// ��ѯ��������ͬ������û�н���ļƷ���Ϣ
		if (strcmp(node->data.aCardName, pName) == 0 && node->data.nStatus == 0)
		{
			return &node->data;
		}

		node = node->next;
		nIndex++;
		*pIndex = nIndex;
	}

	return NULL;
}
