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
	int min, min_index, tmp;
	size_t i = 1, start = 0;

	if (size < 2)
		return;

	min = array[0];
	min_index = 0;
	while (start < size)
	{
		i = start;
		while (i < size)
		{
			if (array[i] < min)
			{
				min = array[i];
				min_index = i;
			}
			i++;
		}
		if (min != array[start])
		{
			tmp = array[start];
			array[start] = min;
			array[min_index] = tmp;
			print_array(array, size);
		}
		min = array[++start];
	}
}
