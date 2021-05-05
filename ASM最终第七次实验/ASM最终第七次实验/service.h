#ifndef SERVICE_H
#define SERVICE_H
#include"model.h"


//上机
int doLogon(const char* pName, const char* pPwd, LogonInfo *pInfo);

//下机
int doSettle(const char *pName, const char* pPwd, SettleInfo *pInfo);


#endif