#include <iostream>

static constexpr int MAX = 100;

class CircularQueue{
public:
    int front = -1;
    int rear = -1;
    int array[MAX] {};

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return (rear + 1) % MAX == front;
    }

    bool enqueue(const int i){
        if(isFull()){ return false; }
        if(front == -1){ front = 0; }

        rear = (rear + 1) % MAX;
        array[rear] = i;
        return true;
    }

    int dequeue(){
        if(isEmpty()){ return -1; }
        int temp = array[front];

        if (front == rear){
            front = -1;
            rear = -1;
        }else{
            front = (front + 1) % MAX;
        }

        return temp;
        
    }
};