#include "produto.h"
#ifndef SIMPLES_H
#define SIMPLES_H

int inserir_simples(produto **cabeca_estoque, int *contador_id);

int listar_simples(produto *cabeca_estoque);

int menu_simples(produto **cabeca_estoque, int *contador_id);

int esvaziar_simples(produto *cabeca_estoque);

int remover_simples(produto **cabeca_estoque);

#endif