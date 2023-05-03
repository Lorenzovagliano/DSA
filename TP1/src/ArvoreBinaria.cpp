#include "ArvoreBinaria.hpp"

ArvoreBinaria::ArvoreBinaria(){
    this->raiz = nullptr;
}

ArvoreBinaria::~ArvoreBinaria(){
    Limpa();
}

void ArvoreBinaria::Insere(char item){
    if(this->raiz == nullptr){
        this->raiz = new Pilha();
    }
}