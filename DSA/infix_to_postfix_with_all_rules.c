//Q. Write a C program to implement Infix to Postfix conversion using stack operations.
//Your program should:Handle operators + , - , * , / , ^
//Follow operator precedence. Apply associativity rules
//+ , - , * , / → Left associative , ^ → Right associative
//Test the program using the expression:A+B*C^D-E
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

// Push element into stack
void push(char x) {
    stack[++top] = x;
}

// Pop element from stack
char pop() {
    return stack[top--];
}

// Peek top element
char peek() {
    return stack[top];
}

// Operator precedence
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Check associativity
int isRightAssociative(char op) {
    if (op == '^')
        return 1;
    return 0;
}

int main() {
    char infix[] = "A+B*C^D-E";
    char postfix[MAX];
    int i = 0, j = 0;

    printf("Infix Expression: %s\n", infix);

    while (infix[i] != '\0') {

        // If operand, add to postfix
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // If '(' push to stack
        else if (infix[i] == '(') {
            push(infix[i]);
        

        }// If ')'
        else if (infix[i] == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();
            pop(); // Remove '('
        }

        // If operator
        else {
            while (!isEmpty() &&
                  ((precedence(peek()) > precedence(infix[i])) ||
                  (precedence(peek()) == precedence(infix[i]) &&
                  !isRightAssociative(infix[i])))) {

                postfix[j++] = pop();
            }
            push(infix[i]);
        }

        i++;
    }
    
    // Pop remaining operators
    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}