#include "TipoNo.hpp"
#include "Pilha.hpp"
#include "ArvoreBinaria.hpp"
#include <string>
#include <iostream>

int main(){
    std::string postfix = "ab+cde+**";
    ArvoreBinaria arvore;
    TipoNo* raiz = new TipoNo();
    raiz = arvore.construir(postfix);
    std::cout << "oi3\n";
 
    std::cout << "Postfix Expression: ";
    arvore.postorder(raiz);
 
    std::cout << "\nInfix Expression: ";
    arvore.inorder(raiz);

    delete raiz;
    return 0;
}