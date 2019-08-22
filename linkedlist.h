#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

typedef struct str_ll_s
{
	char *string;
	struct str_ll_s *next;
} str_ll;

str_ll *add_node_end(str_ll **head, const char *str);
str_ll *_strtoll(char *str, char *delim);
char *_which(char *cmd, str_ll *head);
void free_linkedlist(str_ll *head);

#endif /* LINKEDLIST_H */
