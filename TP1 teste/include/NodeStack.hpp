#ifndef NODESTACK_H
#define NODESTACK_H

#include "NodeStackNode.hpp"
#include <iostream>

class NodeStack {
    private:
        NodeStackNode* top;
    
    public:
        NodeStack();
    
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