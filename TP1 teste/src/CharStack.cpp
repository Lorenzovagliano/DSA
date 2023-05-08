#include "CharStack.hpp"

CharStack::CharStack(){
    this->top = nullptr; 
}

void CharStack::push(char data){
    // Create new node temp and allocate memory in heap
    CharStackNode* temp = new CharStackNode(data);

    // Check if stack (heap) is full.
    // Then inserting an element would
    // lead to stack overflow
    if (!temp) {
        std::cout << "\nStack Overflow";
        exit(1);
    }

    // Initialize data into temp data field
    temp->data = data;

    // Put top pointer reference into temp link
    temp->link = this->top;

    // Make temp as top of CharStack
    this->top = temp;
}

bool CharStack::isEmpty(){
    // If top is nullptr it means that
    // there are no elements are in stack
    return top == nullptr;
}

char CharStack::getTop(){
    // If stack is not empty , return the top element
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

void CharStack::pop(){
    CharStackNode* temp;

    // Check for stack underflow
    if (top == nullptr) {
        std::cout << "\nStack Underflow" << std::endl;
        exit(1);
    }
    else {

        // Assign top to temp
        temp = top;

        // Assign second node to top
        top = top->link;

        // This will automatically destroy
        // the link between first node and second node

        // Release memory of top node
        // i.e delete the node
        free(temp);
    }
}

void CharStack::display(){
    CharStackNode* temp;

    // Check for stack underflow
    if (top == nullptr) {
        std::cout << "\nStack Underflow";
        exit(1);
    }
    else {
        temp = top;
        while (temp != nullptr) {

            // Print node data
            std::cout << temp->data;

            // Assign temp link to temp
            temp = temp->link;
            if (temp != nullptr)
                std::cout << " -> ";
        }
    }
}