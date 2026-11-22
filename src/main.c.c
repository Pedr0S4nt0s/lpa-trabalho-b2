#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILEIRAS 4
#define COLUNAS 5
#define TOTAL_VAGAS 20

#define CAPACIDADE_INICIAL 2
#define MAX_VEICULOS 20

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


int lerLinha(char texto[], int tamanho)
{
    if (fgets(texto, tamanho, stdin) == NULL)
    {
        return 0;
    }

    if (strchr(texto, '\n') != NULL)
    {
        texto[strcspn(texto, "\n")] = '\0';
    }
    else
    {
        int caractere;

        while ((caractere = getchar()) != '\n' &&
               caractere != EOF)
        {

        }

        return 0;
    }

    return 1;
}

int lerInteiro(const char mensagem[], int *valor)
{
    char entrada[100];
    char *fim;
    long numero;

    printf("%s", mensagem);

    if (!lerLinha(entrada, sizeof(entrada)))
    {
        return 0;
    }

    numero = strtol(entrada, &fim, 10);

    if (fim == entrada || *fim != '\0')
    {
        return 0;
    }

    *valor = (int)numero;

    return 1;
}

/*VALIDACAO DO IDENTIFICADOR*/

void normalizarID(char id[])
{
    int i;

    for (i = 0; id[i] != '\0'; i++)
    {
        if (id[i] >= 'a' && id[i] <= 'z')
        {
            id[i] = (char)(id[i] - 'a' + 'A');
        }
    }
}

int validarID(const char id[])
{
    int i;

    if (strlen(id) != TAM_ID)
    {
        return 0;
    }

    for (i = 0; i < TAM_ID; i++)
    {
        int letraMaiuscula =
            id[i] >= 'A' && id[i] <= 'Z';

        int letraMinuscula =
            id[i] >= 'a' && id[i] <= 'z';

        int numero =
            id[i] >= '0' && id[i] <= '9';

        if (!letraMaiuscula &&
            !letraMinuscula &&
            !numero)
        {
            return 0;
        }
    }

    return 1;
}

/* BUSCA DE VEICULO */

int buscarVeiculo(Veiculo *veiculos,
                  int quantidade,
                  const char id[])
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
/*CONSULTA DE VEICULO*/

void consultarVeiculo(
    Veiculo *veiculos,
    int quantidade)
{
    char entradaID[100];
    int indice;

    printf("\n");
    printf("========================================\n");
    printf("          CONSULTA DE VEICULO\n");
    printf("========================================\n");

    printf("\nDigite o identificador: ");

    if (!lerLinha(entradaID, sizeof(entradaID)))
    {
        printf("\nEntrada invalida ou muito longa.\n");
        return;
    }

    normalizarID(entradaID);


    if (!validarID(entradaID))
    {
        printf("\nIdentificador invalido!\n");
        printf("Utilize exatamente 7 caracteres alfanumericos.\n");

        return;
    }


    indice = buscarVeiculo(
        veiculos,
        quantidade,
        entradaID
    );


    if (indice == -1)
    {
        printf("\nVeiculo nao encontrado!\n");

        return;
    }


    printf("\n");
    printf("========================================\n");
    printf("          VEICULO ENCONTRADO\n");
    printf("========================================\n");

    printf("Identificador: %s\n",
           veiculos[indice].id);

    printf("Descricao: %s\n",
           veiculos[indice].descricao);

    if (veiculos[indice].categoria == 1)
    {
        printf("Categoria: Carro\n");
    }
    else
    {
        printf("Categoria: Moto\n");
    }

    printf("Fileira: %d\n",
           veiculos[indice].fileira);

    printf("Coluna: %d\n",
           veiculos[indice].coluna);

    printf("Posicao: F%d/C%d\n",
           veiculos[indice].fileira,
           veiculos[indice].coluna);

    printf("========================================\n");
}

/*ATUALIZACAO DE VEICULO*/

