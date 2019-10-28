#include "sort.h"

/**
 * quick_sort - Sorts integers using Quick sort algorithm.
 * @array: List of data
 * @size: Size of the array
**/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	partition_caller(array, 0, size - 1, size);
}

/**
 * partition_caller - Calls partition to find sides and quicksort them
 * @array: List of data
 * @left: Starting index
 * @right: Ending index
 * @size: Size of the array
**/
void partition_caller(int *array, int left, int right, size_t size)
{
	int pivot = 0;

	if (left < right)
	{
		pivot = partition(array, left, right, size);
		partition_caller(array, left, pivot - 1, size);
		partition_caller(array, pivot + 1, right, size);
	}
}

/**
 * partition - Divides the array with pivot at the center
 * @array: List of data
 * @left: Starting index
 * @right: Ending index
 * @size: Size of the array
 * Return: Returns index of the pivot
**/
int partition(int *array, int left, int right, size_t size)
{
	int i = left - 1;
	int pivot = array[right];
	int j = 0, tmp = 0;

	for (j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}
	if (pivot < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[right];
		array[right] = tmp;
		if (i + 1 != j)
			print_array(array, size);
	}
	return (i + 1);
}
