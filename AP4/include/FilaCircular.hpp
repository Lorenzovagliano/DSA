#ifndef PILHA_CIRCULAR_H
#define PILHA_CIRCULAR_H

#include <iostream>

#define SIZE 10

class FilaCircular{
    private:
        int array[SIZE];

    public:
        int frente = -1;
        int tras = -1;
        
        bool filaVazia();
        void enfila(int valor);
        void desenfila();
        int filaFrente();
        void printFila();
};

#endif