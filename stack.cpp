#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

static void stack_realloc(struct stack *stk, const int capacity);

void stack_ctor(struct stack *stk, const int capacity, const size_t elm_size)
{ 
        stk->data = calloc(capacity, sizeof(elm_size));
        if (!stk->data) {
                fprintf(stderr, "error: couldn't allocate memory\n");
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
        if (stk->size >= stk->capacity) {
                const int expand_val = 2;
                stack_realloc(stk, stk->capacity * expand_val);
        }

        memcpy((char *) stk->data + stk->size * stk->elm_size, (char *) elm,
                        stk->elm_size);

        ++stk->size;
}

void stack_pop(struct stack *stk, void *elm)
{
        const int shrink_lim = 4;
        if (stk->size <= stk->capacity/shrink_lim) {
                const int shrink_val = 2;
                stack_realloc(stk, stk->capacity/shrink_lim);
        }

        memcpy((char *) elm, (char *) stk->data + stk->size * stk->elm_size,
                        stk->elm_size);

        for (int i = 0; i < stk->elm_size; ++i)
                *((char *) stk->data + i * stk->elm_size) = 0;

        --stk->size;
}

static void stack_realloc(struct stack *stk, const int capacity)
{
        stk->data = realloc(stk->data, capacity * sizeof(stk->elm_size));
        if (!stk->data) {
                fprintf(stderr, "error: couldn't allocate memory\n");
                exit(1);
        }
}
