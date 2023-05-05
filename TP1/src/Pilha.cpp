#include "Pilha.hpp"

Pilha::Pilha(){
    this->topo = nullptr;
}

Pilha::~Pilha(){
    Limpa();
}

void Pilha::Empilha(TipoNo* celula){
    TipoNo *nova = celula;

    nova->prox = topo;
    this->topo = nova;
    this->tamanho++;
};

TipoNo* Pilha::Desempilha(){
    TipoNo* aux; TipoNo *p;

    if(this->tamanho == 0){
        throw "A pilha está vazia!";
    }

    aux = this->topo;
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