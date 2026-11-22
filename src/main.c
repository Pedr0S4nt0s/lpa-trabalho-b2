#include <stdio.h>
#include <stdlib.h>

#define FILEIRAS 4
#define COLUNAS 5
#define TOTAL_VAGAS 20

int main(void)
{
    int mapa[FILEIRAS][COLUNAS] = {0};
    int opcao;

    do
    {
        printf("\n");
        printf("========================================\n");
        printf("       SISTEMA DE ESTACIONAMENTO\n");
        printf("========================================\n\n");

        printf("1 - Exibir mapa do estacionamento\n");
        printf("0 - Sair\n\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            int i, j;

            printf("\n       ");

            for (j = 0; j < COLUNAS; j++)
            {
                printf("C%d    ", j + 1);
            }

            printf("\n");

            for (i = 0; i < FILEIRAS; i++)
            {
                printf("F%d     ", i + 1);

                for (j = 0; j < COLUNAS; j++)
                {
                    if (mapa[i][j] == 1)
                    {
                        printf("[X]   ");
                    }
                    else
                    {
                        printf("[.]   ");
                    }
                }

                printf("\n");
            }
        }
        else if (opcao == 0)
        {
            printf("\nEncerrando o sistema...\n");
        }
        else
        {
            printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
