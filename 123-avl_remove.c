#include "binary_trees.h"


/**
 * bst_remove - Removes a node from a BST tree.
 * @root: Root of the tree.
 * @value: Node with this value to remove.
 *
 * Return: The tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int new_value;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;
			free(root);
			return (temp);
		}
		new_value = successor(root->right);
		root->n = new_value;
		root->right = bst_remove(root->right, new_value);
	}
	return (root);
}


/**
 * remove_node - removes a node depending on its children.
 * @root: Node to remove.
 *
 * Return: 0 if it has no children or other value if it has
 */
int remove_node(bst_t *root)
{
	int new_value;

	if (root->left == NULL && root->right == NULL)
	{
		if (root->parent->left == root)
			root->parent->left = NULL;
		else
			root->parent->right = NULL;
		free(root);
		return (0);
	}
	else if (root->left == NULL || root->right == NULL)
	{
		bst_t *child = root->left ? root->left : root->right;
		if (root->parent->left == root)
			root->parent->left = child;
		else
			root->parent->right = child;
		child->parent = root->parent;
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}


/**
 * successor - Get the next successor i mean the min node in the right subtree.
 * @node: Tree to check.
 *
 * Return: The min value of this tree.
 */
int successor(bst_t *node)
{
	while (node->left)
		node = node->left;
	return (node->n);
}


/**
 * balance - Measures balance factor of a AVL.
 * @tree: Tree to go through.
 *
 * Return: Balanced factor.
 */
void balance(avl_t **tree)
{
	int bal_val;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	balance(&(*tree)->left);
	balance(&(*tree)->right);
	bal_val = binary_tree_balance((const binary_tree_t *)*tree);
	if (bal_val > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bal_val < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}


/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: pointer to the root node of the tree.
 * @value: value to remove in the tree.
 *
 * Return: A pointer to the new root node of the tree after
 *         removing the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	balance(&root_a);

	return (root_a);
}
