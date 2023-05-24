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

    for(int i = 0; i < 50; i++){
        pilha.empilha(i);
    }

    for(int i = 20; i < 40; i++){
        pilha.desempilha();
    }

    std::cout << "Pilha após todas operações:\n";
    pilha.printPilha();
}