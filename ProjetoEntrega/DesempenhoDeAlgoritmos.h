#ifndef DESEMPENHODEALGORITMOS_H_INCLUDED
#define DESEMPENHODEALGORITMOS_H_INCLUDED

//estrutura usada para substituir "timeval" da bibliotera "sys/time.h"
struct tempo{
  long int tv_sec;
  long int tv_usec;
};

typedef struct tempo Tempo;
typedef struct tempo *Medir;


int menuEscolheMetodo(); //função chamada pelo "main" para retornar um inteiro representando o método a ser utilizado

int menuEscolheQtd(); //função chamada pelo "main" para retornar um inteiro representando a quantidade a ser utilizada

void getTime(Medir *medir); //função chamada pela "calculaAlgoritmo" para marcar o tempo e atribuir à variável passada como argumento

double timeCalc(Tempo tAntes, Tempo tDepois);//função chamada pela "calculaAlgoritmo" que toma os dois tempos e retorna um double com o tempo decorrido.

//função que toma os inteiros que representam o método, a quantidade e o vetor de elementos e retorna o vetor ordenado.
int* Ordenar(int metodo, int qtd, int *elementos);

/*
* A função mais importante do programa depois da "main", ela recebe a quantidade, o método, gera os vetores aleatórios,
* chama as funções para ordenar e calcular o tempo, repete isso dez vezes e retorna o tempo médio, assim como o melhor e
* pior caso.
*/
double calculaAlgoritmo(int qtd, int metodo);

//método de ordenação
int* BubbleSort(int qtd, int *elementos);

//método de ordenação
int* InsertionSort(int qtd, int *elementos);

//método de ordenação
int* SelectionSort(int qtd, int *elementos);

//método de ordenação
int* ShellSort(int qtd, int *elementos);

//método de ordenação
int* MergeSort(int qtd, int *elementos, int posicaoInicio, int posicaoFim);

//método de ordenação
int* QuickSort(int qtd, int *elementos,int esq, int dir);

//método de ordenação
int* HeapSort(int qtd, int *elementos);

//método de ordenação
int *RadixSort(int qtd, int *elementos);

//método de ordenação
int* CountigSort(int qtd, int *elementos);

//método de ordenação
int* TimSort(int qtd, int *elementos);




#endif // DESEMPENHODEALGORITMOS_H_INCLUDED
