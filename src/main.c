#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILEIRAS 4
#define COLUNAS 5
#define TOTAL_VAGAS 20
#define CAPACIDADE_INICIAL 2
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

int aumentarCapacidade(Veiculo **veiculos, int *capacidade)
{
    int novaCapacidade;
    Veiculo *temporario;

    if (*capacidade >= TOTAL_VAGAS)
    {
        return 0;
    }

    novaCapacidade = *capacidade * 2;

    if (novaCapacidade > TOTAL_VAGAS)
    {
        novaCapacidade = TOTAL_VAGAS;
    }

    temporario = realloc(
        *veiculos,
        novaCapacidade * sizeof(Veiculo)
    );

    if (temporario == NULL)
    {
        printf("\nErro ao aumentar a capacidade do vetor!\n");
        return 0;
    }

    *veiculos = temporario;
    *capacidade = novaCapacidade;

    printf("\nCapacidade do vetor aumentada para %d veiculos.\n",
           *capacidade);

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

void cadastrarVeiculo(
    Veiculo **veiculos,
    int *quantidade,
    int *capacidade,
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

    if (buscarVeiculo(*veiculos, *quantidade, entrada) != -1)
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

    if (*quantidade == *capacidade)
    {
        if (!aumentarCapacidade(veiculos, capacidade))
        {
            return;
        }
    }

    (*veiculos)[*quantidade] = novo;

    mapa[novo.fileira - 1][novo.coluna - 1] = 1;

    (*quantidade)++;

    printf("\nVeiculo cadastrado com sucesso!\n");
}

void consultarVeiculo(Veiculo veiculos[], int quantidade)
{
    char id[TAM_ID + 20];
    int indice;

    printf("\n===== CONSULTA DE VEICULO =====\n");

    printf("Digite o ID: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    normalizarID(id);

    indice = buscarVeiculo(veiculos, quantidade, id);

    if (indice == -1)
    {
        printf("\nVeiculo nao encontrado!\n");
        return;
    }

    printf("\nVEICULO ENCONTRADO\n");
    printf("ID: %s\n", veiculos[indice].id);
    printf("Descricao: %s\n", veiculos[indice].descricao);

    if (veiculos[indice].categoria == 1)
    {
        printf("Categoria: Carro\n");
    }
    else
    {
        printf("Categoria: Moto\n");
    }

    printf("Fileira: %d\n", veiculos[indice].fileira);
    printf("Coluna: %d\n", veiculos[indice].coluna);
}

void atualizarVeiculo(Veiculo veiculos[], int quantidade)
{
    char id[TAM_ID + 20];
    char novaDescricao[TAM_DESCRICAO + 1];
    int novaCategoria;
    int indice;

    printf("\n===== ATUALIZACAO DE VEICULO =====\n");

    printf("Digite o ID do veiculo: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    normalizarID(id);

    indice = buscarVeiculo(veiculos, quantidade, id);

    if (indice == -1)
    {
        printf("\nVeiculo nao encontrado!\n");
        return;
    }

    printf("\nVeiculo encontrado: %s\n", veiculos[indice].descricao);

    printf("Nova descricao: ");
    fgets(novaDescricao, sizeof(novaDescricao), stdin);
    novaDescricao[strcspn(novaDescricao, "\n")] = '\0';

    printf("Nova categoria (1-Carro / 2-Moto): ");
    scanf("%d", &novaCategoria);
    getchar();

    if (novaCategoria != 1 && novaCategoria != 2)
    {
        printf("\nCategoria invalida! Atualizacao cancelada.\n");
        return;
    }

    strcpy(veiculos[indice].descricao, novaDescricao);
    veiculos[indice].categoria = novaCategoria;

    printf("\nVeiculo atualizado com sucesso!\n");
}

void exibirMenu(void)
{
    printf("\n===== ESTACIONAMENTO =====\n");
    printf("1 - Cadastrar veiculo\n");
    printf("2 - Consultar veiculo\n");
    printf("3 - Atualizar veiculo\n");
    printf("4 - Exibir mapa\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main(void)
{
    int mapa[FILEIRAS][COLUNAS] = {0};

    Veiculo *veiculos;
    int quantidade = 0;
    int capacidade = CAPACIDADE_INICIAL;
    int opcao;

    veiculos = malloc(capacidade * sizeof(Veiculo));

    if (veiculos == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    do
    {
        exibirMenu();

        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 1:
                cadastrarVeiculo(
                    &veiculos,
                    &quantidade,
                    &capacidade,
                    mapa
                );
                break;

            case 2:
                consultarVeiculo(veiculos, quantidade);
                break;

            case 3:
                atualizarVeiculo(veiculos, quantidade);
                break;

            case 4:
                exibirMapa(mapa);
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    free(veiculos);

    return 0;
}
