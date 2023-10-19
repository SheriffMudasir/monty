#include "monty.h"
#include <stdio.h>

int main(void)
{
<<<<<<< HEAD
        char *op, *arg;
        size_t len = 0;
        unsigned int line_number = 0;
	stack_t *stack = NULL;
=======
    char *op, *arg;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
>>>>>>> 446b534ba3229ed1d3c1bfea7dbd322372dd7d75

    while (1)
    {
        char *input = NULL;
        ssize_t read = getline(&input, &len, stdin);
        if (read == -1)
            break;

        line_number++;

        op = strtok(input, " \t\n");
        arg = strtok(NULL, " \t\n");

        if (op == NULL || (strcmp(op, "push") == 0 && arg == NULL))
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            free(input);
            exit(EXIT_FAILURE);
        }

        if (strcmp(op, "push") == 0)
        {
            int value;
            if (isdigit(*arg) || (*arg == '-' && isdigit(*(arg + 1))))
            {
                value = atoi(arg);
                push(&stack, value, line_number);
            }
            else
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                free(input);
                exit(EXIT_FAILURE);
            }
        }
        else if (strcmp(op, "pall") == 0)
        {
            pall(stack);
        }
        free(input);
    }

    return (0);
}

void push(stack_t **stack, int value, unsigned int line_number)
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
