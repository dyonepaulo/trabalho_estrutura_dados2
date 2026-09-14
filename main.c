#include "dupla.h"
#include "simples.h"
#include "circular.h"
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcao, contador_id = 1009;
    produto *cabeca_simples = calloc(1, sizeof(produto));
    

    if (cabeca_simples == NULL)
    {
        printf("\nErro de alocação de memoria!!");
        return 1;
    }
    produto *inicio_dupla=calloc(1, sizeof(produto));
    produto *fim_dupla=inicio_dupla;
    if (inicio_dupla == NULL){
        printf("\nErro de alocação de memoria!!");
        return 1;
    }

    listaCircular *cabeca_circular = calloc(1, sizeof(listaCircular));

    if (cabeca_circular == NULL)
    {
        printf("\nErro de alocação de memoria!!");
        return 1;
    }

    while (1)
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
            menu_dupla(&inicio_dupla, &fim_dupla, &contador_id);

            break;
        case 3:
            circular_menu(&cabeca_circular, &contador_id);
            break;
        case 0:
            system("clear");
            printf("PROGRAMA ENCERRADO...\n");
            esvaziar_simples(cabeca_simples);
            esvaziar_circular(&cabeca_circular);
            free(cabeca_simples);
            free(cabeca_circular);
            return 0;
            break;
        default:
            system("clear");
            printf("===============================\n"
                   "Opção inválida. Tente novamente.\n"
                   "===============================\n\n");
        }
    }
}