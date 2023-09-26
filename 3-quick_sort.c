#include "sort.h"
/**
 * swap - swap two elements in an array
 * @array: the array to swap
 * @now: the position of one number in the array
 * @then: position of the second number in the array
 */
void swap(int *array, size_t now, size_t then)
{
	int tmp;
	
	tmp = array[now];
	array[now] = array[then];
	array[then] = tmp;
}
/**
 * partition - sort the pivot to it's appropriate place in the array
 * @array: the array to use
 * @start: the index to begin
 * @end: the index to end
 * @size: the size of the array
 *
 * Description: This algorithm works like the insertion sort. It inserts
 *	the pivot in it's place.
 *
 * Return: the position of the pivot in a sorted list
 */
size_t partition(int *array, size_t start, size_t end, size_t size)
{
	size_t j, i;
	int pivot = array[end];

	for (j = start, i = start - 1; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, j, i);
			print_array(array, size);
		}
	}
	if (i != end)
	{
		swap(array, i + 1, end);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * recurse_sort - execute for quick_sort
 * @array: the array to sort
 * @start: where to begin sorting
 * @end: where to end sorting
 * @size: the size of the array
 */
void recurse_sort(int *array, size_t start, size_t end, size_t size)
{
	size_t pivot;

	if (end <= start)
		return;
	pivot = partition(array, start, end - 1, size);
	recurse_sort(array, start, pivot, size);
	recurse_sort(array, pivot + 1, end, size);
}
/**
 * quick_sort - sort an array
 * @array: the array to sort
 * @size: the size of the array
 *
 * Description: this algorithm works by recursively sorting a pivot
 *	in an array of smaller size. When the array size becomes 1, recursion
 *	stops.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	recurse_sort(array, 0, size, size);
}
