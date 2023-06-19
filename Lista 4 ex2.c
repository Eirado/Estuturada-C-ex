/*2. Escreva uma função que recebe como parâmetros um vetor de inteiros v, o número de elementos dele N e 
ponteiros para variáveis nas quais devem ser armazenados os valores máximo e mínimo do vetor. Sua assinatura deve 
ser:void maximoMinimo(int *v, int N, int *maximo, int *minimo);*/

#include <stdio.h>
#define TamanhoVetor 5

void maximoMinimo(int *v, int N, int *maximo, int *minimo) {
    *maximo = v[0];
    *minimo = v[0];

    for (int i = 1; i < N; i++) {
        if (v[i] > *maximo) {
            *maximo = v[i];
        }
        if (v[i] < *minimo) {
            *minimo = v[i];
        }
    }
}

int main() {
    int v[] = {3, 33, 23, 35, 2352};
    int N = TamanhoVetor; 
    int maximo, minimo;

    maximoMinimo(v, N, &maximo, &minimo);

    printf("\nO valor minimo eh: %d e O valor maximo eh: %d \n", minimo, maximo);

    return 0;
}
