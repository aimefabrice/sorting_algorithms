#include "sort.h"

size_t select_interval(size_t size);
void sort(int *array, int *buff, int *index, size_t size);
void sort_last(int *array, size_t size);
/**
 * shell_sort - sort an array using shellsort
 * @array: the array tosort
 * @size: the size of the array
 *
 * Description: The algorithm is an improvement to the insertion
 *	sort algorithm. It swaps elements that are interval 'h' from
 *	each other first. Then, it narrows down the interval until
 *	the whole array is sorted.
 */
void shell_sort(int *array, size_t size)
{
	int *buff, *index, i, k, h;
	size_t j;

	if (!array || size <= 1)
		return;
	h = select_interval(size);

	buff = malloc(sizeof(int) * (size / h));
	index = malloc(sizeof(int) * size);
	if (!buff || !index)
	{
		(!buff) ? free(index) : free(buff);
		return;
	}
	while (h > 0)
	{
		for (i = 0; i < h - 1; i++)
		{
			for (j = i, k = 0; j < size; j += h)
			{
				buff[k] = array[j];
				index[k] = j;
				k++;
			}
			sort(array, buff, index, size / h);
		}
		if (h > 1)
			print_array(array, size);
		h = (h - 1) / 3;
	}
	sort_last(array, size);
	print_array(array, size);
	free(buff);
	free(index);
}
/**
 * select_interval - select the interval based on Knuth's sequence
 * @size: the maximum size of the array
 *
 * Return: the value of the interval
 */
size_t select_interval(size_t size)
{
	size_t interval = 1;

	while (interval < size / 3)
		interval = interval * 3 + 1;
	return (interval);
}
/**
 * sort - sort a subarray the insertion way and update the bigger array
 * @array: the bigger array
 * @buff: the smaller array
 * @index: the position of elements of smaller array in a bigger array
 * @size: the size of the buff and index
 */
void sort(int *array, int *buff, int *index, size_t size)
{
	size_t i, j;
	int tmp;

	for (i = 0; i < size; i++)
	{
		for (j = size; j > i; j--)
		{
			if (buff[i] > buff[j])
			{
				tmp = buff[i];
				buff[i] = buff[j];
				buff[j] = tmp;
			}
		}
		array[index[i]] = buff[i];
		array[index[j + 1]] = buff[j + 1];
	}
}
/**
 * sort_last - sort a nearly sorted array
 * @array: the array to sort
 * @size: the size of the array to sort
 */
void sort_last(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	for (i = 0; i < size; i++)
	{
		for (j = size - 1; j > i; j--)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}
