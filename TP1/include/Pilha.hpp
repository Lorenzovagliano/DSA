#ifndef PILHA_H
#define PILHA_H

#include "TipoNo.hpp"

class Pilha{
    private:
        TipoNo* topo;
        int tamanho;

    public:
        Pilha();
        ~Pilha();

        bool Vazia();
        void Empilha(char item);
        char Desempilha();
        void Limpa();
};


#endif