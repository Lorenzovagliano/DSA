#ifndef CHARSTACKNODE_H
#define CHARSTACKNODE_H

#include "Node.hpp"

class CharStackNode {
    friend class CharStack;
    
    private:
        char data;
        CharStackNode* link;
    
    public:
        CharStackNode(char n);
};

#endif