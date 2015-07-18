#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 计算平均分
int cal_score(int score[],int judge_type[],int n)
{
	int result;
	int i;
	int sum_spec = 0;
	int sum_comm = 0;
	int count_spec = 0;
	int count_comm = 0;
	for (int i = 0; i < n; ++i)
	{
		if (judge_type[i] ==  1)
		{
			sum_spec += score[i];
			count_spec++;
		}
		if (judge_type[i] == 2)
		{
			sum_comm += score[i];
			count_comm++;
		}
	}
	result = (sum_spec / count_spec) * 0.6 + (sum_comm / count_comm) *0.4;
	return result;
}
int main(int argc, char const *argv[])
{
	int res ;
	int score[5] = {1,2,3,4,5};
	int judge_type[5] = {1,1,1,2,2};
	res = cal_score(score,judge_type,sizeof(score)/sizeof(int));
	printf("ave score:%d\n", res);
	// printf("%d\n", sizeof(score));
	system("pause");
	return 0;
}