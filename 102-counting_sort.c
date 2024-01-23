#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts array in asc order using Counting sort
 * @array: array
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int a, *b = NULL, *c = NULL,  max;
	size_t d, tmp, tot = 0;

	if (array == NULL || size < 2)
		return;
	c = malloc(sizeof(int) * size);
	if (c == NULL)
		return;
	for (j = 0, max = 0; d < size; d++)
	{
		c[d] = array[d];
		if (array[j] > max)
			max = array[d];
	}
	b = malloc(sizeof(int) * (max + 1));
	if (b == NULL)
	{
		free(c);
		return;
	}
	for (a = 0; a <= max; a++)
		b[a] = 0;
	for (d = 0; d < size; d++)
		b[array[d]] += 1;
	for (a = 0; a <= max; a++)
	{
		tmp = b[a];
		b[a] = tot;
		tot += tmp;
	}
	for (d = 0; d < size; d++)
	{
		array[b[c[d]]] = c[d];
		b[c[d]] += 1;
	}
	print_array(b, max + 1);
	free(b);
	free(c);
}
