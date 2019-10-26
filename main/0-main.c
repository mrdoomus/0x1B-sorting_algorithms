#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int test1[] = {1};
    int test2[] = {1, 3, 3, 5, 9, 8, 7};
    int test3[] = {7, 6, 5, 4, 3, 2, 1};
    int test4[] = {1, 2, 3, 4, 5, 6, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    printf("\n");

    /* When array is of 1 element */
    print_array(test1, 1);
    printf("\n");
    bubble_sort(test1, 1);
    printf("\n");
    print_array(test1, 1);
    printf("\n");

    /* When array has similar numbers */
    print_array(test2, 7);
    printf("\n");
    bubble_sort(test2, 7);
    printf("\n");
    print_array(test2, 7);
    printf("\n");

    /* Worst Case */
    print_array(test3, 7);
    printf("\n");
    bubble_sort(test3, 7);
    printf("\n");
    print_array(test3, 7);
    printf("\n");

    /* Best Case */
    print_array(test4, 7);
    printf("\n");
    bubble_sort(test4, 7);
    printf("\n");
    print_array(test4, 7);
    printf("\n");
    return (0);
}
