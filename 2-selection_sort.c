#include "sort.h"
/**
 * selection_sort - sort an array of integers
 * @array: the array to sort
 * @size: the size of the array
 *
 * Description: This algorithm will work by picking the minimum number
 *	for each iteration and put it in it's appropriate spot
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	if (!array || size <= 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
