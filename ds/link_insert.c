#include "ds.h"

typedef int datatype;

struct node
{
	datatype data;
	struct node *next;
};
//  add a node at the front of link
void push(struct node **head_ref,datatype new_data)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	if (NULL == new_node)
	{
		perror("malloc node error");
		return;
	}
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
// insert a node after in given node
void insert_after(struct node *prev,datatype new_data)
{
	if (NULL == prev)
	{
		printf("prev node is NULL\n");
		return;
	}
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	if (NULL == new_node)
	{
		perror("malloc node error");
		return;
	}
	new_node->data = new_data;
	new_node->next = prev->next;
	prev->next = new_node;
}
// append a node at the end of link
void append(struct node **head_ref,datatype data)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	if (NULL == new_node)
	{
		
		perror("malloc node error");
		return;
	}
	new_node->data = data;
	new_node->next = NULL;
	struct node *last = *head_ref;
	if (NULL == *head_ref)
	{
		*head_ref = new_node;
	}
	while(NULL != last->next)
	{
		last = last->next;
	}
	last->next = new_node;
}  
// delete a node which data value equal key 
void delet_node(struct node **head_ref,int key)
{
	struct node *prev,*temp;
	temp = *head_ref;
	if ((NULL != temp) && (key == temp->data))
	{
		*head_ref = temp->next;
		free(temp);
		return;
	}
	while((NULL !=temp->next) && (key != temp->data))
	{
		prev = temp;
		temp = temp->next;
	}
	if (NULL == temp->next)
	{
		printf("not find key\n");
		return ;
	}
	prev->next = temp->next;
	free(temp);
}
// output linklist
void print_list(struct node *node)
{
	while(NULL != node)
	{
		printf("%d \n", node->data);
		node = node->next;
	}
	
}
// count the lenght of link
int get_count(struct node *head)
{
	int count = 0;
	struct node *temp = head;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
// count by using recursive
int get_count_recursive(struct node *head)
{
	if (NULL == head)
	{
		return 0;
	}
	else
		return 1+get_count_recursive(head->next);

}
// delete first node of link
void delete_first(struct node *head)
{
	if (NULL != head)
	{
		struct node *temp;
		temp = head;
		head = head->next;
		free(temp);
	}
}
// delete next node 
void delete_nextnode(struct node *ptr)
{
	struct node *tmp;
	tmp = ptr->next;
	ptr->data = tmp->data;
	ptr->next = tmp->next;
	free(tmp);
}
// get nTH node value
datatype getNth_value(struct node *head,int index)
{
	struct node *current = head;
	int n = 0;
	while(NULL != current)
	{
		if (n == index)
		{
			return current->data;
		}
		n++;
		current = current->next;
	}
	printf("not found value of index %d\n", index);
	return 0;
}
// printf middle node of link
void print_middle(struct node *head)
{
	struct node *fast = head;
	struct node *slow = head;
	if (NULL != head)
	{
		while(NULL != fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		printf("middle node is %d\n", slow->data);
	}
}
// printf middle mothod 2
void print_middle2(struct node *head)
{
	struct node *mid = head;
	int count = 0;
	while(head != NULL)
	{
		if (count & 1)
		{
			mid = mid->next;
		}
		count++;
		head = head->next;
	}
	if (0 != count)
	{
		printf("middle node %d\n", mid->data);	
	}
}
int main(int argc, char const *argv[])
{
	struct node *head = NULL;
	push(&head,2);
	push(&head,5);
	append(&head,1);
	insert_after(head->next,10);
	delet_node(&head,5);
	print_list(head);
	printf("link count is %d\n", get_count(head));
	delete_first(head);
	delete_nextnode(head);
	print_list(head);
	printf("link count is %d\n", get_count_recursive(head));
	printf("N nTH node data %d\n", getNth_value(head,2));
	return 0;
}

