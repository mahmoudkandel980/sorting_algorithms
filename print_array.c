#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * print_array - print an array
 *
 * @array: array to print
 * @size: size of the array
 */
void print_array(const int *array, size_t size)
{
	size_t x;

	x = 0;
	while (array && x < size)
	{
		if (x > 0)
		printf(", ");
		printf("%d", array[x]);
		++x;
	}
	printf("\n");
}
