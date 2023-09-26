#include "sort.h"

void swap_Array(int *array, size_t j, size_t k);
/**
 * selection_sort -  sorts an array of integers in ascending order using the
 *                   Selection sort algorithmi
 *
 * @array: Pointer that point to an array
 * @size: Size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t j, k, minInd;

	for (j = 0; j < size; j++)
	{
		minInd = j;
		for (k = j + 1; k < size; k++)
		{
			if (array[minInd] > array[k])
				minInd = k;
		}
		if (array[j] > array[minInd] && j < size - 1)
		{
			swap_Array(array, j, minInd);
			print_array(array, size);
		}
	}
}

/**
 * swap_Array - Swap two elements in an array
 *
 * @array: Pointer that point to an array
 * @j: This is the index to swap with the index k
 * @k: This is the index to swap with the index j
 *
 */
void swap_Array(int *array, size_t j, size_t k)
{
	int temp;

	temp = array[j];
	array[j] = array[k];
	array[k] = temp;
}
