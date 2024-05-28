#include "stdio.h"
#include "stdlib.h"
#define MAX_NUMBER 10

struct Stack {
    int items[MAX_NUMBER];
    int top;
};

void initialized (struct Stack * stack) {
    stack->top = -1;
}

int isFull (struct Stack * stack) {
    return (stack->top == MAX_NUMBER - 1);
}

int isEmpty (struct Stack * stack) {
    return (stack->top == -1);
}

void push (struct Stack * stack, int num) {
    if (isFull (stack)) {
        printf("Stack overflow");
        exit(1);
    }
    else {
        stack->items[++stack->top] = num;
        printf("Value inserted to place->%d : value = %d\n", stack->top, stack->items[stack->top]);
    }
}

int pop (struct Stack * stack) {
    if (isEmpty (stack)) {
        printf("Stack underflow");
        exit(1);
    } else {
        return stack->items[stack->top--];
    }
}

int peek (struct Stack * stack) {
    if (isEmpty (stack)) {
        printf("Stack has no data");
        return -1;
    } else {
        return stack->items[stack->top];
    }
}

int main () {
    struct Stack stack;
    initialized(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    int last = pop(&stack);
    printf("Peek data :%d\n", peek(&stack));
}