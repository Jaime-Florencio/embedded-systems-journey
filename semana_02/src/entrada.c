#include <stdio.h>
#include "entrada.h"

float ler_float(){
    float valor;

    while(1){
        if(scanf("%f", &valor) == 1){
            while(getchar() != '\n');
            return valor;
        } else {
            printf("Entrada invalida. Digite novamente: ");
            while(getchar() != '\n');
        }
    }
}

int ler_int(){
    int valor;

    while(1){
        if(scanf("%d", &valor) == 1){
            while(getchar() != '\n');
            return valor;
        } else {
            printf("Entrada invalida. Digite novamente: ");
            while(getchar() != '\n');
        }
    }
}
