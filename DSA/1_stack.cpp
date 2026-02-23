#include <iostream>
#include <stdexcept>

constexpr int MAX_SIZE = 1000;

class Stack{
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack(){
        top = -1;
    }

    bool is_empty(){
        return top == -1;
    }
    bool is_full(){
        return top == MAX_SIZE - 1;
    }

    int pop() {
        if (is_empty()) {
            throw std::out_of_range("Stack Underflow: Cannot pop from an empty stack.");
        }
        return arr[top--];
    }

    bool push(int value){
        if(is_full()){
            throw std::out_of_range("Stack overflow: Cannot push in full stack.");
            return false;
        }
        arr[++top] = value; 
        return true;
    }
    int peek() {
            if (is_empty()) {
                return -1;
            }
            return arr[top];
        }

    void display() {
        for (int i = top; i >= 0; --i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }   
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Current Stack: ";
    myStack.display();

    std::cout << "Popped: " << myStack.pop() << "\n";

    std::cout << "Stack after pop: ";
    myStack.display();

    return 0;
}