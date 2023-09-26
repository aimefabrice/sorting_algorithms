#include "sort.h"


int partition(int *array, int low, int high, int size);
void swap_Array(int *array, size_t j, size_t k);
void modifyQuickSort(int *arr, int low, int high, int size);


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

/**
 * quick_sort - Algorithm Quick Sort
 *
 * @array: Pointer that point to an array
 * @size: The size of the array
 *
 */
void quick_sort(int *array, size_t size)
{
	modifyQuickSort(array, 0, size - 1, size);
}

/**
 * partition - Function that implement the Lomuto Partition Scheme
 *
 * @arr: Pointer that point to an array
 * @low: The minimum index
 * @high: The maximum index
 * @size: The size of the array
 *
 * Return: The number of the partition
 */

int partition(int *arr, int low, int high, int size)
{
	int pivot = arr[high];
	int j, i = (low  - 1);

	for (j = low ; j <= high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_Array(arr, i, j);
				print_array(arr, size);
			}
		}
	}
	return (i);
}

/**
 * modifyQuickSort - Algorithm Quick Sort
 *
 * @arr: Pointer that point to an array
 * @low: The minimum index
 * @high: The maximum index
 * @size: The size of the array
 *
 */
void modifyQuickSort(int *arr, int low, int high, int size)
{
	if (low < high)
	{
		int pi = partition(arr, low, high, size);

		modifyQuickSort(arr, low, pi - 1, size);
		modifyQuickSort(arr, pi + 1, high, size);
	}
}
