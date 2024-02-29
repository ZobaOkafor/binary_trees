#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	size_t i = 0, count = 0;

	if (!heap)
		return (NULL);

	/* Count the number of nodes in the heap */
	count = binary_tree_size(heap);

	/* Allocate memory for the sorted array */
	sorted_array = malloc(count * sizeof(int));
	if (!sorted_array)
		return (NULL);

	/* Extract the root node of the heap repeatedly until the heap is empty */
	while (heap)
	{
		sorted_array[i++] = heap->n;
		heap_extract(&heap);
	}

	/* Set the size of the array */
	*size = count;

	/* Reverse the array to get the sorted array in descending order */
	for (i = 0; i < count / 2; i++)
	{
		int temp = sorted_array[i];
		sorted_array[i] = sorted_array[count - i - 1];
		sorted_array[count - i - 1] = temp;
	}

	return sorted_array;
}
