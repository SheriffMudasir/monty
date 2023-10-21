#include "monty.h"
#define STACKSIZE 100
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

#define _GNU_SOURCE
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

void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)

	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
