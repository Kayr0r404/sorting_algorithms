#include "sort.h"

/**
 * swap_ints - Swapping numbers using call by reference
 * @x: input int
 * @y: iput int
 */
void swap_ints(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * heapify - To Max-Heapify a subtree rooted at node i which i
 * an index in A. n -> size of heap
 * this function insure that child node
 * of i node is always smaller than it.
 * @A: input array of integers
 * @n:size of the array
 * @i: index
 * @size: siz eof the array
*/
void heapify(int *A, int n, int i, size_t size)
{
	int largest = i;  /* Initialize largest as root*/
	int l = 2 * i + 1;  /* left = 2*i + 1*/
	int r = 2 * i + 2;  /* right  = 2*i + 2*/

	/* If left child is larger than root*/
	if (l < n && A[l] > A[largest])
		largest = l;
	/* If right child is larger than largest so far*/
	if (r < n && A[r] > A[largest])
		largest = r;

	/* If largest is not root*/
	if (largest != i)
	{
		/*swap A[i] with A[largest]*/
		swap_ints(&A[i], &A[largest]);
		print_array(A, size);
		/* Recursively Max-Heapify the affected sub-tree*/
		heapify(A, n, largest, size);
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
		heapify(A, n, i, size);
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
	for (i = n - 1; i >= 0; i--)
	{
		/* Move top root element to end element*/
		swap_ints(&A[0], &A[i]);
		print_array(A, size);
		/*And reduce size of heap*/
		heap_size = i;
		/* call max heapify on the reduced heap*/
		heapify(A, heap_size, 0, size);
	}
}
