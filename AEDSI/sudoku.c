#include <stdio.h>
#include <stdbool.h>

// Funções
void lerTabuleiro(int sudoku[9][9]);
void exibirTabuleiro(int sudoku[9][9]);
void ordenar(int vetor[9]);
bool validarLinhas(int sudoku[9][9]);
bool validarColunas(int sudoku[9][9]);
bool validarQuadrantes(int sudoku[9][9]);

int main() {
    int sudoku[9][9];

    printf("=== VALIDADOR DE SUDOKU PROFISSIONAL ===\n");
    lerTabuleiro(sudoku);
    
    printf("\nTabuleiro inserido:\n");
    exibirTabuleiro(sudoku);

    if (validarLinhas(sudoku) && validarColunas(sudoku) && validarQuadrantes(sudoku)) {
        printf("\n? PARABENS! O SUDOKU ESTA COMPLETAMENTE VALIDO!\n");
    } else {
        printf("\n? SUDOKU INVALIDO! Revise as regras de repeticao.\n");
    }

    return 0;
}
	// Preencher a matriz
	void lerTabuleiro(int sudoku[9][9]) {
	    printf("Digite os 81 valores (0-9):\n");
	    for (int i = 0; i < 9; i++) {
	        for (int j = 0; j < 9; j++) {
	            scanf("%d", &sudoku[i][j]);
	        }
	    }
	}

	// Matriz formatada
	void exibirTabuleiro(int sudoku[9][9]) {
	    for (int i = 0; i < 9; i++) {
	        if (i % 3 == 0 && i != 0) printf(" ------+-------+------\n");
	        for (int j = 0; j < 9; j++) {
	            if (j % 3 == 0 && j != 0) printf(" |");
	            printf(" %d", sudoku[i][j]);
	        }
	        printf("\n");
	    }
	}
	
	//Bubble Sort 
	void ordenar(int vetor[9]) {
	    for (int x = 0; x < 8; x++) {
	        for (int y = x + 1; y < 9; y++) {
	            if (vetor[x] > vetor[y]) {
	                int temp = vetor[y];
	                vetor[y] = vetor[x];
	                vetor[x] = temp;
	            }
	        }
	    }
	}
	
	// Verifica as 9 linhas
	bool validarLinhas(int sudoku[9][9]) {
	    int vetor[9];
	    for (int i = 0; i < 9; i++) {
	        for (int j = 0; j < 9; j++) vetor[j] = sudoku[i][j];
	        ordenar(vetor);
	        for (int x = 0; x < 9; x++) {
	            if (vetor[x] != x + 1) return false;
	        }
	    }
	    printf("Linhas: OK!\n");
	    return true;
	}
	
	// Verifica as 9 colunas
	bool validarColunas(int sudoku[9][9]) {
	    int vetor[9];
	    for (int j = 0; j < 9; j++) {
	        for (int i = 0; i < 9; i++) vetor[i] = sudoku[i][j];
	        ordenar(vetor);
	        for (int x = 0; x < 9; x++) {
	            if (vetor[x] != x + 1) return false;
	        }
	    }
	    printf("Colunas: OK!\n");
	    return true;
	}
	
	// Verifica os 9 quadrantes 3x3
	bool validarQuadrantes(int sudoku[9][9]) {
	    int vetor[9];
	    for (int li = 0; li < 9; li += 3) {
	        for (int ci = 0; ci < 9; ci += 3) {
	            int aux = 0;
	            for (int l = li; l < li + 3; l++) {
	                for (int c = ci; c < ci + 3; c++) {
	                    vetor[aux++] = sudoku[l][c];
	                }
	            }
	            ordenar(vetor);
	            for (int x = 0; x < 9; x++) {
	                if (vetor[x] != x + 1) return false;
	            }
	        }
	    }
	    printf("Quadrantes: OK!\n");
	    return true;
	}

	/* SUGESTÃO DE TESTE (Copiado de um Sudoku comprovadamente válido):
    Copie e cole a sequência abaixo quando o programa solicitar a entrada:
    
    5 3 4 6 7 8 9 1 2
    6 7 2 1 9 5 3 4 8
    1 9 8 3 4 2 5 6 7
    8 5 9 7 6 1 4 2 3
    4 2 6 8 5 3 7 9 1
    7 1 3 9 2 4 8 5 6
    9 6 1 5 3 7 2 8 4
    2 8 7 4 1 9 6 3 5
    3 4 5 2 8 6 1 7 9
*/	

