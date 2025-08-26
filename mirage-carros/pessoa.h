#ifndef PESSOA_H
#define PESSOA_H
#include "data.h"

typedef struct Cliente{  // Estrutura para os dados do cliente
    char nome[30];
    char cpf[15];
    char cnh[15];
    char rg[15];
    char sexo[2];
    char telefone[14];
    Data nascimento;
}Cliente;

#endif // PESSOA_H
