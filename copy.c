#include "sort.h"

void swap_Array(int *array, size_t j, size_t k);
/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of integer
 * @size: size of the array
 * int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
 */
void bubble_sort(int *array, size_t size)
{
	size_t idx = 0, aux = 0, loop = 0;

	while (idx < size)
	{
		aux = idx + 1;
		if (aux < size && array[aux] < array[idx])
		{
			swap_Array(array, idx, idx + 1);
			print_array(array, size);
			loop++;
		}
		if (idx + 1 == size)
		{
			if (loop == 0)
				break;
			idx = 0;
			loop = 0;
			continue;
		}
		idx += 1;
	}
}

/**
 * swap_Array - Swap two element of position in an array
 * @array: Point to array
 * @j: Position To do the Swap
 * @k: Position to do the swap
 */
void swap_Array(int *array, size_t j, size_t k)
{
	int temp;

	temp = array[j];
	array[j] = array[k];
	array[k] = temp;
}
