#ifndef TOOL_H
#define TOOL_H

//分解时间→日历时间
void timeToString(time_t t ,char* pBuf );

//日历时间→分解时间
time_t stringToTime(char* pTime);


#endif