#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *c = NULL, copyArray[500];
	unsigned int x, maxmum = 0;

	if (array == NULL || size < 2)
		return;
	for (x = 0; x < size; x++)
	{
		if (array[x] > (int)maxmum)
		maxmum = array[x];
		copyArray[x] = array[x];
	}
	maxmum++;
	c = malloc(sizeof(int) * maxmum);
	if (!c)
		return;
	for (x = 0; x < maxmum; x++)
		c[x] = 0;
	for (x = 0; x < size; x++)
		c[array[x]] = c[array[x]] + 1;
	for (x = 0; x < maxmum; x++)
	{
		if (x != 0)
		c[x] = c[x] + c[x - 1];
	}
	print_array((const int *)c, maxmum);
	for (x = 0; x < size; x++)
	{
		array[c[copyArray[x]] - 1] = copyArray[x];
		c[copyArray[x]]--;
	}
	free(c);
}
