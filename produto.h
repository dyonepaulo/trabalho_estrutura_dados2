#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct produto produto;

typedef struct 
{
    int tamanho;
    produto *head;
    produto *tail;

} listaCircular;

typedef struct
{
    produto *proximo, *anterior;
} nos;

struct produto
{
    char nome[50];
    int id, quantidade;
    float valor;
    nos no;
};

int buscar_nome_simples(produto *cabeca_estoque);

int conta_produtos(produto *cabeca_estoque, listaCircular *cabeca_circular);

void exibicaoPausada();

int listaVazia(listaCircular **cabeca_estoque);

#endif