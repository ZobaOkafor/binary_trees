#include "binary_trees.h"

/**
 * right_node - removes a node from a Binary Search Tree for node->right case
 * @root: tree root
 * @node: node to delete
 *
 * Return: pointer the tree root
 */
bst_t *right_node(bst_t *node, bst_t *root)
{
	node->right->left = node->left;
	node->right->parent = node->parent;
	if (node->parent)
	{
		if (node == node->parent->left)
			node->parent->left = node->right;
		if (node == node->parent->right)
			node->parent->right = node->right;
	}
	if (node->left)
		node->left->parent = node->right;
	if (root == node)
		root = node->right;
	free(node);
	return (root);
}


/**
 * rl_node -  removes a node from a Binary Search Tree for node->right->l case
 * @root: tree root
 * @node: node to delete
 *
 * Return: pointer the tree root
 */
bst_t *rl_node(bst_t *node, bst_t *root)
{
	node->right->left->right = node->right;
	node->right->left->parent = node->parent;
	node->right->left->left = node->left;
	if (node->left)
		node->left->parent = node->right->left;
	node->right->parent = node->right->left;
	if (root == node)
		root = node->right->left;
	else
	{
		if (node == node->parent->left)
			node->parent->left = node->right->left;
		if (node == node->parent->right)
			node->parent->right = node->right->left;
	}
	node->right->left = NULL;
	free(node);
	return (root);
}


/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	/* If the node has no children, it's a leaf */
	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}


/**
 * bst_search - Searches for a value in a Binary Search Tree.
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search in the tree.
 *
 * Return: A pointer to the node containing a value equals to `value`,
 *         or NULL if the value is not found or if `tree` is NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	while (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);

		if (value < tree->n)
			tree = tree->left;
		else
			tree = tree->right;
	}

	return (NULL);
}


/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: tree root
 * @value: node value
 * Return: pointer the tree root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	node = bst_search(root, value);

	if (node != NULL)
	{
		if (binary_tree_is_leaf(node) == 1)
		{
			if (node == node->parent->left)
				node->parent->left = NULL;
			if (node == node->parent->right)
				node->parent->right = NULL;
			free(node);
			return (root);
		}
		if (node->right && node->right->left)
			root = rl_node(node, root);
		else if (node->right)
			root = right_node(node, root);
		else
		{
			if (node->parent)
				node->parent->right = node->left;
			node->left->parent = node->parent;
			if (root == node)
				root = node->left;
			free(node);
		}
	}
	return (root);
}
