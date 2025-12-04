#include "sorts.h"

void resetar_metricas(Metricas* m) {
    m->comparacoes = 0;
    m->trocas = 0;
    m->tempo_ms = 0;
}

#define TROCAR(a, b, m) { \
    int temp = *(a); \
    *(a) = *(b); \
    *(b) = temp; \
    (m)->trocas++; \
}


void bubblesort(int *v, int n, Metricas *m) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            m->comparacoes++;
            if(v[j] > v[j + 1]) {
                TROCAR(&v[j], &v[j+1], m);
            }
        }
    }
}

void bubblesort_parada(int *v, int n, Metricas *m) {
    for(int i = 0; i < n - 1; i++) {
        int trocou = 0;
        for(int j = 0; j < n - i - 1; j++) {
            m->comparacoes++;
            if(v[j] > v[j + 1]) {
                TROCAR(&v[j], &v[j + 1], m);
                trocou = 1;
            }
        }
        if(!trocou) break;
    }
}

void insercao_direta(int *v, int n, Metricas *m) {
    for(int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        while(j >= 0) {
            m->comparacoes++;
            if(v[j] > chave) {
                m->trocas++;
                v[j + 1] = v[j];
                j--;
            } else break;
        }
        v[j + 1] = chave;
        m->trocas++;
    }
}

void insercao_binaria(int *v, int n, Metricas *m) {
    for(int i = 1; i < n; i++) {
        int chave = v[i];
        int esq = 0, dir = i - 1;
        int pos;
        while(esq <= dir) {
            m->comparacoes++;
            int meio = (esq + dir) / 2;
            if(chave < v[meio]) {
                dir = meio - 1;
            } else {
                esq = meio + 1;
            }
        }
        pos = esq;
        for(int k = i; k > pos; k--) {
            m->trocas++;
            v[k] = v[k - 1];
        }
        v[pos] = chave;
        m->trocas++;
    }
}

void insercao_ternaria(int *v, int n, Metricas *m) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int esq = 0, dir = i - 1;
        while (dir >= esq) {
            int terco = (dir - esq) / 3;
            int m1 = esq + terco;
            int m2 = dir - terco;

            m->comparacoes++;
            if (chave < v[m1]) {
                dir = m1 - 1;
            } else {
                m->comparacoes++;
                if (chave > v[m2]) {
                    esq = m2 + 1;
                } else {
                    esq = m1 + 1;
                    dir = m2 - 1;
                }
            }
        }
        int pos = esq;
        for (int k = i; k > pos; k--) {
            m->trocas++;
            v[k] = v[k - 1];
        }
        v[pos] = chave;
        m->trocas++;
    }
}

void selecao_direta(int *v, int n, Metricas *m) {
    for(int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < n; j++) {
            m->comparacoes++;
            if(v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        if(min_idx != i) {
            TROCAR(&v[i], &v[min_idx], m);
        }
    }
}

void shellsort(int *v, int n, Metricas *m) {
    //sequencia classica: n/2, n/4, ...
    for(int h = n / 2; h> 0; h /= 2) {
        for(int i = h; i < n; i++) {
            int temp = v[i];
            int j;
            for(j = i; j >= h; j -= h) {
                m->comparacoes++;
                if(v[j - h] > temp) {
                    m->trocas++;
                    v[j] = v[j - h];
                } else break;
            }
            v[j] = temp;
            m->trocas++;
        }
    }
}

static void heapify(int *v, int n, int i, Metricas *m) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    if(esq < n) {
        m->comparacoes++;
        if(v[esq] > v[maior]) {
            maior = esq;
        }
    }
    if(dir < n) {
        m->comparacoes++;
        if(v[dir] > v[maior]) {
            maior = dir;
        }
    }
    if(maior != i) {
        TROCAR(&v[i], &v[maior], m);
        heapify(v, n, maior, m);
    }
}

void heapsort(int *v, int n, Metricas *m) {
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i, m);
    }
    for(int i = n - 1; i > 0; i--) {
        TROCAR(&v[0], &v[i], m);
        heapify(v, i, 0, m);
    }
}

