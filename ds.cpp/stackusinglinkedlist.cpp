#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top; 

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top; 
        top = newNode;       
        cout << value << " pushed to stack\n";
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! (Stack is empty)\n";
            return -1;
        }
        Node* temp = top;     
        int poppedValue = temp->data;
        top = top->next;      
        delete temp;          
        cout << poppedValue << " popped from stack\n";
        return poppedValue;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements (Top to Bottom): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top element is: " << s.peek() << "\n";
    s.pop();
    s.pop();
    s.display();

    return 0;
}