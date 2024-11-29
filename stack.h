#ifndef STACK_H
#define STACK_H

struct stack {
        void *data;
        int capacity;
        int size;
};

struct stack *stack_ctor(const int capacity);
void stack_dtor(struct stack *stk);

#endif
