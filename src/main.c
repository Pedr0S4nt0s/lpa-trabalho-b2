#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILEIRAS 4
#define COLUNAS 5
#define TOTAL_VAGAS 20
#define TAM_ID 7
#define TAM_DESCRICAO 60

typedef struct
{
    char id[TAM_ID + 1];
    char descricao[TAM_DESCRICAO + 1];
    int categoria;
    int fileira;
    int coluna;
} Veiculo;

void normalizarID(char id[])
{
    int i;

    for (i = 0; id[i] != '\0'; i++)
    {
        id[i] = toupper((unsigned char)id[i]);
    }
}

int validarID(const char id[])
{
    int i;

    if (strlen(id) != TAM_ID)
    {
        return 0;
    }

    for (i = 0; id[i] != '\0'; i++)
    {
        if (!isalnum((unsigned char)id[i]))
        {
            return 0;
        }
    }

    return 1;
}

void exibirMapa(int mapa[FILEIRAS][COLUNAS])
{
    int i, j;

    printf("\nMAPA DO ESTACIONAMENTO\n\n");

    for (i = 0; i < FILEIRAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            if (mapa[i][j] == 1)
            {
                printf("[X] ");
            }
            else
            {
                printf("[.] ");
            }
        }

        printf("\n");
    }
}

void testarID(void)
{
    char id[TAM_ID + 20];

    printf("\nDigite um ID de 7 caracteres: ");

    fgets(id, sizeof(id), stdin);

    id[strcspn(id, "\n")] = '\0';

    normalizarID(id);

    printf("\nID normalizado: %s\n", id);

    if (validarID(id))
    {
        printf("ID valido!\n");
    }
    else
    {
        printf("ID invalido! Deve possuir exatamente 7 caracteres alfanumericos.\n");
    }
}

int main(void)
{
    int mapa[FILEIRAS][COLUNAS] = {0};
    int opcao;

    do
    {
        printf("\n===== ESTACIONAMENTO =====\n");
        printf("1 - Exibir mapa\n");
        printf("2 - Testar ID\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 1:
                exibirMapa(mapa);
                break;

            case 2:
                testarID();
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
