/* 
* @Author: jql
* @Date:   2015-08-09 03:53:04
* @Last Modified by:   jql
* @Last Modified time: 2015-08-09 03:55:39
*/

#include <stdio.h>

#define PAIR 50

char str[PAIR * 2 + 1]; // 设括号对数不超过50, str记录括号组合状态

void DFS_bracket(int n, int left_used, int right_used)
{
    if(left_used == right_used && left_used + right_used == 2*n)
    {
        printf("%s\n",str);
        return;
    }
    if(left_used < right_used || left_used + right_used >= 2*n)
    {
        return ;
    }
    int index = left_used + right_used;
    str[index] = '(';
    DFS_bracket(n, left_used + 1, right_used);

    str[index] = ')';
    DFS_bracket(n, left_used, right_used + 1);
}

int main()
{
    int N;
    printf("Input num:\n");
    scanf("%d", &N);
    DFS_bracket(N,0,0);
    return 0;
}