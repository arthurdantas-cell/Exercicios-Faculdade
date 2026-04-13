/*
 * Monitor de Estudo Mensal
 * Descrição: Registra horas de estudo diárias durante 4 semanas, calcula médias 
 * e identifica os recordes (maior e menor tempo).
 */
#include <stdio.h>

int main(void) {
    int semana, dia, horas;
    int totalSemana, totalMensal = 0;
    int maiorHora = -1, menorHora = 999;
    int semMaior, diaMaior, semMenor, diaMenor;
    float mediaSemanal;

    for (semana = 1; semana <= 4; semana++) {
        totalSemana = 0;
        int diasContabilizados = 7;

        printf("\n--- SEMANA %d ---\n", semana);
        for (dia = 1; dia <= 7; dia++) {
            printf("Horas estudadas no dia %d (ou -1 para ignorar): ", dia);
            scanf("%i", &horas);

            if (horas == -1) {
                diasContabilizados--;
                continue; // Pula para o próximo dia
            }

            totalSemana += horas;

            // Lógica para encontrar o maior e menor tempo
            if (horas > 0) {
                if (horas > maiorHora) {
                    maiorHora = horas;
                    semMaior = semana;
                    diaMaior = dia;
                }
                if (horas < menorHora) {
                    menorHora = horas;
                    semMenor = semana;
                    diaMenor = dia;
                }
            }
        }

        totalMensal += totalSemana;
        if (diasContabilizados > 0) {
            mediaSemanal = (float)totalSemana / diasContabilizados;
            printf("Total da Semana: %d h | Media: %.2f h\n", totalSemana, mediaSemanal);
        } else {
            printf("Nenhum dado registrado nesta semana.\n");
        }
    }

    printf("\n--- RESUMO MENSAL ---");
    printf("\nTotal de horas no mes: %d h", totalMensal);
    if (maiorHora != -1) {
        printf("\nMaior tempo: %d h (Semana %d, Dia %d)", maiorHora, semMaior, diaMaior);
        printf("\nMenor tempo: %d h (Semana %d, Dia %d)", menorHora, semMenor, diaMenor);
    }
    printf("\n");

    return 0;
}
