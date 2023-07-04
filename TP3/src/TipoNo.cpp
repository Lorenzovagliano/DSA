#include "TipoNo.hpp"

/**
 * Sobrecarga do operador de inserção em fluxo de saída para imprimir um nó.
 * @param stream O fluxo de saída.
 * @param node O nó a ser impresso.
 * @return O fluxo de saída atualizado.
 */
std::ostream& operator<< (std::ostream& stream, Node& node){
    std::stringstream ss;
    ss << node.frequencia;

    std::string text = "(";
    text += node.symbol;
    text += ",";
    text += ss.str();
    text += ")";

    return stream << text;
}

Node::Node(){
    this->symbol = '\0';
    this->frequencia = 0;
    this->esq = NULL;
    this->dir = NULL;
}

Node::Node(char symbol, int frequencia){
    this->symbol = symbol;
    this->frequencia = frequencia;
    this->ant = NULL;
    this->prox = NULL;
    this->esq = NULL;
    this->dir = NULL;
}

Node::Node(char symbol, int frequencia, Node* ant, Node* prox){
    this->symbol = symbol;
    this->frequencia = frequencia;
    this->ant = ant;
    this->prox = prox;
    this->esq = NULL;
    this->dir = NULL;
}

Node::Node(int frequencia, Node* esq, Node* dir){
    this->symbol = '\0';
    this->frequencia = frequencia;
    this->ant = NULL;
    this->prox = NULL;
    this->esq = esq;
    this->dir = dir;
}

Node::Node(char symbol, int frequencia, Node* ant, Node* prox, Node* esq, Node* dir){
    this->symbol = symbol;
    this->frequencia = frequencia;
    this->ant = ant;
    this->prox = prox;
    this->esq = esq;
    this->dir = dir;
}

void Node::setSymbol(char symbol){
    this->symbol = symbol;
}

void Node::setFrequencia(int frequencia){
    this->frequencia = frequencia;
}

void Node::setAnt(Node* ant){
    this->ant = ant;
}

void Node::setProx(Node* prox){
    this->prox = prox;
}

void Node::setEsq(Node* esq){
    this->esq = esq;
}

void Node::setDir(Node* dir){
    this->dir = dir;
}

bool Node::isFolha(){
    return this->esq == NULL && this->dir == NULL;
}