void atualizarVeiculo(
    Veiculo *veiculos,
    int quantidade)
{
    char entradaID[100];
    char novaDescricao[100];

    int indice;
    int opcao;
    int novaCategoria;

    printf("\n");
    printf("========================================\n");
    printf("         ATUALIZACAO DE VEICULO\n");
    printf("========================================\n");

    printf("\nDigite o identificador do veiculo: ");

    if (!lerLinha(entradaID, sizeof(entradaID)))
    {
        printf("\nEntrada invalida ou muito longa.\n");
        return;
    }

    normalizarID(entradaID);

    if (!validarID(entradaID))
    {
        printf("\nIdentificador invalido!\n");
        printf("Utilize exatamente 7 caracteres alfanumericos.\n");

        return;
    }

    indice = buscarVeiculo(
        veiculos,
        quantidade,
        entradaID
    );

    if (indice == -1)
    {
        printf("\nVeiculo nao encontrado!\n");

        return;
    }


    printf("\nVeiculo encontrado:\n");

    printf("Identificador: %s\n",
           veiculos[indice].id);

    printf("Descricao: %s\n",
           veiculos[indice].descricao);

    if (veiculos[indice].categoria == 1)
    {
        printf("Categoria: Carro\n");
    }
    else
    {
        printf("Categoria: Moto\n");
    }

    printf("Posicao: F%d/C%d\n",
           veiculos[indice].fileira,
           veiculos[indice].coluna);


    printf("\nO que deseja atualizar?\n");
    printf("1 - Descricao\n");
    printf("2 - Categoria\n");
    printf("3 - Descricao e categoria\n");

    if (!lerInteiro("Escolha uma opcao: ", &opcao))
    {
        printf("\nOpcao invalida!\n");
        return;
    }

    if (opcao < 1 || opcao > 3)
    {
        printf("\nOpcao invalida!\n");

        return;
    }


    if (opcao == 1 || opcao == 3)
    {
        printf("\nNova descricao: ");

        if (!lerLinha(novaDescricao,
                      sizeof(novaDescricao)))
        {
            printf("\nDescricao invalida ou muito longa.\n");
            return;
        }

        if (strlen(novaDescricao) == 0)
        {
            printf("\nA descricao nao pode ser vazia.\n");

            return;
        }

        if (strlen(novaDescricao) > TAM_DESCRICAO)
        {
            printf("\nA descricao deve possuir no maximo 60 caracteres.\n");

            return;
        }
    }


    if (opcao == 2 || opcao == 3)
    {
        if (!lerInteiro(
                "\nNova categoria (1 - Carro / 2 - Moto): ",
                &novaCategoria))
        {
            printf("\nCategoria invalida!\n");

            return;
        }

        if (novaCategoria != 1 && novaCategoria != 2)
        {
            printf("\nCategoria invalida!\n");
            printf("Digite 1 para carro ou 2 para moto.\n");

            return;
        }
    }


    if (opcao == 1)
    {
        strcpy(veiculos[indice].descricao,
               novaDescricao);
    }
    else if (opcao == 2)
    {
        veiculos[indice].categoria = novaCategoria;
    }
    else
    {
        strcpy(veiculos[indice].descricao,
               novaDescricao);

        veiculos[indice].categoria = novaCategoria;
    }


    printf("\n========================================\n");
    printf("VEICULO ATUALIZADO COM SUCESSO!\n");
    printf("========================================\n");

    printf("Identificador: %s\n",
           veiculos[indice].id);

    printf("Descricao: %s\n",
           veiculos[indice].descricao);

    if (veiculos[indice].categoria == 1)
    {
        printf("Categoria: Carro\n");
    }
    else
    {
        printf("Categoria: Moto\n");
    }

    printf("Posicao: F%d/C%d\n",
           veiculos[indice].fileira,
           veiculos[indice].coluna);

    printf("========================================\n");
}

/*MOVIMENTACAO DE VEICULO */

