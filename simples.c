#include "simples.h"
#include <stdlib.h>
#include "produto.h"
#include <stdio.h>

int inserir_simples(int opcao, produto **cabeca_estoque, int *contador_id)
{

    produto *aux;
    switch (opcao)
    {
    case 1:
        if ((*cabeca_estoque)->id == 0)
        {
            (*contador_id)++;
            (*cabeca_estoque)->id = *contador_id;
            printf("\n================================"
                   "\n     Cadastro do Produto!!"
                   "\n================================\n"
                   "°QUANTIDADE: ");
            scanf("%d", &(*cabeca_estoque)->quantidade);
            printf("\n°VALOR: ");
            scanf("%f", &(*cabeca_estoque)->valor);
            printf("\n°NOME: ");
            scanf("%49s", (*cabeca_estoque)->nome);
            (*cabeca_estoque)->no.proximo = NULL;
            printf("\n========================"
                   "\nInserido com sucesso!!!!"
                   "\n========================\n");
            return 0;
        }
        else
        {
            aux = (*cabeca_estoque);
            (*cabeca_estoque) = calloc(1, sizeof(produto));
            if (*cabeca_estoque == NULL)
            {
                printf("\nErro de alocação de memoria!!");
                return 1;
            }
            (*cabeca_estoque)->no.proximo = aux;
            (*contador_id)++;
            (*cabeca_estoque)->id = *contador_id;
            printf("\n================================"
                   "\n     Cadastro do Produto!!"
                   "\n================================\n"
                   "°QUANTIDADE: ");
            scanf("%d", &(*cabeca_estoque)->quantidade);
            printf("\n°VALOR: ");
            scanf("%f", &(*cabeca_estoque)->valor);
            printf("\n°NOME: ");
            scanf("%49s", (*cabeca_estoque)->nome);
            printf("\n========================"
                   "\nInserido com sucesso!!!!"
                   "\n========================\n");
            return 0;
        }
        break;

    case 2:
        aux = (*cabeca_estoque);
        while (aux != NULL)
        {
            if (aux->no.proximo == NULL)
            {
                produto *temp = calloc(1, sizeof(produto));
                if (temp == NULL)
                {
                    printf("\nErro de alocação de memoria!!");
                    return 1;
                }
                aux->no.proximo = temp;
                temp->no.proximo = NULL;
                (*contador_id)++;
                temp->id = *contador_id;
                printf("\n================================"
                       "\n     Cadastro do Produto!!"
                       "\n================================\n"
                       "°QUANTIDADE: ");
                scanf("%d", &temp->quantidade);
                printf("\n°VALOR: ");
                scanf("%f", &temp->valor);
                printf("\n°NOME: ");
                scanf("%49s", temp->nome);
                printf("\n========================"
                       "\nInserido com sucesso!!!!"
                       "\n========================\n");
                return 0;
            }
            aux = aux->no.proximo;
        }

        break;
    default:
        printf("Opção invalida!!!!!!!!!!!!!");
        return 0;
    }
}