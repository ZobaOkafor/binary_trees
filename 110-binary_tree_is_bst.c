#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev_val = INT_MIN;

	return (is_bst_util(tree, &prev_val));
}


/**
 * is_bst_util2 - Utility function to check if a tree is a valid BST
 * using in-order traversal.
 * @tree: A pointer to the root node of the tree.
 * @prev_val: A pointer to the previous node's value.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst_util2(const binary_tree_t *tree, int *prev_val)
{
	if (tree == NULL)
		return (1);

	if (!is_bst_util(tree->left, prev_val))
		return (0);

	if (tree->n <= *prev_val)
		return (0);

	*prev_val = tree->n;

	return (is_bst_util(tree->right, prev_val));
}
