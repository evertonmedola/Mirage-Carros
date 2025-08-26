#include<stdio.h>
#include<stdlib.h>
#include "vendedor.h"

void salvarVendedor(Vendedor *ve, const char *vendedores) { // Salva os dados que o usuario digitou no cadastro
    FILE *file = fopen("vendedores.dat", "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    fwrite(ve, sizeof(Vendedor), 1, file);
    fclose(file);
}

void lerVendedor(const char *vendedores) {  // Mostra os dados de todos cadastros
    FILE *file = fopen("vendedores.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    Vendedor ve;
    while (fread(&ve, sizeof(Vendedor), 1, file)) {
        printf("===============================================\n\n");
        printf("Nome: %s\n", ve.Nome);
        printf("ID: %d\n", ve.ID);
        printf("CPF: %s\n", ve.CPF);
        printf("RG: %s\n", ve.RG);
        printf("Sexo: %s\n", ve.Sexo);
        printf("Telefone: %s\n", ve.Telefone);
        printf("Data de Nascimento: %d %s %d\n\n", ve.Nascimento.dia, ve.Nascimento.mes, ve.Nascimento.ano);
    }
    fclose(file);
}

void removerVendedor(const char *vendedores, const int *idRemover) { // Remove o vendedor pelo ID
    FILE *file = fopen("vendedores.dat", "rb");
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

    Vendedor ve;
    int encontrado = 0;
    int idParaRemover = idRemover;

    while (fread(&ve, sizeof(Vendedor), 1, file)) {
        if (ve.ID == idParaRemover) {
            printf("Vendedor com ID %d removido.\n", ve.ID);
            encontrado = 1;
        } else {
            fwrite(&ve, sizeof(Vendedor), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (encontrado) {
        remove("vendedores.dat");
        rename("temp.dat", "vendedores.dat");
    } else {
        printf("Vendedor com ID %d nao encontrado.\n", idRemover);
        remove("temp.dat");
    }
}

int obterProximoID(const char *vendedores) {  // Obtém o próximo ID do vendedor
    FILE *file = fopen("vendedores.dat", "rb");
    if (file == NULL) {
        return 1;
    }

    Vendedor ve;
    int ultimoID = 0;

    while (fread(&ve, sizeof(Vendedor), 1, file)) {
        if (ve.ID >= ultimoID) {
            ultimoID = ve.ID;
        }
    }

    fclose(file);
    return ultimoID + 1;
}
