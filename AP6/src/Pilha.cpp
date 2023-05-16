#include "Pilha.hpp"

bool Pilha::pilhaVazia(){
    if(this->fila1.frente == -1 && this->fila1.tras == -1){
        return true;
    }
    else{
        return false;
    }
}

void Pilha::empilha(int valor){    
    this->fila2.enfila(valor);
    
    while(this->fila1.filaVazia() == false){
        this->fila2.enfila(this->fila1.filaFrente());
        this->fila1.desenfila();
    }
    
    FilaCircular filaAuxiliar = this->fila1;
    this->fila1 = this->fila2;
    this->fila2 = filaAuxiliar;

    std::cout << valor << " Empilhado\n";
}

void Pilha::desempilha(){
    if(this->fila1.filaVazia() == true){
        return;
    } 
    else{
        this->fila1.desenfila();
    }

    std::cout << "Desempilhando\n";
}

void Pilha::printPilha(){
    FilaCircular filaAuxiliar = this->fila1;
    
    while(filaAuxiliar.filaVazia() == false){
        std::cout << filaAuxiliar.filaFrente() << " ";
        filaAuxiliar.desenfila();
    }
    std::cout << "\n";
}