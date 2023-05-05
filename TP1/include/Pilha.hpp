#ifndef PILHA_H
#define PILHA_H

#include "TipoNo.hpp"

class Pilha{
    friend class ArvoreBinaria;
    
    private:
        int tamanho;

    public:
        Pilha();
        ~Pilha();

        TipoNo* topo;
        bool Vazia();
        void Empilha(TipoNo* celula);
        TipoNo* Desempilha();
        void Limpa();
};


#endif