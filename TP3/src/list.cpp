#include <iostream>
#include "list.hpp"

// Constructors.

List::List(){
    this->first = NULL;
    this->last = NULL;
    this->length = 0;
}

// Methods.

void List::add(char symbol){
    Node* node = this->getNode(symbol);

    if(node != NULL){
        node->setFrequency(node->frequency + 1);
        this->sort(node);
    }
    else{
        node = new Node(symbol, 1);
        this->add(node);
    }
}

void List::add(Node* node){
    if(this->isEmpty()){
        this->first = node;
        this->last = node;
        this->length = 1;
    }
    else{
        node->setProx(this->first);
        this->first->setAnt(node);
        this->first = node;
        this->length++;
        this->sort(node);
    }
}

void List::remove(Node* node){
    if(this->length == 0){
        return;
    }

    for(Node* aux = this->first; aux != NULL; aux = aux->prox){
        if(node == aux){
            // Remove o único.
            if(this->length == 1){
                this->first = NULL;
                this->last = NULL;
                this->length--;
                node = NULL;
                break;
            }

            // Remove primeiro.
            if(node == this->first){
                this->first = this->first->prox;
                this->first->setAnt(NULL);
                node = NULL;
                this->length--;
                break;
            }

            // Remove último.
            if(node == this->last){
                this->last = this->last->ant;
                this->last->setProx(NULL);
                node = NULL;
                this->length--;
                break;
            }

            // Remove no meio
            node->ant->setProx(node->prox);
            node->prox->setAnt(node->ant);
            node = NULL;
            this->length--;
            break;
        }
    }
}

bool List::isEmpty(){
    return this->first == NULL && this->last == NULL;
}

Node* List::getNode(char symbol){
    for(Node* aux = this->first; aux != NULL; aux = aux->prox){
        if(aux->symbol == symbol){
            
            return aux;
        }
    }

    return NULL;
}

void List::shift(Node* node, Node* other){
    Node* beforeNode = NULL;
    Node* afterNode = NULL;
    Node* beforeOther = NULL;
    Node* afterOther = NULL;

    if(this->first == node){
        this->first = other;
    }

    if(this->last == other){
        this->last = node;
    }

    if(other->ant != NULL){
        beforeOther = other->ant;
    }

    if(other->prox != NULL){
        afterOther = other->prox;
    }

    if(node->ant != NULL){
        beforeNode = node->ant;
    }

    if(node->prox != NULL){
        afterNode = node->prox;
    }

    node->setProx(NULL);
    node->setAnt(NULL);
    other->setProx(NULL);
    other->setAnt(NULL);

    if(beforeOther != NULL){
        if(beforeOther != node){
            node->setAnt(beforeOther);
            beforeOther->setProx(node);
        }
        else{
            node->setAnt(other);
            other->setProx(node);
        }
    }

    if(afterOther != NULL){
        node->setProx(afterOther);
        afterOther->setAnt(node);
    }
    
    if(beforeNode != NULL){
        other->setAnt(beforeNode);
        beforeNode->setProx(other);
    }

    if(afterNode != NULL){
        if(afterNode != other){
            other->setProx(afterNode);
            afterNode->setAnt(other);
        }
        else{
            other->setProx(node);
            node->setAnt(other);
        }
    }
}

void List::sort(Node* node){
    bool needShift = false;
    Node* aux = node;

    if(aux->prox != NULL){
        while (node->frequency > aux->prox->frequency){
            needShift = true;
            
            aux = aux->prox;

            if(aux->prox == NULL){
                break;
            }
        }

        if(needShift){
            this->shift(node, aux);
        }
    }
}