static void merge(int *v, int *temp, int esq, int meio, int dir, Metricas *m) {
    int i = esq;
    int j = meio + 1;
    int k = esq;
    while(i <= meio && j <= dir) {
        m->comparacoes++;
        if(v[i] <= v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
        m->trocas++;
    }
    while(i <= meio) {
        temp[k++] = v[i++];
        m->trocas++;
    }
    while(j <= dir) {
        temp[k++] = v[j++];
        m->trocas++;
    }
    for(i = esq; i <= dir; i++) {
        v[i] = temp[i];
        m->trocas++;
    }
}

static void mergesort_recursivo(int *v, int *temp, int esq, int dir, Metricas *m) {
    if(esq < dir) {
        int meio = esq + (dir - esq) / 2;
        mergesort_recursivo(v, temp, esq, meio, m);
        mergesort_recursivo(v, temp, meio + 1, dir, m);
        merge(v, temp, esq, meio, dir, m);
    }
}

void mergesort(int *v, int n, Metricas *m) {
    int* temp = (int*) malloc(n * sizeof(int));
    if(temp) {
        mergesort_recursivo(v, temp, 0, n - 1, m);
        free(temp);
    }
}

static int particiona(int *v, int low, int high, Metricas *m) {
    int pivo = v[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++) {
        m->comparacoes++;
        if(v[j] <= pivo) {
            i++;
            TROCAR(&v[i], &v[j], m);
        }
    }
    TROCAR(&v[i + 1], &v[high], m);
    return (i + 1);
}

static void quick_recursiva_fim(int *v, int low, int high, Metricas *m) {
    if(low < high) {
        int pi = particiona(v, low, high, m);
        quick_recursiva_fim(v, low, pi - 1, m);
        quick_recursiva_fim(v, pi + 1, high, m);
    }
}

static void quick_recursiva_centro(int *v, int low, int high, Metricas *m) {
    if (low < high) {
        int meio = low + (high - low) / 2;
        TROCAR(&v[meio], &v[high], m);
        int pi = particiona(v, low, high, m);
        quick_recursiva_centro(v, low, pi - 1, m);
        quick_recursiva_centro(v, pi + 1, high, m);
    }
}

static void quick_recursiva_mediana(int *v, int low, int high, Metricas *m) {
    if (low < high) {
        int meio = low + (high - low) / 2;
        int a = v[low], b = v[meio], c = v[high];
        int indice_mediana = high;
        m->comparacoes += 2; 
        if ((a > b) != (a > c)) indice_mediana = low;
        else if ((b > a) != (b > c)) indice_mediana = meio;
        else indice_mediana = high;
        TROCAR(&v[indice_mediana], &v[high], m);
        int pi = particiona(v, low, high, m);
        quick_recursiva_mediana(v, low, pi - 1, m);
        quick_recursiva_mediana(v, pi + 1, high, m);
    }
}

void quicksort_centro(int *v, int n, Metricas *m) {
    quick_recursiva_centro(v, 0, n - 1, m);
}

void quicksort_fim(int *v, int n, Metricas *m) {
    quick_recursiva_fim(v, 0, n - 1, m);
    
}

void quicksort_mediana(int *v, int n, Metricas *m) {
    quick_recursiva_mediana(v, 0, n - 1, m);
}

static int obter_maximo_val(int *v, int n, Metricas *m) {
    int max = v[0];
    for(int i = 1; i < n; i++) {
        m->comparacoes++;
        if(v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

static void counting_sort_digit(int *v, int n, int exp, Metricas *m) {
    int *output = (int*) malloc(n * sizeof(int));
    int count[10] = {0};
    for(int i = 0; i < n; i++) {
        count[(v[i] / exp) % 10]++; 
    }
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for(int i = n - 1; i >= 0; i--) {
        output[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
        m->trocas++;
    }
    for(int i = 0; i < n; i++) {
        v[i] = output[i];
        m->trocas++;
    }
    free(output);
}

void radixsort(int *v, int n, Metricas *m) {
    int max = obter_maximo_val(v, n, m);
    for(int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort_digit(v, n, exp, m);
    }
}

void bucketsort(int *v, int n, Metricas *m) {
    if (n <= 0) return;

    int max = obter_maximo_val(v, n, m);
    int min = v[0]; 
    for(int i=1; i<n; i++) {
        m->comparacoes++;
        if(v[i] < min) min = v[i];
    }
    int num_baldes = n;
    int *contagem_baldes = (int*) calloc(num_baldes, sizeof(int));
    double range = (double)(max - min + 1);
    for (int i = 0; i < n; i++) {
        int pos = (int)(((v[i] - min) / range) * num_baldes);
        if (pos >= num_baldes) pos = num_baldes - 1;
        contagem_baldes[pos]++;
    }
    int **baldes = (int**) malloc(num_baldes * sizeof(int*));
    for(int i=0; i<num_baldes; i++) {
        if(contagem_baldes[i] > 0)
            baldes[i] = (int*) malloc(contagem_baldes[i] * sizeof(int));
        else
            baldes[i] = NULL;
    }
    int *indices = (int*) calloc(num_baldes, sizeof(int));
    for (int i = 0; i < n; i++) {
        int pos = (int)(((v[i] - min) / range) * num_baldes);
        if (pos >= num_baldes) pos = num_baldes - 1;   
        baldes[pos][indices[pos]] = v[i];
        indices[pos]++;
        m->trocas++; 
    }
    int k = 0;
    for (int i = 0; i < num_baldes; i++) {
        if (contagem_baldes[i] > 0) {
            for (int x = 1; x < contagem_baldes[i]; x++) {
                int chave = baldes[i][x];
                int y = x - 1;
                while (y >= 0) {
                    m->comparacoes++;
                    if(baldes[i][y] > chave) {
                        baldes[i][y+1] = baldes[i][y];
                        y--;
                        m->trocas++;
                    } else break;
                }
                baldes[i][y+1] = chave;
                m->trocas++;
            }
            for (int x = 0; x < contagem_baldes[i]; x++) {
                v[k++] = baldes[i][x];
                m->trocas++;
            }
            free(baldes[i]);
        }
    }
    free(baldes);
    free(contagem_baldes);
    free(indices);
}