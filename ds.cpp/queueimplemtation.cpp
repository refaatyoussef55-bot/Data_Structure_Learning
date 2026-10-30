#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue Overflow! (Queue is full)\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
        cout << item << " enqueued to queue\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! (Queue is empty)\n";
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        cout << item << " dequeued from queue\n";
        count--;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == capacity);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements (Front to Rear): ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Queue q(4);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << q.dequeue() << "\n";
    
    q.display();

    q.enqueue(40);
    q.enqueue(50);

    q.display();

    return 0;
}