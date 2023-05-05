#ifndef STACK_H
#define Stack_H

#include "StackNode.hpp"
#include <iostream>

class Stack {
    private:
        StackNode* top;
    
    public:
        Stack();
    
        void push(Node* data);
    
        // Utility function to check if
        // the stack is empty or not
        bool isEmpty();
    
        // Utility function to return top element in a stack
        Node* getTop();
    
        // Function to remove
        // a key from given queue q
        void pop();
    
        // Function to print all the
        // elements of the stack
        void display();
};

#endif