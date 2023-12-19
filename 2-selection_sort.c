#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	unsigned int ps = 0;
	size_t x = 0, y = 0;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (; x < size; x++)
	{
		ps = size - 1;
		for (y = x; y < size; y++)
		{
			if (array[y] < array[ps])
			{
				ps = y;
			}
		}
		if (array[x] != array[ps])
		{
			SWAP(array[x], array[ps], int);
			print_array((const int *)array, size);
		}
	}
}
