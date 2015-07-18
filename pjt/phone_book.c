#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 500

int Add();
void Delete();
void Sort();
void Search();
void Edit();
void Show();


typedef struct tel
{
	char name[20];
	char telnum[20];
	char email[20];
	char address[30];
}TEL;

TEL tel_array[MAX_NUM];