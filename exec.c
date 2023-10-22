#include "monty.h"
/**
 * execution - This function is the central execution for allocating functions
 * @stack: A pointer to the head of the stack.
 * @input: input read from file
 * @line_number: tracking line number
 * @file: the file passed a argument
 */
void execution(stack_t **stack, char *input, unsigned int line_number, FILE *file)
{
        char *op, *arg;

        op = strtok(input, " \t\n");
        arg = strtok(NULL, " \t\n");

        if (op == NULL)
                return;

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
                push(stack, value);
        }
        else if (strcmp(op, "pall") == 0)
        {
                pall(stack);
        }
}
