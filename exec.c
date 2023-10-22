#include "monty.h"

/**
 * op_funcs - An array of opcode and function pointers.
 * @op: The opcode string.
 * @f: The function to execute for the opcode.
 */
instruction_t op_funcs[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}};

/**
 * ex - This function is the central execution for allocating functions
 * @stack: A pointer to the head of the stack.
 * @input: Input read from the file.
 * @line_number: Tracking line number.
 * @file: The file passed as an argument.
 */
void ex(stack_t **stack, char *input, unsigned int line_number, FILE *file)
{
	char *op;
	char *arg;
	int i;

	op = strtok(input, " \t\n");
	arg = strtok(NULL, " \t\n");

	if (op == NULL)
		return;

	i = 0;
	while (op_funcs[i].opcode != NULL)
	{
		if (strcmp(op, op_funcs[i].opcode) == 0)
		{
			if (arg == NULL && strcmp(op, "push") == 0)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				free(input);
				fclose(file);
				exit(EXIT_FAILURE);
			}

			op_funcs[i].f(stack, arg ? atoi(arg) : 0);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
	free(input);
	fclose(file);
	exit(EXIT_FAILURE);
}
