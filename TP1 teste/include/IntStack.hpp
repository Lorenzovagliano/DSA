#ifndef INTSTACK_H
#define INTSTACK_H

#include "IntStackNode.hpp"
#include <iostream>

class IntStack {
    private:
        IntStackNode* top;
    
    public:
        IntStack();
    
        void push(int data);
    
        // Utility function to check if
        // the stack is empty or not
        bool isEmpty();
    
        // Utility function to return top element in a stack
        int getTop();
    
        // Function to remove
        // a key from given queue q
        void pop();
    
        // Function to print all the
        // elements of the stack
        void display();
};

#endif