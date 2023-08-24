#include "search.h"

/**
 * linear_skip - Function that searches for a value
 * in a sorted skip list of integers
 *
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 * Return: A pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp = list;

	if (!list)
		return (NULL);

	while (list->express)
	{
		tmp = list;
		list = list->express;
		printf("Value checked at index [%ld] = [%d]\n",
				list->index, list->n);
		if (list->n >= value)
			break;
	}

	if (list->n < value && list->express == NULL)
	{
		tmp = list;
		while (list->next)
			list = list->next;
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			tmp->index, list->index);

	while (tmp && tmp->index <= list->index)
	{
		printf("Value checked at index [%ld] = [%d]\n",
				tmp->index, tmp->n);
		if (tmp->n == value)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
