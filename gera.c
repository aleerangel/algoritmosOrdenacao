#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void erro() {
    fprintf(stderr, "Uso: .\\gera <opcao> <quantidade> <nome_arquivo>\n");
    fprintf(stderr, "Opcoes:\n");
    fprintf(stderr, "  -a : aleatoria\n");
    fprintf(stderr, "  -c : crescente\n");
    fprintf(stderr, "  -d : decrescente\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    //verifica os argumentos
    if(argc != 4) erro();

    char* opcao = argv[1];
    int n = atoi(argv[2]); 
    char* nome_arquivo = argv[3];

    if(n <= 0) {
        fprintf(stderr, "Erro: Quantidade invalida.\n");
        return 1;
    }

    //monta o caminho do arquivo
    char caminho[300];
    sprintf(caminho, "Entrada/%s", nome_arquivo);

    //abre o arquivo
    FILE *f = fopen(caminho, "w");
    if(!f) {
        fprintf(stderr, "Erro: Nao foi possivel criar o arquivo em '%s'\n", caminho);
        return 1;
    }


    srand(time(NULL));

    if(strcmp(opcao, "-c") == 0) {
        //crescente
        for(int i = 1; i <= n; i++) {
            fprintf(f, "%d\n", i);
        }
    } 
    else if(strcmp(opcao, "-d") == 0) {
        //decrescente
        for(int i = n; i >= 1; i--) {
            fprintf(f, "%d\n", i);
        }
    }
    else if(strcmp(opcao, "-a") == 0) {
        //aleatorio
        for(int i =0; i <= n; i++) {
            int num = (rand() << 15) | rand();
            if(num < 0) {
                num = -num; //garante que todos sejam positivos
            }
            fprintf(f, "%d\n", num);
        }
    }
    else{
        fprintf(stderr, "Erro: Opcao invalida.\n");
        fclose(f);
        return 1;
    }

    fclose(f);
    printf("Salvo: %s (%d numeros)\n", caminho, n);

    return 0;
}