#ifndef SORTS_H
#define SORTS_H

#include <stdio.h>
#include <stdlib.h>

//estrutura das metricas 
typedef struct {
    unsigned long long comparacoes;
    unsigned long long trocas;
    double tempo_ms;
} Metricas;

//funcao padrao para todos algoritmos
typedef void (*FuncaoOrdenacao)(int*, int, Metricas*);

void resetar_metricas(Metricas* m);

//algoritmos basicos
void bubblesort(int *v, int n, Metricas *m);
void bubblesort_parada(int *v, int n, Metricas *m);
void insercao_direta(int *v, int n, Metricas *m);
void insercao_binaria(int *v, int n, Metricas *m);
void insercao_ternaria(int *v, int n, Metricas *m);
void selecao_direta(int *v, int n, Metricas *m);
void shellsort(int *v, int n, Metricas *m);

//algoritmos eficientes
void heapsort(int *v, int n, Metricas *m);
void mergesort(int *v, int n, Metricas *m);

//quicksort e variacoes de pivo
void quicksort_centro(int *v, int n, Metricas *m);
void quicksort_fim(int *v, int n, Metricas *m);
void quicksort_mediana(int *v, int n, Metricas *m);

//algoritmos lineares
void radixsort(int *v, int n, Metricas *m);
void bucketsort(int *v, int n, Metricas *m);

#endif