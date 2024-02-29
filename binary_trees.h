#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <limits.h>


/* Basic binary tree struct */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Binary search tree typedef */
typedef struct binary_tree_s bst_t;
/* AVL tree typedef */
typedef struct binary_tree_s avl_t;
/* Max binary heap typedef */
typedef struct binary_tree_s heap_t;


/* Printing function prototype */
void binary_tree_print(const binary_tree_t *tree);


/* Function prototypes */
int heap_extract(heap_t **root);
bst_t *bst_remove(bst_t *root, int value);
avl_t *avl_remove(avl_t *root, int value);
bst_t *bst_insert(bst_t **tree, int value);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
bst_t *array_to_bst(int *array, size_t size);
void binary_tree_delete(binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_to_heap(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
int binary_tree_is_heap(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
avl_t *sorted_array_to_avl(int *array, size_t size);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int *heap_to_sorted_array(heap_t *heap, size_t *size);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);




/* Helper functions */
heap_t *max(heap_t *tree);
void extract_recursive(heap_t *tree);
avl_t *successor(avl_t *tree, int mode);
bst_t *rl_node(bst_t *node, bst_t *root);
bst_t *right_node(bst_t *node, bst_t *root);
int check_balance(const binary_tree_t *tree);
void check_avl_balance(avl_t **node, int value);
size_t binary_height(const binary_tree_t *tree);
int check_parent_value(const binary_tree_t *tree);
void change_node(avl_t **arg_tree, avl_t **arg_node);
avl_t *avl_remove_search_ops(avl_t **tree, int value);
avl_t *avl_recursive_insert(avl_t **tree, avl_t *parent,
                avl_t **new, int value);
int is_avl_util(const binary_tree_t *tree, int min, int max);
int is_bst_util(const binary_tree_t *tree, int low, int high);
void create_avl_tree(avl_t **node, int *array, size_t size, int mode);
int tree_is_complete(const binary_tree_t *tree, int idx, int num_nodes);


#endif
