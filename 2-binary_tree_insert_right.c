#include "binary_trees.h"

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t new_n;

    if (parent == NULL)
        return (NULL);

    new_n = binary_tree_node(parent, value);
    if (new_n == NULL)
        return(NULL);

    if (parent->right != NULL){
        new_n->right = parent->right;
        parent->right->parent = new_n;
    }
    parent->right = new_n;

    return (new_n);
}