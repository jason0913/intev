#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

// static linklist operator
#define MAXSIZE 100
typedef int Dataype
typedef struct 	
{
	Dataype data;
	int cursor;
}Static_Link[MAXSIZE];

void Init_Slink(Static_Link S)
{
	S[0].cursor =0;
}
int Length_Slink(Static_Link S)
{
	int c =0;
	int len =0;
	while(0 != S[c].cursor)
	{
		len++;
		c=S[c].cursor;
	}
	return len;
}
int Get_Slink(Static_Link S,int i)
{
	int index =0;
	int j =0;
	while(0!= S[index].cursor && j <i)
	{
		index = S[index].cursor;
		j++
	}
	return S[j].data;
}
int main(int argc, char const *argv[])
{
	Static_Link S;

	return 0;
}