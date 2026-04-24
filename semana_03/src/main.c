#include <stdio.h>

#define TAM 5
#define QTD_DADOS 7

int lerSensor(int dados[], int *indice) {
    int valor = dados[*indice];

    *indice = (*indice + 1) % QTD_DADOS;

    return valor;
}

void inserir(int buffer[], int *pos, int valor, int *soma) {
    *soma = *soma - buffer[*pos] + valor;
    buffer[*pos] = valor;
    *pos = (*pos + 1) % TAM;
}

float calcularMedia(int soma) {
    return (float)soma / TAM;
}

void imprimir(int buffer[], int valor, float media) {
    printf("Valor lido: %d | Buffer: ", valor);

    for (int i = 0; i < TAM; i++) {
        printf("%d ", buffer[i]);
    }

    printf("| Media: %.2f\n", media);
}

int main() {
    int buffer[TAM] = {0};
    int pos = 0;
    int soma = 0;

    int dados[QTD_DADOS] = {10, 20, 30, 40, 50, 60, 70};
    int indiceSensor = 0;

    for (int i = 0; i < 15; i++) {
        int valor = lerSensor(dados, &indiceSensor);

        inserir(buffer, &pos, valor, &soma);

        float media = calcularMedia(soma);

        imprimir(buffer, valor, media);
    }

    return 0;
}
