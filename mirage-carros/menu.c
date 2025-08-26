#include<stdio.h>
#include<stdlib.h>
#include "data.h"
#include "pessoa.h"
#include "veiculo.h"
#include "vendas.h"

void chamarMenu (){  // Menu constante para as funcionalidades da concessionaria
    int i,op,opp;
    int ultimoID;
    Veiculo placaRemover[8];
    Cliente cpfRemover[15];
    int idRemover;
    int idRemoverV;
    while (i!=1){
        printf("-=-=-=-=-=-=-=-=-\n  Mirage Carros\n-=-=-=-=-=-=-=-=-\nEscolha:\n[1] Cadastrar\n");
        printf("[2] Consultar\n[3] Remover\n[4] Sair\n");
        scanf("%d",&op);
        system("cls");
        if (op==1){
            printf("\nCadastrar:\n[1] Veiculo\n[2] Vendedor\n[3] Cliente\n[4] Venda\n[5] Sair\n");
            scanf("%d", &opp);
            system("cls");
            if (opp==1){
                cadastroVeiculo();
            }
            else if (opp==2){
                cadastroVendedor();
            }
            else if (opp==3){
                cadastroCliente();
            }
            else if (opp==4){
                cadastroVenda();
            }
            else if (opp==5){
                printf("Saindo...\n");
            }
            else{
                printf("Erro digite uma opcao valida.\n");
            }
        }
        else if (op==2){
            printf("\nConsultar:\n[1] Veiculo\n[2] Vendedor\n[3] Cliente\n[4] Venda\n[5] Sair\n");
            scanf("%d", &opp);
            system("cls");
            if (opp==1){
                lerVeiculos("veiculos.dat");
            }
            else if (opp==2){
                lerVendedor("vendedores.dat");
            }
            else if (opp==3){
                lerCliente("clientes.dat");
            }
            else if (opp==4){
                lerVenda("vendas.dat");
            }
            else if (opp==5){
                printf("Saindo...\n");
            }
            else{
                printf("Erro digite uma opcao valida.\n");
            }
        }
        else if (op==3){
            printf("\nRemover:\n[1] Veiculo\n[2] Vendedor\n[3] Cliente\n[4] Venda\n[5] Sair\n");
            scanf("%d", &opp);
            system("cls");
            if (opp==1){
                printf("============== Lista de veiculos ==============\n");
                lerVeiculos("veiculos.dat");
                printf("===============================================\n");
                printf("\nInsira a placa do veiculo: ");
                scanf("%7s", &placaRemover);
                removerVeiculo("veiculos.dat", placaRemover);
            }
            else if (opp==2){
                printf("============== Lista de vendedores ==============\n");
                lerVendedor("vendedores.dat");
                printf("=================================================\n");
                printf("\nInsira o ID do vendedores: ");
                scanf("%d", &idRemover);
                removerVendedor("vendedores.dat", idRemover);
            }
            else if (opp==3){
                printf("============== Lista de clientes ==============\n");
                lerCliente("clientes.dat");
                printf("===============================================\n");
                printf("\nInsira o CPF do cliente: ");
                scanf("%14s", &cpfRemover);
                removerCliente("clientes.dat", cpfRemover);
            }
            else if (opp==4){
                printf("============== Lista de vendas ==============\n");
                lerVenda("vendas.dat");
                printf("=============================================\n");
                printf("\nInsira o ID da venda: ");
                scanf("%d", &idRemoverV);
                removerVenda("vendas.dat", idRemoverV);
            }
            else if (opp==5){
                printf("Saindo...\n");
            }
            else{
                printf("Erro digite uma opcao valida.\n");
            }
        }
        else if (op==4){
            printf("Saindo...\n");
            i=1;
        }
    }
}
