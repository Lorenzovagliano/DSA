#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>

#include "ListaDinamica.hpp"

using namespace std;

// Classe que agrega as funções referentes ao algoritmo de Huffman
class Huffman{
    public:
        Huffman();

        void comprimir(std::string filename, std::string outputFileName);
        void descomprimir(std::string filename, std::string outputFileName);  

        private:
            List* list;

            // Compressao
            string ler(string filename);
            List* criarLista(string text);
            Node* criarArvore(List* list);
            string* criarCodificacao(Node* root);
            string arvoreParaString(Node* node, string trie);
            string arvoreParaString(Node* node);
            void write(string text, string filename);
            void write(string trie, int size, string bitflow, string filename);

            // Descompressao
            Node* lerArvore(string* text);
            Node* lerArvore(string text, int* index);
            int lerTamanho(string* text);
            string bytesParaBits(string bytes);
            string traduzir(string bitflow, int size, Node* root);
            string criarBytes(string bitflow);
            void criarCodificacao(string* codes, Node* node, string code);
            string arvoreParaString(string text, string* table);
};

#endif
