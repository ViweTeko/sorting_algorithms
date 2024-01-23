#include "sort.h"

/**
 * shell_sort - sorts array of int in ascending order
 * @size: size of array
 * @array: the array
 */

void shell_sort(int *array, size_t size)
{
	size_t a, b = 1, c = 0;

	if (array == NULL || size < 2)
		return;

	while (b < size / 3)
		b = 3 * b + 1;
	while (b >= 1)
	{
		for (a = b; a < size; a++)
			for (c = a; c >= b &&
					(array[c] < array[c - b]); c -= b)
				swap(array, c, c - b);
		print_array(array, size);
		b /= 3;
	}
}

/**
 * swap - positions of two elements into array
 * @array: array
 * @item1: first item
 * @item2: second item
 */
void swap(int *array, int item1, int item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}
