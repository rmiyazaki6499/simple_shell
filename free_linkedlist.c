#include "linkedlist.h"

/**
 * free_linkedlist - a function that frees a str_ll linked list.
 * @head: pointer to head node
 * Return: Nothing
 */
void free_linkedlist(str_ll *head)
{
	str_ll *free_node;

	while (head != NULL)
	{
		free_node = head->next;

		free(head->string);
		free(head);
		head = free_node;
	}
}
