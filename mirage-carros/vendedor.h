#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "data.h"

typedef struct Vendedor{ // Estrutura para os dados dos vendedores
    char Nome[40];
    int ID;
    char CPF[15];
    char RG[15];
    char Sexo[2];
    char Telefone[14];
    Data Nascimento;
}Vendedor;

#endif // VENDEDOR_H
