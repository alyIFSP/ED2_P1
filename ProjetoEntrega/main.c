#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "DesempenhoDeAlgoritmos.h"

int main(){
    //As duas funções estão chamando os dois menus e retornado o método e quantidade
    int metodo = menuEscolheMetodo(), qtd = menuEscolheQtd();
    double tempo = 0;

    //O tempo retornado aqui já é a média dos 10 tempos utilizados no programa
    tempo = calculaAlgoritmo(qtd, metodo);

    //aqui é exibido para o usuário o tempo com uma precisão de 10 casas decimais
    printf("\n\nO tempo medio para ordenar a quantidade %d foi de: %.10f segundos\n", qtd, tempo);


    return 0;
}
