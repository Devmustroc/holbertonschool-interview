#include "search.h"
skiplist_t *create_skiplist(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    skiplist_t *head = NULL;
    skiplist_t *new_node = NULL;
    size_t i;

    head = malloc(sizeof(skiplist_t));
    if (head == NULL)
        return (NULL);

    head->n = array[0];
    head->index = 0;
    head->express = NULL;
    head->next = NULL;

    new_node = head;

    for (i = 1; i < size ; i++)
    {
        new_node->next = malloc(sizeof(skiplist_t));
        if (new_node->next == NULL)
        {
            free_skiplist(head);
            return (NULL);
        }
        new_node->next->n = array[i];
        new_node->next->index = i;
        new_node->next->express = NULL;
        new_node->next->next = NULL;
        new_node = new_node->next;
    }
    return (head);
}
void print_skiplist(const skiplist_t *list)
{
    const skiplist_t *current = list;
}