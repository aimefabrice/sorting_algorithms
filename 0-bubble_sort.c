#include "sort.h"
#define ORDERED 1
#define NOT_ORDERED 0

/**
 * bubble_sort - sort a list by sorting the largest element of it to the end
 * @array: the integer array to sort
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, tmp;
	static size_t extra = 1;
	int state = ORDERED;

	if (size == 1 || !array)
		return;

	for (i = 0, j = i + 1; j < size; i++, j++)
	{
		if (array[i] > array[j])
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size + extra - 1);
			state = NOT_ORDERED;

		}
	}
	if (state == NOT_ORDERED)
	{
		extra++;
		bubble_sort(array, size - 1);
	}
}
