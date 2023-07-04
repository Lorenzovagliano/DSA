#define ASCII 256
#define BYTE_SIZE 8

#include "Huffman.hpp"

Huffman::Huffman(){
    this->list = NULL;
}

/**
* Lê o conteúdo do arquivo especificado.
*
* @param filename O nome do arquivo.
* @return O conteúdo do arquivo como uma string.
*/
string Huffman::ler(string filename){
    ifstream source;
    source.open(filename.c_str());

    // Verifica se o arquivo foi aberto corretamente
    if(!source){
        cout << "Arquivo nao encontrado!\n";
        exit(-1);
    }

    // Verifica se o arquivo está aberto
    if(!source.is_open()){
        cout << "Nao foi possivel abrir o arquivo!\n";
        exit(-1);
    }

    char head;

    // Lê o conteúdo do arquivo e armazena em um buffer stringstream
    stringstream buffer;
    buffer << source.rdbuf();

    source.close();

    // Retorna o conteúdo do arquivo como uma string
    return buffer.str();
}

/**
* Cria uma lista encadeada com base no texto especificado.
*
* @param text O texto de origem.
* @return A lista encadeada criada.
*/
List* Huffman::criarLista(string text){
    List* list = new List();

    // Percorre o texto e adiciona cada caractere à lista
    for(int i = 0; i < text.size(); ++i){
        list->adicionar(text[i]);
    }

    return list;
}

/**
* Cria uma árvore de Huffman com base na lista especificada.
*
* @param list A lista encadeada.
* @return O nó raiz da árvore de Huffman.
*/
Node* Huffman::criarArvore(List *list){
    if(list == NULL){
        throw "Lista nula!";
    }

    if(list->tamanho == 0){
        throw "Lista vazia!";
    }

    // Constrói a árvore até que reste apenas um nó na lista
    while(list->tamanho > 1){
        Node* inicio = list->inicio;
        Node* segundo = list->inicio->prox;

        // Calcula a frequência do novo nó pai
        int frequencia = inicio->frequencia + segundo->frequencia;

        // Cria o novo nó pai com os nós iniciais como filhos
        Node* pai = new Node(frequencia, inicio, segundo);

        // Remove os nós iniciais da lista
        list->remover(inicio);
        list->remover(segundo);

        // Adiciona o novo nó pai à lista
        list->adicionar(pai);
    }

    return list->inicio;
}

/**
* Cria a tabela de códigos com base na árvore de Huffman.
*
* @param codes A tabela de códigos.
* @param node O nó atual da árvore.
* @param code O código atual em construção.
*/
void Huffman::criarCodificacao(string* codes, Node* node, string code){
    if(node->isFolha()){
        // Atribui o código à posição correspondente na tabela de códigos
        codes[node->symbol] = code;     
        return;
    }

    // Percorre a árvore recursivamente para a esquerda (0) e para a direita (1)
    this->criarCodificacao(codes, node->esq, code + '0');
    this->criarCodificacao(codes, node->dir, code + '1');
}

/**
* Cria a tabela de códigos com base na árvore de Huffman.
*
* @param raiz O nó raiz da árvore de Huffman.
* @return A tabela de códigos.
*/
string* Huffman::criarCodificacao(Node *raiz){
    // Cria um array de strings para armazenar os códigos de cada símbolo
    string* codes = new string[ASCII];

    // Chama a função auxiliar para preencher a tabela de códigos
    this->criarCodificacao(codes, raiz, "");

    return codes;
}

/**
* Converte a árvore de Huffman em uma string.
*
* @param node O nó raiz da árvore.
* @return A representação em string da árvore.
*/
string Huffman::arvoreParaString(Node* node){
    // Chama a função auxiliar para construir a string da árvore a partir do nó raiz
    return this->arvoreParaString(node, "");
}

