#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

#include <iostream>

#include "TipoNo.hpp"

// Classe que implementa uma Lista Encadeada que serve como Fila de Prioridade
class List{
    public:
        Node* inicio;
        Node* fim;
        int tamanho;

        List();
        ~List();

        Node* getNode(char symbol);

        void adicionar(char symbol);
        void adicionar(Node* node);
        void remover(Node* node);
        bool isVazia();
        void shift(Node* node, Node* other);
        void sort(Node* node);
};

#endif