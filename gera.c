#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void erro() {
    fprintf(stderr, "Uso: .\\gera <opcao> <quantidade>\n");
    fprintf(stderr, "Opcoes:\n");
    fprintf(stderr, "  -a : aleatoria\n");
    fprintf(stderr, "  -c : crescente\n");
    fprintf(stderr, "  -d : decrescente\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    //verifica se os argumentos sao suficientes
    if(argc != 3) erro();

    char* opcao = argv[1];
    int n = atoi(argv[2]); 

    if(n <= 0) {
        fprintf(stderr, "Erro: Quantidade invalida.\n");
        return 1;
    }

    srand(time(NULL));

    if(strcmp(opcao, "-c") == 0) {
        //crescente
        for(int i = 1; i <= n; i++) {
            printf("%d\n", i);
        }
    } 
    else if(strcmp(opcao, "-d") == 0) {
        //decrescente
        for(int i = n; i >= 1; i--) {
            printf("%d\n", i);
        }
    }
    else if(strcmp(opcao, "-a") == 0) {
        //aleatorio
        for(int i =0; i <= n; i++) {
            int num = (rand() << 15) | rand();
            if(num < 0) {
                num = -num; //garante que todos sejam positivos
            }
        printf("%d\n", num);
        }
    }
    else{
        fprintf(stderr, "Erro: Opcao invalida.\n");
        erro();
    }

    return 0;
}