/**
* Converte a árvore de Huffman em uma string.
*
* @param node O nó atual a ser processado.
* @param saida A string construída até o momento.
* @return A representação em string da árvore.
*/
string Huffman::arvoreParaString(Node* node, string saida){
    // Verifica se o nó é uma folha
    if(node->isFolha()){
        // Se for uma folha, adiciona '1' na string para indicar uma folha e concatena o símbolo
        saida += '1';
        saida += node->symbol;
        return saida;
    }

    // Se não for uma folha, adiciona '0' na string para indicar um nó interno
    saida += '0';

    // Chamada recursiva para processar os nós filhos esquerdo e direito
    saida = arvoreParaString(node->esq, saida);
    saida = arvoreParaString(node->dir, saida);

    return saida;
}

/**
* Escreve o texto em um arquivo.
*
* @param text O texto a ser salvo.
* @param filename O nome do arquivo de destino.
*/
void Huffman::write(string text, string filename){
    // Cria o arquivo de destino
    ofstream target;
    target.open(filename.c_str());

    // Escreve o texto no arquivo
    target << text;

    // Fecha o arquivo
    target.close();
}

/**
* Escreve a trie, o tamanho da string original e os bits em um arquivo.
*
* @param trie A trie convertida em formato de string.
* @param size O tamanho da string original.
* @param bits A sequência de bits construída.
* @param filename O nome do arquivo de destino.
*/
void Huffman::write(string trie, int size, string bits, string filename){
    string saida;

    // Adiciona a trie à saída
    saida += trie;

    // Salva o tamanho da string original
    stringstream ss;
    ss << size;
    saida += ss.str();

    // Salva os bits
    saida += criarBytes(bits);

    // Salva no arquivo
    this->write(saida, filename);
}

/**
* Comprime um arquivo usando o algoritmo de Huffman.
*
* @param filename O nome do arquivo a ser comprimido.
* @param outputFileName O nome do arquivo de saída onde o resultado da compressão será salvo.
*/
void Huffman::comprimir(string filename, string outputFileName){
    // Ler o conteúdo do arquivo
    string text = this->ler(filename);

    // Criar uma lista de nós para cada caractere do texto
    List* list = this->criarLista(text);

    // Criar a árvore de Huffman a partir da lista de nós
    Node* node = this->criarArvore(list);

    // Criar a tabela de codificação a partir da árvore de Huffman
    string* codes = this->criarCodificacao(node);

    // Converter a árvore de Huffman em uma string
    string trie = this->arvoreParaString(node);

    // Converter o texto original em uma sequência de bits usando a tabela de codificação
    string bits = this->arvoreParaString(text, codes);

    // Salvar a árvore, o tamanho original do texto e os bits comprimidos no arquivo de saída
    this->write(trie, text.size(), bits, outputFileName);
}

/**
* Cria uma sequência de bytes a partir de uma sequência de bits.
*
* @param bits A sequência de bits.
* @return Uma string representando os bytes criados.
*/
string Huffman::criarBytes(string bits){
    unsigned char byte = 0;
    unsigned int currbit = 0;
    std::string saida = "";

    while(currbit < bits.size()){
        for(int i = 0; i < BYTE_SIZE; ){
            if(bits[currbit] == '1'){
                byte = byte << 1; // Desloca um bit para a esquerda
                byte = byte | 1; // Define o bit menos significativo como 1
            }
            else if(bits[currbit] == '0'){
                byte = byte << 1; // Desloca um bit para a esquerda
            }

            ++currbit;
            ++i;

            // Verifica se atingiu o final da sequência de bits
            if(currbit >= bits.size()){
                int remaind = 8 - i; // Calcula quantos bits faltam para completar o byte

                // Completa o byte com zeros à direita para formar um byte completo
                for(int j = 0; j < remaind; ++j){
                    byte = byte << 1; // Desloca um bit para a esquerda
                }

                break;
            }
        }

        saida += byte; // Adiciona o byte resultante à string de saída
        byte = 0; // Reseta a variável byte para o próximo byte
    }

    return saida;
}

/**
* Lê uma árvore Huffman a partir de uma string e um índice de leitura.
*
* @param text A string contendo a representação da árvore Huffman.
* @param index O ponteiro para o índice de leitura na string.
* @return O ponteiro para o nó raiz da árvore lida.
*/
Node* Huffman::lerArvore(string text, int* index){
    (*index)++; // Incrementa o índice antes de cada leitura para avançar na string

    // Se o caractere atual for '1', indica que é um nó folha
    if(text[*index] == '1'){
        (*index)++;
        char symbol = text[*index];

        // Cria um novo nó folha e o retorna
        return new Node(symbol, 0, NULL, NULL, NULL, NULL);
    }

    // Se o caractere atual não for '1', indica que é um nó intermediário
    return new Node('\0', 0, NULL, NULL, lerArvore(text, index), lerArvore(text, index));
}

