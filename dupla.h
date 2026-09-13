#include "produto.h"
#ifndef DUPLA_H
#define DUPLA_H

int inserir_dupla (produto **inicio, produto **fim, int *contador_id );

int remover_dupla (produto **inicio, produto **fim);

int listar_dupla(produto *inicio);

int listar_dupla_reverso(produto *fim);

int buscar_dupla(produto *inicio);

int menu_dupla(produto **inicio, produto **fim, int *contador_id);

#endif