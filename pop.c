#include "monty.h"

/**
 * pop - This function removes the top element of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 */
void pop(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL)
        {
                fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
                exit(EXIT_FAILURE);
        }

        stack_t *temp = *stack;

        *stack = (*stack)->next;

        if (*stack)
                (*stack)->prev = NULL;

        free(temp);
}