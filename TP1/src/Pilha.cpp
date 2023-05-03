#include "Pilha.hpp"

Pilha::Pilha(){
    this->topo = nullptr;
}

Pilha::~Pilha(){
    Limpa();
}

void Pilha::Empilha(char item){
    TipoNo *nova;

    nova = new TipoNo();
    nova->item = item;
    nova->prox = topo;
    this->topo = nova;
    this->tamanho++;
};

char Pilha::Desempilha(){
    char aux; TipoNo *p;

    if(this->tamanho == 0){
        throw "A pilha está vazia!";
    }

    aux = this->topo->item;
    p = this->topo;
    this->topo = this->topo->prox;
    delete p;
    this->tamanho--;

    return aux;
};

void Pilha::Limpa(){
    while(this->tamanho != 0){
        Desempilha();
    }
}