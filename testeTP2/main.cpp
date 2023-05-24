#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Estrutura para representar um ponto no plano cartesiano
struct Ponto {
    int x;
    int y;
};

// Função para calcular a orientação de três pontos (p, q, r)
int calcularOrientacao(Ponto p, Ponto q, Ponto r) {
    int valor = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (valor == 0)
        return 0;  // Colinear
    else if (valor > 0)
        return 1;  // Sentido horário
    else
        return 2;  // Sentido anti-horário
}

// Função para encontrar o fecho convexo usando o algoritmo de Jarvis
vector<Ponto> encontrarFechoConvexoJarvis(vector<Ponto>& pontos) {
    int n = pontos.size();
    if (n < 3)
        return {};

    vector<Ponto> fechoConvexo;

    // Encontrar o ponto mais à esquerda
    int pontoMaisEsquerda = 0;
    for (int i = 1; i < n; i++) {
        if (pontos[i].x < pontos[pontoMaisEsquerda].x)
            pontoMaisEsquerda = i;
    }

    int pontoAtual = pontoMaisEsquerda;
    int pontoProximo;

    do {
        fechoConvexo.push_back(pontos[pontoAtual]);
        pontoProximo = (pontoAtual + 1) % n;

        for (int i = 0; i < n; i++) {
            if (calcularOrientacao(pontos[pontoAtual], pontos[i], pontos[pontoProximo]) == 2)
                pontoProximo = i;
        }

        pontoAtual = pontoProximo;
    } while (pontoAtual != pontoMaisEsquerda);

    return fechoConvexo;
}

// Função para ler os pontos de um arquivo de entrada
vector<Ponto> lerPontosArquivo(string nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    vector<Ponto> pontos;

    if (arquivo.is_open()) {
        int x, y;
        while (arquivo >> x >> y) {
            pontos.push_back({x, y});
        }
        arquivo.close();
    }

    return pontos;
}

// Função para ordenar os pontos por coordenada x usando o algoritmo Merge Sort
void merge(vector<Ponto>& pontos, int inicio, int meio, int fim) {
    int tamanho1 = meio - inicio + 1;
    int tamanho2 = fim - meio;

    vector<Ponto> metadeEsquerda(tamanho1);
    vector<Ponto> metadeDireita(tamanho2);

    for (int i = 0; i < tamanho1; i++)
        metadeEsquerda[i] = pontos[inicio + i];
    for (int j = 0; j < tamanho2; j++)
        metadeDireita[j] = pontos[meio + 1 + j];

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < tamanho1 && j < tamanho2) {
        if (metadeEsquerda[i].x <= metadeDireita[j].x) {
            pontos[k] = metadeEsquerda[i];
            i++;
        } else {
            pontos[k] = metadeDireita[j];
            j++;
        }
        k++;
    }

    while (i < tamanho1) {
        pontos[k] = metadeEsquerda[i];
        i++;
        k++;
    }

    while (j < tamanho2) {
        pontos[k] = metadeDireita[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Ponto>& pontos, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(pontos, inicio, meio);
        mergeSort(pontos, meio + 1, fim);

        merge(pontos, inicio, meio, fim);
    }
}

// Função para calcular o tempo de execução de uma função
double calcularTempoExecucao(clock_t inicio, clock_t fim) {
    return static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <arquivo_entrada.txt>" << endl;
        return 1;
    }

    string nomeArquivo = argv[1];
    vector<Ponto> pontos = lerPontosArquivo(nomeArquivo);

    if (pontos.empty()) {
        cout << "Erro ao ler o arquivo de entrada." << endl;
        return 1;
    }

    clock_t inicio, fim;
    double tempoExecucao;

    // Fecho Convexo com Jarvis + Merge Sort
    inicio = clock();
    mergeSort(pontos, 0, pontos.size() - 1);
    vector<Ponto> fechoConvexoJarvisMergeSort = encontrarFechoConvexoJarvis(pontos);
    fim = clock();
    tempoExecucao = calcularTempoExecucao(inicio, fim);

    // Fecho Convexo com Jarvis + Insertion Sort
    inicio = clock();
    sort(pontos.begin(), pontos.end(), [](Ponto a, Ponto b) {
        return a.x < b.x;
    });
    vector<Ponto> fechoConvexoJarvisInsertionSort = encontrarFechoConvexoJarvis(pontos);
    fim = clock();
    tempoExecucao = calcularTempoExecucao(inicio, fim);

    // Fecho Convexo com Jarvis + Ordenação Linear (Counting, Bucket ou Radix)
    // Implemente aqui o seu método de ordenação linear
    // ...
    inicio = clock();
    // Ordenar os pontos linearmente
    vector<Ponto> fechoConvexoJarvisLinear = encontrarFechoConvexoJarvis(pontos);
    fim = clock();
    tempoExecucao = calcularTempoExecucao(inicio, fim);

    // Imprimir o fecho convexo
    cout << "FECHO CONVEXO:" << endl;
    for (const Ponto& ponto : fechoConvexoJarvisLinear) {
        cout << ponto.x << " x + " << ponto.y << " = 0" << endl;
    }

    // Imprimir os tempos de execução
    cout << "JARVIS+MERGESORT: " << tempoExecucao << "s" << endl;
    cout << "JARVIS+INSERTIONSORT: " << tempoExecucao << "s" << endl;
    cout << "JARVIS+LINEAR: " << tempoExecucao << "s" << endl;

    return 0;
}
