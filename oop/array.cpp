#include <iostream>

class Stack {
private:
    int data[25];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() const {
        return top < 0;
    }

    bool isFull() const {
        return top >= 24;
    }

    bool push(int value) {
        if (isFull()) {
            std::cout << "Stack overflow: cannot push " << value << "\n";
            return false;
        }
        data[++top] = value;
        return true;
    }

    int pop() {
        if (top < 0) {
            std::cout << "Stack underflow: no element to pop\n";
            return -2; // sentinel value for error
        }
        return data[top--];
    }
};

int main() {
    Stack stack;
    
    int value1 {};
    int value2 {};
    std::cout << "Enter a number : ";
    std::cin >> value1;
    std::cout << "Enter a number : ";
    std::cin >> value2;
    
    stack.push(value1);
    stack.push(value2);
    
    
    std::cout << "Popped: " << stack.pop() << "\n";
    std::cout << "Popped: " << stack.pop() << "\n";
    std::cout << "Popped: " << stack.pop() << "\n";
    
    stack.push(value2);
    stack.push(value2);
    
    std::cout << "Popped: " << stack.pop() << "\n";
    std::cout << "Popped: " << stack.pop() << "\n";
    std::cout << "Popped: " << stack.pop() << "\n";
    return 0;
}