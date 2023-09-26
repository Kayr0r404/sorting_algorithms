#include "sort.h"

/**
 * swap_ints - Swapping numbers using call by reference
 * @x: input int
 * @y: input int
 * @modified: pointer to a flag indicating if the array has been modified
 */
void swap_ints(int *x, int *y, int *modified)
{
	int temp = *x;

	*x = *y;
	*y = temp;
	*modified = 1; /* Set the modified flag to 1*/
}

/**
 * heapify - To Max-Heapify a subtree rooted at node i which is
 * this function insures that child nodes of i node are always smaller than it.
 * @A: input array of integers
 * @n: size of the array
 * @i: index
 * @size: size of the array
 * @modified: pointer to a flag indicating if the array has been modified
 */
void heapify(int *A, int n, int i, size_t size, int *modified)
{
	int largest = i;  /* Initialize largest as root*/
	int left_child = 2 * i + 1;  /* left = 2*i + 1*/
	int right_child = 2 * i + 2;  /* right  = 2*i + 2*/

	/* If left child is larger than root*/
	if (left_child < n && A[left_child] > A[largest])
		largest = left_child;
	/* If right child is larger than largest so far*/
	if (right_child < n && A[right_child] > A[largest])
		largest = right_child;

	/* If largest is not root*/
	if (largest != i)
	{
		/*swap A[i] with A[largest]*/
		swap_ints(&A[i], &A[largest], modified);
		if (*modified)
		{
			print_array(A, size); /* Print the array if modified*/
			*modified = 0; /* Reset the modified flag*/
		}

		/* Recursively Max-Heapify the affected sub-tree*/
		heapify(A, n, largest, size, modified);
	}
}

/**
 * create_max_heap - (rearrange array) Converting array A to Max-Heap
 * @A: input array
 * @n: size of the array
 * @size: of the array
 */
void create_max_heap(int *A, int n, size_t size)
{
	int i;

	for (i = (n / 2) - 1; i >= 0; i--)
	{
		int modified = 0; /* Initialize modified flag*/

		heapify(A, n, i, size, &modified);
	}
}

/**
 * heap_sort - main function to do Heap Sort
 * @A: input array of ints
 * @size: the size of the array
 */
void heap_sort(int *A, size_t size)
{
	int i, n = size, heap_size;

	create_max_heap(A, n, size);
	/* One by one extract an element from heap*/
	/*and get the sorted array*/
	for (i = n - 1; i >  0; i--)
	{
		int modified = 0; /* Initialize modified flag*/

		/* Move top root element to end element*/
		swap_ints(&A[0], &A[i], &modified);
		if (modified)
		{
			print_array(A, size); /* Print the array if modified*/
			modified = 0; /* Reset the modified flag*/
		}

		/* And reduce size of heap*/
		heap_size = i;

		/* call max heapify on the reduced heap*/
		heapify(A, heap_size, 0, size, &modified);
	}
}
