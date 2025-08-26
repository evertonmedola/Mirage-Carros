#ifndef VEICULO_H
#define VEICULO_H

typedef struct Veiculo{ // Estrutura para os dados dos veiculos
    char marca[20];
    char modelo[30];
    int hp;
    int anov;
    int donos;
    int portas;
    char combustao[15];
    char cor[15];
    char cambio[12];
    char placa[8];
    int preco;
} Veiculo;

#endif // VEICULO_H
