#ifndef TIPONO_H
#define TIPONO_H

#include "TipoItem.hpp"

class TipoNo{
    friend class ArvoreBinaria;

    private:
        char item;
        TipoNo *esq;
        TipoNo *dir;

    public:
        TipoNo();
};


#endif