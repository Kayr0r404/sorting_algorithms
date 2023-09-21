#include "sort.h"

/**
 * bubble_sort - swap array entries idex by index,
 * until the aray is sorted in ascending order
 * @array: input array of integers
 * @size: size of the input array
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	for (j = 0; j < size; j++)
	{
		for (i = 0; i < size; i++)
		{
			swapped = false;
			if (i + 1 != size)
			{
				if (array[i] > array[i + 1])
				{
					int tmp = array[i];

					array[i] = array[i + 1];
					array[i + 1] = tmp;
					swapped = true;
					print_array(array, size);
				}
			}
		}
		if (swapped)
			break;
	}
}