void movimentarVeiculo(
    Veiculo *veiculos,
    int quantidade,
    int mapa[FILEIRAS][COLUNAS])
{
    char entradaID[100];

    int indice;
    int novaFileira;
    int novaColuna;

    int fileiraAtual;
    int colunaAtual;

    printf("\n");
    printf("========================================\n");
    printf("         MOVIMENTACAO DE VEICULO\n");
    printf("========================================\n");



    printf("\nDigite o identificador do veiculo: ");

    if (!lerLinha(entradaID, sizeof(entradaID)))
    {
        printf("\nEntrada invalida ou muito longa.\n");
        return;
    }

    normalizarID(entradaID);


    if (!validarID(entradaID))
    {
        printf("\nIdentificador invalido!\n");
        printf("Utilize exatamente 7 caracteres alfanumericos.\n");

        return;
    }


    indice = buscarVeiculo(
        veiculos,
        quantidade,
        entradaID
    );

    if (indice == -1)
    {
        printf("\nVeiculo nao encontrado!\n");

        return;
    }


    fileiraAtual = veiculos[indice].fileira;
    colunaAtual = veiculos[indice].coluna;

    printf("\nVeiculo encontrado:\n");

    printf("Identificador: %s\n",
           veiculos[indice].id);

    printf("Descricao: %s\n",
           veiculos[indice].descricao);

    printf("Posicao atual: F%d/C%d\n",
           fileiraAtual,
           colunaAtual);


    if (!lerInteiro(
            "\nNova fileira (1 a 4): ",
            &novaFileira))
    {
        printf("\nFileira invalida!\n");

        return;
    }

    if (novaFileira < 1 || novaFileira > FILEIRAS)
    {
        printf("\nFileira fora do intervalo permitido!\n");

        return;
    }


    if (!lerInteiro(
            "Nova coluna (1 a 5): ",
            &novaColuna))
    {
        printf("\nColuna invalida!\n");

        return;
    }

    if (novaColuna < 1 || novaColuna > COLUNAS)
    {
        printf("\nColuna fora do intervalo permitido!\n");

        return;
    }


    if (novaFileira == fileiraAtual &&
        novaColuna == colunaAtual)
    {
        printf("\nO veiculo ja esta nessa posicao.\n");
        printf("Nenhuma movimentacao foi realizada.\n");

        return;
    }


    if (mapa[novaFileira - 1][novaColuna - 1] == 1)
    {
        printf("\nVaga ocupada!\n");
        printf("Movimentacao cancelada.\n");

        return;
    }


    mapa[fileiraAtual - 1][colunaAtual - 1] = 0;

    mapa[novaFileira - 1][novaColuna - 1] = 1;

    veiculos[indice].fileira = novaFileira;

    veiculos[indice].coluna = novaColuna;

    printf("\n========================================\n");
    printf("VEICULO MOVIMENTADO COM SUCESSO!\n");
    printf("========================================\n");

    printf("Identificador: %s\n",
           veiculos[indice].id);

    printf("Origem: F%d/C%d\n",
           fileiraAtual,
           colunaAtual);

    printf("Destino: F%d/C%d\n",
           novaFileira,
           novaColuna);

    printf("========================================\n");
}

/*REMOCAO DE VEICULO*/

void removerVeiculo(
    Veiculo *veiculos,
    int *quantidade,
    int mapa[FILEIRAS][COLUNAS])
{
    char entradaID[100];

    int indice;
    int fileira;
    int coluna;
    int i;

    printf("\n");
    printf("========================================\n");
    printf("          REMOCAO DE VEICULO\n");
    printf("========================================\n");


    printf("\nDigite o identificador do veiculo: ");

    if (!lerLinha(entradaID, sizeof(entradaID)))
    {
        printf("\nEntrada invalida ou muito longa.\n");
        return;
    }

    normalizarID(entradaID);


    if (!validarID(entradaID))
    {
        printf("\nIdentificador invalido!\n");
        printf("Utilize exatamente 7 caracteres alfanumericos.\n");

        return;
    }


    indice = buscarVeiculo(
        veiculos,
        *quantidade,
        entradaID
    );

    if (indice == -1)
    {
        printf("\nVeiculo nao encontrado!\n");

        return;
    }


    fileira = veiculos[indice].fileira;
    coluna = veiculos[indice].coluna;


    printf("\nVeiculo encontrado:\n");

    printf("Identificador: %s\n",
           veiculos[indice].id);

    printf("Descricao: %s\n",
           veiculos[indice].descricao);

    if (veiculos[indice].categoria == 1)
    {
        printf("Categoria: Carro\n");
    }
    else
    {
        printf("Categoria: Moto\n");
    }

    printf("Posicao: F%d/C%d\n",
           fileira,
           coluna);


    mapa[fileira - 1][coluna - 1] = 0;


    for (i = indice; i < *quantidade - 1; i++)
    {
        veiculos[i] = veiculos[i + 1];
    }


    (*quantidade)--;


    printf("\n========================================\n");
    printf("VEICULO REMOVIDO COM SUCESSO!\n");
    printf("========================================\n");

    printf("Identificador removido: %s\n",
           entradaID);

    printf("Vaga liberada: F%d/C%d\n",
           fileira,
           coluna);

    printf("Veiculos restantes: %d\n",
           *quantidade);

    printf("========================================\n");
}

/*LISTAGEM DE VEICULOS*/

void listarVeiculos(
    Veiculo *veiculos,
    int quantidade)
{
    int i;

    printf("\n");
    printf("========================================\n");
    printf("          LISTAGEM DE VEICULOS\n");
    printf("========================================\n");


    if (quantidade == 0)
    {
        printf("\nNenhum veiculo cadastrado.\n");

        return;
    }


    for (i = 0; i < quantidade; i++)
    {
        printf("\n----------------------------------------\n");

        printf("Veiculo %d\n", i + 1);

        printf("Identificador: %s\n",
               veiculos[i].id);

        printf("Descricao: %s\n",
               veiculos[i].descricao);

        if (veiculos[i].categoria == 1)
        {
            printf("Categoria: Carro\n");
        }
        else
        {
            printf("Categoria: Moto\n");
        }

        printf("Fileira: %d\n",
               veiculos[i].fileira);

        printf("Coluna: %d\n",
               veiculos[i].coluna);

        printf("Posicao: F%d/C%d\n",
               veiculos[i].fileira,
               veiculos[i].coluna);
    }

    printf("\n----------------------------------------\n");

    printf("Total de veiculos cadastrados: %d\n",
           quantidade);

    printf("========================================\n");
}

