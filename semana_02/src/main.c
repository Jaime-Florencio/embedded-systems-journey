#include <stdio.h>
#include "menu.h"
#include "entrada.h"
#include "operacoes.h"

int main(){
    int opcao;
    float a, b, resultado;

    while(1){
        mostrar_menu();
        opcao = ler_int();

        if(opcao == 0){
            printf("Encerrando o programa...\n");
            break;
        }

        if(opcao < 0 || opcao > 4){
            printf("Opcao invalida.\n");
            continue;
        }

        printf("Digite o primeiro numero: ");
        a = ler_float();

        printf("Digite o segundo numero: ");
        b = ler_float();

        switch(opcao){
            case 1:
                resultado = somar(a, b);
                printf("Resultado: %.2f\n", resultado);
                break;

            case 2:
                resultado = subtrair(a, b);
                printf("Resultado: %.2f\n", resultado);
                break;

            case 3:
                resultado = multiplicar(a, b);
                printf("Resultado: %.2f\n", resultado);
                break;

            case 4:
                if(b == 0){
                    printf("Erro: divisao por zero nao permitida.\n");
                } else {
                    resultado = dividir(a, b);
                    printf("Resultado: %.2f\n", resultado);
                }
                break;
        }
    }

    return 0;
}
