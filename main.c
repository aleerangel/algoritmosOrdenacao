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
            sprintf(caminho, "Entrada/input_%d_%s.txt", n, tipos[j]);

            //carrega os dados originais
            int *vetor_origem = ler_arquivo(caminho, n);
            if(!vetor_origem) continue;

            //vetor auxiliar para os testes
            int *vetor_teste = (int*) malloc(n * sizeof(int));

            // 1. Bubble Sort
            memcpy(vetor_teste, vetor_origem, n * sizeof(int));
            rodar_teste(vetor_teste, n, tipos[j], "BubbleSort", bubblesort, csv);

            // 2. Bubble Sort (Stop)
            memcpy(vetor_teste, vetor_origem, n * sizeof(int));
            rodar_teste(vetor_teste, n, tipos[j], "BubbleSortParada", bubblesort_parada, csv);

            // 3. Selection Direct
            memcpy(vetor_teste, vetor_origem, n * sizeof(int));
            rodar_teste(vetor_teste, n, tipos[j], "SelecaoDireta", selecao_direta, csv);

            // 4. Insertion Direct
            memcpy(vetor_teste, vetor_origem, n * sizeof(int));
            rodar_teste(vetor_teste, n, tipos[j], "InsercaoDireta", insercao_direta, csv);

            // 5. Insertion Binary
            memcpy(vetor_teste, vetor_origem, n * sizeof(int));
            rodar_teste(vetor_teste, n, tipos[j], "InsercaoBinaria", insercao_binaria, csv);

            // 6. Insertion Ternary
            memcpy(vetor_teste, vetor_origem, n * sizeof(int));
            rodar_teste(vetor_teste, n, tipos[j], "InsercaoTernaria", insercao_ternaria, csv);

            // 7. Shell Sort
            memcpy(vetor_teste, vetor_origem, n * sizeof(int));
            rodar_teste(vetor_teste, n, tipos[j], "ShellSort", shellsort, csv);

            // 8. Heap Sort
            memcpy(vetor_teste, vetor_origem, n * sizeof(int));
            rodar_teste(vetor_teste, n, tipos[j], "HeapSort", heapsort, csv);

            // 9. Merge Sort
            memcpy(vetor_teste, vetor_origem, n * sizeof(int));
            rodar_teste(vetor_teste, n, tipos[j], "MergeSort", mergesort, csv);

            // 10. Quick Sort (Pivô Fim)
            memcpy(vetor_teste, vetor_origem, n * sizeof(int));
            rodar_teste(vetor_teste, n, tipos[j], "QuickSortFim", quicksort_fim, csv);

            // 11. Quick Sort (Pivô Centro)
            memcpy(vetor_teste, vetor_origem, n * sizeof(int));
            rodar_teste(vetor_teste, n, tipos[j], "QuickSortCentro", quicksort_centro, csv);

            // 12. Quick Sort (Pivô Mediana)
            memcpy(vetor_teste, vetor_origem, n * sizeof(int));
            rodar_teste(vetor_teste, n, tipos[j], "QuickSortMediana", quicksort_mediana, csv);

            // 13. Radix Sort
            memcpy(vetor_teste, vetor_origem, n * sizeof(int));
            rodar_teste(vetor_teste, n, tipos[j], "RadixSort", radixsort, csv);

            // 14. Bucket Sort
            memcpy(vetor_teste, vetor_origem, n * sizeof(int));
            rodar_teste(vetor_teste, n, tipos[j], "BucketSort", bucketsort, csv);

            printf("--- Fim do lote N=%d Tipo=%s ---\n", n, tipos[j]);


            free(vetor_teste);
            free(vetor_origem);
        }
    }

    fclose(csv);
    printf("\nProcesso finalizado.\n");
    
    return 0;
}