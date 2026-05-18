#include<stdio.h>
#include<string.h>

	void transformarDeTextoParaNum(char cpf_texto[], int cpf_num[]) {
	    int i, j = 0;
	    int tam = strlen(cpf_texto); 
	
	    for (i = 0; i < tam; i++) {
	        if (j < 11 && cpf_texto[i] >= '0' && cpf_texto[i] <= '9') {
	            cpf_num[j] = cpf_texto[i] - '0';
	            j++;
	        }
	    }
	}
	
	int validarDigito10(int cpf_num[]) {
	    int digito10;
	    int i, j, mult = 0, soma = 0;
	    for (i = 0, j = 10; i < 9; i++, j--) { // i = 0 a 8 e j = 10 a 2 
	        mult = cpf_num[i] * j;
	        soma = soma + mult;
	    }
	    if (soma % 11 < 2) {
	        digito10 = 0;
	    } else {
	        digito10 = 11 - (soma % 11);
	    }
	    return digito10;
	}
	
	int validarDigito11(int cpf_num[]) {
	    int digito11, i;
	    int peso = 11, soma = 0;
	    for (i = 0; i < 10; i++) {
	        soma = soma + (cpf_num[i] * peso);
	        peso--;
	    }
	    if (soma % 11 < 2) {
	        digito11 = 0;
	    } else {
	        digito11 = 11 - (soma % 11);
	    }
	    return digito11;
	}
	
	int main() {
	    int i, digito10, digito11;
	    int cpf_num[11];
	    int escolha;
	    char cpf_texto[20];
	
	    do {
	        printf("\n--- MENU CPF ---\n");
	        printf("1. Validar CPF\n2. Gerar digitos\n3. Sair\n");
	        printf("Escolha: ");
	        scanf("%i", &escolha);
	        getchar();
	
	        if (escolha == 1) {
	            printf("Digite seu CPF (ex: 123.456.789-00): ");
	            fgets(cpf_texto, sizeof(cpf_texto), stdin);
	
	            transformarDeTextoParaNum(cpf_texto, cpf_num);
	
	            if (validarDigito10(cpf_num) == cpf_num[9]) {
	                printf("Primeiro digito OK! Verificando o segundo...\n");
	
	                if (validarDigito11(cpf_num) == cpf_num[10]) {
	                    printf("Segundo digito OK!\n");
	                    printf("CPF TOTALMENTE VALIDO!\n");
	                } else {
	                    printf("Segundo digito invalido!\n");
	                }
	            } else {
	                printf("Primeiro digito invalido! CPF falso.\n");
	            }
	        } 
	        else if (escolha == 2) {
	            printf("Digite os 9 primeiros digitos do CPF: \n");
	            fgets(cpf_texto, sizeof(cpf_texto), stdin);
	
	            transformarDeTextoParaNum(cpf_texto, cpf_num);
	
	            digito10 = validarDigito10(cpf_num);
	            cpf_num[9] = digito10;
	            digito11 = validarDigito11(cpf_num);
	
	            printf("Primeiro digito:%i \n", digito10);
	            printf("Segundo digito:%i \n", digito11);
	
	        } 
	        else if (escolha == 3) {
	            printf("Fechando o programa...");
	        } 
	        else {
	            printf("Opcao invalida! Tente novamente.\n");
	        }
	
	    } while (escolha != 3);
	
	    return 0;
	}
