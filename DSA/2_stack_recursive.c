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
    printf("%d <- push success!!\n", value);
}

int pop(){
    if (is_empty()){
        printf("Stack is empty!!\n");
        return -1;
    }
    else{
        int value = stack[top--];
        printf("Poped value: %d\n", value);
        return value;
    }
    
}
int peek(){
    if (is_empty()){
        printf("Stack is empty!!\n");
        return -1;
    }
    else{
        return stack[top];
    }
}


void print_r(int poiting_top){
    if(poiting_top < 0){
        return;
    }

    printf("\t|\t%d \t|\n",stack[poiting_top]);
    printf("\t-----------------\n");
    print_r(--poiting_top);
    return;

}

int main(){
    push(10);
    push(20);
    push(30);
    printf("\n");

    printf("CURRENT STACK: \n");
    print_r(top);
    
    return 0;
}