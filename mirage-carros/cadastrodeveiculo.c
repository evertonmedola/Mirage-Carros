#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "pessoa.h"
#include "veiculo.h"

void cadastroVeiculo(){  // Cadastra os dados do veículo
    Veiculo v;
    char continuar[10];

    do {
        printf("Digite a marca do veiculo: ");
        scanf(" %19s", v.marca);

        printf("Digite o modelo do veiculo: ");
        scanf(" %29[^\n]", v.modelo);

        printf("Digite a potencia (hp): ");
        scanf("%d", &v.hp);

        printf("Digite o ano de fabricacao: ");
        scanf("%d", &v.anov);

        printf("Digite o numero de donos: ");
        scanf("%d", &v.donos);

        printf("Digite o numero de portas: ");
        scanf("%d", &v.portas);

        printf("Digite o tipo de combustao: ");
        scanf(" %14s", v.combustao);

        printf("Digite a cor do veiculo: ");
        scanf(" %14s", v.cor);

        printf("Digite o tipo de cambio: ");
        scanf(" %11s", v.cambio);

        printf("Digite a placa do carro: ");
        scanf(" %7s", v.placa);

        printf("Digite o preco do carro: ");
        scanf("%d", &v.preco);

        salvarVeiculo(&v, "veiculos.dat");

        printf("Deseja adicionar outro veiculo? (digite 'sair' para finalizar): ");
        scanf(" %9s", continuar);
    } while (strcmp(continuar, "sair") != 0);

    printf("\nVeiculos salvos no arquivo.\n");
    lerVeiculos("veiculos.dat");

    return 0;
}
