#include "dupla.h"
#include "simples.h"
#include "circular.h"
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    
    int opcao;
     
    while( opcao != 7 ) {
    
        system("clear");
        printf("===== ESTOQUE DA LOJA =====\n"
            "1. Gerenciar Perecíveis (Simples)\n"
            "2. Gerenciar Não Perecíveis (Dupla)\n"
            "3. Gerenciar Promoções (Circular)\n"
            "0. Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
              
                break;
            case 2:
            
                break;
            case 3:

                break;
            case 0:

                system("clear");
                printf("PROGRAMA ENCERRADO...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}