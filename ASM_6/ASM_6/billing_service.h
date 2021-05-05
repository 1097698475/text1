#define _CRT_SECURE_NO_WARNINGS

#ifndef BILLING_SERVICE_H
#define BILLING_DERVICE_H
#include "model.h"
int initBillingList();
void releaseBillingList();
int getBilling();
Billing *checkBilling(const char *pName, int *pIndex);
#endif