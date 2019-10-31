#include "sort.h"

/**
 * quick_sort_hoare - Sorts integers using Quick sort algorithm.
 * @array: List of data
 * @size: Size of the array
**/
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	partition_caller_h(array, 0, size - 1, size, size);
}

/**
 * partition_caller_h - Calls partition to find sides and quicksort them
 * @array: List of data
 * @left: Starting index
 * @right: Ending index
 * @size: Size of the array
 * @tmp: Size of the array
**/
void partition_caller_h(int *array, int left, int right, size_t size, int tmp)
{
	int pivot = 0;

	if (left < right)
	{
		pivot = partition_hoare(array, left, right, size);
		if (pivot == tmp)
			tmp = pivot - 1;
		else
			tmp = pivot;
		partition_caller_h(array, left, tmp, size, pivot);
		partition_caller_h(array, tmp + 1, right, size, pivot);
	}
}

/**
 * partition_hoare - Divides the array with pivot at the center
 * @array: List of data
 * @left: Starting index
 * @right: Ending index
 * @size: Size of the array
 * Return: Returns index of the pivot
**/
int partition_hoare(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i = left - 1;
	/*int pivot = array[left + ((right - left) / 2)];*/
	int j = right + 1, tmp = 0;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		if (i != j)
			print_array(array, size);
	}
}
