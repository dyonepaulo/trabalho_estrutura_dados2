#include "dupla.h"
#include "simples.h"
#include "circular.h"
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int opcao;

    while (opcao != 7)
    {

        printf("===== ESTOQUE DA LOJA =====\n"
               "1. Gerenciar Perecíveis (Simples)\n"
               "2. Gerenciar Não Perecíveis (Dupla)\n"
               "3. Gerenciar Promoções (Circular)\n"
               "0. Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("clear");
        menu_simples:
            printf("===== GERENCIAR PERECÍVEIS =====\n");
            printf("Escolha uma opção:\n");
            printf("1. Inserir no início ou fim\n");
            printf("2. Remover no início ou fim e por ID\n");
            printf("3. Buscar produto por nome\n");
            printf("4. Atualizar quantidade de um produto\n");
            printf("5. Exibir todos os produtos\n");
            printf("6. Contar quantos produtos há no estoque\n");
            printf("7. Esvaziar completamente o estoque\n");
            printf("0. Voltar ao menu principal\n");
            scanf("%d", &opcao);

            switch (opcao)
            {
            case 1:
                system("clear");
                break;
            case 2:
                system("clear");
                break;
            case 3:
                system("clear");

                break;
            case 4:
                system("clear");

                break;
            case 5:
                system("clear");

                break;
            case 6:
                system("clear");

                break;
            case 7:
                system("clear");
                break;
            case 0:
                system("clear");
                break;
            default:
                system("clear");
                printf("===============================\n"
                       "Opção inválida. Tente novamente.\n"
                       "===============================\n\n");
                goto menu_simples;
            }

            break;
        case 2:
            system("clear");

            break;
        case 3:
            system("clear");

            break;
        case 0:
            system("clear");
            printf("PROGRAMA ENCERRADO...\n");
            return 0;
        default:
            system("clear");
            printf("===============================\n"
                   "Opção inválida. Tente novamente.\n"
                   "===============================\n\n");
        }
    }
}