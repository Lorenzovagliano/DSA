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
    this->esq = NULL;
    this->dir = NULL;
}

Node::Node(char symbol, int frequency){
    this->symbol = symbol;
    this->frequency = frequency;
    this->ant = NULL;
    this->prox = NULL;
    this->esq = NULL;
    this->dir = NULL;
}

Node::Node(char symbol, int frequency, Node* ant, Node* prox){
    this->symbol = symbol;
    this->frequency = frequency;
    this->ant = ant;
    this->prox = prox;
    this->esq = NULL;
    this->dir = NULL;
}

Node::Node(int frequency, Node* esq, Node* dir){
    this->symbol = '\0';
    this->frequency = frequency;
    this->ant = NULL;
    this->prox = NULL;
    this->esq = esq;
    this->dir = dir;
}

Node::Node(char symbol, int frequency, Node* ant, Node* prox, Node* esq, Node* dir){
    this->symbol = symbol;
    this->frequency = frequency;
    this->ant = ant;
    this->prox = prox;
    this->esq = esq;
    this->dir = dir;
}

// Methods.

void Node::setSymbol(char symbol){
    this->symbol = symbol;
}

void Node::setFrequency(int frequency){
    this->frequency = frequency;
}

void Node::setEsq(Node* esq){
    this->esq = esq;
}

void Node::setDir(Node* dir){
    this->dir = dir;
}

void Node::setAnt(Node* ant){
    this->ant = ant;
}

void Node::setProx(Node* prox){
    this->prox = prox;
}

bool Node::isLeaf(){
    return this->esq == NULL && this->dir == NULL;
}
