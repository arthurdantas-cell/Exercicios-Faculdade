#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5
#define TESOUROS 3
#define TENTATIVAS 10

int main() {
    int mat[DIM][DIM] = {0}
    int l, c, encontrados = 0, jogadas = 0;
    srand(time(NULL));

    // Posicionamento estratégico dos tesouros
    for (int t = 0; t < TESOUROS; ) {
        int rL = rand() % DIM, rC = rand() % DIM;
        if (mat[rL][rC] == 0) { 
          mat[rL][rC] = 1; 
          t++; 
        }
    }

    printf("=== CAÇA AO TESOURO 5x5 ===\n");

    while (jogadas < TENTATIVAS && encontrados < TESOUROS) {
        printf("\n[%d/%d] Encontrados: %d. Digite Linha e Coluna (0-4): ", jogadas + 1, TENTATIVAS, encontrados);
        if (scanf("%d %d", &l, &c) != 2) break;

        if (l < 0 || l >= DIM || c < 0 || c >= DIM) {
            printf("Coordenada invalida!\n"); continue;
        }

        if (mat[l][c] == 1) {
            printf("BRILHANTE! Tesouro encontrado.\n");
            mat[l][c] = 2; encontrados++;
        } else if (mat[l][c] == 0) {
            printf("Nada aqui...\n");
            mat[l][c] = -1;
        } else {
            printf("Voce ja cavou aqui!\n"); continue;
        }
        jogadas++;
    }

    printf(encontrados == TESOUROS ? "\nVOCE VENCEU!\n" : "\nGAME OVER!\n");
    return 0;
}
