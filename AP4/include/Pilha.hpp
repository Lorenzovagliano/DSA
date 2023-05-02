#ifndef PILHA_H
#define PILHA_H

#include "FilaCircular.hpp"

class Pilha{
    private:
        FilaCircular fila1;
        FilaCircular fila2;

    public:
        bool pilhaVazia();
        void empilha(int valor);
        void desempilha();
        void printPilha();
};


#endif