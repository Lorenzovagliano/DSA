#include "FilaCircular.hpp"

bool FilaCircular::filaVazia(){
    if(this->frente == -1 && this->tras == -1){
        return true;
    }
    else{
        return false;
    }
}

void FilaCircular::enfila(int valor){
    if((this->tras + 1)%SIZE == this->frente){
        std::cout<<"Fila cheia \n";
    }
    else{
        if(this->frente == -1){
            this->frente = 0;
        }
        this->tras = (this->tras+1)%SIZE;
        this->array[this->tras] = valor;
    }
}

void FilaCircular::desenfila(){
    if(this->filaVazia() == true){
        std::cout<<"Fila vazia \n";
    }
    else{
        if(this->frente == this->tras){
            this->frente = this->tras = -1;
        }
        else{
            this->frente = (this->frente + 1)%SIZE;
        }
    }
}

int FilaCircular::filaFrente(){
    if(this->filaVazia() == true){
        throw std::out_of_range("Fila vazia, não há elemento na frente\n");
    }
    else{
        return this->array[this->frente];
    }
}

void FilaCircular::printFila(){
    if(this->filaVazia())
        std::cout<<"Fila vazia\n";
    else{
        int i;
        if(this->frente <= this->tras){
            for(int i = this->frente; i <= this->tras; i++){
                std::cout << this->array[i] << " ";
            }
        }
        else{
            i = this->frente;
            while(i < SIZE){
                std::cout << this->array[i] << " ";
                i++;
            }
            i = 0;
            while(i <= this->tras){
                std::cout << this->array[i] << " ";
                i++;
            }
        }
    }
}