#include "binary_trees.h"

/**
 * binary_tree_leaves - function counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaves of.
 *
 *
 * Return: If tree is NULL, return 0, else number of leaves.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves_t = 0;

	if (tree)
	{
		if (!tree->left && !tree->right)
			leaves_t++;
		leaves_t += binary_tree_leaves(tree->left);
		leaves_t += binary_tree_leaves(tree->right);
	}
	return (leaves_t);
}
