#include <iostream>

static constexpr int MAX = 100;

class Queue{
public:
    int front = -1;
    int rear = -1;
    int array[MAX] {};

    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        return rear == MAX - 1;;
    }

    bool enqueue(const int i){
        if(isFull()){ return false; }
        if (front == -1){ front = 0; }
        
        array[++rear] = i;
        return true;
    }

    int dequeue(){
        if(isEmpty()){ return -1; }
        int temp = array[front]; 
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
            front++;
        }
        return temp;
    }
    int peek(){
        if(isEmpty()){ return -1; }
        return array[front];
    }
};

int main(){}