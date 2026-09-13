#include "produto.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int buscar_nome_simples(produto *cabeca_estoque)
{
    int encontrou = 0;
    system("clear");
    char busca[50];
    printf("\n========================"
           "\nDigite o nome do produto"
           "\n========================\n");
    scanf(" %49[^\n]", busca);
    if (cabeca_estoque->id == 0)
    {
        system("clear");
        printf("\n========================"
               "\n  !!!!LISTA VAZIA!!!!"
               "\n========================\n");
        return 0;
    }
    system("clear");
    while (cabeca_estoque != NULL)
    {
        if (strstr(cabeca_estoque->nome, busca) != NULL)
        {
            encontrou++;
            if (encontrou == 1)
            {
                printf("\n========================="
                       "\n!!!PRODUTOS ENCONTRADO!!!"
                       "\n=========================\n");
                printf("%-18s %-29s %-26s %s \n", "ID", "NOME", "PREÇO", "QUANTIDADE");
            }
            printf("%-19d", cabeca_estoque->id);
            printf("%-30s", cabeca_estoque->nome);
            printf("%-26.2f", cabeca_estoque->valor);
            printf("%d\n", cabeca_estoque->quantidade);
        }
        cabeca_estoque = cabeca_estoque->no.proximo;
    }
    if (encontrou > 0)
    {
        return 0;
    }
    system("clear");
    printf("\n========================="
           "\n !!!!NÃO ENCONTRADO!!!!"
           "\n=========================\n");
    return 0;
}
int conta_produtos(produto *cabeca_estoque, listaCircular *cabeca_circular)
{
    int quantidade_produto = 0;

    while (cabeca_estoque != NULL && cabeca_estoque->id != 0)
    {
        quantidade_produto++;
        cabeca_estoque = cabeca_estoque->no.proximo;
    }
    if (cabeca_circular != NULL)
    {
        produto *aux = cabeca_circular->head;
        while (aux->id != 0)
        {

            quantidade_produto++;
            aux = aux->no.proximo;
            if (aux == cabeca_circular->head)
            {
                goto imprimir_produtos;
            }
        }
    }

imprimir_produtos:
    if (quantidade_produto == 0)
    {
        system("clear");
        printf("\n========================"
               "\n  !!!!LISTA VAZIA!!!!"
               "\n========================\n");
        return 0;
    }

    printf("\n=================================="
           "\n    LISTA POSSUI: %d PRODUTOS"
           "\n==================================\n",
           quantidade_produto);
    return 0;
}