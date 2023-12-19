#include "sort.h"

/**
 * merge_sort_recursive - wrapper that validate array, alloc and free array storage
 *              and call merge sort algorithm.
 *
 * @array_storage: array of numbers to sort with merge sort algorithm.
 * @array: array of numbers to sort with merge sort algorithm.
 * @size: size of the array to sort.
 *
 * Return: aways void
 */
void merge_sort_recursive(int *array_storage, int *array, size_t size)
{
	int min_left = 0, min_right = 0, x = 0, m = size / 2, r = size % 2;

	if (size < 2)
		return;

	merge_sort_recursive(array_storage, array, m);
	merge_sort_recursive(
		array_storage + m,
		array + m,
		m + r
	);

	printf("Merging...\n");
	min_right = m, min_left = 0;

	for (x = 0; x < (int)size; x++)
		array_storage[x] = array[x];

	printf("[left]: "), print_array(array, m);
	printf("[right]: "), print_array(array + m, m + r);
	for (x = 0; x < (int)size; x++)
	{
		if (min_left == m)
		{
			break;
		}
		else if (min_right == (int)size)
		{
			COPY_FROM_UNTIL(array_storage, min_left, array, x, (int)size);
		}
		else if (array_storage[min_left] < array_storage[min_right])
		{
			array[x] = array_storage[min_left], min_left += 1;
		}
		else
		{
			array[x] = array_storage[min_right], min_right += 1;
		}
	}
	printf("[Done]: "), print_array(array, size);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *arrayStorage = NULL;

	if (array == NULL || size < 1)
		return;

	arrayStorage = malloc(sizeof(int) * size);
	merge_sort_recursive(arrayStorage, array, size);
	free(arrayStorage);
}
