#ifndef NODESTACKNODE_H
#define NODESTACKNODE_H

#include "Node.hpp"

class NodeStackNode {
    friend class NodeStack;
    
    private:
        Node* data;
        NodeStackNode* link;
    
    public:
        NodeStackNode(Node* n);
};

#endif