#include "sort.h"
/**
 * swap - swap two numbers in an array
 * @array: the array containing two numbers
 * @now: position of one number
 * @then: position of the second numner
 */
void swap(int *array, size_t now, size_t then)
{
	int tmp;

	tmp = array[now];
	array[now] = array[then];
	array[then] = tmp;
}
/**
 * heapify - check if one node is a min_heap and force it to be one
 * @array: the array containing the element
 * @n: the position of the element in the array
 * @size: the size of the whole array
 * @x: the position in the array
 */
void heapify( int *array, size_t n, size_t size, size_t x)
{
	size_t right = n * 2 + 1;
	size_t left = n * 2;

	if (left >= size || right > size)
		return;
	if (array[n] < array[left] && array[n] < array[right])
		return;
	(array[left] <= array[right]) ? swap(array, n, left) : swap(array, n, right);
	print_array(array - x, size + x);
}
/**
 * min_heap_maker - make a min_heap
 * @array: the array being sorted
 * @size: the size of the array
 * @x: the current position in the array
 */
void min_heap_maker(int *array, size_t size, size_t x)
{
	int i;

	for (i = size/2; i >= 0; i--)
		heapify(array, i, size, x);
	heapify(array, 0, size, x);
}
/**
 * heap_sort - sort an array
 * @array: the array to sort
 * @size: the size of the array
 *
 * Descriptoion: This program works by repeatedly turning the array
 *	into a min_heap and decreasing the size of the array by 1
 */
void heap_sort(int *array, size_t size)
{
	size_t x = 0;

	if (!array || size < 2)
		return;
	for (; x < size - 1; x++)
	{
		min_heap_maker(array + x, size - x, x);
	}
}
