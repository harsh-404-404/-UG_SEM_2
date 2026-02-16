#include <iostream>

void push(int x){
    if(top == full - 1){
        cout << "stack full";
        return;
    }
    stack[++top] = x;
}