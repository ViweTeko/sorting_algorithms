#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts array in ascending order
 * @array: array of ints to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int a, b;
	int c;

	if (size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				c = array[b];
				array[b] = array[b + 1];
				array[b + 1] = c;
				print_array(array, size);
			}
		}
	}
}
