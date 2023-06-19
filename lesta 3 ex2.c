#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumProfessores 2
#define ValorHoraAula 15
#define MaximoDeHorasTrabalhadas 150

struct Professor {
    int codigo;
    char sexo;
    int horasAula;
    float salarioBruto;
    float desconto;
    float salarioLiquido;
};

void calcularSalario(struct Professor *prof) {
    float desconto;

    if (prof->horasAula <= MaximoDeHorasTrabalhadas) {
        if (prof->sexo == 'M') {
            desconto = 0.1;
        } else {
            desconto = 0.08;
        }
    } else {
        if (prof->sexo == 'M') {
            desconto = 0.07;
        } else {
            desconto = 0.05;
        }
    }

    prof->salarioBruto = prof->horasAula * ValorHoraAula;
    prof->desconto = prof->salarioBruto * desconto;
    prof->salarioLiquido = prof->salarioBruto - prof->desconto;
}

void exibirListagem(struct Professor professores[]) {
    printf("\n--- Listagem de Salarios ---\n");
    printf("Codigo\tSalario Bruto\tDesconto\tSalario Liquido\n");
    
    for (int i = 0; i < NumProfessores; i++) {
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n", professores[i].codigo, professores[i].salarioBruto, professores[i].desconto, professores[i].salarioLiquido);
    }
}

float calcularMediaSalarios(struct Professor professores[], char sexo) {
    float somaSalarios = 0;
    int contador = 0;

    for (int i = 0; i < NumProfessores; i++) {
        if (professores[i].sexo == sexo) {
            somaSalarios += professores[i].salarioBruto;
            contador++;
        }
    }

    if (contador == 0) {
        return 0;
    }
    
    float media = somaSalarios / NumProfessores;
    return media;
}

int main() {
    struct Professor professores[NumProfessores];

    printf("--- Cadastro de Professores ---\n");

    for (int i = 0; i < NumProfessores; i++) {
        printf("\nProfessor %d:\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &professores[i].codigo);
        printf("Sexo (M/F): ");
        scanf(" %c", &professores[i].sexo);
        toupper(professores[i].sexo);
        printf("Horas/Aula: ");
        scanf("%d", &professores[i].horasAula);

        calcularSalario(&professores[i]);
    }

    exibirListagem(professores);

    printf("\nMedia de Salarios (Masculino): %.2f\n", calcularMediaSalarios(professores, 'M'));
    printf("Media de Salarios (Feminino): %.2f\n",calcularMediaSalarios(professores, 'F'));

    return 0;
}
