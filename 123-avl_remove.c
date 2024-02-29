#include "binary_trees.h"


/**
 * check_avl_balance - checks the balance of each node
 * @node: pointer to the node
 * @value: input value
 *
 * Return: no return
 */
void check_avl_balance(avl_t **node, int value)
{
	int bal;

	bal = binary_tree_balance(*node);

	if (bal > 1 && value > (*node)->left->n)
	{
		*node = binary_tree_rotate_right(*node);
		return;
	}

	if (bal < -1 && value < (*node)->right->n)
	{
		*node = binary_tree_rotate_left(*node);
		return;
	}

	if (bal > 1 && value < (*node)->left->n)
	{
		(*node)->left = binary_tree_rotate_left((*node)->left);
		*node = binary_tree_rotate_right(*node);
		return;
	}

	if (bal < -1 && value > (*node)->right->n)
	{
		(*node)->right = binary_tree_rotate_right((*node)->right);
		*node = binary_tree_rotate_left(*node);
		return;
	}
}

/**
 * sucessor - determines the next/previous node of the removed node
 * @tree: pointer to the node
 * @mode: 1 for inorder sucessor, 2 for inorder precessor
 *
 * Return: pointer to the next/previous node
 */
avl_t *sucessor(avl_t *tree, int mode)
{
	avl_t *node;

	if (mode == 1)
	{
		if (tree->left == NULL)
		{
			if (tree == tree->parent->left)
				tree->parent->left = NULL;
			else
				tree->parent->right = NULL;

			return (tree);
		}

		node = sucessor(tree->left, 1);
	}
	else
	{
		if (tree->right == NULL)
		{
			if (tree == tree->parent->right)
				tree->parent->right = NULL;
			else
				tree->parent->left = NULL;

			return (tree);
		}

		node = sucessor(tree->right, 2);
	}

	return (node);
}


/**
 * node_swap - swaps the removed node by the next/previous node
 * @arg_tree: pointer to the removed node
 * @arg_node: poitner to the next/previous node
 *
 * Return: no return
 */
void node_swap(avl_t **arg_tree, avl_t **arg_node)
{
	avl_t *swap_node, *tree;

	swap_node = *arg_node;
	tree = *arg_tree;

	if (tree->left && tree->left != swap_node)
	{
		if (swap_node->left)
		{
			swap_node->parent->right = swap_node->left;
			swap_node->left->parent = swap_node->parent;
		}

		swap_node->left = tree->left;
		tree->left->parent = swap_node;
	}
	if (tree->right && tree->right != swap_node)
	{
		if (swap_node->right)
		{
			swap_node->parent->left = swap_node->right;
			swap_node->right->parent = swap_node->parent;
		}

		swap_node->right = tree->right;
		tree->right->parent = swap_node;
	}

	swap_node->parent = tree->parent;

	if (tree->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = swap_node;
		else
			tree->parent->right = swap_node;
	}

	*arg_tree = tree;
	*arg_node = swap_node;
}


/**
 * avl_remove_search_ops - searches to remove a node in an AVL tree
 * @tree: tree root
 * @value: node value
 *
 * Return: pointer the removed node
 */
avl_t *avl_remove_search_ops(avl_t **tree, int value)
{
	avl_t *swap_node;

	if (tree && *tree && value < (*tree)->n)
	{
		swap_node = avl_remove_search_ops(&((*tree)->left), value);
		check_avl_balance(tree, value);
		return (swap_node);
	}
	if (tree && *tree && value > (*tree)->n)
	{
		swap_node = avl_remove_search_ops(&((*tree)->right), value);
		check_avl_balance(tree, value);
		return (swap_node);
	}
	if (tree && *tree)
	{
		if ((*tree)->left || (*tree)->right)
		{
			if ((*tree)->right)
				swap_node = sucessor((*tree)->right, 1);
			else
				swap_node = sucessor((*tree)->left, 2);
			node_swap(tree, &swap_node);
			free(*tree);
			*tree = swap_node;
		}
		else
		{
			swap_node = *tree;
			if ((*tree)->parent)
			{
				if ((*tree)->parent->left == (*tree))
					(*tree)->parent->left = NULL;
				else
					(*tree)->parent->right = NULL;
			}
			free(swap_node), *tree = NULL;
		}
	}
	return (*tree);
}


/**
 * avl_remove - removes a node in an AVL tree
 * @root: tree root
 * @value: node value
 *
 * Return: pointer to the new root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	avl_remove_search_ops(&root, value);

	return (root);
}
