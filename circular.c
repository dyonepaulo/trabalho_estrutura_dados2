#include "circular.h"
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>

void inserir(produto **novo, int ***contador_id){
    (*novo) = calloc(1, sizeof(produto));

    if ((*novo) == NULL) {
        printf("Erro: falha na alocação de memória\n");
        exit(1);
    }

    if ((*novo)->id == 0) {
        (*(*contador_id)++);
        (*novo)->id = (*(*(*contador_id)))++;
        printf( "\n================================"
                "\n     Cadastro do Produto!!"
                "\n================================\n"
                "QUANTIDADE: ");
        scanf("%d", &(*novo)->quantidade);
        printf("\nVALOR: ");
        scanf("%f", &(*novo)->valor);
        printf("\nNOME: ");
        scanf("%49s", (*novo)->nome);
        (*novo)->no.proximo = NULL;

        printf( "\n========================"
                "\nInserido com sucesso!!!!"
                "\n========================\n");
    }
}

void inserir_circular(listaCircular **cabeca_estoque, int *contador_id){
    int option;

    printf("===== INSERIR PRODUTO =====\n"
                   "Escolha uma opção:\n"
                   "1. Inserir no início\n "
                   "2. Inserir no fim\n"
                   "3. Sair\n"
                   "\n>>>");

    scanf("%d", option);  

    switch (option)
    {
    case 1:
        inserir_circular_inicio(&cabeca_estoque, &contador_id);
        break;
    case 2:
        inserir_circular_fim(&cabeca_estoque, &contador_id);
        break;
    case 3:
        return;

    default:
        printf("\nEntrada inválida.");
        return;
    }
}

void inserir_circular_fim(listaCircular ***cabeca_estoque, int **contador_id){
    produto *anterior;
    produto *novo;

    inserir(&novo, &contador_id);

    if((*(*cabeca_estoque))->head == NULL){
        (*(*cabeca_estoque))->head = novo;
        (*(*cabeca_estoque))->tail = novo;

        return;
    } else {
        anterior = (*(*cabeca_estoque))->tail;

        anterior->no.proximo = novo;
        (*(*cabeca_estoque))->tail = novo;
        novo->no.proximo = (*(*cabeca_estoque))->head;
        return;
    }      
}

void inserir_circular_inicio(listaCircular ***cabeca_estoque, int **contador_id){
    produto *anterior;
    produto *novo;

    inserir(&novo, &contador_id);

    if((*(*cabeca_estoque))->head == NULL){
        (*(*cabeca_estoque))->head = novo;
        (*(*cabeca_estoque))->tail = novo;        
        
        return;
    } else {
        anterior = (*(*cabeca_estoque))->head;

        (*(*cabeca_estoque))->head = novo;
        novo->no.proximo = anterior;
        (*(*cabeca_estoque))->tail->no.proximo = novo;
        return;
    }
}    

void remover_circular_fim(listaCircular **cabeca_estoque){
    produto *atual;

    atual = (*cabeca_estoque)->head;
    while(1){
        if(atual->no.proximo != (*cabeca_estoque)->tail){
            atual = atual->no.proximo;
        } else {
            free(atual->no.proximo);
            (*cabeca_estoque)->tail = atual;
            atual->no.proximo = (*cabeca_estoque)->head;

            return ;
        }
    } 
}

void remover_circular_inicio(listaCircular **cabeca_estoque){
    produto *prox;

    prox = (*cabeca_estoque)->head->no.proximo;

    free((*cabeca_estoque)->head);
    (*cabeca_estoque)->head = prox;
    (*cabeca_estoque)->tail->no.proximo = prox;

    return;
} 

void listarProduto(listaCircular *cabeca_estoque)
{
    produto *atual;
    
    if (cabeca_estoque->head->id == 0)
        {
            printf("\n========================"
                   "\n  !!!!LISTA VAZIA!!!!"
                   "\n========================\n");
            return;
        }
    
    atual = cabeca_estoque->head;
    while (atual != NULL)
    {
        printf("%-19d", atual->id);
        printf("%-30s", atual->nome);
        printf("%-26.2f", atual->valor);
        printf("%d\n", atual->quantidade);

        atual = atual->no.proximo;
    }

    return;
}






