#include <stdio.h>
#include <stdlib.h>
#include "DesempenhoDeAlgoritmos.h"

int menuEscolheMetodo(){
  printf("Escolha o metodo que deseja utilizar\n");
  printf("1 - BubbleSort\n");
  printf("2 - InsertionSort\n");
  printf("3 - SelectionSort\n");
  printf("4 - ShellSort\n");
  printf("5 - MergeSort\n");
  printf("6 - QuickSort\n");
  printf("7 - HeapSort\n");
  printf("8 - RadixSort\n");
  printf("9 - CountigSort\n");
  printf("10 - TimSort\n");

  int opcao = 0;
  scanf("%d", &opcao);
  while(opcao <= 0 || opcao > 10){
    printf("opcao invalida, tente novamente");
    scanf("%d", &opcao);
  }

  return opcao;
}

int menuEscolheQtd(){
  printf("Escolha a quantidade de elementos\n");
  printf("1 - 1.000\n");
  printf("2 - 5.000\n");
  printf("3 - 10.000\n");
  printf("4 - 20.000\n");
  printf("5 - 50.000\n");
  printf("6 - 100.000\n");

  int opcao = 0, qtd = 0;
  scanf("%d", &opcao);
  while(opcao < 1 || opcao > 6){
    printf("opcao invalida, tente novamente");
    scanf("%d", &opcao);
  }

  switch(opcao){
    case 1:
    qtd = 1000;
    break;
    case 2:
    qtd = 5000;
    break;
    case 3:
    qtd = 10000;
    break;
    case 4:
    qtd = 20000;
    break;
    case 5:
    qtd = 5000;
    break;
    case 6:
    qtd = 100000;
    break;
    default:
    break;
  }

  return qtd;
}

int BubbleSort(int qtd, int elementos[]){

}
int InsertionSort(int qtd, int elementos[]){
  
}
int SelectionSort(int qtd, int elementos[]){
  
}
int ShellSort(int qtd, int elementos[]){
  
}
int MergeSort(int qtd, int elementos[]){
  
}
int QuickSort(int qtd, int elementos[]){
  
}
int HeapSort(int qtd, int elementos[]){
  
}
int RadixSort(int qtd, int elementos[]){
  
}
int CountigSort(int qtd, int elementos[]){
  
}
int TimSort(int qtd, int elementos[]){
  
}