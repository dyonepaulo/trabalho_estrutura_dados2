#include "dupla.h"
#include "simples.h"
#include "circular.h"
#include "produto.h"
#include <stdio.h>

int main() {
    
    int opcao = 100;
     
    while( opcao != 7 ) {

        printf("===== ESTOQUE DA LOJA =====\n"
            "1. Gerenciar Perecíveis (Simples)\n"
            "2. Gerenciar Não Perecíveis (Dupla)\n"
            "3. Gerenciar Promoções (Circular)\n"
            "0. Sair\n");
            
        printf("\nEscolha uma opção: ");

        
        switch(opcao) {
            case 1:
              
                break;
            case 2:
               
                break;
            case 3:
               
            case 0:

                printf("Saindo do programa...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }


    }
}