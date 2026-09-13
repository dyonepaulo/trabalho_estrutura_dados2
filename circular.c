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
                "\n================================\n");

        printf("QUANTIDADE: ");         
        scanf("%d", &(*novo)->quantidade);
        if(getchar() != '\n'){              // artifício para retornar a informação que leitura não foi realizada com sucesso
            printf("\nEntrada invalida. "); 
        }

        printf("VALOR: ");
        scanf("%f", &(*novo)->valor);
        if(getchar() != '\n'){
            printf("\nEntrada inválida. ");
            return -1;
        }

        printf("NOME: ");
        scanf(" %[^\n]", (*novo)->nome);
    }
    
    return 0;
}

void inserir_circular_fim(listaCircular **cabeca_estoque, int **contador_id){
    produto *anterior;
    produto *novo;

    if(inserir(&novo, &contador_id) == -1){  // encerramento por causa da leitura errada
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
        if(atual != (*cabeca_estoque)->tail){  // o *atual avança até a tail
            atual = atual->no.proximo;
            anterior = anterior->no.proximo;
        } else {
            if(atual == (*cabeca_estoque)->head){  // verfica se a lista contém um único elemento
                free((*cabeca_estoque)->head);
                (*cabeca_estoque)->head = NULL;

                printf("Removido com sucesso. \n");
                exibicaoPausada();
                return;
            }

            (*cabeca_estoque)->tail = anterior;  // casos comuns
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

    if(prox == (*cabeca_estoque)->head){        // verifica se a lista é única (1 elemento), se não, a cabeça é removida
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

void listarProduto(listaCircular **cabeca_estoque)
{
    produto *atual = NULL;
    
    if (listaVazia(cabeca_estoque) == 1) 
        return;

    while (atual != (*cabeca_estoque)->head)
    {
        if(atual == NULL)
            atual = (*cabeca_estoque)->head;

        printf("%-19d", atual->id);
        printf("%-30s", atual->nome);
        printf("%-26.2f", atual->valor);
        printf("%d\n", atual->quantidade);

        atual = atual->no.proximo;
    }

    exibicaoPausada();
}

void remover_circular_ID(listaCircular **cabeca_estoque, int ID){
    produto *atual = (*cabeca_estoque)->head;
    produto *anterior = atual;
       
    while(anterior != (*cabeca_estoque)->tail){
        if (anterior == atual) { // verfica o primeiro elemento da lista
            if(atual->id == ID){ // verifica se o ID corresponde
                if(atual->no.proximo == atual){ // verifica o caso onde a lista tem 1 único elemento
                    (*cabeca_estoque)->head = NULL;
                    free(atual);

                    printf("Produto Removido.\n");
                    exibicaoPausada();
                    return;
                } else {
                    (*cabeca_estoque)->head = atual->no.proximo;
                    
                    free(atual);

                    printf("Produto Removido.\n");
                    exibicaoPausada();
                    return;
                }
            } else {
                printf("ID não encontrado.\n");
                exibicaoPausada();
                return;
            }
            atual = atual->no.proximo; // avanço o *atual para que ele fique um nó à frente do *anterior
            continue;
        }

        if(atual == (*cabeca_estoque)->tail){ // verifica o último elemento
            if(atual->id == ID){
                (*cabeca_estoque)->tail = anterior;
                anterior->no.proximo = atual->no.proximo;
                free(atual);

                printf("Produto Removido.\n");
                exibicaoPausada();
                return;
            } else {
                printf("ID não encontrado.\n");
                exibicaoPausada();
                return;
            } 

            if(atual->id == ID){ // remove o produto no caso comum
                if(atual->id == ID){
                    anterior->no.proximo = atual->no.proximo;
                    free(atual);
                    printf("Produto removido.\n");
                    exibicaoPausada();
                    return;
                }
            }
        }

        atual = atual->no.proximo; 
        anterior = anterior->no.proximo;
    }
    
}

int circular_menu(int *contador_id){
    listaCircular *cabeca_estoque = calloc(1, sizeof(listaCircular));

    int opcao, ID;
    
    if ((*contador_id) == 1009)
        cabeca_estoque->head = NULL;
    

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

                scanf("%d", &opcao);

                switch (opcao)
                {
                    case 1: 
                        if (listaVazia(&cabeca_estoque) == 1)
                            break;
                        
                        remover_circular_inicio(&cabeca_estoque);
                        break;
                    case 2:
                        if (listaVazia(&cabeca_estoque) == 1)
                            break;
                        
                        remover_circular_fim(&cabeca_estoque);
                        break;
                    case 3:
                        if (listaVazia(&cabeca_estoque) == 1)
                            break;
                        
                        printf("Digite o ID: ");
                        scanf("%d", &ID);
                        remover_circular_ID(&cabeca_estoque, ID);
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

                break;
            case 4:
                system("clear");

                break;
            case 5:
                system("clear");
                printf("%-18s %-29s %-26s %s\n", "ID", "NOME", "PREÇO", "QUANTIDADE");
                listarProduto(&cabeca_estoque);
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