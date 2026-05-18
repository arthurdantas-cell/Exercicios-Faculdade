#include <stdio.h>

void ordenar_vetor(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main() {
    int tam = 30, vet[30];
    int maiorFreq = 0, menorFreq = 31;
    int maisRepete, menosRepete;

    for (int i = 0; i < tam; i++) {
        printf("Valor %d/%d: ", i + 1, tam);
        scanf("%d", &vet[i]);
    }

    ordenar_vetor(vet, tam);

    printf("\n--- RELATORIO DE FREQUENCIA ---\n");
    int freq = 1;
    for (int i = 0; i < tam; i++) {
        if (i < tam - 1 && vet[i] == vet[i + 1]) {
            freq++;
        } else {
            printf("Numero %d: %d vez(es)\n", vet[i], freq);
            
            if (freq > maiorFreq) { 
              maisRepete = vet[i]; maiorFreq = freq; 
            }
            if (freq < menorFreq) {
              menosRepete = vet[i]; menorFreq = freq; 
            }
            freq = 1;
        }
    }

    printf("\nEstatistica: Mais comum: %d (%d vezes) | Raro: %d (%d vezes)\n", maisRepete, maiorFreq, menosRepete, menorFreq);
    return 0;
}