/*MAPA DO ESTACIONAMENTO*/

void exibirMapa(
    int mapa[FILEIRAS][COLUNAS])
{
    int i;
    int j;

    printf("\n");
    printf("========================================\n");
    printf("          MAPA DO ESTACIONAMENTO\n");
    printf("========================================\n");


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


    printf("\n========================================\n");

    printf("Legenda:\n");
    printf("[X] - Vaga ocupada\n");
    printf("[.] - Vaga livre\n");

    printf("========================================\n");
}

void relatorioOcupacao(Veiculo *veiculos, int quantidade,
                       int mapa[FILEIRAS][COLUNAS])
{
    int ocupadas = 0;
    int livres;
    int carros = 0;
    int motos = 0;
    int i, j;

    for (i = 0; i < FILEIRAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            if (mapa[i][j] == 1)
            {
                ocupadas++;
            }
        }
    }

    livres = TOTAL_VAGAS - ocupadas;

    for (i = 0; i < quantidade; i++)
    {
        if (veiculos[i].categoria == 1)
        {
            carros++;
        }
        else if (veiculos[i].categoria == 2)
        {
            motos++;
        }
    }

    printf("\n========== RELATORIO DE OCUPACAO ==========\n");

    printf("Total de vagas:       %d\n", TOTAL_VAGAS);
    printf("Vagas ocupadas:       %d\n", ocupadas);
    printf("Vagas livres:         %d\n", livres);

    printf("-------------------------------------------\n");

    printf("Percentual ocupado:   %.2f%%\n",
           (ocupadas * 100.0) / TOTAL_VAGAS);

    printf("Percentual livre:     %.2f%%\n",
           (livres * 100.0) / TOTAL_VAGAS);

    printf("-------------------------------------------\n");

    printf("Carros estacionados:  %d\n", carros);
    printf("Motos estacionadas:   %d\n", motos);

    printf("===========================================\n");
}


/*CADASTRO DE VEICULO*/

