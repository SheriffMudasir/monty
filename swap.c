#include "monty.h"

void swap(stack_t **stack)
{
        if (*stack == NULL || (*stack)->prev == NULL)
        {
                fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        int temp = (*stack)->n;
        (*stack)->n = (*stack)->prev->n;
        (*stack)->prev->n = temp;
}