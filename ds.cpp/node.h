#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
    int data;
    Node* next;
    Node* prev;
};
#endif // NODE_H