#ifndef NODE_H
#define NODE_H

class Node{
    private:
        char data;
        Node *left, *right;
    
    public:
        Node(char data);
        Node(char data, Node *left, Node *right);
};

#endif