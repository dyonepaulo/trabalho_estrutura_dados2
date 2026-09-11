#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct produto produto;

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

#endif