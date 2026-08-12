#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
public:
    int items[MAX_SIZE];
    int front;
    int rear;

public:
    // Constructor (initialize queue)
    Queue() : front { -1 } , rear { 0 } {
        
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == rear - 1);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == MAX_SIZE);
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        items[rear] = value;
        rear++;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        front++;
    }

    // Peek front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return items[front + 1];
    }

    // Print queue
    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Current Queue: ";
        for (int i = front + 1; i < rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    Queue q;
    // Enqueue elements 
    for(int i = 0; i < 100; ++i){
        q.enqueue(67);
        q.dequeue();
    }
    
    cout << q.front << ' ' << q.rear << '\n';

    q.enqueue(23);


    return 0;
}