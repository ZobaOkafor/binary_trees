#include <stddef.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using LOT
 * @tree: A pointer to the root node
 * @func: A pointer to a function to call
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *queue[10000];
	binary_tree_t *current;
	int front = 0, rear = 0;

	if (tree == NULL || func == NULL)
		return;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);
		if (current->left != NULL)
			queue[rear++] = current->left;
		if (current->right != NULL)
			queue[rear++] = current->right;
	}
}
