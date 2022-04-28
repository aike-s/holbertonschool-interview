#include "lists.h"
#include <stdlib.h> /* malloc */

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to the first node of the listint_t list
 * @number: integer to be included in new node
 * Return: address of the new node, or NULL if it failed.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = *head, *previous = NULL;
	listint_t *new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (current)
	{
		if (number < current->n)
		{
			if (current == *head && current->next)
			{
				new->next = current, *head = new;
				return (new);
			}

			if (previous)
			{
				new->next = current, previous->next = new;
				return (new);
			}
		}
		previous = current, current = current->next;
	}

	previous->next = new;
	return (new);
}
