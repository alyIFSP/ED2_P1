#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
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
    qtd = 50000;
    break;
    case 6:
    qtd = 100000;
    break;
    default:
    break;
  }

  return qtd;
}

void getTime(Medir *medir){

  gettimeofday(medir, NULL);

}
double timeCalc(Tempo tAntes, Tempo tDepois){

  double tDecorrido = (tDepois.tv_sec + tDepois.tv_usec/1000000.0) - (tAntes.tv_sec + tAntes.tv_usec/1000000.0);

  return tDecorrido;
}

int *Ordenar(int metodo, int qtd, int *elementos){
  switch(metodo){
    case 1:
    return BubbleSort(qtd, elementos);
    break;
    case 2:
    return InsertionSort(qtd, elementos);
    break;
    case 3:
    return SelectionSort(qtd, elementos);
    break;
    case 4:
    return ShellSort(qtd, elementos);
    break;
    case 5:
    return MergeSort(qtd, elementos, 0, qtd-1);
    break;
    case 6:
    return QuickSort(qtd, elementos, 0, qtd-1);
    break;
    case 7:
    return HeapSort(qtd, elementos);
    break;
    case 8:
    return RadixSort(qtd, elementos);
    break;
    case 9:
    return CountigSort(qtd, elementos);
    break;
    case 10:
    return TimSort(qtd, elementos);
    break;
    default:
    return;
    break;
  }
}

double calculaAlgoritmo(int qtd, int metodo){

  double media[10]; //cada posição ficará o tempo de cada ordenação
  double tDecorrido; //variável auxiliar para salvar o tempo de ordenação calculado
  Tempo tAntes, tDepois; //variáveis para salvar os tempos

  for(int i=0; i<10; i++){
    //aloca a memória para o vetor
    int *elementos = malloc(qtd * sizeof(int));

    if(elementos){
     //gera elementos aleatórios para o vetor
      for(int i=0; i < qtd; i++){
        elementos[i] = rand() % qtd;
      }
    }else{
      printf("erro ao alocar memoria");
    }

    getTime(&tAntes); //marcar o tempo;
    elementos = Ordenar(metodo, qtd, elementos);
    getTime(&tDepois); //marcar o tempo;

    tDecorrido = timeCalc(tAntes, tDepois);
    media[i] = tDecorrido;


    if(i==9){

      //melhor caso
      getTime(&tAntes); //marcar o tempo;
      elementos = Ordenar(metodo, qtd, elementos);
      getTime(&tDepois); //marcar o tempo;
      tDecorrido = timeCalc(tAntes, tDepois);
      printf("tempo no melhor caso: %.10f\n", tDecorrido);

      //pior caso
      int *elementosInvert = malloc(qtd * sizeof(int));

      for(int j=0; j<qtd; j++)
        elementosInvert[j] = elementos[qtd-j-1]; //salva os elementos do vetor ordenado em posição invertida

      getTime(&tAntes); //marcar o tempo;
      elementosInvert = Ordenar(metodo, qtd, elementosInvert);
      getTime(&tDepois); //marcar o tempo;
      tDecorrido = timeCalc(tAntes, tDepois);
      printf("tempo no pior caso: %.10f\n", tDecorrido);
      free(elementosInvert); //libera o vetor invertido
    }

    //libera somente quando ele não é mais necessário
    free(elementos);
}

for(int i=1; i<10; i++)
	media[0]+=media[i];

media[0] = media[0]/10;

//retorna tempo decorrido
return media[0];

}

int* BubbleSort(int qtd, int *elementos){
  int i, continua, aux, fim = qtd;
  do{
    continua = 0;
    for(i=0; i<fim -1; i++){
      if(elementos[i] > elementos[i+1]){
        aux = elementos[i];
        elementos[i] = elementos[i+1];
        elementos[i+1] = aux;
        continua = i;
      }
    }
    fim--;
  }while(continua != 0);
  return elementos;
}

