#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return (0);
    }
    int left_height = tree_height(tree->left);
    int right_height = tree_height(tree->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const avl_t *tree)
{
    if (tree == NULL)
        return (0);
    int left_height = tree_height(tree->left);
    int right_height = tree_height(tree->right);

    if (abs(left_height - right_height) <= 1 && binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right))
        return (1);
    return (0);
}