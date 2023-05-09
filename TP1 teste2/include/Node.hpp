#ifndef NODE_H
#define NODE_H

#include <string>

class Node{
    public:
        std::string data;
        Node *left, *right;
        
        Node(std::string data);
        Node(std::string data, Node *left, Node *right);
};

#endif