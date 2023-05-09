#ifndef STRINGSTACKNODE_H
#define STRINGSTACKNODE_H

#include <string>

using namespace std;

class StringStackNode {
    friend class StringStack;
    
    private:
        string data;
        StringStackNode* link;
    
    public:
        StringStackNode(std::string n);
};

#endif