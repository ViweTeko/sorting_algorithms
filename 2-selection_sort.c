#include "sort.h"

/**
 * selection_sort - sorts an array following the selection sort algorithm
 * @array: array to sort
 * @size: size of the array;
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, lil;

	register int tmp;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		lil = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[lil])
				lil = j;
		}
		tmp = array[i];
		array[i] = array[lil];
		array[lil] = tmp;
		if (i != lil)
			print_array(array, size);
	}
}
