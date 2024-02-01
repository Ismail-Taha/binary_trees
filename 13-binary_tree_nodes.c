#include "binary_trees.h"

/**
 * binary_tree_nodes - function counts the nodes with at least 1 child in b-tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 *
 * Return: If tree is NULL, return 0, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    size_t nodes_t = 0;

    if (tree)
    {
        if(tree->left || tree->right)
            nodes_t++;
        nodes_t += binary_tree_nodes(tree->left);
        nodes_t += binary_tree_nodes(tree->right);
    }
    return (nodes_t);
}