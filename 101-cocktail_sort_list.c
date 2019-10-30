#include "sort.h"

/**
 * swap - Swaps nodes like bubble sort
 * @list: A list of data
 * @node: A tmporary copy of the list node
**/
void swap(listint_t **list, listint_t **node)
{
	listint_t *left, *right;

	left = (*node);
	right = (*node)->next;
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;
	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;
}

/**
 * cocktail_sort_list - Sorts integers using Cocktail sort algorithm.
 * @list: A list of data
**/
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	short swapped = 1;

	if (list == NULL || *list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	node = *list;
	while (swapped)
	{
		swapped = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				swapped = 1;
				swap(list, &node);
				print_list(*list);
			}
			else
				node = node->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		node = node->prev;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				swapped = 1;
				node = node->prev;
				swap(list, &node);
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
