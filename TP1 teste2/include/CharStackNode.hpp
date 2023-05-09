#ifndef CHARSTACKNODE_H
#define CHARSTACKNODE_H

#include <string>

class CharStackNode {
    friend class CharStack;
    
    private:
        std::string data;
        CharStackNode* link;
    
    public:
        CharStackNode(std::string n);
};

#endif