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
        node->setNext(this->first);
        this->first->setPrev(node);
        this->first = node;
        this->length++;
        this->sort(node);
    }
}

void List::remove(Node* node){
    if(this->length == 0){
        return;
    }

    for(Node* aux = this->first; aux != NULL; aux = aux->next){
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
                this->first = this->first->next;
                this->first->setPrev(NULL);
                node = NULL;
                this->length--;
                break;
            }

            // Remove último.
            if(node == this->last){
                this->last = this->last->prev;
                this->last->setNext(NULL);
                node = NULL;
                this->length--;
                break;
            }

            // Remove no meio
            node->prev->setNext(node->next);
            node->next->setPrev(node->prev);
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
    for(Node* aux = this->first; aux != NULL; aux = aux->next){
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

    if(other->prev != NULL){
        beforeOther = other->prev;
    }

    if(other->next != NULL){
        afterOther = other->next;
    }

    if(node->prev != NULL){
        beforeNode = node->prev;
    }

    if(node->next != NULL){
        afterNode = node->next;
    }

    node->setNext(NULL);
    node->setPrev(NULL);
    other->setNext(NULL);
    other->setPrev(NULL);

    if(beforeOther != NULL){
        if(beforeOther != node){
            node->setPrev(beforeOther);
            beforeOther->setNext(node);
        }
        else{
            node->setPrev(other);
            other->setNext(node);
        }
    }

    if(afterOther != NULL){
        node->setNext(afterOther);
        afterOther->setPrev(node);
    }
    
    if(beforeNode != NULL){
        other->setPrev(beforeNode);
        beforeNode->setNext(other);
    }

    if(afterNode != NULL){
        if(afterNode != other){
            other->setNext(afterNode);
            afterNode->setPrev(other);
        }
        else{
            other->setNext(node);
            node->setPrev(other);
        }
    }
}

void List::sort(Node* node){
    bool needShift = false;
    Node* aux = node;

    if(aux->next != NULL){
        while (node->frequency > aux->next->frequency){
            needShift = true;
            
            aux = aux->next;

            if(aux->next == NULL){
                break;
            }
        }

        if(needShift){
            this->shift(node, aux);
        }
    }
}
