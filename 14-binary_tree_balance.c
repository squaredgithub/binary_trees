#include "binary_trees.h"

/**
 * binary_tree_balance - function that measures the
 * balance factor of a binary tree
 * @tree: is a pointer to the root node of the
 * tree to measure the balance factor
 * Return: balance of binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
	return (0);
}
/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 * Return: height of binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t countLeft = 0, countRight = 0;

	if (tree)
	{
		if (tree->left)
			countLeft = 1 + binary_tree_height(tree->left);
		else
			countLeft = 1;
		if (tree->right)
			countRight = 1 + binary_tree_height(tree->right);
		else
			countRight = 1;

		if (countLeft > countRight)
			return (countLeft);
		else
			return (countRight);
	}
	return (0);
}
