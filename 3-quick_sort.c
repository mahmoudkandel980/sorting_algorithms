#include "sort.h"
#include <unistd.h>

/**
 * quick_sort_print - the implementation of the algorithm quick sort.
 *
 * @array_p: array of the number list to sort with quick sort algorithm.
 * @size_p: size of the array.
 * @array: array of the number list to sort with quick sort algorithm.
 * @size: size of the array.
 * Return: void
 */
void quick_sort_print(int *array_p, size_t size_p, int *array, size_t size)
{
	int p = size - 1, c = 0, m = 0;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (array[m] < array[p])
	{
		m++;
	}
	c = m;
	for (; m <= p; m++)
	{
		if (array[m] <=  array[p])
		{
			if (array[c] !=  array[p])
			{
				SWAP(array[m], array[c], int);
				print_array(array_p, size_p);
			}
			c++;
		}
	}
	p = c - 1;
	quick_sort_print(array_p, size_p, array, p);
	quick_sort_print(array_p, size_p, array + p + 1, size - p - 1);
}

/**
 * quick_sort - the implementation of the algorithm quick sort.
 *
 * @array: array of the number list to sort with quick sort algorithm.
 * @size: size of the array.
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_print(array, size, array, size);
}
