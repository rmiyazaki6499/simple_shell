#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	ssize_t bytes_read;
	char *input;
	size_t input_length;
	char *child_program_argv[2] = {NULL, NULL};
	pid_t child_pid;

	while (1)
	{
		printf("$ ");

		bytes_read = getline(&input, &input_length, stdin);
		if (bytes_read == -1)
		{
			free(input);
			putchar('\n');
			break;
		}

		input[bytes_read - 1] = '\0';

		child_program_argv[0] = input;

		child_pid = fork();
		if (child_pid < 0)
		{
			perror("Error");
			exit(1);
		}
		else if (child_pid == 0)
		{
			if (execve(input, child_program_argv, NULL) == -1)
			{
				perror("Error");
				free(input);
				exit(127);
			}
		}
		else
			wait(NULL);
		free(input);
		input = NULL;
		input_length = 0;
	}

	return (EXIT_SUCCESS);
}
