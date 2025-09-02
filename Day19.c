#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int stack[MAX], top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* expr) {
    char *token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))) {
            push(atoi(token));   // push number
        } else {
            int b = pop();
            int a = pop();
            switch(token[0]) {
                case '+': push(a+b); break;
                case '-': push(a-b); break;
                case '*': push(a*b); break;
                case '/': push(a/b); break;
            }
        }
        token = strtok(NULL, " ");
    }
    return pop();
}

int main() {
    char expr[MAX];
    printf("Enter postfix expression: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = 0; // remove newline
    printf("Result: %d\n", evaluatePostfix(expr));
    return 0;
}
