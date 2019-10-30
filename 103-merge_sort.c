#include "sort.h"

/**
 * merge_sort - Sorts an array with Merge sort algorithm
 * @array: List of data
 * @size: Size of the array
**/
void merge_sort(int *array, size_t size)
{
	int *sub_array;

	if (size < 2)
		return;

	sub_array = malloc(sizeof(int) * size);
	if (sub_array == NULL)
		return;

	merge_recursion(array, sub_array, 0, size - 1);
	free(sub_array);
}

/**
 * merge_caller - Calls merge to merge previously divided arrays
 * @array: List of data
 * @sub_array: Holder for array
 * @left: Starting index
 * @right: Ending index
**/
void merge_caller(int *array, int *sub_array, int left, int right)
{
	int mid;

	if (right - left < 1)
		return;
	mid = left + (right - left) / 2;
	merge_caller(sub_array, array, left, mid);
	merge_caller(sub_array, array, mid, right);
	merge(sub_array, array, left, mid, right);
}

/**
 * merge - Merges divided arrays into one
 * @array: List of data
 * @sub_array: Holder for array
 * @left: Starting index
 * @middle: Middle index
 * @right: Ending index
 */
void merge_subarray(int *arr, int *array, int left, int mid, int right)
{
	int i, j;
	int k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid  - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	for (i = left, j = mid; i < mid && j < right; k++)
	{
		if (array[i] < array[j])
			sub_array[k] = array[i++];
		else
			sub_array[k] = array[j++];
	}

	/** Fill sub array **/

	printf("[Done]: ");
	print_array(array + left, right - left);
}

