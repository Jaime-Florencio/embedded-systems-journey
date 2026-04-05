#include <stdio.h>

int main() {
    int opcao;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1 - Dizer Ola\n");
        printf("2 - Mostrar numero\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Ola!\n");
        } else if (opcao == 2) {
            printf("Numero fixo: 42\n");
        } else if (opcao == 0) {
            printf("Saindo...\n");
            break;
        } else {
            printf("Opcao invalida\n");
        }
    }

    return 0;
}
