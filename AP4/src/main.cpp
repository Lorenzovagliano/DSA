#include "FilaCircular.hpp"
#include "Pilha.hpp"

int main(){
    Pilha pilha;

    bool isVazia = pilha.pilhaVazia();

    if(isVazia == true){
        std::cout << "A pilha está vazia\n";
    }
    else{
        std::cout << "A pilha não está vazia\n";
    }

    pilha.empilha(0);
    pilha.empilha(1);
    pilha.empilha(2);
    pilha.desempilha();

    pilha.empilha(3);
    pilha.empilha(4);
    pilha.empilha(5);
    pilha.desempilha();

    pilha.empilha(6);
    pilha.empilha(7);
    pilha.empilha(8);
    pilha.desempilha();

    pilha.empilha(9);

    isVazia = pilha.pilhaVazia();
    if(isVazia == true){
        std::cout << "A pilha está vazia\n";
    }
    else{
        std::cout << "A pilha não está vazia\n";
    }

    std::cout << "Pilha após todas operações:\n";
    pilha.printPilha();
}