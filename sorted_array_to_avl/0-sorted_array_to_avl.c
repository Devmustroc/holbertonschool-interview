#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

    if (new_node == NULL)
        return (NULL);

    new_node->parent = parent;
    new_node->n = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_avl_helper(int *array, int start, int end, avl_t *parent)
{
    avl_t *new_node;
    size_t mid;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;
    new_node = binary_tree_node(parent, array[mid]);

    if (!new_node)
        return (NULL);

    new_node->left = sorted_avl_helper(array, start, mid - 1, new_node);
    new_node->right = sorted_avl_helper(array, mid + 1, end, new_node);
    return (new_node);
}
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size < 1)
        return (NULL);
    return (sorted_avl_helper(array, 0, size - 1, NULL));
}