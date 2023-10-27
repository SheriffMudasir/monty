#include "monty.h"

/**
 * pall - This function prints all elements in the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}