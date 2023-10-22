#include "monty.h"

/**
 * sub - This function subtracts the top element from the second top element of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 */
void sub(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        stack_t *first = *stack;
        stack_t *second = (*stack)->next;

        second->n -= first->n;
        pop(stack, line_number);
}