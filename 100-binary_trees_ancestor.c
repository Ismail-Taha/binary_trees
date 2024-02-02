#include "binary_trees.h"

binary_tree_t *find_lca(const binary_tree_t *node1, const binary_tree_t *node2, const binary_tree_t *ancest);

/**
 * binary_trees_ancestor - function finds the lowest common ancest of two nodes in a binary tree.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancest, or NULL if no common ancest.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    if (first == NULL || second == NULL)
        return (NULL);

    return (find_lca(first, second, first->parent));
}

/**
 * find_lca - Recursive function to find the lowest common ancestor.
 * @node1: A pointer to the first node.
 * @node2: A pointer to the second node.
 * @ancest: The current ancest being checked.
 *
 * Return: A pointer to the lowest common ancest, or NULL if no common ancestot.
 */
binary_tree_t *find_lca(const binary_tree_t *node1, const binary_tree_t *node2, const binary_tree_t *ancest)
{
    binary_tree_t *left_lca, *right_lca;

    if (ancest == NULL)
        return (NULL);

    if (ancest == node1 || ancest == node2)
        return ((binary_tree_t *)ancest);

    left_lca = find_lca(node1, node2, ancest->left);
    right_lca = find_lca(node1, node2, ancest->right);

    if (left_lca != NULL && right_lca != NULL)
        return ((binary_tree_t *)ancest);

    return ((left_lca != NULL) ? left_lca : right_lca);
}