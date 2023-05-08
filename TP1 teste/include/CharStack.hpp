#ifndef CHARSTACK_H
#define CHARSTACK_H

#include "CharStackNode.hpp"
#include <iostream>

class CharStack {
    private:
        CharStackNode* top;
    
    public:
        CharStack();
    
        void push(char data);
    
        // Utility function to check if
        // the stack is empty or not
        bool isEmpty();
    
        // Utility function to return top element in a stack
        char getTop();
    
        // Function to remove
        // a key from given queue q
        void pop();
    
        // Function to print all the
        // elements of the stack
        void display();
};

#endif