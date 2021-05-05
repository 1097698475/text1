//#define _CRT_SECURE_NO_WARNINGS
//#include<time.h>
//
//
////将time_t类型转换为字符串，字符串格式为"年—月—日 时：分" 格式的字符串
//void timeToString(time_t t, char* pBuf)
//{
//	struct tm *pTimeInfo;  //定义一个tm类型的结构体指针
//
//	pTimeInfo = localtime(&t);    //获得tm结构体的时间
//	strftime(pBuf, 20, "%Y-%m-%d %H:%M",pTimeInfo);    //将时间转换为"年-月-日 时-分"格式字符串
//}