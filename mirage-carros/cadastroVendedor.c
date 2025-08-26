#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "vendedor.h"
#include "data.h"

void cadastroVendedor(){ // Cadastra os dados dos vendedores
    Vendedor ve;
    char continuar[10];
    int proximoID = obterProximoID("vendedores.dat");

    do {
        printf("Digite o nome do vendedor: ");
        scanf(" %39[^\n]", ve.Nome);

        printf("Digite o CPF do vendedor: ");
        scanf(" %14s", ve.CPF);

        printf("Digite o RG do vendedor: ");
        scanf(" %14s", ve.RG);

        printf("Digite o sexo do vendedor (M/F): ");
        scanf(" %1s", ve.Sexo);

        printf("Digite o numero do telefone do vendedor: ");
        scanf(" %13s", ve.Telefone);

        printf("Digite a data de nascimento do vendedor: ");
        scanf("%d %11s %d", &ve.Nascimento.dia, ve.Nascimento.mes, &ve.Nascimento.ano);

        ve.ID = proximoID++;

        salvarVendedor(&ve, "vendedores.dat");   // Salva os dados do vendedor cadastrado

        printf("Deseja adicionar outro vendedor? (digite 'sair' para finalizar): ");
        scanf(" %9s", continuar);
    } while (strcmp(continuar, "sair") != 0);

    printf("Vendedor salvo no arquivo.\n");
    lerVendedor("vendedores.dat");  // Mostra a lista de vendedores

    return 0;
}
