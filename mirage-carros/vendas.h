#ifndef VENDAS_H
#define VENDAS_H
#include "data.h"

typedef struct Venda{ // Estrutura para os dados das vendas
    char VendedorNome[40];
    char VeiculoMarca[20];
    char VeiculoModelo[30];
    char VeiculoPlaca[8];
    int ID;
    char ClienteNome[40];
    char ClienteCPF[15];
    Data Venda;
}Venda;

#endif // VENDAS_H
