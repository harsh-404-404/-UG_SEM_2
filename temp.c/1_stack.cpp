#include <iostream>

#define MAX 500

class Stack{
private:
    int array[MAX] {};
    int top = -1;

public:
    bool push(const int i){
        if(top == MAX - 1){
            return false;    
        }
        array[++top] = i;
        return true;
    }
    
    int pop(){
        if(empty()) return -1;
        return array[top--];
    }
    
    int peek(){
        if(empty()) return -1;
        return array[top];
    }
    
    bool empty(){ return top == -1; }

    void display(){
        for(int i = top; i > 0; --i){
            std::cout << array[i] << " ";
        }
        std::cout << "\n";
    }
};

int main(){

    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Current Stack: ";
    myStack.display();

    std::cout << "Popped: " << myStack.pop() << "\n";

    std::cout << "Stack after pop: ";
    myStack.display();


}