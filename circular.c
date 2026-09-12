#include "circular.h"
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>

int inserir(produto **novo, int ***contador_id){
    (*novo) = calloc(1, sizeof(produto));

    if ((*novo) == NULL) {
        printf("Erro: falha na alocação de memória\n");
        exit(1);
    }

    if ((*novo)->id == 0) {
        system("clear");

        (*(*(*contador_id)))++;
        (*novo)->id = (*(*(*contador_id)))++;
        printf( "\n================================"
                "\n     Cadastro do Produto!!"
                "\n================================\n"
                "QUANTIDADE: ");
        scanf("%d", &(*novo)->quantidade);
        printf("VALOR: ");
        scanf("%f", &(*novo)->valor);
        printf("NOME: ");
        scanf(" % [^\n]", (*novo)->nome);
    }
    
    return 0;
}

void inserir_circular_fim(listaCircular **cabeca_estoque, int **contador_id){
    produto *anterior;
    produto *novo;

    inserir(&novo, &contador_id);

    if((*cabeca_estoque) == NULL){
        (*cabeca_estoque)->head = novo;
        (*cabeca_estoque)->tail = novo;

        return;
    } else {
        anterior = (*cabeca_estoque)->tail;

        anterior->no.proximo = novo;
        (*cabeca_estoque)->tail = novo;
        novo->no.proximo = (*cabeca_estoque)->head;
        return;
    }      
}

void inserir_circular_inicio(listaCircular **cabeca_estoque, int **contador_id){
    produto *anterior;
    produto *novo;

    inserir(&novo, &contador_id);

    if((*cabeca_estoque)->head == NULL){
        (*cabeca_estoque)->head = novo;
        (*cabeca_estoque)->tail = novo;        
        
        return;
    } else {
        anterior = (*cabeca_estoque)->head;

        (*cabeca_estoque)->head = novo;
        novo->no.proximo = anterior;
        (*cabeca_estoque)->tail->no.proximo = novo;
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
    char opcao;
    produto *atual = NULL;
    
    if (cabeca_estoque->head->id == 0)
        {
            printf("\n========================"
                   "\n  !!!!LISTA VAZIA!!!!"
                   "\n========================\n");
            return;
        }

    while (atual != cabeca_estoque->head)
    {
        if(atual == NULL)
            atual = cabeca_estoque->head;

        printf("%-19d", atual->id);
        printf("%-30s", atual->nome);
        printf("%-26.2f", atual->valor);
        printf("%d\n", atual->quantidade);

        atual = atual->no.proximo;
    }

    printf("\n\nAperte Enter para sair");
    getchar();
    while(getchar() != '\n')
        ;
    return;
}

int circular_menu(int *contador_id){
    listaCircular *cabeca_estoque = calloc(1, sizeof(listaCircular));

    int opcao;
    
    if ((*contador_id) == 1009)
        cabeca_estoque->head = NULL;
    

    while(1){
        system("clear");
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
        
        if(scanf("%d", &opcao) == 0){

            printf("OPÇÃO INVÁLIDA.\n\n\n\n\n\n");
            while(getchar() != '\n');

        } else {
            switch (opcao)
            {
            case 1:
                system("clear");
                printf("===== INSERIR PRODUTO =====\n"
                        "Escolha uma opção:\n"
                        "1. Inserir no início\n"
                        "2. Inserir no fim\n"
                        "3. Sair\n"
                        "\n>>> ");

                scanf("%d", &opcao);  

                switch (opcao)
                {
                    case 1: inserir_circular_inicio(&cabeca_estoque, &contador_id);
                            break;
                    case 2: inserir_circular_fim(&cabeca_estoque, &contador_id);
                            break;
                    case 3: break;

                    default:printf("\nEntrada inválida.");
                            break;
                }
                break;
            case 2:
                system("clear");
                printf("===== REMOVER PRODUTO =====\n"
                        "Escolha uma opção:\n"
                        "1. Remover no início\n"
                        "2. Remover no fim\n"
                        "3. Remover por ID\n"
                        "4. Voltar\n"
                        "\n>>> ");

                switch (opcao)
                {
                    case 1: remover_circular_inicio(&cabeca_estoque);
                            break;
                    case 2: remover_circular_fim(&cabeca_estoque);
                            break;
                    case 3: //remover_circular_ID(&cabeca_estoque);
                            break;
                    case 4: break;

                    default: printf("\nEntrada inválida.");
                            break;
                }

                break;
            case 3:
                system("clear");

                break;
            case 4:
                system("clear");

                break;
            case 5:
                system("clear");
                printf("%-18s %-29s %-26s %s\n", "ID", "NOME", "PREÇO", "QUANTIDADE");
                listarProduto(cabeca_estoque);
                break;
            case 6:
                system("clear");

                break;
            case 7:
                system("clear");

                break;
            case 0:
                return 0;

            default:
                printf("===============================\n"
                        "Opção inválida. Tente novamente.\n"
                        "===============================\n\n");
                break;
            }
        }
    }
}