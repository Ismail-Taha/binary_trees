#include "binary_trees.h"

/**
 * level - function returns the level of a given
 *         node in a binary tree.
 * @tree: A pointer to the node to measure the level of.
 *
 * Return: The level of node.
 */
size_t level(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + level(tree->parent) : 0);
}

/**
 * leaf - function returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first leaf.
 */
const binary_tree_t *leaf(const binary_tree_t *tree)
{
	if ((tree->left == NULL && tree->right == NULL) ? 1 : 0)
		return (tree);
	return (tree->left ? leaf(tree->left) : leaf(tree->right));
}

/**
 * is_perfect - function checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_level: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 *
 * Return: If the tree is perfect, 1, else 0.
 */
int is_perfect(const binary_tree_t *tree,
		size_t leaf_level, size_t level)
{
	if ((tree->left == NULL && tree->right == NULL) ? 1 : 0)
		return (level == leaf_level ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect(tree->left, leaf_level, level + 1) &&
		is_perfect(tree->right, leaf_level, level + 1));
}
/**
 * binary_tree_is_perfect - function checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 *
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect(tree, level(leaf(tree)), 0));
}
