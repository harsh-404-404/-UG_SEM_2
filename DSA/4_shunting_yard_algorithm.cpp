#include <iostream>
#include <string>

constexpr int MAX_SIZE = 1000;

class Stack{
private:
    char arr[MAX_SIZE];
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

    bool push(char value){
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

// std::string ToPostFix(const std::string& infix){

// }

int main(){

    Stack test;
    std::string expression { "AB+CD" };
    for(int i = 0; i < expression.length(); ++i){
        if(is_operator(expression[i])){
            
        }
    }
    test.display();

}