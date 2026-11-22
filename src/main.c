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

int buscarVeiculo(Veiculo veiculos[], int quantidade, const char id[])
{
    int i;

    for (i = 0; i < quantidade; i++)
    {
        if (strcmp(veiculos[i].id, id) == 0)
        {
            return i;
        }
    }

    return -1;
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

void cadastrarVeiculo(
    Veiculo veiculos[],
    int *quantidade,
    int mapa[FILEIRAS][COLUNAS])
{
    Veiculo novo;
    char entrada[100];

    if (*quantidade >= TOTAL_VAGAS)
    {
        printf("\nEstacionamento cheio!\n");
        return;
    }

    printf("\n===== CADASTRO DE VEICULO =====\n");

    printf("ID (7 caracteres): ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0';

    normalizarID(entrada);

    if (!validarID(entrada))
    {
        printf("\nID invalido!\n");
        return;
    }

    if (buscarVeiculo(veiculos, *quantidade, entrada) != -1)
    {
        printf("\nID ja cadastrado!\n");
        return;
    }

    strcpy(novo.id, entrada);

    printf("Descricao do veiculo: ");
    fgets(novo.descricao, sizeof(novo.descricao), stdin);
    novo.descricao[strcspn(novo.descricao, "\n")] = '\0';

    printf("Categoria (1-Carro / 2-Moto): ");
    scanf("%d", &novo.categoria);
    getchar();

    if (novo.categoria != 1 && novo.categoria != 2)
    {
        printf("\nCategoria invalida!\n");
        return;
    }

    printf("Fileira (1 a 4): ");
    scanf("%d", &novo.fileira);
    getchar();

    if (novo.fileira < 1 || novo.fileira > FILEIRAS)
    {
        printf("\nFileira invalida!\n");
        return;
    }

    printf("Coluna (1 a 5): ");
    scanf("%d", &novo.coluna);
    getchar();

    if (novo.coluna < 1 || novo.coluna > COLUNAS)
    {
        printf("\nColuna invalida!\n");
        return;
    }

    if (mapa[novo.fileira - 1][novo.coluna - 1] == 1)
    {
        printf("\nVaga ocupada!\n");
        return;
    }

    veiculos[*quantidade] = novo;

    mapa[novo.fileira - 1][novo.coluna - 1] = 1;

    (*quantidade)++;

    printf("\nVeiculo cadastrado com sucesso!\n");
}

void exibirMenu(void)
{
    printf("\n===== ESTACIONAMENTO =====\n");
    printf("1 - Cadastrar veiculo\n");
    printf("2 - Exibir mapa\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main(void)
{
    int mapa[FILEIRAS][COLUNAS] = {0};

    Veiculo veiculos[TOTAL_VAGAS];

    int quantidade = 0;
    int opcao;

    do
    {
        exibirMenu();

        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 1:
                cadastrarVeiculo(veiculos, &quantidade, mapa);
                break;

            case 2:
                exibirMapa(mapa);
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
