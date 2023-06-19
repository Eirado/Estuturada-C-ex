/*
3.Escrever um programa que cadastre o nome, a matrícula e duas notas de vários alunos. Em seguida imprima a matrícula, 
o nome e a média de cada um deles. Utilize Structs e função utilizando ponteiros
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxAlunos 2

struct Aluno {
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
};

void cadastrarAluno(struct Aluno *aluno) {

    printf("Nome: ");
    scanf("%s", aluno->nome);
    printf("Matrícula: ");
    scanf("%d", &(aluno->matricula));
    printf("Nota 1: ");
    scanf("%f", &(aluno->nota1));
    printf("Nota 2: ");
    scanf("%f", &(aluno->nota2));
}

void calcularMedia(struct Aluno *aluno) {

    float media = (aluno->nota1 + aluno->nota2) / 2;

    printf("Matrícula: %d\n", aluno->matricula);
    printf("Nome: %s\n", aluno->nome);
    printf("Média: %.2f\n", media);
    printf("\n");
}



int main() {
    struct Aluno alunos[MaxAlunos];

    printf("Cadraste os alunos: \n");

    for (int i = 0; i < MaxAlunos; i++) {
        printf("Aluno %d\n", i+1);
        cadastrarAluno(&alunos[i]);
        printf("\n");
    }

    system("clear");
    printf("RESULTADOS: \n\n");

    for (int i = 0; i < MaxAlunos; i++) {
        calcularMedia(&alunos[i]);
    }

    return 0;
}
