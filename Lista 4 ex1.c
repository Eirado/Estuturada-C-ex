/*1. Escreva uma função mm que receba um vetor inteiro v[0..n-1] e os endereços de duas variáveis inteiras, 
digamos min e max, e deposite nessas variáveis o valor de um elemento mínimo e o valor de um elemento máximo 
do vetor.Escreva também uma função main que use a função mm.*/


#include <stdio.h>
#define TamanhoVetor 5


void mm(int v[], int n, int* min, int* max) {
    *min = v[0];
    *max = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] < *min) {
            *min = v[i];
        }
        if (v[i] > *max) {
            *max = v[i];
        }
    }
}

int main() {
    int v[] = {6, 4, 2, 10, 2};
    int n = TamanhoVetor; 
    int min, max;

    mm(v, n, &min, &max);

    printf("\nO valor minimo eh: %d e O valor maximo eh: %d \n", min, max);

    return 0;
}
