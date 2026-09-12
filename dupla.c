#include "dupla.h"
#include <stdio.h>
#include <stdlib.h>
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
}