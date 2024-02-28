#include "binary_trees.h"


/**
 * array_to_bst - Builds a binary search tree from an array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the BST.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (bst_insert(&tree, array[i]) == NULL)
		{
			/* bst_insert failed, free previously allocated nodes */
			binary_tree_delete(tree);
			return (NULL);
		}
	}

	return (tree);
}
