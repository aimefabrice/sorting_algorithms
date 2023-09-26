#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of integer
 * @size: size of the array
 * int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	size_t n = size;
	int temp = 0;
	int *arrayB = malloc(n * sizeof(int));

	arrayB = array;

	for (a = 1; a < n; a++)
	{
		for (b = 0; b < n - 1; b++)
		{
			if (arrayB[b] > arrayB[b + 1])
			{
				temp = arrayB[b];
				arrayB[b] = arrayB[b + 1];
				arrayB[b + 1] = temp;
				print_array(arrayB, n);
			}
		}
	}
}
