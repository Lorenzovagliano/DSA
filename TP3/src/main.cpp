#include <iostream>
#include <fstream>
#include <string.h>

#include "node.hpp"
#include "list.hpp"
#include "huff.hpp"

void erroUso(){
    std::cout << "\n\tERRO DE USO, utilize o formato de execução correto: ";
    std::cout << "\n\n\t\tCompactação: ./Huff -c <nome do arquivo a ser compactado> <nome do arquivo de destino>";
    std::cout << "\n\t\tDescompactação: ./Huff -d <nome do arquivo a ser descompactado> <nome do arquivo de destino>";
    std::cout << "\n\n\t\tExemplo: ./Huff -c texto.txt compacto.z";
    std::cout << "\n\t\tExemplo: ./Huff -c compacto.z descompacto.txt\n\n";
}

int main(int argc, char* argv[]){
    if(argc == 1){
        erroUso();
        return 0;
    }

    for(int i = 0; i < argc; i++){
        Huff* huff = new Huff();

        if(strcmp(argv[i], "-c") == 0){
            if((i + 1) < argc){
                string filename = (string)argv[i + 1];
                string outputFilename = (string)argv[i + 2];
                huff->compress(filename, outputFilename);
            }
            else{
                erroUso();
            }
        }
        else if(strcmp(argv[i], "-d") == 0){
            if((i + 1) < argc){
                string filename = (string)argv[i + 1];
                string outputFilename = (string)argv[i + 2];
                huff->expand(filename, outputFilename);
            }
            else{
                erroUso();
            }
        }
    }
}
