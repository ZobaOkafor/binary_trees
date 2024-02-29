#include "binary_trees.h"

/**
 * create_avl_tree - recursively creates an AVL tree from sorted array
 * @node: pointer node
 * @array: pointer to the first element in the array
 * @size: number of elements in the array
 * @mode: 1 to adding on the left, 2 to adding on the right
 *
 * Return: no return
 */
void create_avl_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t mid;

	if (size == 0)
		return;

	mid = (size / 2);
	mid = (size % 2 == 0) ? mid - 1 : mid;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[mid]);
		create_avl_tree(&((*node)->left), array, mid, 1);
		create_avl_tree(&((*node)->left), array + mid + 1, (size - 1 - mid), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[mid]);
		create_avl_tree(&((*node)->right), array, mid, 1);
		create_avl_tree(&((*node)->right), array + mid + 1, (size - 1 - mid), 2);
	}
}


/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 *
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t mid;

	root = NULL;

	if (size == 0)
		return (NULL);

	mid = (size / 2);

	mid = (size % 2 == 0) ? mid - 1 : mid;

	root = binary_tree_node(root, array[mid]);

	create_avl_tree(&root, array, mid, 1);
	create_avl_tree(&root, array + mid + 1, (size - 1 - mid), 2);

	return (root);
}
