#include <iostream>
#include <string>
#include <sstream>
#include "node.hpp"

// Operators overloading.

std::ostream& operator<< (std::ostream& stream, Node& node){
    std::stringstream ss;
    ss << node.frequency;

    std::string text = "(";
    text += node.symbol;
    text += ",";
    text += ss.str();
    text += ")";

    return stream << text;
}

// Constructors.

Node::Node(){
    this->symbol = '\0';
    this->frequency = 0;
    this->left = NULL;
    this->right = NULL;
}

Node::Node(char symbol, int frequency){
    this->symbol = symbol;
    this->frequency = frequency;
    this->prev = NULL;
    this->next = NULL;
    this->left = NULL;
    this->right = NULL;
}

Node::Node(char symbol, int frequency, Node* prev, Node* next){
    this->symbol = symbol;
    this->frequency = frequency;
    this->prev = prev;
    this->next = next;
    this->left = NULL;
    this->right = NULL;
}

Node::Node(int frequency, Node* left, Node* right){
    this->symbol = '\0';
    this->frequency = frequency;
    this->prev = NULL;
    this->next = NULL;
    this->left = left;
    this->right = right;
}

Node::Node(char symbol, int frequency, Node* prev, Node* next, Node* left, Node* right){
    this->symbol = symbol;
    this->frequency = frequency;
    this->prev = prev;
    this->next = next;
    this->left = left;
    this->right = right;
}

// Methods.

void Node::setSymbol(char symbol){
    this->symbol = symbol;
}

void Node::setFrequency(int frequency){
    this->frequency = frequency;
}

void Node::setLeft(Node* left){
    this->left = left;
}

void Node::setRight(Node* right){
    this->right = right;
}

void Node::setPrev(Node* prev){
    this->prev = prev;
}

void Node::setNext(Node* next){
    this->next = next;
}

bool Node::isLeaf(){
    return this->left == NULL && this->right == NULL;
}
