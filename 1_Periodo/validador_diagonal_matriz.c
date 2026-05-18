#include<stdio.h>
	
	int verificaDiagonaisSecundarias(int tam, int mat[tam][tam]){
		int i, j;
			// caso seja 3: 0x2, 1x1, 2x0;
			for(i = 0, j = tam - 1; i < tam; i++, j--){ 
			if(mat[i][j] % 5 != 0){
				return 0;
			}
		}
	return 1;
	}
	
	int main(){
		int i, j, tam;
				
			printf("Digite o tamanho da matriz: ");
			scanf("%i", &tam);
		int mat[tam][tam];
	
	for(i = 0; i < tam; i++){
		for(j = 0; j < tam; j++){
				printf("Digite o numero de acordo com a cordenada %ix%i: ", i,j);
				scanf("%i", &mat[i][j]);	
		}
	}
	
	if(verificaDiagonaisSecundarias(tam, mat)) {
        printf("\nSUCESSO\n");
    } else {
        printf("\nFALHA\n");
    }
		return 0;
	}