/**
* Lê uma árvore Huffman a partir de uma string.
*
* @param text A string contendo a representação da árvore Huffman.
* @return O ponteiro para o nó raiz da árvore lida.
*/
Node* Huffman::lerArvore(string* text){
    int index = -1;
    Node* node = this->lerArvore(*text, &index);
    index++;
    (*text).replace(0, index, "");
    return node;
}

/**
* Lê o tamanho da string original a partir de uma string e atualiza a string removendo o tamanho lido.
*
* @param text A string contendo o tamanho seguido dos dados.
* @return O tamanho da string original.
*/
int Huffman::lerTamanho(string* text){
    stringstream ss(*text);
    int size;

    ss >> size;
    ss.str("");
    ss.clear();

    ss << size;
    int index = ss.str().size();

    (*text) = (*text).replace(0, index, "");

    return size;
}

/**
* Converte uma string de texto em uma representação codificada usando uma tabela de codificação.
*
* @param text A string de texto a ser convertida.
* @param table O ponteiro para a tabela de codificação.
* @return A representação codificada da string de texto.
*/
string Huffman::arvoreParaString(string text, string* table){
    string saida = "";

    for(int i = 0; i < text.size(); ++i){
        saida += table[text[i]];
    }

    return saida;
}

/**
* Converte uma sequência de bytes em uma representação binária de bits.
*
* @param bytes A sequência de bytes a ser convertida.
* @return A representação binária em bits da sequência de bytes.
*/
string Huffman::bytesParaBits(string bytes){
    string bits = "";

    for(int i = 0; i < bytes.size(); ++i){
        for(int j = 0; j < BYTE_SIZE; ++j){
            // Verifica o bit mais significativo do byte
            if((bytes[i] & 256) == 256){
                bits += '1'; // Adiciona '1' se o bit for 1
                
            }
            else{
                bits += '0';
            }

            bytes[i] = bytes[i] << 1; // Desloca os bits para a esquerda
        }
    }

    return bits;
}

/**
* Traduz uma sequência de bits de volta para o texto original usando a árvore de Huffman.
*
* @param bits A sequência de bits a ser traduzida.
* @param size O tamanho original do texto antes da compactação.
* @param raiz A raiz da árvore de Huffman.
* @return O texto original traduzido.
*/
string Huffman::traduzir(string bits, int size, Node* raiz){
    int bit = 0;
    string text = "";

    for(int i = 0; i < size; ++i){
        Node* node = raiz;

        while(!node->isFolha()){
            if(bits[bit] == '1'){
                node = node->dir; // Se o bit for '1', move-se para o nó da direita
                
            }
            else{
                node = node->esq; // Se o bit for '0', move-se para o nó da esquerda
            }

            ++bit; 
        }
        
        // Adiciona o símbolo do nó folha ao texto
        text += node->symbol;
    }

    return text;
}

/**
* Descomprime um arquivo usando o algoritmo de Huffman.
*
* @param filename O nome do arquivo comprimido a ser descomprimido.
* @param outputFileName O nome do arquivo de saída onde o texto descomprimido será salvo.
*/
void Huffman::descomprimir(string filename, string outputFileName){
    // Ler o conteúdo do arquivo comprimido
    string text = this->ler(filename);

    // Reconstruir a árvore de Huffman a partir do texto
    Node* raiz = this->lerArvore(&text);

    // Obter o tamanho original do texto antes da compactação
    int size = this->lerTamanho(&text);

    // Converter os bytes comprimidos de volta para a sequência de bits original
    string bits = this->bytesParaBits(text);

    // Traduzir a sequência de bits de volta para o texto original usando a árvore de Huffman
    string translated = this->traduzir(bits, size, raiz);

    // Salvar o texto descomprimido no arquivo de saída
    this->write(translated, outputFileName);
}