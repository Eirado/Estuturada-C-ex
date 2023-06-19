#include <stdio.h>

struct Aluno {
    char nome[50];
    int matricula;
    char telefone[20];
    char sexo;
    int frequencia;
    float notaA1;
    float notaA2;
    float mediaFinal;
};

void calcularMediaFinal(struct Aluno *aluno) {
    aluno->mediaFinal = (aluno->notaA1 + aluno->notaA2) / 2.0;
}

void exibirDadosAluno(struct Aluno aluno) {
    printf("\nNome: %s\n", aluno.nome);
    printf("Número da Matrícula: %d\n", aluno.matricula);
    printf("Frequência: %d aulas\n", aluno.frequencia);
    printf("Média Final: %.2f\n", aluno.mediaFinal);
    
    if (aluno.mediaFinal >= 6.0 && aluno.frequencia >= 60) {
        printf("Situação: Aprovado\n");
    } else {
        printf("Situação: Reprovado\n");
    }
}

void exibirMaiorEMenorMedia(struct Aluno alunos[], int numAlunos) {
    float maiorMedia = alunos[0].mediaFinal;
    float menorMedia = alunos[0].mediaFinal;

    for (int i = 1; i < numAlunos; i++) {
        if (alunos[i].mediaFinal > maiorMedia) {
            maiorMedia = alunos[i].mediaFinal;
        }
        if (alunos[i].mediaFinal < menorMedia) {
            menorMedia = alunos[i].mediaFinal;
        }
    }

    printf("\nMaior Média Final: %.2f\n", maiorMedia);
    printf("Menor Média Final: %.2f\n", menorMedia);
}

void exibirAlunoMaiorMedia(struct Aluno alunos[], int numAlunos) {
    float maiorMedia = alunos[0].mediaFinal;
    int indiceMaiorMedia = 0;
    int i = 0;

    for (int i = 1; i < numAlunos; i++) {
        if (alunos[i].mediaFinal > maiorMedia) {
            maiorMedia = alunos[i].mediaFinal;
            indiceMaiorMedia = i;
        }
    }

    printf("\nAluno(a) com Maior Média:\n");
    printf("Nome: %s\n", alunos[indiceMaiorMedia].nome);
    printf("Número da Matrícula: %d\n", alunos[indiceMaiorMedia].matricula);
    printf("Média Final: %.2f\n", alunos[indiceMaiorMedia].mediaFinal);
}

void calcularAprovadosReprovados(struct Aluno alunos[], int numAlunos, int *aprovados, int *reprovados) {
    *aprovados = 0;
    *reprovados = 0;
    int i = 0;

    for ( i = 0; i < numAlunos; i++) {
        if (alunos[i].mediaFinal >= 6.0 && alunos[i].frequencia >= 60) {
            (*aprovados)++;
        } else {
            (*reprovados)++;
        }
    }
}

float calcularPercentagemReprovadosPorFrequencia(struct Aluno alunos[], int numAlunos) {
    int reprovadosPorFrequencia = 0;
    int i = 0;

    for ( i = 0; i < numAlunos; i++) {
        if (alunos[i].frequencia < 60) {
            reprovadosPorFrequencia++;
        }
    }

    float percentagemReprovados = (float)reprovadosPorFrequencia / numAlunos * 100.0;
    return percentagemReprovados;
}

int main() {
    struct Aluno alunos[5];
    int aprovados, reprovados;
    int i = 0;
    printf("=== Cadastro de Alunos ===\n");

    for ( i = 0; i < 5; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Número da Matrícula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Telefone: ");
        scanf("%s", alunos[i].telefone);
        printf("Sexo (M/F): ");
        scanf(" %c", &alunos[i].sexo);
        printf("Frequência (nº de aulas frequentadas): ");
        scanf("%d", &alunos[i].frequencia);
        printf("Nota A1: ");
        scanf("%f", &alunos[i].notaA1);
        printf("Nota A2: ");
        scanf("%f", &alunos[i].notaA2);

        calcularMediaFinal(&alunos[i]);
    }

    printf("\n=== Dados dos Alunos ===\n");

    for ( i = 0; i < 5; i++) {
        exibirDadosAluno(alunos[i]);
    }

    exibirMaiorEMenorMedia(alunos, 5);
    exibirAlunoMaiorMedia(alunos, 5);

    calcularAprovadosReprovados(alunos, 5, &aprovados, &reprovados);
    printf("\nTotal de Alunos Aprovados: %d\n", aprovados);
    printf("Total de Alunos Reprovados: %d\n", reprovados);

    float percentagemReprovadosPorFrequencia = calcularPercentagemReprovadosPorFrequencia(alunos, 5);
    printf("Percentagem de Alunos Reprovados por Frequência: %.2f%%\n", percentagemReprovadosPorFrequencia);

    return 0;
}
