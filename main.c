#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorts.h"
#include "utils.h"

int main() {
    int tamanhos[] = {10000, 100000, 500000};
    const char *tipos[] = {"aleatorio", "crescente", "decrescente"};

    FILE *csv = fopen("resultados.csv", "w");
    if(!csv) {
        printf("Erro ao criar CSV");
        return 1;
    }

    fprintf(csv, "Algoritmo,N,Tipo,Tempo(ms),Comparacoes,Trocas\n");

    //loop dos tamanhos
    for(int i = 0; i < 3; i++) {
        int n = tamanhos[i];

        //loop dos tipos
        for (int j = 0; j < 3; j++) {
            char caminho[100];
            sprintf(caminho, "Saida/input_%d_%s.txt", n, tipos[j]);

            //carrega os dados originais
            int *vetor_origem = ler_arquivo(caminho, n);
            if(!vetor_origem) continue;

            //vetor auxiliar para os testes
            int *vetor_teste = (int*) malloc(n * sizeof(int));

            //testes dos algoritmos



            free(vetor_teste);
            free(vetor_origem);
        }
    }

    fclose(csv);
    printf("\nProcesso finalizado.\n");
    
    return 0;
}