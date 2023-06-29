#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node{
    public:
        // Attributes.
        char symbol;
        int frequency;
        Node* prev;
        Node* next;
        Node* left;
        Node* right;

        // Constructors.
        Node();
        Node(char symbol, int frequency);
        Node(char symbol, int frequency, Node* prev, Node* next);
        Node(int frequency, Node* left, Node* right);
        Node(char symbol, int frequency, Node* prev, Node* next, Node* left, Node* right);

        // Destructor.
        ~Node();

        // Getters and Setters.
        void setSymbol(char symbol);
        void setFrequency(int frequency);
        void setPrev(Node* prev);
        void setNext(Node* next);
        void setLeft(Node* left);
        void setRight(Node* right);

        // Methods.
        bool isLeaf();
        
        // Overloads.
        friend std::ostream& operator<< (std::ostream& stream, Node& node);
};

#endif
