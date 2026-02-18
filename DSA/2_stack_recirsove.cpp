#include <iostream>
#include <stdexcept>

constexpr int MAX_SIZE = 1000;

class Stack{
private:
    int arr[MAX_SIZE];
    int top;

    void displayhelper(int current_top){
        if(current_top < 0){
            return;
        }
        std::cout << "\t|\t" << arr[top] << "\t|\n";
        std::cout << "\t-----------------" << '\n';
        displayhelper(--current_top);
        return;
    }

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
        displayhelper(top);
    }   
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Current Stack: \n";
    myStack.display();

    std::cout << "Popped: " << myStack.pop() << "\n";

    std::cout << "Stack after pop: \n";
    myStack.display();

    return 0;
}