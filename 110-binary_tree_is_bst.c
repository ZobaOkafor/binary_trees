#include "binary_trees.h"


/**
 * is_bst_util - Utility function to check if a tree is a valid BST.
 *
 * @tree: A pointer to the root node of the tree.
 * @min: The minimum value allowed in the subtree.
 * @max: The maximum value allowed in the subtree.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst_util(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if ((min && tree->n <= *min) || (max && tree->n >= *max))
		return (0);

	return (is_bst_util(tree->left, min, tree->n) &&
			is_bst_util(tree->right, &(tree->n), max));
}



/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_util(tree, NULL, NULL));
}
