#include <stdio.h>

#define MAXSIZE 100 

int stack[MAXSIZE];
int top = -1;

int is_empty(){
    return top == -1;
}

int is_full(){
    return top == MAXSIZE - 1;
}

void push(int value){
    if(is_full()){
        printf("stack full"); 
        return;
    }
    stack[++top] = value;
    printf("%d <- push success!!", value);
}

int pop(){
    if (is_empty()){
        printf("Stack is empty!!");
        return -1;
    }
    else{
        int value = stack[top--];
        printf("Poped value%d", value);
        return value;
    }
    
}
int peek(){
    if (is_empty()){
        printf("Stack is empty!!");
        return -1;
    }
    else{
        return stack[top];
    }
}

int main(){
    push(10);
    printf("\n"); 
    push(20);
    printf("\n");
    push(30);
    printf("\n");
    pop();
    printf("\n");

    for(int i = top; i >= 0; --i){
        printf("%d ", stack[i]);
    }
    
    return 0;
}