#include "binary_trees.h"
avl_t *sorted_array_to_avl_helper(int *array, int start, int end, avl_t *parent)
{
    avl_t *new_node;
    int mid;
    if (start > end)
        return NULL;
    mid = (start + end) / 2;
    new_node = malloc(sizeof(avl_t));
    if (new_node == NULL)
        return NULL;
    new_node->n = array[mid];
    new_node->parent = parent;
    new_node->left = sorted_array_to_avl_helper(array, start, mid - 1, new_node);
    new_node->right = sorted_array_to_avl_helper(array, mid + 1, end, new_node);
    return new_node;
}
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return NULL;
    return sorted_array_to_avl_helper(array, 0, size - 1, NULL);
}
