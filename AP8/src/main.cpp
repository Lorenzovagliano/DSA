#include "FilaCircular.hpp"
#include "Pilha.hpp"
#include "memlog.h"

char lognome[1000];

int main(){
    lognome[0] = 'l';
    lognome[1] = 'o';
    lognome[2] = 'g';

    iniciaMemLog(lognome);
    ativaMemLog();

    defineFaseMemLog(0);
    Pilha pilha, pilha2;

    defineFaseMemLog(1);
    for(int i = 0; i < 25; i++){
        pilha.empilha(i);
    }

    defineFaseMemLog(2);
    for(int i = 0; i < 13; i++){
        pilha.desempilha();
    }

    std::cout << "Pilha após todas operações:\n";
    defineFaseMemLog(3);
    pilha.printPilha();

    desativaMemLog();
    finalizaMemLog();

    return 0;
}