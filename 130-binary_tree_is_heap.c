#include "binary_trees.h"


/**
 * check_parent_value - Checks if parent has a greater value than its children.
 * @tree: pointer to the root
 *
 * Return: 1 if parent has a greater value, 0 otherwise
 */
int check_parent_value(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->parent && tree->n > tree->parent->n)
		return (0);

	return (check_parent_value(tree->left) && check_parent_value(tree->right));
}


/**
 * binary_tree_is_complete - Calling function.
 * @tree: pointer to the tree root.
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t num_nodes;

	if (tree == NULL)
		return (0);

	num_nodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, num_nodes));
}


/**
 * tree_is_complete - Checks if tree is complete.
 * @tree: Pointer to the tree root.
 * @idx: Node index.
 * @num_nodes: Number of nodes.
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int tree_is_complete(const binary_tree_t *tree, int idx, int num_nodes)
{
	if (tree == NULL)
		return (1);

	if (idx >= num_nodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * idx) + 1, num_nodes) &&
			tree_is_complete(tree->right, (2 * idx) + 2, num_nodes));
}


/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: pointer to the tree root.
 *
 * Return: Size of the tree or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}


/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the tree root.
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent_value(tree));
}
