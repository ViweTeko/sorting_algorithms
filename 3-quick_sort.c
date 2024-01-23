#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array
 * @size: size of the array
 **/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quickie(array, 0, size - 1, size);
}

/**
 * quickie - function to quicksort
 * @array: array
 * @low: low
 * @high: high
 * @size: size of the array
 **/
void quickie(int *array, int low, int high, size_t size)
{
	int a = 0;

	if (low < high)
	{
		a = partition(array, low, high, size);
		quickie(array, low, a - 1, size);
		quickie(array, a + 1, high, size);
	}
}

/**
 * _pos - function that changes the position of numbers
 * @array: array
 * @num1: first number
 * @num2: second number
 * @size: size of the array
 **/
void _pos(int *array, int *num1, int *num2, size_t size)
{
	int change = *num1;

	*num1 = *num2;
	*num2 = change;
	print_array(array, size);
}

/**
 * partition - partition function for the array
 * @array: array
 * @low: low
 * @high: high
 * @size: size of the array
 * 
 * Return: index of partition
 **/
int partition(int *array, int low, int high, size_t size)
{
	int a = 0, pivot = array[high], idx = low;

	for (a = low; a < high; a++)
	{
		if (array[a] <= pivot)
		{
			if (idx != a)
				_pos(array, &array[a], &array[idx], size);
			idx++;
		}
	}
	if (idx != high)
		_pos(array, &array[high], &array[idx], size);
	return (idx);
}
