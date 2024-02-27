#include <stddef.h>
#include "binary_trees.h"
#include "11-binary_tree_size.c"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node
 * Return: The height of the tree or -1 if NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return ((left_height >
				right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node
 * Return: 1 if the tree is full, 0 if it's not or NULL.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(
					tree->left) && binary_tree_is_full(
						tree->right));
	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: A pointer to the root node
 * Return: 1 if the tree is perfect, 0 if it's not or if NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;

	if (tree == NULL)
		return (0);
	height = binary_tree_height(tree);
	if (binary_tree_is_full(tree) && (
				(size_t)1 << height) - 1 == binary_tree_size(
					tree))
		return (1);
	return (0);
}
