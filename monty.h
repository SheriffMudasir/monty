#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define STACKSIZE 100

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
} stack_t;

void push(stack_t **stack, int value);
void pall(stack_t *stack);

#endif
