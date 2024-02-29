#include "binary_trees.h"


/**
 * extract_recursive - Recursively extracts the max from the tree.
 * @tree: The pointer to the root of the tree.
 *
 */
void extract_recursive(heap_t *tree)
{
	heap_t *sub_max, *right_max = NULL;

	if (!tree->left)
		return;
	sub_max = max((tree)->left);
	if (tree->right)
		right_max = max(tree->right);
	if (right_max && right_max->n > sub_max->n)
		sub_max = right_max;
	tree->n = sub_max->n;
	if (!sub_max->left)
	{
		if (sub_max->parent && sub_max->parent->left == sub_max)
			sub_max->parent->left = NULL;
		if (sub_max->parent && sub_max->parent->right == sub_max)
			sub_max->parent->right = NULL;
		free(sub_max);
	}
	else
		extract_recursive(sub_max);
}


/**
 * max - Finds the maximum node in a tree.
 * @tree: The pointer to the root of the tree.
 *
 * Return: The node with the maximum value.
 */
heap_t *max(heap_t *tree)
{
	heap_t *curr_max, *left_max, *right_max;

	if (!tree->left)
		return (tree);
	left_max = max(tree->left);
	if (left_max->n > tree->n)
		curr_max = left_max;
	else
		curr_max = tree;
	if (tree->right)
	{
		right_max = max(tree->right);
		if (right_max->n > curr_max->n)
			curr_max = right_max;
		else
			curr_max = tree;
	}
	return (curr_max);
}


/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: A double pointer to the root node of heap.
 *
 * Return: The value stored in the root node.
 */
int heap_extract(heap_t **root)
{
	int val;

	if (!*root)
		return (0);
	val = (*root)->n;
	if (!(*root)->left)
	{
		val = (*root)->n;
		free(*root);
		*root = NULL;
		return (val);
	}
	extract_recursive(*root);
	return (val);
}
