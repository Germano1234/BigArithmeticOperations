#include "stack.hpp"

Node::Node(int val) : data(val), next(nullptr) {}

void Node::setNext(Node* nextNode) {
    next = nextNode;
}

int Node::getValue() const {
    return data;
}

Node* Node::getNext() const {
    return next;
}

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}


bool Stack::isEmpty() const {
    return top == nullptr;
}

void Stack::push(int val) {
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack underflow: cannot pop from an empty stack");
    }
    int val = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return val;
}

int Stack::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty: cannot peek");
    }
    return top->data;
}
