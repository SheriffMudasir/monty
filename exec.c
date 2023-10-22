include "monty.h"

    void
    exec(char *op, char *input, FILE *file)
{
        if (strcmp(op, "push") == 0)
        {
                if (arg == NULL)
                {
                        fprintf(stderr, "L%u: usage: push integer\n", line_number);
                        free(input);
                        fclose(file);
                        exit(EXIT_FAILURE);
                }

                value = atoi(arg);
                push(&stack, value);
        }
        else if (strcmp(op, "pall") == 0)
        {
                pall(&stack);
        }
        free(input);
        fclose(file);
}