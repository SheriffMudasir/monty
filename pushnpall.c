#include "monty.h"
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    char *op, *arg;
    stack_t *stack = NULL;
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char *input = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

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
            pall(stack);
        }
	else if (strcmp(op, "pint") == 0)
	{
		pint(stack,line_number);
	}
	else if (strcmp(op, "pop") == 0)
	{
		pop(&stack);
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
    new_node->prev = *stack;
    *stack = new_node;
}

void pall(stack_t *stack)
{
    stack_t *current = stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->prev;
    }
}
