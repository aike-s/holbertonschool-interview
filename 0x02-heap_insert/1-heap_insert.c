#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const heap_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_height(tree) == 0)
		return (0);
	else
		return (1);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointerr to the root of the tree
 * Return: the height
 */
size_t binary_tree_height(const heap_t *tree)
{
	size_t left_height = 0, right_height = 0;

	/* if there are no children */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL)
		left_height = binary_tree_height(tree->left);

	if (tree->right != NULL)
		right_height = binary_tree_height(tree->right);

	/* return the max value adding 1 */
	if (left_height != right_height)
		return (0);
	else
		return (right_height + 1);
}
/**
 * full_tree - checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if the tree is full, otherwise 0
 */
int full_tree(const heap_t *tree)
{
	int left_child = 0, right_child = 0;

	if (tree == NULL)
		return (1);

	/* If the node has NO children is full :) */
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_child = full_tree(tree->left);
	right_child = full_tree(tree->right);

	if (left_child != right_child)
		return (1);
	else
		return (left_child);
}

int is_parent(heap_t *tree)
{
	if (tree->left != NULL || tree->right != NULL)
		return (0);

	return (-1);
}
/**
 * which_node - Choose the node in which to insert the new node
 * @tree: the binary tre to search
 * @value: value to compare n
 * Return: the node in which to insert the new node
 */
heap_t *which_node(heap_t *tree, int value)
{
	int tmp = 0, perfect = 0;

	if (value >= tree->n)
	{
		perfect = binary_tree_is_perfect(tree->left);
		if (perfect != 1)
		{

		}
	}

	/* If is not a parent */
	if (tree->left == NULL && tree->right == NULL)
	{

	}

	which_node(tree->left, value);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: the value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	int left_node = 0, right_node = 0, tmp = 0, parent = 0, perfect = 0;

	/* If the binary tree is empty */
	if ((*root) != NULL && (*root)->parent == NULL)
	{
		new_node = binary_tree_node(*root, value);
		return (new_node);
	}


	perfect = binary_tree_is_perfect((*root));

	if (perfect == 1)
	{

	}

	/* First verify left child */
	if ((*root)->left == NULL && (*root)->n >= value)
	{
		new_node = binary_tree_node(*root, value);
		(*root)->left = new_node;
		return (new_node);
	}

	/* Now verify right child */
	if ((*root)->right == NULL && (*root)->n >= value)
	{
		new_node = binary_tree_node(*root, value);
		(*root)->right = new_node;
		return (new_node);
	}



	if ((*root)->left->n  (*root)->n >= value)
	{
		new_node = binary_tree_node(*root, value);
		(*root)->right = new_node;
	}





	heap_insert((*root)->left, value);
	heap_insert((*root)->right, value);


	parent = is_parent((*root));

	/* If it is a parent it should be grader than her childs */
	if (parent == 0)
	{
		left_node = (*root)->left->n;
		right_node = (*root)->right->n;

	}

}

	/* If there is only one node in the binary tree */
	if (full_tree((*root)) && value >= (*root)->n)
	{
		tmp = (*root)->n;
		(*root)->n = value;
		new_node = binary_tree_node(*root, tmp);
		(*root)->left = new_node;
	}

	/* If the value is < root->n */
	else if ((*root)->left == NULL || full_tree((*root)->right))
	{
		/* code */
	}
	

	if (value >= (*root)->n)
	{
		/* Cambiar value del parent por nuevo value y reorganizar los hijos*/
	}
