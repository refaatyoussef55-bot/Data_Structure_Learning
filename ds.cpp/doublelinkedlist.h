#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <iostream>
using namespace std;
#include "node.h"

class DoubleLinkedList {
public:
    DoubleLinkedList(){
        tail = nullptr;
        head = nullptr;
    };

    void addNode(int value){
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }


    void insertAt(int pos, int value) {
        if (pos < 0 || pos > countNodes()) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (pos == 0) {
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        } else {
            Node* current = head;
            for (int i = 0; i < pos; i++) {
                current = current->next;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
    }

    void displayForward() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void displayBackward() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void deleteNode(int value) {
        Node* nodeToDelete = search(value);
        if (nodeToDelete == nullptr) {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        if (nodeToDelete == head) {
            if (nodeToDelete == tail) {
                head = nullptr;
                tail = nullptr;
            }

            else {
                head = nodeToDelete->next;
                head->prev = nullptr;
            }
        }

        else if (nodeToDelete == tail) {
            tail = nodeToDelete->prev;
            tail->next = nullptr;
        }

        else {
            nodeToDelete->prev->next = nodeToDelete->next;
            nodeToDelete->next->prev = nodeToDelete->prev;
        }

        delete nodeToDelete;
    }

    void deleteAt(int pos) {
        if (pos < 0 || pos >= countNodes()) {
            cout << "Invalid position." << endl;
            return;
        }

        if (pos == 0) {
            Node* nodeToDelete = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr; // List is now empty
            }
            delete nodeToDelete;
        } else {
            Node* current = head;
            for (int i = 0; i < pos; i++) {
                current = current->next;
            }
            current->prev->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev; // Update tail if last node is deleted
            }
            delete current;
        }
    }

    int countNodes() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    int getbyindex(int index) {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            if (count == index) {
                return current->data;
            }
            count++;
            current = current->next;
        }
        cout << "Index " << index << " is out of bounds." << endl;
        return -1; // Return -1 to indicate that the index is out of bounds
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void displayReverse() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    private:
    Node* head;
    Node* tail;

    Node * search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};

#endif // DOUBLELINKEDLIST_H