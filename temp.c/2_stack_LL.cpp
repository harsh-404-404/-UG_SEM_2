#include <iostream>

struct ListNode{
    int data{};
    ListNode* next { nullptr };
};

class Stack{
public:
    Stack() = default;

    ListNode* Top { nullptr };

    void push(const int i){
        Top = new ListNode{ i, Top };
    }

    int pop(){
        if(Top == nullptr){ return -1; }

        ListNode*   temp { Top };
        int         data { Top->data };
        
        Top = Top->next;
        
        delete temp;
        return data;
    }   

    int peek(){
        if(Top == nullptr){ return -1; }
        return Top->data;
    }   

    void display(){
        ListNode* ptr { Top };
        while(ptr){
            std::cout << Top->data << " ";
            ptr = ptr->next;
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
