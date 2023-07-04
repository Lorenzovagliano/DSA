#include <iostream>
#include <fstream>
#include <string.h>

#include "TipoNo.hpp"
#include "ListaDinamica.hpp"
#include "Huffman.hpp"

void erroUso(){
    std::cout << "\n\tERRO DE USO, utilize o formato de execução correto: ";
    std::cout << "\n\n\t\tCompactação: ./Huffman -c <nome do arquivo a ser compactado> <nome do arquivo de destino>";
    std::cout << "\n\t\tDescompactação: ./Huffman -d <nome do arquivo a ser descompactado> <nome do arquivo de destino>";
    std::cout << "\n\n\t\tExemplo: ./Huffman -c texto.txt compacto.z";
    std::cout << "\n\t\tExemplo: ./Huffman -d compacto.z descompactado.txt\n\n";
}

int main(int argc, char* argv[]){
    if(argc == 1){
        erroUso();
        return 0;
    }

    for(int i = 0; i < argc; i++){
        Huffman* huff = new Huffman();

        if(strcmp(argv[i], "-c") == 0){
            if((i + 1) < argc){
                string filename = (string)argv[i + 1];
                string outputFilename = (string)argv[i + 2];
                huff->comprimir(filename, outputFilename);

                std::cout << "Arquivo comprimido\n";
            }
            else{
                erroUso();
            }
        }
        else if(strcmp(argv[i], "-d") == 0){
            if((i + 1) < argc){
                string filename = (string)argv[i + 1];
                string outputFilename = (string)argv[i + 2];
                huff->descomprimir(filename, outputFilename);

                std::cout << "Arquivo descomprimido\n";
            }
            else{
                erroUso();
            }
        }
    }
}
