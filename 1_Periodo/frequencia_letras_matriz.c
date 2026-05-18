#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main() {
    int num_paragrafos, i, j;

    printf("Quantos paragrafos deseja analisar? ");
    scanf("%i", &num_paragrafos);

    getchar();//usado para limpar o enter  

    int freq[num_paragrafos][26];
    char texto[500];

    for(i = 0; i < num_paragrafos; i++) { //inicializa a matriz
        for(j = 0; j < 26; j++) {
            freq[i][j] = 0;
        }
    }

    for(i = 0; i < num_paragrafos; i++) {
        printf("\nDigite o paragrafo %i:\n", i + 1);
        fgets(texto, 500, stdin);
        getchar();


        for(j = 0; j < strlen(texto); j++) {
            char c = tolower(texto[j]);// troca todos as letras para minusculas
        
            if(c >= 'a' && c <= 'z') {
                int indice = c - 'a'; 
                freq[i][indice]++;  
            }
        }
    }

    
    printf("\n--- MATRIZ DE FREQUENCIA ---\n"); 
    printf("Parag. | ");
    for(char c = 'a'; c <= 'z'; c++){
	printf("%c ", c);
	}
    printf("\n-------------------------------------------------------\n");

    for(i = 0; i < num_paragrafos; i++) {
        printf("  %02i   | ", i + 1);
        for(j = 0; j < 26; j++) {
            printf("%i ", freq[i][j]);
        }
        printf("\n");
    }

    return 0;
}
