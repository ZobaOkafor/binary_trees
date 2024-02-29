#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree.
 *
 * @tree: A double pointer to the root node of the AVL tree for inserting the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->left = new_node;
			return (new_node);
		}
		new_node = avl_insert(&((*tree)->left), value);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->right = new_node;
			return (new_node);
		}
		new_node = avl_insert(&((*tree)->right), value);
	}

	if (new_node == NULL)
		return (NULL);

	/* Update the balance factor and balance the tree */
	binary_tree_balance(*tree);

	return (new_node);
}
