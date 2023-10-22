#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include "monty.h"
/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * REturn: 0 if successfull
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	FILE *file = fopen(argv[1], "r");
	char *input;
	size_t len;
	unsigned int line_number;

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
		execute_instruction(&stack, input, line_number, file);
	}

	free(input);
	fclose(file);
	return 0;
}
