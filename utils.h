#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include "sorts.h"

int* ler_arquivo(const char *caminho, int n);
void salvar_saida(const char *nome_algoritmo, int n, const char *tipo, int *arr);
void rodar_teste(int *copia_dados, int n, const char *tipo, const char *nome_algo, FuncaoOrdenacao funcao_sort, FILE* csv);

#endif