int* InsertionSort(int qtd, int *elementos){
  int i, j, varAux;
  for (i=2; i<=qtd; i++){
    varAux = elementos[i];
    j=i-1;
    elementos[0] = varAux;

    while (varAux < elementos[j]){
      elementos[j+1] = elementos[j];
      j--;
    }
    elementos[j+1] = varAux;

  }
  return elementos;
}

int* SelectionSort(int qtd, int *elementos){

  int i, j, min, varAux;
  for (i=1; i<=qtd-1; i++){
    min = i;

    for (j=i+1; j<=qtd; j++){
      if (elementos[j] < elementos[min])
        min = j;
    }

	  varAux = elementos[min];
	  elementos[min] = elementos[i];
	  elementos[i] = varAux;
  }
   return elementos;
}

int* ShellSort(int qtd, int *elementos){

  int i , j , value;
  int gap = 1;

  while(gap < qtd) {
    gap = 3*gap+1;
  }

  while ( gap > 1) {
    gap /= 3;
    for(i = gap; i < qtd; i++) {
      value = elementos[i];
      j = i - gap;
      while (j >= 0 && value < elementos[j]) {
        elementos [j + gap] = elementos[j];
        j -= gap;
      }
      elementos [j + gap] = value;
    }
  }
   return elementos;
}

int* MergeSort(int qtd, int *elementos, int posicaoInicio, int posicaoFim){

  int i, j, k, metadeTamanho, *vetorTemp;
  if(posicaoInicio == posicaoFim) return -1;

  metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

  MergeSort(qtd, elementos, posicaoInicio, metadeTamanho);
  MergeSort(qtd, elementos, metadeTamanho + 1, posicaoFim);

  i = posicaoInicio;
  j = metadeTamanho + 1;
  k = 0;
  vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

  while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
    if (i == metadeTamanho + 1 ) {
      vetorTemp[k] = elementos[j];
      j++;
      k++;
    }
    else{
      if (j == posicaoFim + 1) {
        vetorTemp[k] = elementos[i];
        i++;
        k++;
      }
      else {
        if (elementos[i] < elementos[j]) {
          vetorTemp[k] = elementos[i];
          i++;
          k++;
        }
        else {
          vetorTemp[k] = elementos[j];
          j++;
          k++;
        }
      }
    }
  }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
      elementos[i] = vetorTemp[i - posicaoInicio];
    }
  free(vetorTemp);
   return elementos;
}

int* QuickSort(int qtd, int *elementos, int esq, int dir){

  int pivo = esq, i,ch,j;
  for(i=esq+1;i<=dir;i++){
    j = i;
    if(elementos[j] < elementos[pivo]){
      ch = elementos[j];

      while(j > pivo){
        elementos[j] = elementos[j-1];
        j--;
      }

      elementos[j] = ch;
      pivo++;
    }
    }
    if(pivo-1 >= esq){
      QuickSort(qtd, elementos, esq, pivo-1);
    }
    if(pivo+1 <= dir){
      QuickSort(qtd, elementos, pivo+1, dir);
    }
     return elementos;
}

int* HeapSort(int qtd, int *elementos){
  int i, aux;
    for(i = (qtd - 1)/2; i >= 0; i--){
      aux = elementos[i];
      int j = i * 2 + 1;
      while(j <= qtd-1){
        if(j < qtd-1){
          if(elementos[j] < elementos[j + 1]){
            j = j + 1;
          }
        }
        if(aux < elementos[j]){
          elementos[i] = elementos[j];
          i = j;
          j = 2 * i + 1;
        }else{
          j = qtd-1 + 1;
        }
      }
      elementos[i] = aux;
    }
    for(i = qtd-1; i >= 1; i--){
      aux = elementos[0];
      elementos[0] = elementos[i];
      elementos[i] = aux;
      aux = elementos[i];
      int j = i * 2 + 1;
      while(j <= qtd-1){
        if(j < qtd-1){
          if(elementos[j] < elementos[j + 1]){
            j = j + 1;
          }
        }
        if(aux < elementos[j]){
          elementos[i] = elementos[j];
          i = j;
          j = 2 * i + 1;
        }else{
          j = qtd-1 + 1;
        }
      }
      elementos[i] = aux;
    }

    return elementos;
}


