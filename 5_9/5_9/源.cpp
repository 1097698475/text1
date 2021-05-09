#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int hour, min;
	scanf("%d:%d", &hour, &min);

	if (hour >= 0 && hour <= 11)
		printf("Only %02d:%02d.  Too early to Dang.", hour, min);

	if (hour >= 12)
	{
		int count;
		if (hour == 12 && min == 0)
		{
			printf("Only %02d:%02d.  Too early to Dang.", hour, min);
		}
		else
		{
			count = hour % 12;
			if (min > 0)
				count++;
			for (int i = 0; i < count; i++)
				printf("Dang");
		}
	}
	return 0;
}