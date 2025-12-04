#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int* ler_arquivo(const char *caminho, int n) {
    FILE* f = fopen(caminho, "r");
    if(!f) {
        printf("ERRO: Nao abriu %s\n", caminho);
        return NULL;
    }

    int *arr = (int*) malloc(n * sizeof(int));
    if(!arr) {
        printf("ERRO: Falha ao alocal memoria para %d inteiros.\n", n);
        fclose(f);
        return NULL;
    }

    for(int i = 0; i < n; i++) {
        fscanf(f, "%d", &arr[i]);
    }
    fclose(f);
    return arr;
}

void salvar_saida(const char *nome_algoritmo, int n, const char *tipo, int *arr) {
    char caminho[200];
    sprintf(caminho, "Saida/%s_%d_%s.txt", nome_algoritmo, n, tipo);

    FILE* f = fopen(caminho, "w");
    if(!f) return;

    for(int i = 0; i < n; i++) {
        fprintf(f, "%d\n", arr[i]);
    }
    fclose(f);
}

void rodar_teste(int *copia_dados, int n, const char *tipo, const char *nome_algo, FuncaoOrdenacao funcao_sort, FILE* csv) {
    Metricas m;
    resetar_metricas(&m);

    clock_t inicio = clock();
    funcao_sort(copia_dados, n, &m);
    clock_t fim = clock();

    m.tempo_ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

    printf("[%s] N=%d Tipo=%s -> Tempo: %.2fms\n", nome_algo, n, tipo, m.tempo_ms);
    fprintf(csv, "%s, %d, %s, %.4f, %llu, %llu\n", nome_algo, n, tipo, m.tempo_ms, m.comparacoes, m.trocas);
    fflush(csv);

    salvar_saida(nome_algo, n, tipo, copia_dados);
}