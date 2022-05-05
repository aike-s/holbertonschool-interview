#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stdio.h>

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
typedef struct binary_tree_s heap_t;


/* creates a binary tree node */
heap_t *binary_tree_node(heap_t *parent, int value);
/* inserts a value into a Max Binary Heap */
heap_t *heap_insert(heap_t **root, int value);
void binary_tree_print(const heap_t *tree);

#endif
