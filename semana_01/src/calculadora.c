#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao, expoente;
    float num1, num2, resultado;

    while (1) {
        printf("\n--- CALCULADORA ---\n");
        printf("1 - Soma\n");
        printf("2 - Subtracao\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Divisao\n");
        printf("5 - Potenciacao\n");
        printf("0 - Sair\n");

        while (1) {
            printf("Escolha a operacao desejada: ");

            if (scanf("%d", &opcao) == 1) {
                while (getchar() != '\n');
                break;
            } else {
                printf("Erro: digite um numero inteiro para a opcao.\n");
                while (getchar() != '\n');
            }
        }

        if (opcao == 0) {
            printf("Saindo da calculadora. Ate mais!\n");
            break;
        }

        if (opcao >= 1 && opcao <= 4) {
            while (1) {
                printf("Informe o primeiro numero: ");

                if (scanf("%f", &num1) == 1) {
                    while (getchar() != '\n');
                    break;
                } else {
                    printf("Erro: digite um numero valido.\n");
                    while (getchar() != '\n');
                }
            }

            while (1) {
                printf("Informe o segundo numero: ");

                if (scanf("%f", &num2) == 1) {
                    while (getchar() != '\n');
                    break;
                } else {
                    printf("Erro: digite um numero valido.\n");
                    while (getchar() != '\n');
                }
            }
        }

        if (opcao == 5) {
            while (1) {
                printf("Informe a base: ");

                if (scanf("%f", &num1) == 1) {
                    while (getchar() != '\n');
                    break;
                } else {
                    printf("Erro: digite um numero valido para a base.\n");
                    while (getchar() != '\n');
                }
            }

            while (1) {
                printf("Informe o expoente (inteiro): ");

                if (scanf("%d", &expoente) == 1) {
                    while (getchar() != '\n');
                    break;
                } else {
                    printf("Erro: digite um numero inteiro valido para o expoente.\n");
                    while (getchar() != '\n');
                }
            }
        }

        switch (opcao) {
            case 1:
                resultado = num1 + num2;
                printf("Resultado: %.2f\n", resultado);
                break;

            case 2:
                resultado = num1 - num2;
                printf("Resultado: %.2f\n", resultado);
                break;

            case 3:
                resultado = num1 * num2;
                printf("Resultado: %.2f\n", resultado);
                break;

            case 4:
                if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("Resultado: %.2f\n", resultado);
                } else {
                    printf("Erro: divisao por zero nao e permitida.\n");
                }
                break;

            case 5:
                if (expoente < 0) {
                    printf("Erro: a potenciacao com expoente negativo nao e suportada.\n");
                    break;
                } else if (expoente == 0) {
                    printf("Resultado: 1.00\n");
                    break;
                }

                resultado = 1;
                for (int i = 0; i < expoente; i++) {
                    resultado *= num1;
                }
                printf("Resultado: %.2f\n", resultado);
                break;

            default:
                printf("Opcao invalida. Por favor, escolha uma opcao entre 0 e 5.\n");
        }
    }

    return 0;
}
