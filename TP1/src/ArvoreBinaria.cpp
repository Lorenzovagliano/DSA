#include "ArvoreBinaria.hpp"

ArvoreBinaria::ArvoreBinaria(){
    this->raiz = nullptr;
}

ArvoreBinaria::~ArvoreBinaria(){
}

void ArvoreBinaria::postorder(TipoNo* raiz){
    if (raiz == nullptr) {
        return;
    }
 
    postorder(raiz->esq);
    postorder(raiz->dir);
    std::cout << raiz->item;
}

bool ArvoreBinaria::isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void ArvoreBinaria::inorder(TipoNo* raiz){
    if (raiz == nullptr) {
        return;
    }
 
    // if the current token is an operator, print open parenthesis
    if (isOperator(raiz->item)) {
        std::cout << "(";
    }
 
    inorder(raiz->esq);
    std::cout << raiz->item;
    inorder(raiz->dir);
 
    // if the current token is an operator, print close parenthesis
    if (isOperator(raiz->item)) {
        std::cout << ")";
    }
}

TipoNo* ArvoreBinaria::construir(std::string posfixa){
    // base case
    if (posfixa.length() == 0) {
        return nullptr;
    }
 
    // create an empty stack to store tree pointers
    Pilha s;
 
    // traverse the posfixa expression
    for (char c: posfixa)
    {
        // if the current token is an operator
        if (isOperator(c))
        {
            // Desempilha two nodes `x` and `y` from the stack
            TipoNo* x = new TipoNo();
            x = s.topo;
            s.Desempilha();
 
            TipoNo* y = new TipoNo();
            y = s.topo;
            s.Desempilha();
 
            // construct a new binary tree whose root is the operator and whose
            // left and right children point to `y` and `x`, respectively
            this->raiz->item = c;
            this->raiz->esq = y;
            this->raiz->dir = x;
 
            // Empilha the current node into the stack
            s.Empilha(this->raiz);
        }
 
        // if the current token is an operand, create a new binary tree node
        // whose root is the operand and Empilha it into the stack
        else {
            this->raiz->item = c;
            s.Empilha(this->raiz);
        }
    }
 
    // a pointer to the root of the expression tree remains on the stack
    return s.topo;
}