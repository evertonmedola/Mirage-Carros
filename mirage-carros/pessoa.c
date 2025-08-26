#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "pessoa.h"
#include "veiculo.h"

void cadastroCliente(){  // Cadastra os dados do cliente
    Cliente c;
    char continuar[10];

    do {
        printf("Digite o nome do cliente: ");
        scanf(" %29[^\n]", c.nome);

        printf("Digite o CPF do cliente: ");
        scanf(" %14s", c.cpf);

        printf("Digite a CNH do cliente: ");
        scanf(" %14s", c.cnh);

        printf("Digite o RG do cliente: ");
        scanf(" %14s", c.rg);

        printf("Digite o sexo do cliente (M/F): ");
        scanf(" %1s", c.sexo);

        printf("Digite o telefone do cliente: ");
        scanf(" %13s", c.telefone);

        printf("Digite a data de nascimento do cliente: ");
        scanf(" %d %11s %d", &c.nascimento.dia, c.nascimento.mes, &c.nascimento.ano);

        salvarCliente(&c, "clientes.dat");

        printf("Deseja adicionar outro cliente? (digite 'sair' para finalizar): ");
        scanf(" %9s", continuar);
    } while (strcmp(continuar, "sair") != 0);

    printf("\Clientes salvos no arquivo.\n");
    lerCliente("clientes.dat");

    return 0;
}
