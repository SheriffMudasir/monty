#include "monty.h"

void add(stack_t **stack)
{
        if (*stack == NULL || (*stack)->prev == NULL)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        (*stack)->prev->n += (*stack)->n;
        pop(stack);
}
