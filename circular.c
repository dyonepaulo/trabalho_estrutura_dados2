#include "produto.h"
#include "circular.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
                "\n================================\n");

        printf("QUANTIDADE: ");         
        scanf("%d", &(*novo)->quantidade);
        if(getchar() != '\n'){              
            printf("\nEntrada invalida. "); 
            return -1;
        }

        printf("VALOR: ");
        scanf("%f", &(*novo)->valor);
        if(getchar() != '\n'){
            printf("\nEntrada inválida. ");
            return -1;
        }

        printf("NOME: ");
        scanf(" %49[^\n]", (*novo)->nome);
    }
    
    return 0;
}

void inserir_circular_fim(listaCircular **cabeca_estoque, int **contador_id){
    produto *anterior;
    produto *novo;

    if(inserir(&novo, &contador_id) == -1){  
        exibicaoPausada();   
        return;
    }

    if((*cabeca_estoque)->head == NULL){
        (*cabeca_estoque)->head = novo;  
        (*cabeca_estoque)->tail = novo;
        novo->no.proximo = novo;       

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

    if(inserir(&novo, &contador_id) == -1){
        exibicaoPausada();
        return;
    }

    if((*cabeca_estoque)->head == NULL){
        (*cabeca_estoque)->head = novo;
        (*cabeca_estoque)->tail = novo;        
        novo->no.proximo = (*cabeca_estoque)->head;

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
    produto *anterior;

    atual = (*cabeca_estoque)->head;
    anterior = (*cabeca_estoque)->tail;

    while(1){                                
        if(atual != (*cabeca_estoque)->tail){  
            atual = atual->no.proximo;
            anterior = anterior->no.proximo;
        } else {
            if(atual == (*cabeca_estoque)->head){ 
                free((*cabeca_estoque)->head);
                (*cabeca_estoque)->head = NULL;

                printf("Removido com sucesso. \n");
                exibicaoPausada();
                return;
            }

            (*cabeca_estoque)->tail = anterior;  
            anterior = atual->no.proximo;
            free(atual);
        
            printf("Removido com sucesso. \n");
            exibicaoPausada();
            return;
        }
    } 
}

void remover_circular_inicio(listaCircular **cabeca_estoque){
    produto *prox;

    prox = (*cabeca_estoque)->head->no.proximo;

    if(prox == (*cabeca_estoque)->head){        
        free((*cabeca_estoque)->head);
        (*cabeca_estoque)->head = NULL;

        printf("Removido com sucesso. \n");
        exibicaoPausada();
        return;
    }

    free((*cabeca_estoque)->head);
    (*cabeca_estoque)->head = prox;
    (*cabeca_estoque)->tail->no.proximo = prox;

    printf("Removido com sucesso. \n");
    exibicaoPausada();
    return;
} 

void listarProduto(listaCircular *cabeca_estoque)
{
    produto *atual = NULL;
    
    if (listaVazia(cabeca_estoque) == 1) 
        return;

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

    exibicaoPausada();
}

void remover_circular_ID(listaCircular **cabeca_estoque, int ID) {
    if ((*cabeca_estoque)->head == NULL) {
        printf("Estoque vazio.\n");
        exibicaoPausada();
        return;
    }

    produto *atual = (*cabeca_estoque)->head;
    produto *anterior = NULL;

    do {
        if (atual->id == ID) {
            if (atual->no.proximo == atual) {
                (*cabeca_estoque)->head = NULL;
                (*cabeca_estoque)->tail = NULL;
                free(atual);
                printf("Produto Removido.\n");
                exibicaoPausada();
                return;
            }

            if (atual == (*cabeca_estoque)->head) {
                (*cabeca_estoque)->head = atual->no.proximo;
                (*cabeca_estoque)->tail->no.proximo = (*cabeca_estoque)->head;
                free(atual);
                printf("Produto Removido.\n");
                exibicaoPausada();
                return;
            }

            if (atual == (*cabeca_estoque)->tail) {
                anterior->no.proximo = atual->no.proximo;
                (*cabeca_estoque)->tail = anterior;
                free(atual);
                printf("Produto Removido.\n");
                exibicaoPausada();
                return;
            }

            anterior->no.proximo = atual->no.proximo;
            free(atual);
            printf("Produto Removido.\n");
            exibicaoPausada();
            return;
        }

        anterior = atual;
        atual = atual->no.proximo;
    } while (atual != (*cabeca_estoque)->head);

    printf("ID não encontrado.\n");
    exibicaoPausada();
}

void esvaziar_circular(listaCircular **cabeca_estoque){
    if ((*cabeca_estoque)->head == NULL) {
        system("clear");
        printf("===========================\n"
                "Estoque já está desocupado.\n"
                "===========================\n\n");
        
        exibicaoPausada();
        return;
    }

    produto *atual = (*cabeca_estoque)->head;
    produto *prox = atual;

    do {
        prox = atual->no.proximo; 
        free(atual);
        atual = prox;
        
    } while(atual != (*cabeca_estoque)->head);

    (*cabeca_estoque)->head = NULL;
    (*cabeca_estoque)->tail = NULL;

    system("clear");
    printf("===========================\n"
            "Estoque desocupado.\n"
            "===========================\n\n");
        
    exibicaoPausada();
    return;
}

void atualizar_circular(listaCircular **cabeca_estoque, int ID){
    produto *atual = (*cabeca_estoque)->head;
    int qtd;

    do {
        if(atual->id == ID){
            system("clear");
            printf("===========================\n"
                    "   Produto Encontrado.\n"
                    "===========================\n\n");

            printf("%-18s %-29s %-26s %s\n", "ID", "NOME", "VALOR", "QUANTIDADE");
            printf("%-19d", atual->id);
            printf("%-30s", atual->nome);
            printf("%-26.2f", atual->valor);
            printf("%d\n", atual->quantidade);
            
            printf("Digite o valor desejado: ");
            scanf("%d", &qtd);

            atual->quantidade = qtd;
            printf( "===========================\n"
                    "  Quantidade modificada.\n"
                    "===========================\n\n");

            return;
        }
        
        atual = atual->no.proximo;
    } while (atual != (*cabeca_estoque)->head);

    printf("===========================\n"
            "Produto não encontrado.\n"
            "===========================\n\n");
}

int buscar_nome_circular(listaCircular *cabeca_estoque)
{
    int encontrou = 0;

    if (cabeca_estoque->head == NULL)
    {
        system("clear");
        printf("\n========================"
               "\n  !!!!LISTA VAZIA!!!!"
               "\n========================\n");
        exibicaoPausada();
        return 0;
    }

    system("clear");
    char busca[50];
    
    printf("\n========================"
           "\nDigite o nome do produto"
           "\n========================\n");
    scanf(" %49[^\n]", busca);

    
    
    system("clear");
    produto *atual = cabeca_estoque->head;
    
    do
    {
        if (strstr(atual->nome, busca) != NULL)
        {
            encontrou++;

            if (encontrou == 1)
            {
                printf("\n========================="
                       "\n!!!PRODUTOS ENCONTRADOS!!!"
                       "\n=========================\n"
                       "%-18s %-29s %-26s %s \n",
                       "ID", "NOME", "PREÇO", "QUANTIDADE");
            }
            
            printf("%-19d", atual->id);
            printf("%-30s", atual->nome);
            printf("%-26.2f", atual->valor);
            printf("%d\n", atual->quantidade);
        }
        
        atual = atual->no.proximo;
        
    } while (atual != cabeca_estoque->head);
    
    
    if (encontrou > 0)
    {
        exibicaoPausada();
        return 0;
    }
    
    system("clear");
    printf("\n========================="
           "\n !!!!NÃO ENCONTRADO!!!!"
           "\n=========================\n");
    exibicaoPausada();
    return 0;
}

int circular_menu(listaCircular **cabeca_estoque, int *contador_id){
    int opcao, ID;
    
    if ((*contador_id) == 1009)
        (*cabeca_estoque)->head = NULL;
    

    while(1){
        system("clear");
        printf("===== GERENCIAR PROMOÇÕES =====\n"
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
                    case 1: inserir_circular_inicio(cabeca_estoque, &contador_id);
                            break;
                    case 2: inserir_circular_fim(cabeca_estoque, &contador_id);
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

                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1: 
                    if (listaVazia(*cabeca_estoque) == 1)
                        break;
                    
                    remover_circular_inicio(cabeca_estoque);
                    break;
                case 2:
                    if (listaVazia(*cabeca_estoque) == 1)
                        break;
                    
                    remover_circular_fim(cabeca_estoque);
                        break;
                case 3:
                    if (listaVazia(*cabeca_estoque) == 1)
                        break;
                    
                    printf("Digite o ID: ");
                    scanf("%d", &ID);
                    remover_circular_ID(cabeca_estoque, ID);
                    break;
                case 4: 
                
                    break;

                default: 
                    printf("\nEntrada inválida.");
                    break;
                }

                break;
            case 3:
                system("clear");
                buscar_nome_circular(*cabeca_estoque);
                break;
            case 4:
                system("clear");
                Atualizar_quantidade((*cabeca_estoque)->head);
                break;
            case 5:
                system("clear");
                printf("%-18s %-29s %-26s %s\n", "ID", "NOME", "PREÇO", "QUANTIDADE");
                listarProduto(*cabeca_estoque);
                break;
            case 6:
                system("clear");
                conta_produtos(NULL, *cabeca_estoque);
                break;
            case 7:
                system("clear");
                esvaziar_circular(cabeca_estoque);
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