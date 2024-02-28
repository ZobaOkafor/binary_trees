#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST).
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current, *parent;

	if (tree == NULL)
		return (NULL);

	/* Create a new node */
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	/* If the tree is empty, set the new node as the root */
	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}
	/* Find the correct position to insert the new node */
	current = *tree;
	while (current != NULL)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
		{
			/* If the value is already present, free the new node and return NULL */
			free(new_node);
			return (NULL);
		}
	}
	/* Insert the new node */
	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;
	return (new_node);
}
