#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

void stack_ctor(struct stack *stk, const int capacity, const size_t elm_size)
{ 
        stk->data = calloc(capacity, sizeof(elm_size));
        if (!stk->data) {
                fprintf(stderr, "error: couldn't allocate memory");
                exit(1);
        }

        stk->capacity = capacity;
        stk->elm_size = elm_size;
}

void stack_dtor(struct stack *stk)
{
        free(stk->data);
        stk->data = NULL;
}

void stack_push(struct stack *stk, void *elm)
{
        memcpy((char *) stk->data + stk->size * stk->elm_size, (char *) elm, stk->elm_size);
        ++stk->size;
}
