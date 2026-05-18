#include <stdio.h>

// Função que calcula a mediana
float mediana(int valor1, int valor2, int tam) {
    float med;
    if (tam % 2 == 0) {
        med = (float)(valor1 + valor2) / 2;
    } else {
        med = (float)valor1;
    }
    return med;
}

int main() {
    int i, j, tam;
    int aux = 0;
    int valor1, valor2;

    printf("Digite o tamanho do vetor: \n");
    scanf("%i", &tam);

    int vet[tam]; 

    
    for (i = 0; i < tam; i++) {
        printf("Digite o %io valor: ", i + 1);
        scanf("%i", &vet[i]);
    }

    // Algoritmo de Ordenação (Bubble Sort)
    for (i = 0; i < tam; i++) {
        for (j = i + 1; j < tam; j++) {
            if (vet[i] > vet[j]) {
                aux = vet[j];
                vet[j] = vet[i];
                vet[i] = aux;
            }
        }
    }

    // Exibição do vetor ordenado
    printf("\nSequencia ordenada: ");
    for (i = 0; i < tam; i++) {
        printf("%i ", vet[i]);
    }

    
    if (tam % 2 == 0) {
        valor1 = vet[tam / 2];
        valor2 = vet[tam / 2 - 1];
    } else {
        valor1 = vet[tam / 2];
        valor2 = 0;
    }

    
    printf("\nMediana: %.2f\n", mediana(valor1, valor2, tam));

    return 0;
}
