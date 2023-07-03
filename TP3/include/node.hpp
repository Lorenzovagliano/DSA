#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node{
    public:
        // Attributes.
        char symbol;
        int frequency;
        Node* ant;
        Node* prox;
        Node* esq;
        Node* dir;

        // Constructors.
        Node();
        Node(char symbol, int frequency);
        Node(char symbol, int frequency, Node* prev, Node* prox);
        Node(int frequency, Node* esq, Node* dir);
        Node(char symbol, int frequency, Node* prev, Node* prox, Node* esq, Node* dir);

        // Destructor.
        ~Node();

        // Getters and Setters.
        void setSymbol(char symbol);
        void setFrequency(int frequency);
        void setAnt(Node* prev);
        void setProx(Node* prox);
        void setEsq(Node* esq);
        void setDir(Node* dir);

        // Methods.
        bool isLeaf();
        
        // Overloads.
        friend std::ostream& operator<< (std::ostream& stream, Node& node);
};

#endif
