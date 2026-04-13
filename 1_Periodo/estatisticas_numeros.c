/*
 * Analisador de Conjunto de Dados
 * Descrição: Lê 10 números e calcula soma, média, os dois maiores, 
 * os dois menores e a contagem de paridade.
 */
#include <stdio.h>
#include <limits.h> // Necessário para usar INT_MIN e INT_MAX

int main() {
    int v, i;
    int soma = 0, pares = 0, impares = 0;
    int maior = INT_MIN, segMaior = INT_MIN;
    int menor = INT_MAX, segMenor = INT_MAX;

    printf("Digite 10 numeros inteiros:\n");

    for (i = 1; i <= 10; i++) {
        printf("%dº numero: ", i);
        scanf("%d", &v);

        soma += v;

        // Contagem de paridade
        if (v % 2 == 0) pares++;
        else impares++;

        // Lógica para Maior e Segundo Maior
        if (v > maior) {
            segMaior = maior;
            maior = v;
        } else if (v > segMaior) {
            segMaior = v;
        }

        // Lógica para Menor e Segundo Menor
        if (v < menor) {
            segMenor = menor;
            menor = v;
        } else if (v < segMenor) {
            segMenor = v;
        }
    }

    printf("\n--- RESULTADOS ESTATISTICOS ---\n");
    printf("Soma: %d | Media: %.2f\n", soma, (float)soma / 10);
    printf("Pares: %d | Impares: %d\n", pares, impares);
    printf("-------------------------------\n");
    printf("Maior: %d\n", maior);
    printf("Segundo Maior: %d\n", segMaior);
    printf("Menor: %d\n", menor);
    printf("Segundo Menor: %d\n", segMenor);

    return 0;
}
