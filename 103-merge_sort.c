#include "sort.h"
/**
 * merge - merge two lists into a bigger one
 * @parent: the original array
 * @copy: the buffer to store in the sorted array
 * @start: where to bigin the merge
 * @mid: the mid point
 * @end: where to end the merge
 */
void merge(int *parent, int *copy, size_t start, size_t mid, size_t end)
{
	size_t j, k;
	size_t i = 0;

	printf("Merging...\n[Left]: ");
	print_array(parent + start, mid - start);

	printf("[right]: ");
	print_array(parent + mid, end - mid);

	j = start, k = mid;
	while (j < mid && k < end)
	{
		if (parent[j] <= parent[k])
			copy[i++] = parent[j++];
		else
			copy[i++] = parent[k++];
	}
	/*
	 * To be stable, or preserve the order in the original,
	 * the remainder of the left comes before the right
	 */
	for (; j < mid; j++)
		copy[i++] = parent[j];
	for (; k < end; k++)
		copy[i++] = parent[k];
	for (i = start, k = 0; i < end; i++)
		parent[i] = copy[k++];
	printf("[Done]: ");
	print_array(parent + start, end - start);
}
/**
 * divide_and_merge - divide an array into sub arrays and merge them sorted
 * @array: the original array
 * @copy: the final, sorted copy of the original array
 * @start: the beginning index
 * @end: the ending index
 */
void divide_and_merge(int *array, int *copy, size_t start, size_t end)
{
	size_t mid;

	if (start + 1 == end || start == end)
		return;
	mid = start + (end - start) / 2;
	divide_and_merge(array, copy, start, mid);
	divide_and_merge(array, copy, mid, end);
	merge(array, copy, start, mid, end);
}
/**
 * merge_sort - divide an array into sub arrays and merge them
 * @array: the array to divide and sort
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *copy;
	if (!array || size <= 1)
		return;
	copy = malloc(sizeof(int) * size);

	if (copy)
	{
		divide_and_merge(array, copy, 0, size);
		print_array(copy, size);
		free(copy);
	}
}
