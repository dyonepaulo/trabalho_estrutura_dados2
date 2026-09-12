#include "produto.h"
#ifndef CIRCULAR_H
#define CIRCULAR_H

typedef struct 
{
    int tamanho;
    produto *head;
    produto *tail;

} listaCircular;

void inserir(produto **novo, int ***contador_id);

void inserir_circular(listaCircular **cabeca_estoque, int *contador_id);

void inserir_circular_fim(listaCircular ***cabeca_estoque, int **contador_id);

void inserir_circular_inicio(listaCircular ***cabeca_estoque, int **contador_id);   

void remover_circular_fim(listaCircular **cabeca_estoque);

void remover_circular_inicio(listaCircular **cabeca_estoque);

void listarProduto(listaCircular *cabeca_estoque);

#endif