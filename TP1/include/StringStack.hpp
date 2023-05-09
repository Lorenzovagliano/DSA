#ifndef STRINGSTACK_H
#define STRINGSTACK_H

#include "StringStackNode.hpp"
#include <iostream>

class StringStack {
    private:
        StringStackNode* top;
    
    public:
        StringStack();
    
        void push(std::string data);
        bool isEmpty();
        std::string getTop();
        void pop();
};

#endif