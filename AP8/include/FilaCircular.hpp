#ifndef PILHA_CIRCULAR_H
#define PILHA_CIRCULAR_H

#include <iostream>

#define SIZE 25

class FilaCircular{
    friend class Pilha;

    private:
        int id;
        int array[SIZE];

    public:
        int frente = -1;
        int tras = -1;
        
        FilaCircular();
        bool filaVazia();
        void enfila(int valor);
        void desenfila();
        int filaFrente();
        void printFila();
};

#endif