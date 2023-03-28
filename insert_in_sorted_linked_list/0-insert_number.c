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
	/* declare new node and temp node */
	listint_t *new_node, *temp;
	/* if head is NULL, return NULL */
	if (head == NULL)
		return (NULL);
	/* allocate memory for new node */
	new_node = malloc(sizeof(listint_t));
	/* if malloc fails, return NULL */
	if (new_node == NULL)
		return (NULL);
	/* assign number to new node */
	new_node->n = number;
	new_node->next = NULL;
	/* if head is NULL or number is less than head, insert new node at head */
	if (*head == NULL || number < (*head)->n)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL && temp->next->n < number)
		{
			temp = temp->next;
			new_node->next = temp->next;
			temp->next = new_node;
		}
	}
	return (new_node);
}
