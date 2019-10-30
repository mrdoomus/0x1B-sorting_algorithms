#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort -  Sorts integers using counting sort algorithm.
 * @array: List of data
 * @size: Size of the array
 *
 * Return: Void.
 */
void counting_sort(int *array, size_t size)
{
	int *tmp, *result;
	int i, j, z, w, counter, maximum = 0;

	if (size < 2)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (maximum < array[i])
			maximum = array[i];
	}
	tmp = malloc(sizeof(int) * (maximum + 1));
	if (tmp == NULL)
		return;
	result = malloc(sizeof(int) * size);
	if (result == NULL)
	{ free(tmp);
		return;
	}
	for (w = 0; w < (maximum + 1); w++)
	{ tmp[w] = 0;
	}
	for (i = 0; i < (int)size; i++)
	{ tmp[array[i]] += 1;
	}
	counter = 0;
	for (j = 0; j < (maximum + 1); j++)
	{ counter += tmp[j];
		tmp[j] = counter;
	}
	print_array(tmp, (maximum + 1));
	for (z = 0; z < (int)size; z++)
	{ result[tmp[array[z]] - 1] = array[z];
		tmp[array[z]] -= 1;
	}
	for (z = 0; z < (int)size; z++)
	{ array[z] = result[z];
	}
	free(tmp);
	free(result);
}
