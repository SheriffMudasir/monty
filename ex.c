#include "monty.h"

instruction_t op_funcs[] = {
    {"push", push},
    {"pall", pall},
    {NULL, NULL}};

void ex(stack_t **stack, char *input, unsigned int line_number, FILE *file)
{
	int i;
	char *op;
	char *arg;
	
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