#include "sort.h"
#include <stdio.h>

/**
 * shell_sort -  Sorts integers using Shell sort algorithm.
 * @array: List of data
 * @size: Size of the array
 *
 * Return: Always 0
 */

void shell_sort(int *array, size_t size)
{
	int gap, j, tmp;
	size_t i, k = 1;

	if (size < 2)
		return;

	gap = 1;
	while (gap < (int)size)
	{
		gap = 3 * gap + 1;
	}

	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		/*printf("gap: %d\n", gap);*/
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
		k++;
	}
}
