#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 * An empty list is considered a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head; /* slow and fast pointers */
	listint_t *stack = NULL, *tmp; /* stack and tmp pointers */

	/* Find the middle of the list using the slow and fast pointers */
	while (fast && fast->next)
	{
		/*  while fast and fast->next are not NULL */
		fast = fast->next->next; /* move fast pointer two nodes at a time */
		tmp = slow; /* save the current node */
		slow = slow->next; /* move to the next node */
		tmp->next = stack; /* push the nodes before the middle onto the stack */
		stack = tmp;  /* push the nodes before the middle onto the stack */
	}
	if (fast)
	{
		/* odd number of nodes, skip the middle node */
		slow = slow->next; /* move to the next node */
	}
	/* Compare the second half of the list with the nodes on the stack */
	while (slow && stack)
	{
		if (slow->n != stack->n)
		{
			return (0);  /* not a palindrome */
		}
		slow = slow->next; /* move to the next node */
		stack = stack->next; /* pop the node from the stack */
	}
	return (1);  /* palindrome */
}
