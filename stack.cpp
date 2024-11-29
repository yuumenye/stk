#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct stack *stack_ctor(const int capacity)
{ 
        struct stack *stk = (struct stack *) calloc(capacity, sizeof(char));
        if (!stk) {
                fprintf(stderr, "error: couldn't allocate memory");
                exit(1);
        }
        return stk;
}

void stack_dtor(struct stack *stk)
{
        free(stk);
        stk = NULL;
}
