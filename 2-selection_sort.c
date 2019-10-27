#include "sort.h"

/**
 * selection_sort - Sorts integers in ascending order
 * using Selection sort algorithm
 * @array: List of data
 * @size: Size of the array
**/
void selection_sort(int *array, size_t size)
{
	short iterable = 1;
	int min, tmp;
	size_t i = 0, j;

	while (i < size - 1 || iterable == 1)
	{
		iterable = 0;
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min])
			{
				iterable = 1;
				min = j;
			}
			j++;
		}
		tmp = array[min];
		array[min] = array[i];
		array[i] = tmp;
		print_array(array, size);
		i++;
	}
}
