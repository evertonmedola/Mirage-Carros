#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "vendas.h"
#include "data.h"

void cadastroVenda(){  // Cadastra os dados das vendas
    Venda ven;
    char continuar[10];
    int proximoID = obterProximoIDV("vendas.dat"); // Obtém o próximo ID da venda

    do {
        printf("Digite o nome do vendedor: ");
        scanf(" %39[^\n]", ven.VendedorNome);

        printf("Digite a marca do veiculo: ");
        scanf(" %19s", ven.VeiculoMarca);

        printf("Digite o modelo do veiculo: ");
        scanf(" %29s", ven.VeiculoModelo);

        printf("Digite a placa do veiculo: ");
        scanf(" %7s", ven.VeiculoPlaca);

        printf("Digite o nome do cliente: ");
        scanf(" %39[^\n]", ven.ClienteNome);

        printf("Digite o CPF do cliente: ");
        scanf(" %14s", ven.ClienteCPF);

        printf("Digite a data da venda: ");
        scanf("%d %11s %d", &ven.Venda.dia, ven.Venda.mes, &ven.Venda.ano);

        ven.ID = proximoID++;

        salvarVenda(&ven, "vendas.dat"); // Salva o arquivo de vendas

        printf("Deseja adicionar outra venda? (digite 'sair' para finalizar): ");
        scanf(" %9s", continuar);
    } while (strcmp(continuar, "sair") != 0);

    printf("Venda salva no arquivo.\n");
    lerVenda("vendas.dat");

    removerVeiculo("veiculos.dat", ven.VeiculoPlaca);  // Remoção do veiculo vendido

    return 0;
}
