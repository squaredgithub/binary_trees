#include "binary_trees.h"
/**
 * binary_tree_depth - function that  the depth of a node in a binary tree
 * @tree: is a pointer to the root node of the tree to measure the depth
 * Return: depth of binary tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		if (tree->parent)
			count = 1 + binary_tree_depth(tree->parent);
	}
	return (count);
}
