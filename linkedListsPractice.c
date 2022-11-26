
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_Node{
	char *str_val;
	struct s_Node *next_node;
}t_Node;

int n_strlen(char *str)
{
	int i = 0;
	if(!str)
		return 0;
	while (str[i])
		i++;
	return i;
}

int populate_list_ptop(t_Node **node_list, char **strs_arr, int arr_size)
{
	t_Node *temp_node = NULL;
	//t_Node *list_head = *node_list;
	for (int i = 0; i < arr_size; i++)
	{
		if(!*node_list)
		{
			*node_list = malloc(sizeof(t_Node));
			(*node_list)->str_val = malloc(sizeof(char) * n_strlen(strs_arr[i]) + 1);
			
			if(!*node_list){return 1;}
			strcpy((*node_list)->str_val,strs_arr[i]);
			(*node_list)->next_node = NULL;
		}
		else{
			temp_node = malloc(sizeof(t_Node));
			if(!temp_node){return 1;}
			temp_node->str_val = malloc(sizeof(char) * n_strlen(strs_arr[i]) + 1);
			strcpy(temp_node->str_val,strs_arr[i]);
			temp_node->next_node = NULL;
			while ((*node_list)->next_node != NULL)
				node_list = &((*node_list)->next_node);//by doing this, were updating the non-changable pointer so it will only change within the function
		}
		(*node_list)->next_node = temp_node;
		}
	return 0;
}

int	display_list(t_Node *node_list)
{
	int index = 0;
	while (node_list)
	{
		if (node_list->str_val)
			printf("Index: {%i};\tValue:{%s};\n", index++, node_list->str_val);
		node_list = node_list->next_node;
	}
	return 0;
}

int remove_item_if_matches(t_Node **node_list, char *poppable_val)
{
	if(!node_list){return 1;}
	t_Node *prev_node = NULL;
	t_Node *this_node = *node_list;
	t_Node *node_to_free = NULL;

	while (this_node)
	{
		if(strcmp (this_node->str_val, poppable_val) == 0)//if are the same
		{
			node_to_free = this_node;
			//if is the 1st item
			if (!prev_node){
				*node_list = this_node->next_node;
				}
			else
			{
				prev_node->next_node = this_node->next_node;
			}

			this_node = this_node->next_node;

			free(node_to_free->str_val);
			free(node_to_free);
			}
		else
		{
			prev_node = this_node;
			this_node = this_node->next_node;
		}
	}
	return 0;
}

int remove_item_linked_func(t_Node **node_list, char *comparable_val, int (cmp_func)())
{
	if(!node_list){return 1;}
	t_Node *prev_node = NULL;
	t_Node *this_node = *node_list;
	t_Node *node_to_free = NULL;

	while (this_node)
	{
		if((cmp_func)(this_node->str_val, comparable_val) == 0)//if are the same
		{
			node_to_free = this_node;
			//if is the 1st item
			if (!prev_node){
				*node_list = this_node->next_node;
				}
			else
			{
				prev_node->next_node = this_node->next_node;
			}

			this_node = this_node->next_node;

			free(node_to_free->str_val);
			free(node_to_free);
			}
		else
		{
			prev_node = this_node;
			this_node = this_node->next_node;
		}
	}
	return 0;
}

int	free_list(t_Node *node_list)
{
	if(!node_list){return 1;}

	if (node_list->next_node)
		free_list(node_list->next_node);
	free(node_list->str_val);
	free(node_list);
	return 0;
}

int main(void)
{
	t_Node *node_list = NULL;
	char *str_arr[] = {"one", "two", "three", "four", "five", "one"};

	printf("populmate_list_ptop returned:\t%i\n",populate_list_ptop(&node_list, str_arr, (int) sizeof(str_arr) / sizeof(char *)));
	printf("display_list returned:\t%i\n", display_list(node_list));
	printf("remove_item_if_matches returned:\t%i\n", remove_item_if_matches(&node_list, "one"));
	printf("remove_item_linked_func returned:\t%i\n", remove_item_linked_func(&node_list, "four", strcmp));

	printf("display_list returned:\t%i\n", display_list(node_list));

	printf("free_list returned:\t%i\n", free_list(node_list));


	return (0);
}