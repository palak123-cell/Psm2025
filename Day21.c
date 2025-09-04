#include <stdio.h>
#include <stdlib.h>

#define MAX 10000   // Maximum stack size

// Structure for Stack
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Function to initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push element into stack
void push(Stack *s, int x) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = x;
}

// Pop element from stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Function to insert element at the bottom of stack using recursion
void insertAtBottom(Stack *s, int x) {
    if (isEmpty(s)) {
        push(s, x);
        return;
    }
    int temp = pop(s);
    insertAtBottom(s, x);
    push(s, temp);
}

// Function to reverse stack using recursion
void reverseStack(Stack *s) {
    if (isEmpty(s)) return;
    int temp = pop(s);
    reverseStack(s);
    insertAtBottom(s, temp);
}

// Function to print stack
void printStack(Stack *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Stack s;
    initStack(&s);

    // Example input
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);

    printf("Original Stack: ");
    printStack(&s);

    reverseStack(&s);

    printf("Reversed Stack: ");
    printStack(&s);

    return 0;
}
