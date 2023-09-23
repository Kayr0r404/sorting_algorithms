#include "sort.h"

/**
 * merge_sort - implementation of merge sort, sorting an
 * array of integers
 * @array: input array opn integers
 * @size: the size of the input array
*/

void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2, i, j = 0;
	int *left_arr, *right_arr;

	if (size == 0 || size == 1 || array == NULL)
		return;

	left_arr = malloc(sizeof(int) * mid);
	right_arr = malloc(sizeof(int) * (size - mid));

	/*populate both left and right arrays*/
	for (i = 0; i < size; i++)
	{
		if (i >= mid)
		{
			*(right_arr + j) = array[i];
			j++;
		}
		else
			*(left_arr + i) = array[i];
	}

	/*call the function/ recurse, first the left then right*/
	merge_sort(left_arr, mid);
	merge_sort(right_arr, size - mid);

    /*merge the two arrays into onr array*/
	merge(left_arr, right_arr, array, mid, size - mid);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left_arr, mid);
	printf("[right]: ");
	print_array(right_arr, size - mid);
	printf("[Done]: ");
	print_array(array, size);

	free(left_arr);
	free(right_arr);
}

/**
 * merge - merge two arrays of integers
 * @left_arr: input array of integers
 * @right_arr: input array of integers
 * @main_arr: destination array
 * @l_size: the size of left_arr
 * @r_size: the size of the right_arr
*/
void merge(int *left_arr, int *right_arr,
int *main_arr, size_t l_size, size_t r_size)
{
	size_t i = 0, j = 0, k = 0;

	while (i < l_size && j < r_size)
	{
		if (left_arr[i] > right_arr[j])
			main_arr[k++] = right_arr[j++];
		else
			main_arr[k++] = left_arr[i++];
	}

	while (i < l_size)
		main_arr[k++] = left_arr[i++];

	while (j < r_size)
		main_arr[k++] = right_arr[j++];
}
