/* 
* @Author: jql
* @Date:   2015-08-10 07:04:26
* @Last Modified by:   jql
* @Last Modified time: 2015-08-10 07:39:36
  bind search in matrix
*/

#include <stdio.h>

int binsearch(int array[],int length,int num)
{
	if (NULL == array || length <0)
	{
		return -1;
	}
	int left = 0;
	int mid = length /2;
	int right = length -1;
	while(left < right)
	{
		if (array[mid] == num)
		{
			return num;
		}
		else if (array[mid] > num)
		{
			right = mid-1;
		}
		else
			left = mid+1;
	}
	return -1;
}
int row_binserch(int matrix[][3],int rowlen,int collen,int num)
{
	int row = rowlen;
	for (int i = 0; i < row; ++i)   //use binserch in each row
	{
		if (-1 != binsearch(matrix[i],collen,num))
		{
			return num;
		}

	}
	return -1;
}

int Search(int matrix[][3],int rowlen,int collen,int num)
{
	if (NULL == matrix)
	{
		return -1;
	}
	int row = 0;
	int col = collen-1;
	while(row < rowlen && col >= 0)
	{
		if (num == matrix[row][col])
		{
			printf("index matrix row:%d col:%d\n", row,col);
			return num;
		}
		else if (num > matrix[row][col])
		{
			row++;
		}
		else
			col--;
	}
	return -1;
}
int main() {

	int matrix[][3] ={{15,20,40},{20,35,70},{30,60,90}};
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	int res =-1;
	int num;
	printf("input search num:\n");
	scanf("%d",&num);
	res =Search(matrix,3,3,num);
	if (-1 == res)
	{
		printf("not find\n");
	}
	else
		printf("find!\n");
	printf("row_binserch-----------\n");
	res = -1;
	res = row_binserch(matrix,3,3,num);
	if (-1 == res)
	{
		printf("not find\n");
	}
	else
		printf("find!\n");
    return 0;
}