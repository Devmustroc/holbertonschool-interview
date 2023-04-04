#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to head of list
 * @number: number to be inserted
 * Return: address of the new node or NULL if failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t **p = head;
	listint_t *new_node = malloc(sizeof(listint_t));

	if (!new_node)
	{
		return (NULL);
	}
	new_node->n = number;
	new_node->next = NULL;
	while (*p && (*p)->n < number)
	{
		p = &(*p)->next;
	}
	new_node->next = *p;
	*p = new_node;
	return (new_node);
}
