#ifndef STACKNODE_H
#define STACKNODE_H

#include "Node.hpp"

class StackNode {
    friend class Stack;
    
    private:
        Node* data;
        StackNode* link;
    
    public:
        StackNode(Node* n);
};

#endif