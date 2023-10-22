#include "monty.h"

/**
 * mod - This function computes the remainder of the division of the second top element by the top element of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 */
void mod(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        stack_t *first = *stack;
        stack_t *second = (*stack)->next;

        if (first->n == 0)
        {
                fprintf(stderr, "L%u: division by zero\n", line_number);
                exit(EXIT_FAILURE);
        }

        second->n %= first->n;
        pop(stack, line_number);
}