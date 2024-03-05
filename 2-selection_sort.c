#include "sort.h"

/**
 * selection_sort -  sorts an array of integers
 * in ascending order using the Selection sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	int min, tmp;
	size_t i = 1, start = 0;

	if (size < 2)
		return;

	min = 0;
	while (start < size)
	{
		i = start;
		while (i < size)
		{
			if (array[i] < array[min])
				min = i;
			i++;
		}
		if (array[min] != array[start])
		{
			tmp = array[start];
			array[start] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
		start++;
		min = start;
	}
}
