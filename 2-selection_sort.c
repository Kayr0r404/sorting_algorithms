#include "sort.h"

/**
 * selection_sort - implementation of selecting sort,
 * sorting an array of integers
 * @array: input array of integers
 * @size: size of the array
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, idx;
	bool swapped;

	if (!array || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		tmp = array[i];
		swapped = false;

		for (j = i + 1; j < size; j++)
		{
			if (tmp > array[j])
			{
				tmp = array[j];
				idx = j;
				swapped = true;
			}
		}
		if (swapped)
		{
			array[idx] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
