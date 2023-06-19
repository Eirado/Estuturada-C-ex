/*Uma empresa concederá um aumento de salário aos seus funcionários, variável de acordo com o cargo, conforme a tabela abaixo. 
Faça um algoritmo que leia o salário e o cargo de um funcionário e calcule o novo salário. Se o cargo do funcionário não estiver 
na tabela, ele deverá, então, receber 40% de aumento. Mostre o salário antigo, o novo salário e a diferença. Utilize Structs e função 
utilizando ponteiros.

código 101  cargo gerente percentual de 10%
código 102  cargo Engenheiro percentual de 20%
código 103 cargo Tecnico percentual de 30%*/


#include <stdio.h>

struct Funcionario {
    int codigo;
    char cargo[50];
    float salario;
};

void calcularNovoSalario(struct Funcionario *funcionario) {
    float percentual;

    switch (funcionario->codigo) {
        case 101:
            percentual = 0.1;
            break;
        case 102:
            percentual = 0.2;
            break;
        case 103:
            percentual = 0.3;
            break;
        default:
            percentual = 0.4;
            break;
    }

    float novoSalario = funcionario->salario + (funcionario->salario * percentual);
    float diferenca = novoSalario - funcionario->salario;

    printf("Salario Antigo: %.2f\n", funcionario->salario);
    printf("Novo Salário: %.2f\n", novoSalario);
    printf("Tem %.2f de diferenca\n", diferenca);
}

int main() {
    struct Funcionario funcionario;

    printf("Os cargos da empresa sao:\n\n101- Gerente\n102- Engenheiro\n103- Tecnico\n\n");
    printf("Codigo do Cargo: ");
    scanf("%d", &(funcionario.codigo));

    printf("Salario: ");
    scanf("%f", &(funcionario.salario));

    printf("Cargo: ");
    scanf("%s", funcionario.cargo);

    calcularNovoSalario(&funcionario);

    return 0;
}
