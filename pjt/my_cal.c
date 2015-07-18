#include <stdio.h>
#include <stdlib.h>

/*
the program to display cal
*/

void usage();
int leap_year(int year);
int days_mounth(int year,int mounth);
int up_to_now_days(int year,int mounth,int day);
void show_head(int year,int mounth);
void show_days(int days,int week_today);
void show_oneyear(int year);


char *weeks[7]=
	{"Su","Mo","Tu","We","Th","Fr","Sa"};
char *mounths[12]=
	{"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
int mounth_days[]={31,28,31,30,31,30,31,31,30,31,30,31};
int leap_mounth_days[]={31,29,31,30,31,30,31,31,30,31,30,31};

int week_today =6;
int total_days=0;

int main(int argc, char const *argv[])
{
	int year,mounth,days;

	if ((argc >3) || (argc <2))
		usage();

	if (3 == argc)
	{
		year = atoi(argv[1]);
		mounth = atoi(argv[2]);
		days = days_mounth(year,mounth);
		if (mounth >12 || mounth < 1)
		{
			printf("mounth: 1-12\n");
			exit(-1);
		}
		if (year <1)
		{
			printf("year: 1-5000\n");
			exit(-1);
		}

		show_head(year,mounth);
		total_days = up_to_now_days(year,mounth,1);
		week_today = (week_today+ total_days) %7;
		show_days(days,week_today);
		printf("\n");
		printf("%d\n", total_days);
		printf("%d\n", week_today);
	}
	else if (2 == argc)
	{
		year = atoi(argv[1]);

		if (year <1)
		{
			printf("year: 1-5000\n");
			exit(-1);
		}
		show_oneyear(year);
	}
	return 0;
}

void usage()
{
	{
		printf("Usage: cal year mounth. or cal year\n");
		exit(-1);
	}
}

int leap_year(int year)
{
	return ((year % 4 == 0 && year % 100 != 0)
		||year%400==0);
}
// show weeks header
void show_head(int year,int mounth)
{
	int i;
	printf("\t\b%s %d\n", mounths[mounth-1],year);
	for (i = 0; i < 7; ++i)
	{
		printf("%s ", weeks[i]);
	}
	printf("\n");
}
// each mounths has days
int days_mounth(int year,int mounth)
{
	switch(mounth)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			{
				return 31;
				break;
			}
		case 4:
		case 6:
		case 9:
		case 11:
			{
				return 30;
				break;
			}
		case 2:
			if (leap_year(year))
			{
				return 29;
				break;
			}
			else
			{
				return 28;
				break;
			}
	}
}
// show date below weeks
void show_days(int days,int week_today)
{
	int i;
	int delim=0;
	/*for (i = 1; i < week_today; ++i)
	{
		printf(" ");
	}*/
	for (i = 1; i <= days +week_today; ++i)
	{
		if (i < week_today)
		{
			printf("   ");
		}
		else
		{
			if (7 == delim)
			{
				printf("\n");
				delim=0;
			}
			if (i-week_today  <10)
			{
				printf(" %d ", i-week_today);
			}
			else
				printf("%d ", i-week_today);
		}
		delim++;
	}
	printf("\n");
}
// calulate total days from AD 1 1 to now
int up_to_now_days(int year,int mounth,int day)
{
	int i;
	int total_days=0;
	for (i = 1; i <= year-1; ++i)
	{
		if (leap_year(i))
		{
			total_days += 366;
		}
		else
			total_days += 365;
	}
	if (leap_year(year))
	{
		for (i = 0; i < mounth-1; ++i)
		{
			total_days += leap_mounth_days[i];
		}
	}
	else
	{
		for (i = 0; i <	mounth-1; ++i)
		{
			total_days += mounth_days[i];
		}
	}
	return total_days;
}
// show one year cal
void show_oneyear(int year)
{
	int i;
	if (leap_year(year))
	{
		for (i = 1; i <= 12; ++i)
		{
			week_today =6;
			show_head(year,i);
			total_days = up_to_now_days(year,i,1);
			week_today = (week_today+ total_days) %7;
			show_days(leap_mounth_days[i-1],week_today);
			printf("\n");
			printf("%d\n", total_days);
			printf("%d\n", week_today);
		}
	}
	else
	{
		for (i = 1; i <= 12; ++i)
		{
			week_today =6;
			show_head(year,i);
			total_days = up_to_now_days(year,i,1);
			week_today = (week_today+ total_days) %7;
			show_days(mounth_days[i-1],week_today);
			printf("\n");
			printf("%d\n", total_days);
			printf("%d\n", week_today);
		}
	}
}