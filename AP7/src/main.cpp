// C++ program for implementation of Heap Sort
 
#include <iostream>
#include <random>
#include <chrono>
using namespace std;
 
void heapify(int arr[], int N, int i){
    int largest = i;
 
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if(l < N && arr[l] > arr[largest]){
        largest = l;
    }
 
    if(r < N && arr[r] > arr[largest]){
        largest = r;
    }
 
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}
 
void heapSort(int arr[], int N){
    for(int i = N / 2 - 1; i >= 0; i--){
        heapify(arr, N, i);
    }

    for(int i = N - 1; i > 0; i--){
        swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
    }
}
  
int fibonacci[14] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377};

int shellSort(int arr[], int n){
    int k = 14;
    while(k > 0){
        for(int gap = 377; gap > 0; gap = fibonacci[k]){
            for(int i = gap; i < n; i += 1){
                int temp = arr[i];

                int j;            
                for(j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                    arr[j] = arr[j - gap];
                }
                    
                arr[j] = temp;
            }
            k--;
        }
    }
    return 0;
}

int* generateRandomArray(int size) {
    int* arr = new int[size];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100000);

    for(int i = 0; i < size; i++){
        arr[i] = dis(gen);
    }

    return arr;
}
 
// Driver's code
int main(){
    int* arrays[10];

    //Etapa 1
    int tamanhos1[10] = {377, 557, 737, 917, 1097, 1277, 1457, 1637, 1817, 2000};

    cout << "ShellSort Etapa 1: " << endl << endl;

    long double shellSortTime1 = 0;
    for(int i = 0; i < 10; i++){
        int times = 10 + 10*i;
        for(int j = 0; j < times; j++){
            arrays[i] = generateRandomArray(tamanhos1[i]);

            auto start = chrono::high_resolution_clock::now();

            shellSort(arrays[i], tamanhos1[i]);

            auto end = chrono::high_resolution_clock::now();

            double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            time_taken *= 1e-9;

            cout << "Tamanho: " << tamanhos1[i] << '\t' << "Tempo: " << time_taken << endl;
            shellSortTime1 += time_taken;
        }
    }

    cout << "HeapSort Etapa 1: " << endl << endl;

    long double heapSortTime1 = 0;
    for(int i = 0; i < 10; i++){
        int times = 10 + 10*i;
        for(int j = 0; j < times; j++){
            arrays[i] = generateRandomArray(tamanhos1[i]);

            auto start = chrono::high_resolution_clock::now();

            heapSort(arrays[i], tamanhos1[i]);

            auto end = chrono::high_resolution_clock::now();

            double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            time_taken *= 1e-9;

            cout << "Tamanho: " << tamanhos1[i] << '\t' << "Tempo: " << time_taken << endl;
            heapSortTime1 += time_taken;
        }
    }

    //Etapa 2
    cout << "Etapa 2: " << endl << endl;
    cout << "A prómixa etapa demora bastante para executar devido ao tamanho da entradas. ISSO NÃO É UM ERRO, aguarde: " << endl;
    int tamanhos2[10] = {37700, 55700, 73700, 91700, 109700, 127700, 145700, 163700, 181700, 200000};

    cout << "ShellSort Etapa 2: " << endl << endl;

    long double shellSortTime2 = 0;
    for(int i = 0; i < 10; i++){
        int times = 10 + 10*i;
        for(int j = 0; j < times; j++){
            arrays[i] = generateRandomArray(tamanhos2[i]);

            auto start = chrono::high_resolution_clock::now();

            shellSort(arrays[i], tamanhos2[i]);

            auto end = chrono::high_resolution_clock::now();

            double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            time_taken *= 1e-9;

            cout << "Tamanho: " << tamanhos2[i] << '\t' << "Tempo: " << time_taken << endl;
            shellSortTime2 += time_taken;
        }
    }

    cout << "HeapSort Etapa 2: " << endl << endl;

    long double heapSortTime2 = 0;
    for(int i = 0; i < 10; i++){
        int times = 10 + 10*i;
        for(int j = 0; j < times; j++){
            arrays[i] = generateRandomArray(tamanhos2[i]);

            auto start = chrono::high_resolution_clock::now();

            heapSort(arrays[i], tamanhos2[i]);

            auto end = chrono::high_resolution_clock::now();

            double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            time_taken *= 1e-9;

            cout << "Tamanho: " << tamanhos2[i] << '\t' << "Tempo: " << time_taken << endl;
            heapSortTime2 += time_taken;
        }
    }

    cout << "Etapa 1" << endl;
    cout << "Somatório Shell sort: " << shellSortTime1 << endl;
    cout << "Somatório Heap sort: " << heapSortTime1 << endl;

    cout << "Etapa 2" << endl;
    cout << "Somatório Shell sort: " << shellSortTime2 << endl;
    cout << "Somatório Heap sort: " << heapSortTime2 << endl;

    return 0;
}