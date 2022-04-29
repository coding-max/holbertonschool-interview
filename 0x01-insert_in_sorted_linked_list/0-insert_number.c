#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: pointer to the list.
 * @number: data for the new node.
 * Return: the address of the new node, or NULL if it failed
 **/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *aux_node = *head;
	listint_t *new_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;

	if (!(*head))
	{
		new_node->next = NULL;
		*head = new_node;
		return (new_node);
	}

	while (aux_node && aux_node->next && number > aux_node->next->n)
	{
		aux_node =  aux_node->next;
	}

	if (aux_node && number > aux_node->n)
	{
		new_node->next = aux_node->next;
		aux_node->next = new_node;
	} else
	{
		new_node->next = aux_node;
		*head = new_node;
	}

	return (new_node);
}
