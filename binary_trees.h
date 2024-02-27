#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>


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
static size_t _height(const binary_tree_t *tree);
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s);


/* Function prototypes */


#endif
