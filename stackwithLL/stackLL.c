#include "stdio.h"
#include "stdlib.h"

struct Node {
    int data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

void initialize (struct Stack* stack) {
    stack->top = NULL;
}

int isEmpty (struct Stack* stack) {
    return (stack->top == NULL);
}

void push(struct Stack *stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memmory Allocation Failed");
        exit(1);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("New node pushed");
}

int pop (struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty");
        exit(1);
    }
    struct Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

int main () {
    struct Stack stack;
    initialize(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    int num = pop(&stack);
    printf("\n this is pop %d", num);
}