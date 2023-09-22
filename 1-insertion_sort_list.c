#include "sort.h"
/**
 * insertion_sort_list_1 - sort the list using insertion sort/
 * implementation of insertion sort, sorting doubly list
 * @list: input list of integeres
*/
void insertion_sort_list_1(listint_t **list)
{
	listint_t *curr = *list;

	while (curr != NULL && curr->next != NULL)
	{
		listint_t *next_node = curr->next;

		if (curr->n > next_node->n)
		{
			swap(curr);
			print_list(*list);
			if (curr->prev)
			{
				if (curr->n < curr->prev->n)
					curr = curr->prev;
				else
					curr = curr->next;
			}
		}
		else
			curr = curr->next;
	}
}

/**
 * swap - swaps two nodes, by swaping the data in the nodes
 * @arr: input list of integers
*/
void swap(listint_t *arr)
{
	listint_t *curr;
	int *ptr, tmp;

	if (arr == NULL)
		return;

	curr = arr;
	tmp = curr->n;

	ptr = (int *)&curr->n;
	*ptr = curr->next->n;
	ptr = (int *)&curr->next->n;
	*ptr = tmp;
}

/**
 * insertion_sort_list - sort the list using insertion sort/
 * implementation of insertion sort, sorting doubly list
 * @list: input list of integeres
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;

	if (!list || !(*list))
		return;

	curr = (*list)->next;
	for (; curr; curr = curr->next)
	{
		listint_t *tmp = curr;

		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			swap(tmp->prev);
			print_list(*list);
			tmp = tmp->prev;
		}
	}
}
