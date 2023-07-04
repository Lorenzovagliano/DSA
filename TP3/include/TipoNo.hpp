#ifndef TIPONO_H
#define TIPONO_H

#include <iostream>
#include <iostream>
#include <string>
#include <sstream>


// Classe que implementa o No para a Lista Encadeada e para a Arvore de Huffman
class Node{
    public:
        char symbol;
        int frequencia;
        Node* ant;
        Node* prox;
        Node* esq;
        Node* dir;

        friend std::ostream& operator<< (std::ostream& stream, Node& node);

        Node();
        Node(char symbol, int frequencia);
        Node(char symbol, int frequencia, Node* prev, Node* prox);
        Node(int frequencia, Node* esq, Node* dir);
        Node(char symbol, int frequencia, Node* prev, Node* prox, Node* esq, Node* dir);

        ~Node();

        void setSymbol(char symbol);
        void setFrequencia(int frequencia);
        void setAnt(Node* prev);
        void setProx(Node* prox);
        void setEsq(Node* esq);
        void setDir(Node* dir);

        bool isFolha();
};

#endif
