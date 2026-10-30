#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;
#include "node.h"

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
    }

    void addNode(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAt(int pos, int value) {
        if (pos < 0 || pos > countNodes()) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
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

    void displayReverse() {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;

        current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;

        // Restore the original order
        current = head;
        prev = nullptr;
        while (current != nullptr) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }

    
    void deleteNode(int value) {
        Node* nodeToDelete = search(value);
        if (nodeToDelete == nullptr) {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        if (nodeToDelete == head) {
            head = head->next;
        } else {
            Node* current = head;
            while (current->next != nodeToDelete) {
                current = current->next;
            }
            current->next = nodeToDelete->next;
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
            delete nodeToDelete;
        } else {
            Node* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            Node* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            delete nodeToDelete;
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
        return -1;
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

private:
    Node* head;

    Node* search(int value) {
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

#endif // LINKEDLIST_H