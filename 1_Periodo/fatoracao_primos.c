/*
 * Decomposição em Fatores Primos
 * Descrição: Recebe um número inteiro e exibe sua fatoração em primos
 * utilizando notação de potência (ex: 2^3 x 3^1).
 */
#include <stdio.h>

int main() {
    int n, divisor = 2;
    int contador;

    printf("Digite um numero inteiro positivo: ");
    if (scanf("%i", &n) != 1 || n <= 0) {
        printf("Erro: O numero deve ser um inteiro positivo maior que zero.\n");
        return 1;
    }

    if (n == 1) {
        printf("O numero 1 nao possui fatoracao em primos (por definicao).\n");
        return 0;
    }

    printf("Fatoracao de %d: ", n);

    while (n > 1) {
        contador = 0;

        // Enquanto o divisor atual dividir n, incrementa a potência
        while (n % divisor == 0) {
            n /= divisor;
            contador++;
        }

        if (contador > 0) {
            printf("%d", divisor);
            if (contador > 1) {
                printf("^%d", contador);
            }
            if (n > 1) {
                printf(" x ");
            }
        }
        divisor++;
    }
    printf("\n");

    return 0;
}
