#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <float.h>

#define MAX_LINE_LENGTH 1024

void converter_timestamp(char *timestamp_str, char *data_formatada) {
    // Converta o timestamp para um time_t
    time_t timestamp = (time_t)atol(timestamp_str);

    // Converta o timestamp para uma estrutura tm
    struct tm *time_info = localtime(&timestamp);

    // Formate a data como dd/mm/yyyy
    strftime(data_formatada, 11, "%d/%m/%Y", time_info);
}

int main() {
    FILE *arquivo;
    char linha[MAX_LINE_LENGTH];

    arquivo = fopen("csv_data.csv", "r"); // Abrir o arquivo para leitura

    if (arquivo != NULL) {
        // Variáveis para calcular estatísticas de latência
        double latencia_min = DBL_MAX;
        double latencia_max = DBL_MIN;
        double latencia_total = 0;
        int contagem_latencias = 0;

        // Exibir cabeçalho da tabela
        printf("%-20s %-20s %-20s\n", "TIMESTAMP", "HOST", "LATENCY_MS");
        printf("-------------------------------------------------------------\n");

        while (fgets(linha, sizeof(linha), arquivo) != NULL) { // Ler cada linha do arquivo
            char *token;
            char *rest = linha;
            int coluna = 0;
            char data_formatada[11]; // Buffer para armazenar a data formatada
            double latencia_atual = 0;

            // Iterar sobre cada token na linha
            while ((token = strtok_r(rest, ",", &rest))) {
                if (coluna == 0) {
                    // Converter o timestamp para o formato dd/mm/yyyy
                    converter_timestamp(token, data_formatada);
                    printf("%-20s", data_formatada);
                } else if (coluna == 2) {
                    // Converter e exibir a latência
                    latencia_atual = atof(token);
                    printf("%-20s", token);

                    // Atualizar as estatísticas de latência
                    if (latencia_atual < latencia_min) {
                        latencia_min = latencia_atual;
                    }
                    if (latencia_atual > latencia_max) {
                        latencia_max = latencia_atual;
                    }
                    latencia_total += latencia_atual;
                    contagem_latencias++;
                } else {
                    // Ajustar a largura da coluna para a exibição em tabela
                    printf("%-20s", token);
                }
                coluna++;
            }

            // Certificar que temos três colunas na saída
            while (coluna < 3) {
                printf("%-20s", "");
                coluna++;
            }
            printf("\n");
        }
        fclose(arquivo); // Fechar o arquivo após a leitura

        // Calcular a média de latência
        double latencia_media = latencia_total / contagem_latencias;

        // Exibir as estatísticas de latência
        printf("\nEstatísticas de Latência:\n");
        printf("Latência Mínima: %.2f ms\n", latencia_min);
        printf("Latência Máxima: %.2f ms\n", latencia_max);
        printf("Latência Média: %.2f ms\n", latencia_media);

    } else {
        fprintf(stderr, "Não foi possível abrir o arquivo.\n");
    }

    return 0;
}
