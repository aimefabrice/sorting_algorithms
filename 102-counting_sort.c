#include "sort.h"
/**
 * largest_number - show the largest number in an array
 * @array: the array in question
 * @size: the size of the array
 *
 * Return: the largest item in the array
 */
int largest_number(int *array, size_t size)
{
	int largest;
	size_t i;

	if (!array || !size)
		return (0);
	largest = 0;
	for (i = 0; i < size; i++)
	{
		if (array[i] > largest)
			largest = array[i];
	}
	return (largest);
}
/**
 * counting_sort - counting sort
 * @array: the array of integers to sort
 * @size: the size of the array
 *
 * Description: the algorithm works by counting the occurance
 *	of every number in the array, and therefore calculating it's
 *	relative position in the sorted array The array must br of
 *	integers exclusively.
 */
void counting_sort(int *array, size_t size)
{
	int *tmp, *counting;
	size_t i, k;

	if (!array || size < 2)
		return;
	k = largest_number(array, size);
	tmp = malloc(sizeof(int) * k + 1);
	counting = malloc(sizeof(int) * size);

	if (!tmp || !counting)
		return;
	/* Initialize tmp to 0 */
	for (i = 0; i <= k; i++)
		tmp[i] = 0;

	/*Count the occurance of every item in array */
	for (i = 0; i < size; i++)
		tmp[array[i]] += 1;

	/* Calculate relative first position in sorted array */
	for (i = 1; i <= k; i++)
		tmp[i] += tmp[i - 1];
	print_array(tmp, k + 1);

	/* Set things up in the counting array*/
	for (i = size - 1; i > 0; i--)
	{
		counting[tmp[array[i]]] = array[i];
		tmp[array[i]]--;
	}
	counting[tmp[array[0]]] = array[0];
	/*copy all things back in the original array */
	for (i = 0; i < size; i++)
		array[i] = counting[i];

	free(tmp);
	free(counting);
}