void cadastrarVeiculo(
    Veiculo **veiculos,
    int *quantidade,
    int *capacidade,
    int mapa[FILEIRAS][COLUNAS])
{
    Veiculo novoVeiculo;

    char entradaID[100];
    char entradaDescricao[100];

    int categoria;
    int fileira;
    int coluna;

    Veiculo *novoEndereco;

    printf("\n");
    printf("========================================\n");
    printf("          CADASTRO DE VEICULO\n");
    printf("========================================\n");


    if (*quantidade >= MAX_VEICULOS)
    {
        printf("\nEstacionamento lotado!\n");
        printf("Nao e possivel cadastrar mais veiculos.\n");

        return;
    }


    printf("\nIdentificador (7 caracteres): ");

    if (!lerLinha(entradaID, sizeof(entradaID)))
    {
        printf("\nEntrada invalida ou muito longa.\n");
        return;
    }

    normalizarID(entradaID);

    if (!validarID(entradaID))
    {
        printf("\nIdentificador invalido!\n");
        printf("Utilize exatamente 7 caracteres alfanumericos.\n");

        return;
    }


    if (buscarVeiculo(*veiculos,
                      *quantidade,
                      entradaID) != -1)
    {
        printf("\nIdentificador ja cadastrado!\n");

        return;
    }


    printf("Descricao: ");

    if (!lerLinha(entradaDescricao,
                  sizeof(entradaDescricao)))
    {
        printf("\nDescricao invalida ou muito longa.\n");
        return;
    }

    if (strlen(entradaDescricao) == 0)
    {
        printf("\nA descricao nao pode ser vazia.\n");
        return;
    }

    if (strlen(entradaDescricao) > TAM_DESCRICAO)
    {
        printf("\nA descricao deve possuir no maximo 60 caracteres.\n");
        return;
    }


    if (!lerInteiro(
            "Categoria (1 - Carro / 2 - Moto): ",
            &categoria))
    {
        printf("\nCategoria invalida!\n");
        return;
    }

    if (categoria != 1 && categoria != 2)
    {
        printf("\nCategoria invalida!\n");
        printf("Digite 1 para carro ou 2 para moto.\n");

        return;
    }


    if (!lerInteiro("Fileira (1 a 4): ", &fileira))
    {
        printf("\nFileira invalida!\n");
        return;
    }

    if (fileira < 1 || fileira > FILEIRAS)
    {
        printf("\nFileira fora do intervalo permitido!\n");

        return;
    }


    if (!lerInteiro("Coluna (1 a 5): ", &coluna))
    {
        printf("\nColuna invalida!\n");
        return;
    }

    if (coluna < 1 || coluna > COLUNAS)
    {
        printf("\nColuna fora do intervalo permitido!\n");

        return;
    }


    if (mapa[fileira - 1][coluna - 1] == 1)
    {
        printf("\nVaga ocupada!\n");
        printf("Escolha outra posicao.\n");

        return;
    }


    strcpy(novoVeiculo.id, entradaID);

    strcpy(novoVeiculo.descricao,
           entradaDescricao);

    novoVeiculo.categoria = categoria;
    novoVeiculo.fileira = fileira;
    novoVeiculo.coluna = coluna;


    if (*quantidade == *capacidade)
    {
        int novaCapacidade;

        novaCapacidade = *capacidade * 2;

        if (novaCapacidade > MAX_VEICULOS)
        {
            novaCapacidade = MAX_VEICULOS;
        }

        novoEndereco = realloc(
            *veiculos,
            novaCapacidade * sizeof(Veiculo)
        );

        if (novoEndereco == NULL)
        {
            printf("\nErro ao ampliar a memoria da colecao.\n");
            printf("Cadastro cancelado.\n");

            return;
        }

        *veiculos = novoEndereco;

        *capacidade = novaCapacidade;

        printf("\nCapacidade da colecao ampliada para %d registros.\n",
               *capacidade);
    }


    (*veiculos)[*quantidade] = novoVeiculo;


    mapa[fileira - 1][coluna - 1] = 1;


    (*quantidade)++;


    printf("\n========================================\n");
    printf("VEICULO CADASTRADO COM SUCESSO!\n");
    printf("========================================\n");

    printf("Identificador: %s\n",
           novoVeiculo.id);

    printf("Descricao: %s\n",
           novoVeiculo.descricao);

    if (categoria == 1)
    {
        printf("Categoria: Carro\n");
    }
    else
    {
        printf("Categoria: Moto\n");
    }

    printf("Posicao: F%d/C%d\n",
           fileira,
           coluna);

    printf("Veiculos cadastrados: %d\n",
           *quantidade);

    printf("========================================\n");
}



int exibirMenu(void)
{
    char entrada[100];
    char *fim;
    long opcao;

    printf("\n");
    printf("========================================\n");
    printf("       SISTEMA DE ESTACIONAMENTO\n");
    printf("========================================\n\n");

    printf("1 - Cadastrar veiculo\n");
    printf("2 - Consultar veiculo por identificador\n");
    printf("3 - Atualizar veiculo\n");
    printf("4 - Movimentar veiculo\n");
    printf("5 - Remover veiculo\n");
    printf("6 - Listar veiculos\n");
    printf("7 - Exibir mapa do estacionamento\n");
    printf("8 - Exibir relatorio de ocupacao\n");
    printf("\n");
    printf("0 - Sair\n");
    printf("\n");
    printf("========================================\n");
    printf("Escolha uma opcao: ");

    if (fgets(entrada, sizeof(entrada), stdin) == NULL)
    {
        return 0;
    }

    entrada[strcspn(entrada, "\n")] = '\0';

    opcao = strtol(entrada, &fim, 10);

    if (fim == entrada || *fim != '\0')
    {
        return -1;
    }

    if (opcao < 0 || opcao > 8)
    {
        return -1;
    }

    return (int)opcao;
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
        printf("Erro ao alocar memoria.\n");

        return 1;
    }


    do
    {
        opcao = exibirMenu();

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
                movimentarVeiculo(veiculos, quantidade, mapa);
                break;

            case 5:
                removerVeiculo(veiculos, &quantidade, mapa);
                break;

            case 6:
                listarVeiculos(veiculos, quantidade);
                break;

            case 7:
                exibirMapa(mapa);
                break;

            case 8:
                 relatorioOcupacao(veiculos, quantidade, mapa);
                break;

            case 0:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                printf("Digite um numero entre 0 e 8.\n");
                break;
        }

    } while (opcao != 0);
    
free(veiculos);

veiculos = NULL;

printf("Memoria liberada.\n");

printf("Sistema encerrado com sucesso.\n");

    return 0;
}
