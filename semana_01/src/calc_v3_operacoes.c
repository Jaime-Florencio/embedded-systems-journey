#include <stdio.h>

/* =========================================================
   DEFINIÇÃO DOS ESTADOS DO SISTEMA
   ---------------------------------------------------------
   Cada macro representa a posição de um bit.

   FLAG_MENU         -> bit 0
   FLAG_SOMAR        -> bit 1
   FLAG_SAIR         -> bit 2
   FLAG_SUBTRAIR     -> bit 3
   FLAG_MULTIPLICAR  -> bit 4
   FLAG_DIVIDIR      -> bit 5
   ========================================================= */
#define FLAG_MENU         0
#define FLAG_SOMAR        1
#define FLAG_SAIR         2
#define FLAG_SUBTRAIR     3
#define FLAG_MULTIPLICAR  4
#define FLAG_DIVIDIR      5

/* =========================================================
   check_flag
   ---------------------------------------------------------
   Verifica se o bit da posição "pos" está ativo em "flags".

   Retorna:
   1 -> bit ativo
   0 -> bit inativo
   ========================================================= */
int check_flag(int flags, int pos) {
    return (flags >> pos) & 1;
}

/* =========================================================
   limpar_buffer
   ---------------------------------------------------------
   Descarta os caracteres restantes do buffer de entrada
   até encontrar o ENTER.
   Isso evita que lixo de entrada atrapalhe leituras futuras.
   ========================================================= */
void limpar_buffer() {
    while (getchar() != '\n');
}

/* =========================================================
   somar
   ---------------------------------------------------------
   Lê dois números reais e mostra a soma.
   ========================================================= */
void somar() {
    float num1, num2, resultado;

    printf("\n=== SOMA ===\n");
    printf("Digite o primeiro numero: ");

    if (scanf("%f", &num1) == 1) {

        printf("Digite o segundo numero: ");

        if (scanf("%f", &num2) == 1) {
            resultado = num1 + num2;
            printf("Resultado: %.2f\n", resultado);
        } 
        else {
            printf("Entrada invalida para o segundo numero.\n");
        }

    } 
    else {
        printf("Entrada invalida para o primeiro numero.\n");
    }

    limpar_buffer();
}

/* =========================================================
   subtrair
   ---------------------------------------------------------
   Lê dois números reais e mostra a subtração.
   ========================================================= */
void subtrair() {
    float num1, num2, resultado;

    printf("\n=== SUBTRACAO ===\n");
    printf("Digite o primeiro numero: ");

    if (scanf("%f", &num1) == 1) {

        printf("Digite o segundo numero: ");

        if (scanf("%f", &num2) == 1) {
            resultado = num1 - num2;
            printf("Resultado: %.2f\n", resultado);
        } 
        else {
            printf("Entrada invalida para o segundo numero.\n");
        }

    } 
    else {
        printf("Entrada invalida para o primeiro numero.\n");
    }

    limpar_buffer();
}

/* =========================================================
   multiplicar
   ---------------------------------------------------------
   Lê dois números reais e mostra a multiplicação.
   ========================================================= */
void multiplicar() {
    float num1, num2, resultado;

    printf("\n=== MULTIPLICACAO ===\n");
    printf("Digite o primeiro numero: ");

    if (scanf("%f", &num1) == 1) {

        printf("Digite o segundo numero: ");

        if (scanf("%f", &num2) == 1) {
            resultado = num1 * num2;
            printf("Resultado: %.2f\n", resultado);
        } 
        else {
            printf("Entrada invalida para o segundo numero.\n");
        }

    } 
    else {
        printf("Entrada invalida para o primeiro numero.\n");
    }

    limpar_buffer();
}

/* =========================================================
   dividir
   ---------------------------------------------------------
   Lê dois números reais e mostra a divisão.

   Diferença importante:
   - se o divisor for 0, o programa pede novamente o segundo
     número, porque esse é um erro corrigível pelo usuário.
   ========================================================= */
void dividir() {
    float num1, num2, resultado;

    printf("\n=== DIVISAO ===\n");
    printf("Digite o primeiro numero: ");

    if (scanf("%f", &num1) == 1) {

        while (1) {
            printf("Digite o segundo numero: ");

            if (scanf("%f", &num2) == 1) {

                if (num2 == 0) {
                    printf("Erro: divisao por zero nao permitida. Tente novamente.\n");
                } 
                else {
                    resultado = num1 / num2;
                    printf("Resultado: %.2f\n", resultado);
                    break;
                }

            } 
            else {
                printf("Entrada invalida para o segundo numero.\n");
                limpar_buffer();
            }
        }

    } 
    else {
        printf("Entrada invalida para o primeiro numero.\n");
    }

    limpar_buffer();
}

/* =========================================================
   main
   ---------------------------------------------------------
   A função principal controla o fluxo do sistema.

   Ideia central:
   - flags guarda o estado atual
   - o while mantém o sistema rodando
   - cada bloco if/else if reage ao estado ativo
   - depois da operação, o sistema volta ao MENU
   ========================================================= */
int main() {
    int flags = 0;
    int opcao;

    /* Estado inicial do sistema: MENU */
    flags = (1 << FLAG_MENU);

    /* Enquanto SAIR não estiver ativo, o sistema continua */
    while (!check_flag(flags, FLAG_SAIR)) {

        /* =========================
           ESTADO: MENU
           ========================= */
        if (check_flag(flags, FLAG_MENU)) {
            printf("\n=== MENU ===\n");
            printf("1 - Somar\n");
            printf("2 - Subtrair\n");
            printf("3 - Multiplicar\n");
            printf("4 - Dividir\n");
            printf("0 - Sair\n");
            printf("Escolha: ");

            if (scanf("%d", &opcao) == 1) {

                if (opcao == 1) {
                    flags = (1 << FLAG_SOMAR);
                }
                else if (opcao == 2) {
                    flags = (1 << FLAG_SUBTRAIR);
                }
                else if (opcao == 3) {
                    flags = (1 << FLAG_MULTIPLICAR);
                }
                else if (opcao == 4) {
                    flags = (1 << FLAG_DIVIDIR);
                }
                else if (opcao == 0) {
                    flags = (1 << FLAG_SAIR);
                }
                else {
                    printf("Opcao invalida.\n");
                    flags = (1 << FLAG_MENU);
                }

                limpar_buffer();
            }
            else {
                printf("Entrada invalida. Por favor, digite um numero.\n");
                limpar_buffer();
                flags = (1 << FLAG_MENU);
            }
        }

        /* =========================
           ESTADO: SOMAR
           ========================= */
        else if (check_flag(flags, FLAG_SOMAR)) {
            somar();
            flags = (1 << FLAG_MENU);
        }

        /* =========================
           ESTADO: SUBTRAIR
           ========================= */
        else if (check_flag(flags, FLAG_SUBTRAIR)) {
            subtrair();
            flags = (1 << FLAG_MENU);
        }

        /* =========================
           ESTADO: MULTIPLICAR
           ========================= */
        else if (check_flag(flags, FLAG_MULTIPLICAR)) {
            multiplicar();
            flags = (1 << FLAG_MENU);
        }

        /* =========================
           ESTADO: DIVIDIR
           ========================= */
        else if (check_flag(flags, FLAG_DIVIDIR)) {
            dividir();
            flags = (1 << FLAG_MENU);
        }
    }

    printf("Programa encerrado.\n");

    return 0;
}
