#include "dupla.h"
#include "simples.h"
#include "circular.h"
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcao = 67, contador_id = 1009;
    produto *cabeca_simples = calloc(1, sizeof(produto));
    if (cabeca_simples == NULL)
    {
        printf("\nErro de alocação de memoria!!");
        return 1;
    }

    system("clear");
    while (opcao != 0)
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

        menu_simples:
            printf("===== GERENCIAR PERECÍVEIS =====\n"
                   "Escolha uma opção:\n"
                   "1. Inserir no início ou fim\n"
                   "2. Remover no início ou fim e por ID\n"
                   "3. Buscar produto por nome\n"
                   "4. Atualizar quantidade de um produto\n"
                   "5. Exibir todos os produtos\n"
                   "6. Contar quantos produtos há no estoque\n"
                   "7. Esvaziar completamente o estoque\n"
                   "0. Voltar ao menu principal\n");
            scanf("%d", &opcao);

            switch (opcao)
            {
            case 1:
                system("clear");

                printf("1. Inserir no início\n"
                       "2. Inserir no fim\n");
                scanf("%d", &opcao);
                inserir_simples(opcao, &cabeca_simples, &contador_id);
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
                printf("%-18s %-29s %-26s %s \n", "ID", "NOME", "PREÇO", "QUANTIDADE");
                listar_simples(cabeca_simples);
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

                printf("===============================\n"
                       "Opção inválida. Tente novamente.\n"
                       "===============================\n\n");
                goto menu_simples;
            }

            break;
        case 2:

            break;
        case 3:

            break;
        case 0:

            printf("PROGRAMA ENCERRADO...\n");
            break;
        default:

            printf("===============================\n"
                   "Opção inválida. Tente novamente.\n"
                   "===============================\n\n");
        }
        return 0;
    }
}