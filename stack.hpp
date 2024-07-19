#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>

class Node {
public:
    int data;
    Node* next;

    Node(int val);

    void setNext(Node* nextNode);

    int getValue() const;
    Node* getNext() const;
};

class Stack {
private:
    Node* top;

public:
    Stack();

    ~Stack();

    bool isEmpty() const;

    void push(int val);

    int pop();

    int peek() const;
};

#endif 


