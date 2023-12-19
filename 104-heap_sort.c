#include "sort.h"
/**
 * sift_down - sort from top to down
 *
 * @array: array to sort
 * @index: index of the array
 * @size: size of the array
 * @size_print: size of the array
 */
void sift_down(int *array, size_t index, size_t size, size_t size_print)
{
	size_t indexMaximum = 0;

	if (RIGHT_INDEX(index) < size
		&& array[RIGHT_INDEX(index)] > array[LEFT_INDEX(index)])
	{
		indexMaximum = RIGHT_INDEX(index);
	}
	else if (LEFT_INDEX(index) < size)
	{
		indexMaximum = LEFT_INDEX(index);
	}
	else
	{
		indexMaximum = index;
	}

	if (array[index] >= array[indexMaximum])
	{
		indexMaximum = index;
	}

	if (indexMaximum != index)
	{
		SWAP(array[indexMaximum], array[index], int);
		print_array(array, size_print);
		sift_down(array, indexMaximum, size, size_print);
	}
}

/**
 * heap_sort - sort an array
 *
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || size < 2)
	{
		return;
	}

	BUILD_HEAD_STUCTURE(array, size);

	for (x = (int)size - 1; x > 0; x--)
	{
		SWAP(array[0], array[x], int);
		print_array(array, size);
		sift_down(array, 0, x, size);
	}
}

