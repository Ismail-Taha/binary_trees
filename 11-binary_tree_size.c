#include "binary_trees.h"

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