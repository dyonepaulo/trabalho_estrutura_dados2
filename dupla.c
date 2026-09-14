#include "dupla.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

int inserir_dupla (produto **inicio, produto **fim, int *contador_id ){

    produto *aux;
    int escolha;
    inicio:
    printf("=======INSERIR=======\n"
        "1. Inserir no início\n"
        "2. Inserir no fim\n"
        "3. Voltar\n"
        "Escolha uma opção: ");
    scanf("%d", &escolha);

    switch (escolha){
        case 1:
            if((*inicio)->id==0){
                (*contador_id)++;
                (*inicio)->id=*contador_id;
                printf("\n================================"
                    "\n     Cadastro do Produto!!"
                    "\n================================\n"
                    "°QUANTIDADE: ");
                scanf("%d", &(*inicio)->quantidade);
                printf("\n°VALOR: ");
                scanf("%f", &(*inicio)->valor);
                printf("\n°NOME: ");
                scanf("%49s", (*inicio)->nome);
                (*inicio)->no.proximo=NULL;
                (*inicio)->no.anterior=NULL;
                (*inicio)->no.anterior = NULL;
                *fim=*inicio;
                printf("\n========================"
                    "\nInserido com sucesso!!!!"
                    "\n========================\n");
                return 0;

            } 
            else {
                aux=(*inicio);
                (*inicio)=calloc(1,sizeof(produto));

                if(*inicio==NULL){
                    printf("\nErro de alocação de memoria!!");
                    return 1;
                }
                (*inicio)->no.proximo=aux;
                (aux)->no.anterior=*inicio;;
                (*contador_id)++;
                (*inicio)->id=*contador_id;
                printf("\n================================"
                    "\n     Cadastro do Produto!!"
                    "\n================================\n"
                    "°QUANTIDADE: ");
                scanf("%d", &(*inicio)->quantidade);
                printf("\n°VALOR: ");
                scanf("%f", &(*inicio)->valor);
                printf("\n°NOME: ");
                scanf("%49s", (*inicio)->nome);
                printf("\n========================"
                    "\nInserido com sucesso!!!!"
                    "\n========================\n");
                return 0;
            }
        break;
        case(2):
            if((*fim)->id==0){
                (*contador_id)++;
                (*fim)->id=*contador_id;
                printf("\n================================"
                    "\n     Cadastro do Produto!!"
                    "\n================================\n"
                    "°QUANTIDADE: ");
                scanf("%d", &(*fim)->quantidade);
                printf("\n°VALOR: ");
                scanf("%f", &(*fim)->valor);
                printf("\n°NOME: ");
                scanf("%49s", (*fim)->nome);
                (*fim)->no.proximo=NULL;
                (*fim)->no.anterior=NULL;
                *inicio=*fim;
                printf("\n========================"
                    "\nInserido com sucesso!!!!"
                    "\n========================\n");
                return 0;

            } 
            else {
                aux=(*fim);
                (*fim)=calloc(1,sizeof(produto));

                if(*fim==NULL){
                    printf("\nErro de alocação de memoria!!");
                    return 1;
                }
                (*fim)->no.anterior=aux;
                (aux)->no.proximo=*fim;;
                (*contador_id)++;
                (*fim)->id=*contador_id;
                printf("\n================================"
                    "\n     Cadastro do Produto!!"
                    "\n================================\n"
                    "°QUANTIDADE: ");
                scanf("%d", &(*fim)->quantidade);
                printf("\n°VALOR: ");
                scanf("%f", &(*fim)->valor);
                printf("\n°NOME: ");
                scanf("%49s", (*fim)->nome);
                printf("\n========================"
                    "\nInserido com sucesso!!!!"
                    "\n========================\n");
                return 0;}
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

int remover_dupla (produto **inicio, produto **fim){

    int escolha;
    inicio:
    printf("=======REMOVER=======\n"
        "1. Remover do início\n"
        "2. Remover do fim\n"
        "3. Remover por ID\n"
        "4. Voltar\n"
        "Escolha uma opção: ");
    scanf("%d", &escolha);
    switch(escolha){
        case 1:
            if(*inicio==NULL){
                printf("\n========================"
                    "\nLista vazia!!!!"
                    "\n========================\n");
                return 0;
            }
            else{
                produto *aux=(*inicio);
                if(*inicio==*fim){
                    *inicio=NULL;
                    *fim=NULL;
                }
                else{
                    (*inicio)=(*inicio)->no.proximo;
                    (*inicio)->no.anterior=NULL;
                }
                free(aux);
                printf("\n========================"
                    "\nRemovido com sucesso!!!!"
                    "\n========================\n");
                return 0;
            }
        case 2:
            if(*fim==NULL){
                printf("\n========================"
                    "\nLista vazia!!!!"
                    "\n========================\n");
                return 0;
            }
            else{
                produto *aux=(*fim);
                if(*inicio==*fim){
                    *inicio=NULL;
                    *fim=NULL;
                }
                else{
                    (*fim)=(*fim)->no.anterior;
                    (*fim)->no.proximo=NULL;
                }
                free(aux);
                printf("\n========================"
                    "\nRemovido com sucesso!!!!"
                    "\n========================\n");
                return 0;
            }
        case 3:
            printf("\nDigite o ID do produto a ser removido: ");
            int id;
            scanf("%d", &id);
            if (*inicio==NULL){
                printf("\n========================"
                    "\nLista vazia!!!!"
                    "\n========================\n");
                return 0;
            }
                produto *aux=(*inicio);
                while(aux!=NULL){
                    if(aux->id==id){
                        if(aux==*inicio && aux==*fim){
                            *inicio=NULL;
                            *fim=NULL;
                        }
                        else if(aux==*inicio){
                            *inicio=aux->no.proximo;
                            if(*inicio!=NULL){
                                (*inicio)->no.anterior=NULL;
                            }
                        }
                        else if(aux==*fim){
                            *fim=aux->no.anterior;
                            if(*fim!=NULL){
                                (*fim)->no.proximo=NULL;
                            }
                        }
                        else{
                            aux->no.anterior->no.proximo=aux->no.proximo;
                            aux->no.proximo->no.anterior=aux->no.anterior;
                        }
                        free(aux);
                        printf("\n========================"
                            "\nRemovido com sucesso!!!!"
                            "\n========================\n");
                        return 0;
                    }
                    aux=aux->no.proximo;
                }
                printf("\n========================"
                    "\nProduto não encontrado!!!!"
                    "\n========================\n");
                return 0;
        case 4:
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

int listar_dupla(produto *inicio){
    if(inicio==NULL){
        printf("\n========================"
            "\nLista vazia!!!!"
            "\n========================\n");
        return 0;
    }
    produto *aux=inicio;
    while(aux!=NULL){
        printf("ID: %d\n", aux->id);
        printf("Nome: %s\n", aux->nome);
        printf("Quantidade: %d\n", aux->quantidade);
        printf("Valor: %.2f\n", aux->valor);
        printf("========================\n");
        aux=aux->no.proximo;
    }
    return 0;
}

int listar_dupla_reverso(produto *fim){
    if(fim==NULL){
        printf("\n========================"
            "\nLista vazia!!!!"
            "\n========================\n");
        return 0;
    }
    produto *aux=fim;
    while(aux!=NULL){
        printf("ID: %d\n", aux->id);
        printf("Nome: %s\n", aux->nome);
        printf("Quantidade: %d\n", aux->quantidade);
        printf("Valor: %.2f\n", aux->valor);
        printf("========================\n");
        aux=aux->no.anterior;
    }
    return 0;
}

int buscar_dupla(produto *inicio){
    if(inicio==NULL){
        printf("\n========================"
            "\nLista vazia!!!!"
            "\n========================\n");
        return 0;
    }
    printf("\nPor favor, digite o nome do produto que deseja buscar: ");
    char nome[50];
    scanf(" %[^\n]", nome);
    produto *aux=inicio;
    int existe=0;
    while(aux!=NULL){
        if(strstr(aux->nome, nome)!=NULL){
            printf("ID: %d\n", aux->id);
            printf("Nome: %s\n", aux->nome);
            printf("Quantidade: %d\n", aux->quantidade);
            printf("Valor: %.2f\n", aux->valor);
            printf("========================\n");
            existe=1;
        }
        aux=aux->no.proximo;
        }
    if(existe==0){
        printf("\n========================"
            "\nProduto não encontrado!!!!"
            "\n========================\n");
    }
    return 0;
}

int menu_dupla(produto **inicio, produto **fim, int *contador_id){
    int escolha;
    inicio:
    printf("=======MENU=======\n"
        "1. Inserir\n"
        "2. Remover\n"
        "3. Listar\n"
        "4. Listar em ordem reversa\n"
        "5. Buscar por nome\n"
        "6. Voltar\n"
        "Escolha uma opção: ");
    scanf("%d", &escolha);
    switch(escolha){
        case 1:
            inserir_dupla(inicio, fim, contador_id);
            break;
        case 2:
            remover_dupla(inicio, fim);
            break;
        case 3:
            listar_dupla(*inicio);
            break;
        case 4:
            listar_dupla_reverso(*fim);
            break;
        case 5:
            buscar_dupla(*inicio);
            break;
        default:
            system("clear");
            printf("===============================\n"
                   "Opção inválida. Tente novamente.\n"
                   "===============================\n\n");
        goto inicio;
    }
}