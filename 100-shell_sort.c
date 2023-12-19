#include "sort.h"

/**
 * insertion_array - insertion algorithm applied to an array.
 *
 * @array: array to sort with the algorithm.
 * @size: size of the array to sort.
 *
 * Return: void
 */
void insertion_array(int *array, size_t size)
{
	int x, y, z;

	for (x = 0; x < (int)size; x++)
	{
		z = x;
		for (y = z - 1; y >= 0 && array[y] >= array[z];)
		{
			SWAP(array[y], array[z], int);
			z--;
			y--;
		}
	}
}

/**
 * insertion_array_gap - insertion algorithm applied to an array.
 *
 * @array: array to sort with the algorithm.
 * @size: size of the array to sort.
 * @gap: gap of the algorithm.
 *
 * Return: void
 */
void insertion_array_gap(int *array, size_t size, int gap)
{
	int x;

	if (gap > 1)
	{
		x = size - 1;
		while (x - gap >= 0)
		{
			if (array[x] < array[x - gap])
			{
				SWAP(array[x], array[x - gap], int);
			}
			x--;
		}
		print_array((const int *)array, size);
		gap = (gap - 1) / 3;
		insertion_array_gap(array, size, gap);
	}
	else if (gap == 1)
	{
		insertion_array(array, size);
		print_array((const int *)array, size);
	}
}

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int g = 1;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (g < ((int)size - 1) / 3)
	{
		g = g * 3 + 1;
	}
	insertion_array_gap(array, size, g);
}
