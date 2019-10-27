#include "sort.h"

/**
 * selection_sort - Sorts integers in ascending order
 * using Selection sort algorithm
 * @array: List of data
 * @size: Size of the array
**/
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i = 0, j, min = 0;

	if (size < 2)
		return;

	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			j++;
		}
		tmp = array[min];
		array[min] = array[i];
		array[i] = tmp;
		if (i != min)
			print_array(array, size);
		i++;
	}
}
