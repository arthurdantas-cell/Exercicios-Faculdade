/*
 * Validador de Códigos para Sorteio
 * Descrição: Filtra números em um intervalo baseado em propriedades matemáticas 
 * (múltiplos de 4 ou 6 e paridade da soma dos dígitos).
 */
#include <stdio.h>

int main() {
    int x, y, i;
    int maiorCodigo = -1;
    int totalSomaDigitos = 0;
    int qtdValidos = 0;

    printf("Informe o valor (X): ");
    scanf("%i", &x);
    printf("Informe o valor (Y): ");
    scanf("%i", &y);

    if (x < y && x > 0) {
        printf("\nCodigos Validados:\n");
        for (i = x; i <= y; i++) {
            
            // Regra 1: Múltiplo de 4 OU 6, mas não de ambos (Operador XOR lógico)
            if ((i % 4 == 0) != (i % 6 == 0)) {
                int numAux = i;
                int somaDigitos = 0;

                // Regra 2: Cálculo da soma dos dígitos
                while (numAux > 0) {
                    somaDigitos += numAux % 10;
                    numAux /= 10;
                }

                // Regra 3: Soma dos dígitos deve ser ímpar
                if (somaDigitos % 2 != 0) {
                    printf(" -> %i\n", i);
                    qtdValidos++;
                    totalSomaDigitos += somaDigitos;

                    if (i > maiorCodigo) {
                        maiorCodigo = i;
                    }
                }
            }
        }

        // Exibição dos resultados estatísticos
        if (qtdValidos > 0) {
            printf("\n--- RESULTADOS ---");
            printf("\nTotal encontrados: %i", qtdValidos);
            printf("\nMaior codigo: %i", maiorCodigo);
            printf("\nMedia das somas: %.2f\n", (float)totalSomaDigitos / qtdValidos);
        } else {
            printf("\nNenhum codigo atende aos criterios no intervalo informado.\n");
        }
    } else {
        printf("Erro: Certifique-se de que X < Y e ambos sejam positivos.\n");
    }

    return 0;
}
