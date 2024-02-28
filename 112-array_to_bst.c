#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 *
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i, j;
	bool duplicate;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		duplicate = false;

		/* Check for duplicates */
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
			{
				duplicate = true;
				break;
			}
		}

		/* If no duplicate found, insert into BST */
		if (!duplicate)
		{
			if (bst_insert(&tree, array[i]) == NULL)
			{
				/* bst_insert failed, free previously allocated nodes */
				binary_tree_delete(tree);
				return (NULL);
			}
		}
	}

	return (tree);
}
