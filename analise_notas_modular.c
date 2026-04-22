#include <stdio.h>

/* * Objetivo: Gerar a Sequência de Fibonacci até um termo N.
 * Complexidade de Tempo: O(n) - Execução linear e eficiente.
 * Complexidade de Espaço: O(1) - Uso otimizado de memória (apenas 3 variáveis).
 */

void gerarFibonacci(int n) {
    long long int t1 = 0, t2 = 1, proximoTermo;

    printf("Sequencia de Fibonacci (%d termos):\n", n);

    for (int i = 1; i <= n; ++i) {
        printf("%lld ", t1);
        proximoTermo = t1 + t2;
        t1 = t2;
        t2 = proximoTermo;
    }
    printf("\n");
}

int main() {
    int n;

    printf("Digite a quantidade de termos que deseja ver: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, digite um numero positivo.\n");
    } else {
        gerarFibonacci(n);
    }

    return 0;
}
