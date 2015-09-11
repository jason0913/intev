/* 
* @Author: root
* @Date:   2015-07-26 07:28:24
* @Last Modified by:   jql
* @Last Modified time: 2015-08-02 22:48:30
  sort in O(n) by hash
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxValue  100    //数据的范围为0~99
#define TotalNum  200  //数据量为200，这两个量大家可以自己调整哈。
static int result[TotalNum];
static void genRandNum(int num[], int totalNum)
{
    register int i = 0;
    for(i = 0; i < totalNum; i++) {
        *(num + i) = rand() % MaxValue;
    }
}
static void sort(int num[], int totalNum)
{
    register int i = 0;
    static int tmp[MaxValue] = {0};
    for ( i = 0; i < totalNum; i++) {
        tmp[num[i]] ++;
    }
    for ( i = 1; i< MaxValue; i++) {
        tmp[i] = tmp[i] + tmp[i-1];
    }
    for ( i = 0 ; i < totalNum; i++) {
        result[ tmp[num[i]] -1 ] = num[i];
        tmp[num[i]] --;
    }
}
static void printData(int num[],int totalNum)
{
    int i = 0;
    for( i = 0; i < totalNum; i++) {
        printf("-%3d-",num[i] );
    }
}
int main()
{
    int num[TotalNum];
    genRandNum(num, TotalNum);
    printData(num, TotalNum );
    sort(num, TotalNum);
    printf("\n----------------\n");
    printData(result, TotalNum);
    return 0;
}
