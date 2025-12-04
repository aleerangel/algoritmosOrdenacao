#ifndef SORTS_H
#define SORTS_H

#include <stdio.h>

typedef struct {
    unsigned long long comparacoes;
    unsigned long long trocas;
    double tempo_ms;
} Metricas;

typedef void (*FuncaoOrdenacao)(int*, int, Metricas*);

void resetar_metricas(Metricas* m);

#endif