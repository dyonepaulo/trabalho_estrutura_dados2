#include "produto.h"
#ifndef CIRCULAR_H
#define CIRCULAR_H

int inserir(produto **novo, int ***contador_id);

void inserir_circular(listaCircular *cabeca_estoque, int *contador_id);

void listarProduto(listaCircular *cabeca_estoque);

int circular_menu(listaCircular **cabeca_estoque, int *contador_id);

void esvaziar_circular(listaCircular **cabeca_estoque);

#endif