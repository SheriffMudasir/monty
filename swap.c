#include "monty.h"

/**
 * swap - This function swaps the top two elements of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 */
void swap(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        stack_t *first = *stack;
        stack_t *second = (*stack)->next;

        first->next = second->next;
        first->prev = second;
        second->next = first;
        second->prev = NULL;
        *stack = second;

        if (first->next)
                first->next->prev = first;
}