#include <stdio.h>
#include <stdlib.h>

// 计算某一段数据范围内的素数
struct prime_number_node
{
	int prime_number;
	prime_number_node* next;
};

int calc_prime_number()
{
	prime_number_node* list_head = new prime_number_node();
	list_head->next = NULL;
	list_head->prime_number = 2;
	prime_number_node* list_tail = list_head;
	for(int number = 3 ; number < 100 ; number++)
	{
		int remainder;
		prime_number_node* cur_node_ptr = list_head;
		while(cur_node_ptr != NULL)
		{
			remainder = number%cur_node_ptr->prime_number;
			if(remainder == 0)
			{
				//1
				break;
				
			}
			else
			{
				//2
				cur_node_ptr = cur_node_ptr->next;
			}
		}
		if(remainder != 0)
		{
			prime_number_node* new_node_ptr = new prime_number_node(); 
			new_node_ptr->prime_number = number;
			new_node_ptr->next = NULL;
			list_tail->next = new_node_ptr;
			//3
			list_tail = list_tail->next;
		}
	}
	int result = 0;
	while(list_head != NULL)
	{
		result++;
		prime_number_node* temp_ptr = list_head;
		list_head = list_head->next;
		//4
		delete temp_ptr;
	}
	return result;
}

int main()
{
	calc_prime_number();
	return 0;
}