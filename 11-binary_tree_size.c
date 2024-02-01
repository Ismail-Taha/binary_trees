#include "binary_trees.h"

/**
 * binary_tree_size - function measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 *
 * Return: If tree is NULL, return 0, else return size.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_t = 0;

	if (tree)
	{
		size_t++;
		size_t += binary_tree_size(tree->left);
		size_t += binary_tree_size(tree->right);
	}
	return (size_t);
}