int* RadixSort(int qtd, int *elementos){
  int arr1[qtd];
  //Variveis de controle
    int i = 0;  //locomove dentro do vetor
    int j = 0;  //locomove dentro do vetor
    int k = 0;  //n�mero de casa decimais
    int t = 0;  //indice do menor elemento

    int min = 0;    //Armazena o menor valor encontrado
    int tmp = 0;    //Armazena um valor temporario para realizar uma troca

    for (i = 0; i < qtd; i++)   //Percorre o vetor
      arr1[i] = elementos[i];       //Amazenan todos os elementos de arr em arr1

    for (k = 0; k < 3; k++) {   //Varre o vetor k vezes, sendo k o n�mero de casas decimais presentes no vetor
      for (i = 0; i < qtd; i++) { //Percorre o vetor
        min = elementos[i] % 10;  //min recebe o resto de arr[i] / 10
        t = i;
        for (j = i + 1; j < qtd; j++) { //Percorre o vetor a partir do ponto i+1
          if (min > (elementos[j] % 10)) {  //Se min for maior q o atual resto da divis�o do vetor por 10
            min = elementos[j] % 10;  //min recebe o resto a partir do valor atual
            t = j;  //t recebe j
          }
        }

        tmp = arr1[t];
        arr1[t] = arr1[i];
        arr1[i] = tmp;
                            //Realiza a troca entre os indices i e t
        tmp = elementos[t];
        elementos[t] = elementos[i];
        elementos[i] = tmp;
        }
      for (j = 0; j < qtd; j++)
        elementos[j] = elementos[j] / 10;   //Percorre o arr1 subdividindo ele
    }

     return elementos;
}

int* CountigSort(int qtd, int *elementos){
  #define MAX qtd //intervalo entre vetores
  int i, j, k;
  int baldes[MAX];

  // Inicializa os baldes com zeros
  for (i = 0; i < MAX; i++) {
    baldes[i] = 0;
  }

  // Conta as ocorrências de cada valor no array
  for (i = 0; i < qtd; i++) {
    baldes[elementos[i]]++;
  }

  i = 0; // Índice para percorrer o array original
  // Preenche o array ordenado com os valores ordenados
  for (j = 0; j < MAX; j++) {
    for (k = baldes[j]; k > 0; k--) {
      elementos[i++] = j;
    }
  }

   return elementos;
}


int* TimSort(int qtd, int *elementos) {
  const int RUN = 4;
  int i = 0;
  for (i = 0; i < qtd; i += RUN) {
    int right = (i + RUN - 1) < (qtd - 1) ? (i + RUN - 1) : (qtd - 1);
    for (int j = i + 1; j <= right; j++) {
      int key = elementos[j];
      int k = j - 1;

      while (k >= i && elementos[k] > key) {
        elementos[k + 1] = elementos[k];
        k--;
      }
      elementos[k + 1] = key;
    }
  }

  for (int size = RUN; size < qtd; size = 2 * size) {
    for (int left = 0; left + 2 * size < qtd; left += 2 * size) {
      int mid = left + size - 1;
      int right = (left + 2 * size - 1) < (qtd - 1) ? (left + 2 * size - 1) : (qtd - 1);
      int len1 = mid - left + 1, len2 = right - mid + 1;
      int leftMerge[len1], rightMerge[len2];

      for (int i = 0; i < len1; i++)
        leftMerge[i] = elementos[left + i];
      for (int i = 0; i < len2; i++)
        rightMerge[i] = elementos[mid + 1 + i];

      int i = 0, j = 0, k = left;

      while (i < len1 && j < len2) {
        if (leftMerge[i] <= rightMerge[j]) {
          elementos[k] = leftMerge[i];
          i++;
        } else {
          elementos[k] = rightMerge[j];
          j++;
        }
        k++;
      }

      while (i < len1) {
        elementos[k] = leftMerge[i];
        i++;
        k++;
      }

      while (j < len2) {
        elementos[k] = rightMerge[j];
        j++;
        k++;
      }
    }
  }
  return elementos;
}

