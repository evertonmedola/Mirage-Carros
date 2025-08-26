#include<stdio.h>
#include<stdlib.h>
#include "pessoa.h"

void salvarCliente(Cliente *c, const char *clientes) { // Salva os dados que o usuario digitou no cadastro
    FILE *file = fopen("clientes.dat", "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    fwrite(c, sizeof(Cliente), 1, file);
    fclose(file);
}

void lerCliente(const char *clientes) {  // Mostra os dados de todos cadastros
    FILE *file = fopen("clientes.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    Cliente c;
    while (fread(&c, sizeof(Cliente), 1, file)) {
        printf("===============================================\n\n");
        printf("Nome: %s\n", c.nome);
        printf("CPF: %s\n", c.cpf);
        printf("CNH: %s\n", c.cnh);
        printf("RG: %s\n", c.rg);
        printf("Sexo: %s\n", c.sexo);
        printf("Telefone: %s\n", c.telefone);
        printf("Data de Nascimento: %d %s %d\n\n", c.nascimento.dia, c.nascimento.mes, c.nascimento.ano);
    }
    fclose(file);
}

void removerCliente(const char *clientes, const char *cpfRemover) {   // Remove o cliente pelo CPF
    FILE *file = fopen("clientes.dat", "rb");
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

    Cliente c;
    int encontrado = 0;

    while (fread(&c, sizeof(Cliente), 1, file)) {
        if (strcmp(c.cpf, cpfRemover) == 0) {
            printf("Cliente com CPF %s removido.\n", c.cpf);
            encontrado = 1;
        } else {
            fwrite(&c, sizeof(Cliente), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (encontrado) {
        remove("clientes.dat");
        rename("temp.dat", "clientes.dat");
    } else {
        printf("Cliente com CPF %s nao encontrado.\n", cpfRemover);
        remove("temp.dat");
    }
}
