#include "Pilha.hpp"
#include "memlog.h"

int idPilha = 0;

Pilha::Pilha(){
    this->id = idPilha;
    ESCREVEMEMLOG((long int) (&(this->fila1)), sizeof(double), this->id);
    idPilha++;
}

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
    ESCREVEMEMLOG((long int) (&(this->fila2.array[fila2.filaFrente()])), sizeof(double), this->fila2.id);
    
    while(this->fila1.filaVazia() == false){
        LEMEMLOG((long int) (&(this->fila1.array[fila1.filaFrente()])), sizeof(double), this->fila1.id);
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
        LEMEMLOG((long int) (&(this->fila1.array[fila1.filaFrente()])), sizeof(double), this->fila1.id);
        ESCREVEMEMLOG((long int) (&(this->fila1.array[fila1.filaFrente()])), sizeof(double), this->fila1.id);
    }

    std::cout << "Desempilhando\n";
}

void Pilha::printPilha(){
    FilaCircular filaAuxiliar = this->fila1;
    
    while(filaAuxiliar.filaVazia() == false){
        std::cout << filaAuxiliar.filaFrente() << " ";
        LEMEMLOG((long int) (&(filaAuxiliar.array[filaAuxiliar.filaFrente()])), sizeof(double), filaAuxiliar.id);
        ESCREVEMEMLOG((long int) (&(filaAuxiliar.array[filaAuxiliar.filaFrente()])), sizeof(double), filaAuxiliar.id);
        filaAuxiliar.desenfila();
    }
    std::cout << "\n";
}