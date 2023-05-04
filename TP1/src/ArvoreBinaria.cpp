#include "ArvoreBinaria.hpp"

ArvoreBinaria::ArvoreBinaria(){
    this->raiz = nullptr;
}

ArvoreBinaria::~ArvoreBinaria(){
    Limpa();
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
            TipoNo* x = s.topo;
            s.Desempilha();
 
            TipoNo* y = s.topo;
            s.Desempilha();
 
            // construct a new binary tree whose root is the operator and whose
            // left and right children point to `y` and `x`, respectively
            ArvoreBinaria* arvore = new ArvoreBinaria();
            arvore->raiz->item = c;
            arvore->raiz->esq = y;
            arvore->raiz->dir = x;
            TipoNo* node = new TipoNo(c, y, x);
 
            // push the current node into the stack
            s.push(arvore->raiz);
        }
 
        // if the current token is an operand, create a new binary tree node
        // whose root is the operand and push it into the stack
        else {
            s.push(new Node(c));
        }
    }
 
    // a pointer to the root of the expression tree remains on the stack
    return s.top();
}