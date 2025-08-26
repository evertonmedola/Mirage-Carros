#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "veiculo.h"

void salvarVeiculo(Veiculo *v, const char *veiculos) {  // Salva os dados que o usuario digitou no cadastro
    FILE *file = fopen("veiculos.dat", "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    fwrite(v, sizeof(Veiculo), 1, file);
    fclose(file);
}

void lerVeiculos(const char *veiculos) {  // Mostra os dados de todos cadastros
    FILE *file = fopen("veiculos.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    Veiculo v;
    while (fread(&v, sizeof(Veiculo), 1, file)) {
        printf("Marca: %s\n", v.marca);
        printf("Modelo: %s\n", v.modelo);
        printf("Potencia: %d hp\n", v.hp);
        printf("Ano: %d\n", v.anov);
        printf("Donos: %d\n", v.donos);
        printf("Portas: %d\n", v.portas);
        printf("Combustivel: %s\n", v.combustao);
        printf("Cor: %s\n", v.cor);
        printf("Cambio: %s\n", v.cambio);
        printf("Placa: %s\n", v.placa);
        printf("Preco: %d\n\n", v.preco);
    }
    fclose(file);
}

void removerVeiculo(const char *veiculos, const char *placaRemover) {  // Remove os dados do carro pela placa
    FILE *file = fopen("veiculos.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Erro ao abrir o arquivo temporario para escrita.\n");
        fclose(file);
        return;
    }

    Veiculo v;
    int encontrado = 0;

    while (fread(&v, sizeof(Veiculo), 1, file)) {
        if (strcmp(v.placa, placaRemover) == 0) {
            printf("Veiculo com placa %s removido.\n", v.placa);
            encontrado = 1;
        } else {
            fwrite(&v, sizeof(Veiculo), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (encontrado) {
        remove("veiculos.dat");
        rename("temp.dat", "veiculos.dat");
    } else {
        printf("Veiculo com placa %s nao encontrado.\n", placaRemover);
        remove("temp.dat");
    }
}
