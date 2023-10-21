
#include "monty.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * REturn: 0 if successfull
 */

int main(int argc, char **argv)
{
	char *op;
	char *arg;
	stack_t *stack = NULL;
	FILE *file = fopen(argv[1], "r");
	char *input;
	size_t len;
	unsigned int line_number;

	stack = NULL;
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	input = NULL;
	len = 0;
	line_number = 0;

	while (getline(&input, &len, file) != -1)
	{
		line_number++;
		op = strtok(input, " \t\n");
		arg = strtok(NULL, " \t\n");

		if (op == NULL)
			continue;

		if (strcmp(op, "push") == 0)
		{
			if (arg == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				free(input);
				fclose(file);
				exit(EXIT_FAILURE);
			}

			int value = atoi(arg);
			push(&stack, value);
		}
		else if (strcmp(op, "pall") == 0)
		{
			pall(&stack, line_number);
		}
	}

	free(input);
	fclose(file);
	return (0);
}
