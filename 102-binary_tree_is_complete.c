#include <stddef.h>
#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node
 * Return: 1 if complete, 0 if it's not or NULL
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int gap_found = 0;
	binary_tree_t *queue[10000], *current;
	int front = 0, rear = 0;

	if (tree == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		current = queue[front++];
		if (current == NULL)
			gap_found = 1;
		if (gap_found && current != NULL)
			return (0);
		if (current != NULL)
		{
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}
	return (1);
}
