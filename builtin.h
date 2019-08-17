#ifndef BUILTIN_H
#define BUILTIN_H

typedef struct builtin_t
{
	        char *func_name;
		int (*function)(char **):
		char **long_description;
		char *short_description;
		struct builtin_t_ *next;
} builtin;

#endif /* BUILTIN_H */
