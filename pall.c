#include "monty.h"
/**
 * pall - This function print all elements in the stack.
 * @stack: A pointer to the head of the stack.
 */
void pall(stack_t **stack)
{
        stack_t *current = *stack;

        while (current != NULL)
        {
                printf("%d\n", current->n);
                current = current->next;
        }
}
