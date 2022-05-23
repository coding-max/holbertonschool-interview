#include "lists.h"

/**
 * ispalindorme - checks if a singly linked list is a palindrome.
 * @head: double pointer to the first node of a singly linked list.
 * @aux: aux pointer to move over the linked list.
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int ispalindorme(listint_t **head, listint_t *aux)
{
	if (aux->next)
	{
		if (ispalindorme(head, aux->next))
			(*head) = (*head)->next;
		else
			return (0);
	}
	if ((*head)->n == aux->n)
		return (1);
	return (0);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: double pointer to the first node of a singly linked list.
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */

int is_palindrome(listint_t **head)
{
	if (!head)
		return (0);
	if (!*head)
		return (1);
	return (ispalindorme(head, *head));
}
