#include "ListaDinamica.hpp"

List::List(){
    this->inicio = NULL;
    this->fim = NULL;
    this->tamanho = 0;
}

/**
* Retorna o nó correspondente ao símbolo especificado na lista.
* @param symbol O símbolo do nó a ser buscado.
* @return Um ponteiro para o nó encontrado ou NULL se o nó não estiver presente na lista.
*/
Node* List::getNode(char symbol){
    for(Node* aux = this->inicio; aux != NULL; aux = aux->prox){
        if(aux->symbol == symbol){
            
            return aux;
        }
    }

    return NULL;
}

/**
* Adiciona um novo símbolo à lista ou incrementa a frequência caso o símbolo já esteja presente.
* @param symbol O símbolo a ser adicionado ou cuja frequência será incrementada.
*/
void List::adicionar(char symbol){
    Node* node = this->getNode(symbol);

    if(node != NULL){
        // Se o nó já existe na lista, incrementa a frequência e reordena a lista.
        node->setFrequencia(node->frequencia + 1);
        this->sort(node);
    }
    else{
        // Se o nó ainda não existe na lista, cria um novo nó com frequência 1 e adiciona-o à lista.
        node = new Node(symbol, 1);
        this->adicionar(node);
    }
}

/**
* Adiciona um nó à lista.
* @param node O nó a ser adicionado à lista.
*/
void List::adicionar(Node* node){
    // Se a lista está vazia, define o nó como início e fim da lista.
    if(this->isVazia()){
        this->inicio = node;
        this->fim = node;
        this->tamanho = 1;
    }
    // Se a lista não está vazia, insere o nó no início da lista.
    else{
        node->setProx(this->inicio);
        this->inicio->setAnt(node);
        this->inicio = node;
        this->tamanho++;
        this->sort(node);
    }
}

/**
* Remove um nó da lista.
* @param node O nó a ser removido da lista.
*/
void List::remover(Node* node){
    // Se a lista está vazia, não há nada para remover.
    if(this->tamanho == 0){
        return;
    }

    for(Node* aux = this->inicio; aux != NULL; aux = aux->prox){
        if(node == aux){
            // Se a lista possui apenas um nó, remove o nó e atualiza os ponteiros da lista.
            if(this->tamanho == 1){
                this->inicio = NULL;
                this->fim = NULL;
                this->tamanho--;
                node = NULL;
                break;
            }

            // Se o nó é o primeiro da lista, atualiza o início da lista.
            if(node == this->inicio){
                this->inicio = this->inicio->prox;
                this->inicio->setAnt(NULL);
                node = NULL;
                this->tamanho--;
                break;
            }

            // Se o nó é o último da lista, atualiza o fim da lista.
            if(node == this->fim){
                this->fim = this->fim->ant;
                this->fim->setProx(NULL);
                node = NULL;
                this->tamanho--;
                break;
            }

            // Se o nó está no meio da lista, atualiza os ponteiros dos nós vizinhos.
            node->ant->setProx(node->prox);
            node->prox->setAnt(node->ant);
            node = NULL;
            this->tamanho--;
            break;
        }
    }
}

/**
* Verifica se a lista está vazia.
* @return true se a lista está vazia, false caso contrário.
*/
bool List::isVazia(){
    return this->inicio == NULL && this->fim == NULL;
}

/**
 * Troca a posição de dois nós na lista.
 * @param node Um dos nós a serem trocados de posição.
 * @param other O outro nó a ser trocado de posição.
 */
void List::shift(Node* node, Node* other){
    Node* beforeNode = NULL;
    Node* afterNode = NULL;
    Node* beforeOther = NULL;
    Node* afterOther = NULL;

    // Atualiza o início e o fim da lista, se necessário.
    if(this->inicio == node){
        this->inicio = other;
    }

    if(this->fim == other){
        this->fim = node;
    }

    // Verifica os nós adjacentes a "node".
    if(other->ant != NULL){
        beforeOther = other->ant;
    }

    if(other->prox != NULL){
        afterOther = other->prox;
    }

    // Verifica os nós adjacentes a "other".
    if(node->ant != NULL){
        beforeNode = node->ant;
    }

    if(node->prox != NULL){
        afterNode = node->prox;
    }

    // Desconecta os nós de suas posições originais.
    node->setProx(NULL);
    node->setAnt(NULL);
    other->setProx(NULL);
    other->setAnt(NULL);

    // Reorganiza os ponteiros para que "node" assuma a posição de "other".
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
    
    // Reorganiza os ponteiros para que "other" assuma a posição de "node".
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

/**
 * Ordena a lista com base na frequência dos nós.
 * @param node O nó a ser inserido na posição correta.
 */
void List::sort(Node* node){
    bool needShift = false;
    Node* aux = node;

    if(aux->prox != NULL){
        while (node->frequencia > aux->prox->frequencia){
            needShift = true;
            
            aux = aux->prox;

            if(aux->prox == NULL){
                break;
            }
        }

        // Se for necessário, realiza o deslocamento do nó para a posição correta.
        if(needShift){
            this->shift(node, aux);
        }
    }
}
