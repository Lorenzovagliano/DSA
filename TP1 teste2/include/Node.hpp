#ifndef NODE_H
#define NODE_H

class Node{
    public:
        char data;
        char array[7];
        Node *left, *right;
        
        Node(char data);
        Node(char data, Node *left, Node *right);
};

#endif