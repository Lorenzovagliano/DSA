#ifndef LIST_H
#define LIST_H

#include "node.hpp"

class List{
    public:
        // Attributes.
        Node* first;
        Node* last;
        int length;

        // Constructors.
        List();

        // Destructor.
        ~List();

        // Methods.
        void add(char symbol);
        void add(Node* node);
        void remove(Node* node);
        bool isEmpty();

        // Getters and Setters.
        Node* getNode(char symbol);

    private:
        // Methods.
        void shift(Node* node, Node* other);
        void sort(Node* node);
};

#endif