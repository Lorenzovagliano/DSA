#ifndef TIPONO_H
#define TIPONO_H

class TipoNo{
    friend class ArvoreBinaria;
    friend class Pilha;

    private:
        char item;
        TipoNo *prox;
        TipoNo *esq;
        TipoNo *dir;

    public:
        TipoNo();
};


#endif