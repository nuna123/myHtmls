
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
/* 
int populate_list_ptop(t_Node **node_list, char **strs_arr, int arr_size)
{
	t_Node *temp_node = NULL;
	t_Node *list_head = *node_list;
	for (int i = 0; i < arr_size; i++)
	{
		if(!list_head)
		{
			list_head = malloc(sizeof(t_Node));
			*node_list = list_head;
			(list_head)->str_val = malloc(sizeof(char) * n_strlen(strs_arr[i]) + 1);
			
			if(!list_head){return 1;}
			strcpy((list_head)->str_val,strs_arr[i]);
			(list_head)->next_node = NULL;
		}
		else{
			temp_node = malloc(sizeof(t_Node));
			if(!temp_node){return 1;}
			temp_node->str_val = malloc(sizeof(char) * n_strlen(strs_arr[i]) + 1);
			strcpy(temp_node->str_val,strs_arr[i]);
			temp_node->next_node = NULL;
			while ((list_head)->next_node != NULL)
				list_head = (list_head)->next_node;
		}
		(list_head)->next_node = temp_node;
		}
	return 0;
} */

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
	char *str_arr[] = {"one", "two", "", "four", "five"};

	printf("populate_list_ptop returned:\t%i\n",populate_list_ptop(&node_list, str_arr, (int) sizeof(str_arr) / sizeof(char *)));
	printf("display_list returned:\t%i\n", display_list(node_list));
	printf("free_list returned:\t%i\n", free_list(node_list));


	return (0);
}