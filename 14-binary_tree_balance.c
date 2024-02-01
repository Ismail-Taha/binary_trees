#include "binary_trees.h"

/**
 * binary_tree_balance - function measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 *
 * Return: If tree is NULL, return 0, else return BF.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int bf = 0;

	if (tree)
	{
		bf = (binary_tree_height(tree->left) - binary_tree_height(tree->right));
		return (bf);
	}
	return (0);
}
/**
 * binary_tree_height - function measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 *
 * Return: If tree is NULL, return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	left_h = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	right_h = tree->right ? 1 + binary_tree_height(tree->right) : 1;

	return (left_h > right_h ? left_h : right_h);
}
