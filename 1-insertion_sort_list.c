#include "sort.h"

/**
 * insertion_sort_list - Sorts integers using Insertion sort algorithm.
 * @list: List of data.
 *
 * Return: void.
**/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;
	int var;

	if (list == NULL || *list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	current = *list;
	while (current != NULL)
	{
		if (current == *list)
			current = current->next;
		else
		{
			tmp = current;
			var = current->n;
			current = current->next;
			while (tmp->prev->n > var && tmp->prev != NULL)
			{
				tmp->prev->next = tmp->next;
				if (tmp->next != NULL)
					tmp->next->prev = tmp->prev;
				if (tmp->prev->prev != NULL)
				{ tmp->prev->prev->next = tmp;
					tmp->next = tmp->prev;
					tmp->prev = tmp->prev->prev;
					tmp->next->prev = tmp;
					print_list(*list);
				}
				else
				{ tmp->next = tmp->prev;
					tmp->prev = NULL;
					tmp->next->prev = tmp;
					*list = tmp;
					print_list(*list);
					break;
				}
			}
		}
	}
}
