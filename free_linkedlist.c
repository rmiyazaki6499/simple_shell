#include "linkedlist.h"

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
