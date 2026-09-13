#include "simples.h"
#include <stdlib.h>
#include "produto.h"
#include <stdio.h>
#include <string.h>

int inserir_simples(produto **cabeca_estoque, int *contador_id)
{

    produto *aux;
    int opcao;
inicio:
    printf("=======INSERIR=======\n"
           "1. Inserir no início\n"
           "2. Inserir no fim\n"
           "3. Voltar\n"
           "Escolha uma opção:");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        if ((*cabeca_estoque)->id == 0)
        {
            (*contador_id)++;
            (*cabeca_estoque)->id = *contador_id;
            system("clear");
            printf("\n================================"
                   "\n     Cadastro do Produto!!"
                   "\n================================\n"
                   "°QUANTIDADE: ");
            scanf("%d", &(*cabeca_estoque)->quantidade);
            printf("\n°VALOR: ");
            scanf("%f", &(*cabeca_estoque)->valor);
            printf("\n°NOME: ");
            scanf(" %49[^\n]", (*cabeca_estoque)->nome);
            (*cabeca_estoque)->no.proximo = NULL;
            system("clear");
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
        cadastrar:
            (*contador_id)++;
            (*cabeca_estoque)->id = *contador_id;
            system("clear");
            printf("\n================================"
                   "\n     Cadastro do Produto!!"
                   "\n================================\n"
                   "°QUANTIDADE: ");
            scanf("%d", &(*cabeca_estoque)->quantidade);
            printf("\n°VALOR: ");
            scanf("%f", &(*cabeca_estoque)->valor);
            printf("\n°NOME: ");
            scanf(" %49[^\n]", (*cabeca_estoque)->nome);
            system("clear");
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
            if (aux->id == 0)
            {
                goto cadastrar;
            }
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
                system("clear");
                printf("\n================================"
                       "\n     Cadastro do Produto!!"
                       "\n================================\n"
                       "°QUANTIDADE: ");
                scanf("%d", &temp->quantidade);
                printf("\n°VALOR: ");
                scanf("%f", &temp->valor);
                printf("\n°NOME: ");
                scanf(" %49[^\n]", temp->nome);
                system("clear");
                printf("\n========================"
                       "\nInserido com sucesso!!!!"
                       "\n========================\n");
                return 0;
            }
            aux = aux->no.proximo;
        }

        break;
    case 3:
        system("clear");
        return 0;
    default:
        system("clear");
        printf("===============================\n"
               "Opção inválida. Tente novamente.\n"
               "===============================\n\n");
        goto inicio;
    }
}

int listar_simples(produto *cabeca_estoque)
{
    if (cabeca_estoque->id == 0)
    {
        system("clear");
        printf("\n========================"
               "\n  !!!!LISTA VAZIA!!!!"
               "\n========================\n");
        return 0;
    }
    while (cabeca_estoque != NULL)
    {
        printf("%-19d", cabeca_estoque->id);
        printf("%-30s", cabeca_estoque->nome);
        printf("%-26.2f", cabeca_estoque->valor);
        printf("%d\n", cabeca_estoque->quantidade);
        cabeca_estoque = cabeca_estoque->no.proximo;
    }
    return 0;
}

int menu_simples(produto **cabeca_estoque, int *contador_id)
{
    int opcao;
    system("clear");
    while (1)
    {
        printf("===== GERENCIAR PERECÍVEIS =====\n"
               "1. Inserir no início ou fim\n"
               "2. Remover no início ou fim por ID\n"
               "3. Buscar produto por nome\n"
               "4. Atualizar quantidade de um produto\n"
               "5. Exibir todos os produtos\n"
               "6. Contar quantos produtos há no estoque\n"
               "7. Esvaziar completamente o estoque\n"
               "0. Voltar ao menu principal\n"
               "Escolha uma opção:");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("clear");
            inserir_simples(cabeca_estoque, contador_id);
            break;
        case 2:
            system("clear");

            break;
        case 3:
            system("clear");
            buscar_nome_simples(*cabeca_estoque);
            break;
        case 4:
            system("clear");

            break;
        case 5:
            system("clear");
            printf("%-18s %-29s %-26s %s \n", "ID", "NOME", "PREÇO", "QUANTIDADE");
            listar_simples(*cabeca_estoque);
            break;
        case 6:
            system("clear");

            break;
        case 7:
            system("clear");
            esvaziar_simples(*cabeca_estoque);
            break;
        case 0:
            system("clear");
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
int esvaziar_simples(produto *cabeca_estoque)
{
    int protege_cabeca = 1;
    produto *libera;
    while (1)
    {
        if (cabeca_estoque->id == 0)
        {
            system("clear");
            printf("===========================\n"
                   "Estoque já está desocupado.\n"
                   "===========================\n\n");
            return 0;
        }
        if (protege_cabeca == 1)
        {
            if (cabeca_estoque->no.proximo == NULL)
            {
                cabeca_estoque->id = 0;
                system("clear");
                printf("=======================\n"
                       "Estoque foi desocupado.\n"
                       "=======================\n\n");
                return 0;
            }
            cabeca_estoque->id = 0;
            cabeca_estoque = cabeca_estoque->no.proximo;
            protege_cabeca = 0;
        }
        libera = cabeca_estoque->no.proximo;
        free(cabeca_estoque);
        cabeca_estoque = libera;
        if (libera == NULL)
        {
            system("clear");
            printf("=======================\n"
                   "Estoque foi desocupado.\n"
                   "=======================\n\n");
            return 0;
        }
    }
}