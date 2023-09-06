#include "binary_trees.h"

int is_perfect(const binary_tree_t *tree, size_t depth, size_t level);
size_t binary_tree_depth(const binary_tree_t *tree);
int is_leaf(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);

/**
 * is_leaf - checks if node is leaf
 * @tree: is a pointer to the node to be checked
 * Return: 1 if node is leaf 0 if not
 */
int is_leaf(const binary_tree_t *tree)
{
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (0);
}

/**
 * get_leaf - fetches the leaf of a given binary tree
 * @tree: is a pointer to the tree to fetch the leaf from
 * Return: pointer to the leaf of the binary tree
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);

	if (tree->left)
		return (get_leaf(tree->left));
	else
		return (get_leaf(tree->right));

}

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

/**
 * is_perfect - checks recursively if node is perfect or not
 * @tree: is a pointer to the node to be checked
 * @depth: is depth of the node
 * @level: is level of the node
 * Return: 1 if node is perfect else 0
 */
int is_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (is_leaf(tree))
	{
		if (level == depth)
			return (1);
		else
			return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, depth, level + 1) &&
		is_perfect(tree->right, depth, level + 1));
}
/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if perfect else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t d;

	if (tree == NULL)
		return (0);

	d = binary_tree_depth(get_leaf(tree));

	return (is_perfect(tree, d, 0));
}

