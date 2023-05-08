#ifndef INTESTACKNODE_H
#define INTESTACKNODE_H

#include "Node.hpp"

class IntStackNode {
    friend class IntStack;
    
    private:
        int data;
        IntStackNode* link;
    
    public:
        IntStackNode(int n);
};

#endif