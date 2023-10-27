#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int argc, char **argv)
{
	char *input;
	size_t len;
	unsigned int line_number;
	stack_t *stack;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

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
		ex(&stack, input, line_number, file);
	}

	free(input);
	fclose(file);
	return (0);
}