#ifndef HUFF_H
#define HUFF_H

#include <iostream>
#include <string>

#include "list.hpp"

using namespace std;

class Huff{
    public:
        // Constructors.
        Huff();

        // Methods.
        void compress(std::string filename, std::string outputFileName);
        void expand(std::string filename, std::string outputFileName);  

        private:
        // Attributes.
        List* list;

        // Methods.
        string buildBytes(string bitflow);
        string* buildCode(Node* root);
        void buildCode(string* codes, Node* node, string code);
        List* buildList(string text);
        Node* buildTrie(List* list);
        string bytesToBitflow(string bytes);
        int find(string text, char charact);
        string getFileExtension(string filename, int dotPos);
        string read(string filename);
        string readFileExtension(string* text);
        int readSize(string* text);
        Node* readTrie(string* text);
        Node* readTrie(string text, int* index);
        string translate(string bitflow, int size, Node* root);
        string transform(Node* node, string trie);
        string transform(Node* node);
        string transform(string text, string* table);
        void write(string text, string filename);
        void write(string fileext, string trie, int size, string bitflow, string filename);
};

#endif
