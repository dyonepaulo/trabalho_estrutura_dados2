# trabalho_estrutura_dados2

INTEGRANTES; Dyone Paulo Trindade da Silva, Pablo Donato da Silva e Leonardo Santos da Silva


    Trabalho acadêmico de Estruturas de Dados escrito em C, que implementa um sistema de gerenciamento de estoque usando três estruturas de dados encadeadas distintas, cada uma associada a uma categoria de produto.

    A busca por nome usa strstr, ou seja, aceita correspondências parciais. As operações de remoção e esvaziamento liberam a memória com free. Ao sair (opção 0), o programa chama esvaziar_simples e esvaziar_circular e libera as cabeças alocadas.

O programa mantém três estoques independentes em memória, cada um manipulado pela sua estrutura:

*1 - Perecíveis → Lista Simples (menu_simples): inserir no início/fim, remover no início/fim/por ID, buscar por nome, atualizar quantidade, listar, contar e esvaziar.*

*2 - Não Perecíveis → Lista Dupla (menu_dupla): inserir/remover início/fim, remover por ID, listar para frente e em ordem reversa, e buscar por nome.*

*3 - Promoções → Lista Circular (circular_menu): inserir/remover início/fim, remover por ID, buscar por nome, atualizar quantidade, listar, contar e esvaziar.*

    
