#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX_ALUNOS 5

struct Aluno {
    char nome[50];
    int matricula;
    int idade;
    char sexo[2];
    float notaA1;
    float notaA2;
    int frequencia;
};

int verificarSexoValido(char sexo[]) {
    if (strcmp(sexo, "M") == 0 || strcmp(sexo, "m") == 0 || strcmp(sexo, "F") == 0 || strcmp(sexo, "f") == 0){
        return 1;
    } else {
        return 0;
    }
}

void cadastrarAluno(struct Aluno *aluno) {
    printf("\n--- Cadastro de Aluno ---\n");
    printf("Nome: ");
    scanf("%s", aluno->nome);
    printf("Matricula: ");
    scanf("%d", &aluno->matricula);
    printf("Idade: ");
    scanf("%d", &aluno->idade);

    do {
        printf("Sexo (M/F): ");
        scanf("%s", aluno->sexo);
    } while (!verificarSexoValido(aluno->sexo));

    printf("Nota A1: ");
    scanf("%f", &aluno->notaA1);
    printf("Nota A2: ");
    scanf("%f", &aluno->notaA2);
    printf("Frequencia (numero de aulas): ");
    scanf("%d", &aluno->frequencia);
}

void consultarAlunoPorMatricula(struct Aluno alunos[], int totalAlunos) {
    int matricula;
    int encontrado = 0;

    printf("\n--- Consultar Aluno por Matricula ---\n");
    printf("Informe o numero da matricula: ");
    scanf("%d", &matricula);

    for (int i = 0; i < totalAlunos; i++) {       
        if (alunos[i].matricula == matricula) {
            printf("\n--- Dados do Aluno ---\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Idade: %d\n", alunos[i].idade);
            printf("Sexo: %s\n", alunos[i].sexo);
            printf("Nota A1: %.2f\n", alunos[i].notaA1);
            printf("Nota A2: %.2f\n", alunos[i].notaA2);
            printf("Frequencia: %d\n", alunos[i].frequencia);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Aluno nao encontrado.\n");
    }
}

void consultarAlunoPorNome(struct Aluno alunos[], int totalAlunos) {
    char nome[50];
    int encontrado = 0;

    printf("\n--- Consultar Aluno por Nome ---\n");
    printf("Informe o nome do aluno: ");
    scanf("%s", nome);

    for (int i = 0; i < totalAlunos; i++) {
        if (strcmp(alunos[i].nome, nome) == 0) {
            printf("\n--- Dados do Aluno ---\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Idade: %d\n", alunos[i].idade);
            printf("Sexo: %s\n", alunos[i].sexo);
            printf("Nota A1: %.2f\n", alunos[i].notaA1);
            printf("Nota A2: %.2f\n", alunos[i].notaA2);
            printf("Frequencia: %d\n", alunos[i].frequencia);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Aluno nao encontrado.\n");
    }
}


float calcularMedia(float notaA1, float notaA2) {
    return (notaA1 + notaA2) / 2;
}

float calcularMediaPorMatricula(struct Aluno alunos[], int totalAlunos, int matricula1) {
    float media = 0;
    int encontrou = 0;

    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula1) {
            media = calcularMedia(alunos[i].notaA1, alunos[i].notaA2);
            encontrou = 1;
            break;
        }
    }

    if (!encontrou) {
        printf("Aluno nao encontrado.\n");
    }

    return media;
}

void verificarAprovacao(struct Aluno aluno) {
    float media = calcularMedia(aluno.notaA1, aluno.notaA2);

    if (media >= 6.0 && aluno.frequencia >= 25) {
        printf("O aluno %s foi aprovado!\n", aluno.nome);
    } else {
        printf("O aluno %s foi reprovado.\n", aluno.nome);
    }
}

float calcularMaiorMedia(struct Aluno alunos[], int totalAlunos) {
    float maiorMedia = -1;

    for (int i = 0; i < totalAlunos; i++) {
        float media = calcularMedia(alunos[i].notaA1, alunos[i].notaA2);
        if (media > maiorMedia) {
            maiorMedia = media;
        }
    }

    return maiorMedia;
}

