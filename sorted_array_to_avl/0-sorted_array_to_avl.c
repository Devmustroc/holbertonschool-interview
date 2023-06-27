#include "binary_trees.h"
#include <stdlib.h>
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *tree;
    int mid;
    if (!array || size == 0)
        return (NULL);
    tree = malloc(sizeof(avl_t));
    if (!tree)
        return (NULL);
    mid = (size - 1) / 2;
    tree->n = array[mid];
    tree->parent = NULL;
    tree->left = NULL;
    tree->right = NULL;
    if (mid != 0)
        tree->left = sorted_array_to_avl(array, mid);
    if (mid != (int)size - 1)
        tree->right = sorted_array_to_avl(&array[mid + 1], size - mid - 1);
    if (tree->left)
        tree->left->parent = tree;
    if (tree->right)
        tree->right->parent = tree;
    return (tree);
}
