#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int isOperator(char symbol) {
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-') {
        return 1;
    }
    return 0;
}

int precedence(char symbol) {
    if (symbol == '^') return 3;
    else if (symbol == '*' || symbol == '/') return 2;
    else if (symbol == '+' || symbol == '-') return 1;
    else return 0;
}

void infixToPostfix(char infix_exp[], char postfix_exp[]) {
    int i = 0, j = 0;
    char item, x;

    push('(');
    strcat(infix_exp, ")");

    item = infix_exp[i];

    while (item != '\0') {
        if (item == '(') {
            push(item);
        } else if (isalnum(item)) {
            postfix_exp[j++] = item;
        } else if (isOperator(item)) {
            x = pop();
            while (isOperator(x) == 1 && precedence(x) >= precedence(item)) {
                postfix_exp[j++] = x;
                x = pop();
            }
            push(x);
            push(item);
        } else if (item == ')') {
            x = pop();
            while (x != '(') {
                postfix_exp[j++] = x;
                x = pop();
            }
        } else {
            printf("Invalid expression.\n");
            exit(1);
        }
        i++;
        item = infix_exp[i];
    }
    postfix_exp[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter Infix expression (e.g., A+B*C): ");
    // For automated testing without user input, we use a predefined string
    strcpy(infix, "a+b*(c^d-e)^(f+g*h)-i");
    printf("%s\n", infix);

    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);

    return 0;
}