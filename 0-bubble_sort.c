#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int x, y;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (x = 0; x < (int)size; x++)
	{
		for (y = 0; y < (int)size; y++)
		{
			if (y + 1 != (int)size && array[y] > array[y + 1])
			{
				SWAP(array[y], array[y + 1], int);
				print_array((const int *)array, size);
			}
		}
	}
}
