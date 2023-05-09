#ifndef NODESTACK_H
#define NODESTACK_H

#include "NodeStackNode.hpp"
#include <iostream>

class NodeStack {
    private:
        NodeStackNode* top;
    
    public:
        NodeStack();
    
        void push(TreeNode* data);
        bool isEmpty();
        TreeNode* getTop();
        void pop();
};

#endif