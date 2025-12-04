#include "sorts.h"

void resetar_metricas(Metricas* m) {
    m->comparacoes = 0;
    m->trocas = 0;
    m->tempo_ms = 0;
}