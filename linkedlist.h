#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct str_ll
{
	char *string;
	struct str_ll *next;
} str_ll;

str_ll strtoll(char *str, char delim);
char *_which(char *cmd);

#endif /* LINKEDLIST_H */
