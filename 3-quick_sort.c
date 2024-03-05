#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order recursively
 * using the Quick sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 * @origin_array: the array
 * @origin_size: the size
 */
void quick_sort_recursive(int *array, size_t size,
                          int *origin_array, int origin_size)
{
    int pivot = size - 1, tmp;
    int i, j;

    if (size < 2)
        return;

    j = 0;
    for (i = 0; i < (int)size; i++)
    {
        if (array[i] < array[pivot])
        {
            if (i != j)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                print_array(origin_array, origin_size);
            }
            j++;
        }
    }

    if (pivot != j)
    {
        tmp = array[pivot];
        array[pivot] = array[j];
        array[j] = tmp;
        print_array(origin_array, origin_size);
    }

    quick_sort_recursive(array, j, origin_array, origin_size);
    quick_sort_recursive(array + j + 1, size - j - 1,
                         origin_array, origin_size);
}
/**
 * quick_sort - sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
    quick_sort_recursive(array, size, array, size);
}
