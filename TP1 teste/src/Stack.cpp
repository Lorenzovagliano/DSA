#include "Stack.hpp"

Stack::Stack(){
    this->top = nullptr; 
}

void Stack::push(Node* data){
    // Create new node temp and allocate memory in heap
    StackNode* temp = new StackNode(data);

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

    // Make temp as top of Stack
    this->top = temp;
}

bool Stack::isEmpty(){
    // If top is nullptr it means that
    // there are no elements are in stack
    return top == nullptr;
}

Node* Stack::getTop(){
    // If stack is not empty , return the top element
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

void Stack::pop(){
    StackNode* temp;

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

void Stack::display(){
    StackNode* temp;

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