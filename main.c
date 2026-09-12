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

    while (opcao != 13)
    {
        printf("\n===== ESTOQUE DA LOJA =====\n"
               "1. Gerenciar Perecíveis (Simples)\n"
               "2. Gerenciar Não Perecíveis (Dupla)\n"
               "3. Gerenciar Promoções (Circular)\n"
               "0. Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            menu_simples(&cabeca_simples, &contador_id);

            break;
        case 2:

            break;
        case 3:

            break;
        case 0:
            system("clear");
            printf("PROGRAMA ENCERRADO...\n");
            return 0;
            break;
        default:
            system("clear");
            printf("===============================\n"
                   "Opção inválida. Tente novamente.\n"
                   "===============================\n\n");
        }
    }
    return 0;
}