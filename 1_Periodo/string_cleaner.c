#include <stdio.h>
#include <string.h>
#include <ctype.h>

void limpar_string(char *origem, char *destino) {
    int j = 0;
    for (int i = 0; origem[i] != '\0'; i++) {
        // Se NÃO for dígito, mantém o caractere
        if (!isdigit(origem[i])) {
            destino[j++] = origem[i];
        }
    }
    destino[j] = '\0';
}

int main() {
    char lixo[] = "Pr0gr4m4c40";
    char limpo[30];

    limpar_string(lixo, limpo);

    printf("Original: %s\n", lixo);
    printf("Filtrada: %s\n", limpo);

    return 0;
}
