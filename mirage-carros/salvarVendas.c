#include<stdio.h>
#include<stdlib.h>
#include "vendas.h"
#include "data.h"

void salvarVenda(Venda *ven, const char *vendas) {   // Salva os dados que o usuario digitou
    FILE *file = fopen("vendas.dat", "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    fwrite(ven, sizeof(Venda), 1, file);
    fclose(file);
}

void lerVenda(const char *vendas) {    // Mostra os dados de todos cadastros
    FILE *file = fopen("vendas.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    Venda ven;
    while (fread(&ven, sizeof(Venda), 1, file)) {
        printf("===============================================\n\n");
        printf("Nome do Vendedor: %s\n", ven.VendedorNome);
        printf("Marca do Veiculo: %s\n", ven.VeiculoMarca);
        printf("Modelo do Veiculo: %s\n", ven.VeiculoModelo);
        printf("Placa do Veiculo: %s\n", ven.VeiculoPlaca);
        printf("Nome do Cliente: %s\n", ven.ClienteNome);
        printf("CPF do Cliente: %s\n", ven.ClienteCPF);
        printf("Data da Venda: %d %s %d\n", ven.Venda.dia, ven.Venda.mes, ven.Venda.ano);
        printf("ID: %d\n\n", ven.ID);
    }
    fclose(file);
}

void removerVenda(const char *vendas, const int *idRemoverV) {  // Remove a venda cadastrada pelo ID da venda
    FILE *file = fopen("vendas.dat", "rb");
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

    Venda ven;
    int encontrado = 0;
    int idParaRemover = idRemoverV;

    while (fread(&ven, sizeof(Venda), 1, file)) {
        if (ven.ID == idParaRemover) {    // Compara o ID para a remoção pelo ID
            printf("Venda com ID %d removido.\n", ven.ID);
            encontrado = 1;
        } else {
            fwrite(&ven, sizeof(Venda), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (encontrado) {
        remove("vendas.dat");
        rename("temp.dat", "vendas.dat");
    } else {
        printf("Venda com ID %d nao encontrado.\n", idRemoverV);
        remove("temp.dat");
    }
}

int obterProximoIDV(const char *vendas) {  // Vê qual foi o ultimo ID e retorna o valor +1
    FILE *file = fopen("vendas.dat", "rb");
    if (file == NULL) {
        return 1;
    }

    Venda ven;
    int ultimoID = 0;

    while (fread(&ven, sizeof(Venda), 1, file)) {
        if (ven.ID >= ultimoID) {
            ultimoID = ven.ID;
        }
    }

    fclose(file);
    return ultimoID + 1;
}
