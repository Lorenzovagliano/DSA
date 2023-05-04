#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include "TipoNo.hpp"
#include "Pilha.hpp"
#include <string>

class ArvoreBinaria{
    private:
        TipoNo *raiz;
        Pilha pilha;
        
        void InsereRecursivo(TipoNo* &p, char item);
        void ApagaRecursivo(TipoNo* p);
        void PorNivel();
        void PreOrdem(TipoNo* p);
        void InOrdem(TipoNo* p);
        void PosOrdem(TipoNo* p);

    public:
        ArvoreBinaria();
        ~ArvoreBinaria();

        TipoNo* construir(std::string posfixa);
        void Insere(char item);
        void Caminha(int tipo);
        void Limpa();
};

#endif