float calcularPercentualReprovados(struct Aluno alunos[], int totalAlunos) {
    int reprovados = 0;

    for (int i = 0; i < totalAlunos; i++) {
        float media = calcularMedia(alunos[i].notaA1, alunos[i].notaA2);
        if (media < 6.0 || alunos[i].frequencia < 25) {
            reprovados++;
        }
    }

    return (float) reprovados / totalAlunos * 100;
}

void escreverDadosCalculados(struct Aluno alunos[], int totalAlunos) {
    float maiorMedia = calcularMaiorMedia(alunos, totalAlunos);
    float percentualReprovados = calcularPercentualReprovados(alunos, totalAlunos);

    printf("\n--- Dados Calculados ---\n");
    printf("Maior Media: %.2f\n", maiorMedia);
    printf("Percentual de Alunos Reprovados: %.2f%%\n", percentualReprovados);
}

void menu() {
    char escolha;
    struct Aluno alunos[MAX_ALUNOS];
    int totalAlunos = 0;

    do {
        printf("\n--- Menu Principal ---\n");
        printf("A - Cadastrar Aluno\n");
        printf("B - Consultar Dados dos Alunos\n");
        printf("X - Para sair\n");
        printf("Escolha a opcao: ");
        scanf(" %c", &escolha);
        escolha = toupper(escolha);

        switch (escolha) {
            case 'A':
                if (totalAlunos < MAX_ALUNOS) {
                    cadastrarAluno(&alunos[totalAlunos]);
                    totalAlunos++;
                } else {
                    printf("Numero maximo de alunos cadastrados atingido.\n");
                }
                break;
            case 'B': {
                char opcaoConsulta;
                do {
                    printf("\n--- Consultar Dados dos Alunos ---\n");
                    printf("1 - Consultar Aluno por Matricula\n");
                    printf("2 - Consultar Aluno por Nome\n");
                    printf("3 - Verificar média\n");
                    printf("4 - Verificar Aprovacao do Aluno\n");
                    printf("5 - Calcular Maior Media\n");
                    printf("6 - Calcular Percentual de Alunos Reprovados\n");
                    printf("7 - Escrever Dados Calculados\n");
                    printf("8 - Retornar ao Menu Principal\n");
                    printf("Escolha a opcao: ");
                    scanf(" %c", &opcaoConsulta);

                    switch (opcaoConsulta) {
                        case '1':
                            consultarAlunoPorMatricula(alunos, totalAlunos);
                            break;
                        case '2':
                            consultarAlunoPorNome(alunos, totalAlunos);
                            break;
                        case '3': { int matricula1;
                            
                             printf("Informe a matricula do aluno: ");
                             scanf("%d", &matricula1);
                             float media = calcularMediaPorMatricula(alunos, totalAlunos, matricula1);
                             printf("\n\nA media das notas do aluno com matricula %d: %.2f\n", matricula1, media);
                             break;
                        }
                        case '4': {
                            int matricula;
                            printf("\nInforme a matricula do aluno: ");
                            scanf("%d", &matricula);
                            for (int i = 0; i < totalAlunos; i++) {
                                if (alunos[i].matricula == matricula) {
                                    verificarAprovacao(alunos[i]);
                                    break;
                                }
                            }
                            break;
                        }
                        case '5': {
                            float maiorMedia = calcularMaiorMedia(alunos, totalAlunos);
                            printf("\n\nA maior media entre os alunos cadastrados: %.2f\n", maiorMedia);
                            break;
                        }
                        case '6': {
                            float percentualReprovados = calcularPercentualReprovados(alunos, totalAlunos);
                            printf("\n\nPercentual de alunos reprovados: %.2f%%\n", percentualReprovados);
                            break;
                        }
                        case '7':
                            escreverDadosCalculados(alunos, totalAlunos);
                            break;
                        case '8':
                            break;
                        default:
                            printf("\n\nOpcao invalida! Tente novamente.\n");
                            break;
                    }
                } while (opcaoConsulta != '7');
                break;
            }
            case 'X':
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (escolha != 'X');
}

int main() {
    menu();
    return 0;
}
