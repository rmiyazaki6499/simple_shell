#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>


/**
 * struct str_ll_s - linked list
 * @string: malloc'ed string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for simple shell
 */
typedef struct str_ll_s
{
	char *string;
	struct str_ll_s *next;
} str_ll;

str_ll *add_node_end(str_ll **head, const char *str);
str_ll *add_node_at_index(str_ll **head, const char *str, size_t index);
str_ll *_strtoll(char *str, char *delim);
char *_which(char *cmd, str_ll *head);
void free_linkedlist(str_ll *head);

#endif /* LINKEDLIST_H */
