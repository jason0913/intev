/* 
* @Author: jql
* @Date:   2015-07-29 08:13:50
* @Last Modified by:   jql
* @Last Modified time: 2015-07-29 10:39:55
  show time
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int isleap(int year)
{
	if ((0 ==year %4 && 0!= year %100) || (0 == year %400))
	{
		return 1;
	}
	else
		return 0;
}
void NextTime(int &year,int &mouth,int &day,int &hour,int &min,int &sec)
{
	static int second = sec;
	second++;
	int currmouth = mouth;
	int currday = day;
	if (second >= 60)
	{
		second =0;
		min++;
		if (min >= 60)
		{
			min =0;
			hour++;
			if (hour >=24)
			{
				hour =0;
				day++;
				switch(currmouth)
				{
					case 1 :;
					case 3 :;
					case 5 :;
					case 7 :;
					case 8 :;
					case 10 :;
					case 12 :;
						currday = 31;
						break;
					case 4 :;
					case 6 :;
					case 9 :;
					case 11 :;
						currday =30;
						break;
					case 2:
						if (isleap(year))
						{
							currday = 29;
						}
						else
							currday =28;
						break;
				}
				if (day >= currday)
				{
					day =1;
					mouth++;
					if (mouth >=12)
					{
						mouth =1;
						year++;
					}
				}
			}
		}
	}
	if (second <10)
	{
		printf("%d %2d %2d %2d:%2d:0%d\n", year,mouth,day,hour,min,second);
	}
	else if (second <10 && min <10)
	{
		printf("%d %2d %2d %2d:0%d:0%d\n", year,mouth,day,hour,min,second);
	}
	else if (second <10 && min <10 && hour <10)
	{
		printf("%d %2d %2d 0%d:0%d:0%d\n", year,mouth,day,hour,min,second);
	}
	else
		printf("%d %2d %2d %2d:%2d:%2d\n", year,mouth,day,hour,min,second);
}

static int second =50;
static int min =59;
static int hour =23;
static int day =31;
static int mouth =12;
static int year =2015;
void sig_func(int )
{
	// printf("got alarm\n");
	NextTime(year,mouth,day,hour,min,second);
	alarm(1);
}
int main() {

	/*while(1)
	{
		NextTime(year,mouth,day,hour,min,second);
		sleep(1);
	}*/
	signal(SIGALRM,sig_func);
	alarm(1);
	while(1)
	{
		sleep(3);
	}
    return 0;
}