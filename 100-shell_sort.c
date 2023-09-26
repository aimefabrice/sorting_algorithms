#include "sort.h"
/**
* shell_sort - function that sort array
* @array: array to sort
* @size: number of array items
*/
void shell_sort(int *array, size_t size)
{
	size_t k = 1, a, b;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (k < size)
		k = k * 3 + 1;
	k = (k - 1) / 3;
	while (k > 0)
	{
		b = 0;
		for (a = 0; a + k < size; a++)
		{
			if (array[a] > array[a + k])
			{
				temp = array[a];
				array[a] = array[a + k];
				array[a + k] = temp;
				b = 1;
			}

		}
		if (b == 0)
		{
			k = (k - 1) / 3;
			print_array(array, size);
		}
	}
}
