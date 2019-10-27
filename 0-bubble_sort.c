#include "sort.h"

/**
 * bubble_sort - Sorts integers in ascending order using Bubble sort algorithm
 * @array: List of data
 * @size: Size of the array
**/

void bubble_sort(int *array, size_t size)
{
	short iterable = 1;
	size_t i = 0;
	int tmp;

	if (size < 2)
		return;

	while (iterable == 1)
	{
		iterable = 0;
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				iterable = 1;
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
}
