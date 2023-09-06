#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * Return: 0 if not full 1 if full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int leftFull = 0, rightFull = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		leftFull = 1 + binary_tree_is_full(tree->left);
	if (tree->right)
		rightFull = 1 + binary_tree_is_full(tree->right);

	if ((rightFull - leftFull) == 0)
		return (1);
	else
		return (0);
}
