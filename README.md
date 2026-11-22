# Sistema de Controle de Estacionamento

**Disciplina:** Lógica de Programação e Algoritmos  
**Semestre:** 2026/2  
**Trabalho:** 2º Bimestre  
**Desenvolvimento:** Individual

**Integrante:** Pedro Santos de Oliveira  
**GitHub:** [Pedr0S4nt0s](https://github.com/Pedr0S4nt0s)

## Descrição do Projeto

Sistema desenvolvido em linguagem C para controle de um estacionamento com capacidade para 20 veículos, distribuídos em 4 fileiras e 5 colunas.

O sistema permite cadastrar, consultar, atualizar, movimentar, remover e listar veículos, além de exibir o mapa do estacionamento e um relatório de ocupação.

## Menu do Sistema e Funcionalidades

O sistema disponibiliza um menu interativo com as seguintes opções:

| Opção | Funcionalidade |
|---|---|
| 1 | Cadastrar veículo |
| 2 | Consultar veículo |
| 3 | Atualizar dados do veículo |
| 4 | Movimentar veículo |
| 5 | Remover veículo |
| 6 | Listar veículos cadastrados |
| 7 | Exibir mapa do estacionamento |
| 8 | Relatório de ocupação |
| 0 | Encerrar o programa |

## Estruturas de Dados

O sistema utiliza:

Uma matriz bidimensional para representar as vagas,
uma estrutura `struct` para armazenar os dados dos veículos e um vetor
dinâmico para gerenciar os registros.

A alocação e o redimensionamento de memória são realizados por meio
de `malloc` e `realloc`. A organização do programa em funções permite
separar as responsabilidades das operações.
## Modularização

As principais funções são:

| Função | Responsabilidade |
|---|---|
| `cadastrarVeiculo` | Realiza o cadastro de um novo veículo, validando os dados e a disponibilidade da vaga. |
| `consultarVeiculo` | Busca e apresenta as informações de um veículo pelo identificador. |
| `atualizarVeiculo` | Permite alterar a descrição e a categoria de um veículo cadastrado. |
| `movimentarVeiculo` | Realiza a transferência de um veículo para outra vaga disponível. |
| `removerVeiculo` | Remove o veículo do sistema e libera sua vaga. |
| `listarVeiculos` | Exibe os veículos cadastrados. |
| `exibirMapa` | Apresenta visualmente a situação das vagas do estacionamento. |
| `relatorioOcupacao` | Apresenta informações sobre vagas ocupadas e disponíveis. |
| `buscarVeiculo` | Localiza um veículo no vetor dinâmico a partir do identificador. |
| `normalizarID` | Padroniza o identificador do veículo para facilitar as comparações. |
| `validarID` | Verifica se o identificador informado atende aos critérios estabelecidos. |
| `exibirMenu` | Apresenta as opções disponíveis para o usuário. |

A função `main` é responsável pela inicialização das estruturas de dados,
pela alocação inicial de memória, pelo controle do menu principal e pelo
encerramento do programa, incluindo a liberação da memória utilizada.

### Matriz do Estacionamento

O estacionamento é representado por uma matriz bidimensional de inteiros,
com 4 linhas e 5 colunas, totalizando 20 vagas.

Cada posição da matriz representa uma vaga:
- `0`: vaga livre.
- `1`: vaga ocupada.

A matriz permite controlar a ocupação das vagas e visualizar a disposição
dos veículos no estacionamento.

### Estrutura dos Veículos

Cada veículo é representado por uma estrutura `struct`, contendo informações
como identificador, descrição, categoria e localização no estacionamento
(linha e coluna).

### Vetor Dinâmico

Os veículos cadastrados são armazenados em um vetor dinâmico, inicialmente
alocado para 2 elementos.

O sistema controla:
- **Quantidade:** número de veículos atualmente cadastrados.
- **Capacidade:** número de elementos que o vetor pode armazenar.

Quando a quantidade de veículos atinge a capacidade do vetor, a memória
é redimensionada utilizando `realloc`, aumentando a capacidade de
armazenamento.

O vetor possui limite máximo de 20 veículos, correspondente à capacidade
total do estacionamento.

A memória é alocada inicialmente com `malloc` e liberada ao encerrar
o programa utilizando `free`.

## Organização dos Arquivos

```text
Estacionamento/
├── README.md
├── .gitignore
└── src/
    └── main.c
```

## Compilação

O programa pode ser compilado utilizando o GCC, com suporte ao padrão C11.

Comando de compilação:

```bash
gcc -std=c11 -Wall -Wextra -pedantic src/main.c -o estacionamento
```

## Execução

Após a compilação, execute o programa através do terminal.

No Windows:

```cmd
estacionamento.exe
```

## Limitações

Os dados cadastrados permanecem disponíveis somente durante a execução do programa. Ao encerrar o sistema, os dados são perdidos.

O sistema possui capacidade máxima de 20 veículos, correspondente à quantidade de vagas disponíveis.

## Desenvolvimento e Responsabilidades

O trabalho foi desenvolvido individualmente, devido à dificuldade de encontrar
uma dupla.

O desenvolvedor realizou a implementação das funcionalidades
do sistema, organização do código, utilização das estruturas de dados,
realização de testes, documentação e gerenciamento do repositório GitHub.

As responsabilidades pelas etapas do projeto foram assumidas pelo desenvolvedor.

## Controle de Versão

O projeto utiliza Git e GitHub para controle de versão, organização e registro do desenvolvimento.

O desenvolvimento está sendo realizado na branch `Desenvolvimento-Individual`.

## Testes

Os testes foram realizados manualmente, por meio da execução do programa,
verificando o funcionamento das funcionalidades implementadas e o tratamento
de situações inválidas.

| Teste | Entrada/Operação | Resultado Esperado | Resultado Obtido | Status |
|---|---|---|---|---|
| T01 | Iniciar o programa e consultar o mapa do estacionamento vazio | Todas as 20 vagas devem estar livres | Sistema iniciado corretamente, com todas as vagas disponíveis | Aprovado |
| T02 | Cadastrar um veículo utilizando identificador válido e vaga disponível | Veículo deve ser cadastrado na vaga escolhida | Cadastro realizado com sucesso | Aprovado |
| T03 | Tentar cadastrar um veículo utilizando identificador já existente, alterando letras maiúsculas/minúsculas | Cadastro deve ser recusado | Identificador duplicado recusado | Aprovado |
| T04 | Tentar cadastrar um veículo em uma vaga já ocupada | Operação deve ser recusada | Vaga ocupada identificada e operação recusada | Aprovado |
| T05 | Cadastrar veículos até ultrapassar a capacidade inicial do vetor | Capacidade do vetor deve ser ampliada automaticamente | Coleção expandida corretamente | Aprovado |
| T06 | Consultar um veículo e atualizar sua descrição e categoria | Dados devem ser atualizados sem alterar o identificador | Dados atualizados corretamente | Aprovado |
| T07 | Movimentar um veículo para outra vaga disponível | Veículo deve ocupar nova vaga e liberar a anterior | Movimentação realizada corretamente | Aprovado |
| T08 | Remover um veículo cadastrado | Veículo deve ser removido e a vaga liberada | Remoção realizada corretamente | Aprovado |
| T09 | Consultar o relatório de ocupação após operações de cadastro e remoção | Quantidade de vagas ocupadas e livres deve corresponder à situação do estacionamento | Relatório apresentado corretamente | Aprovado |
| T10 | Selecionar a opção de encerramento do programa | Programa deve encerrar corretamente | Programa encerrado | Aprovado |

## Referências

- Enunciado do trabalho disponibilizado na disciplina de Lógica de Programação e Algoritmos.
- KIPPER. *Aprenda Git e GitHub do zero – guia completo*. YouTube. Disponível em: https://youtu.be/pyM5QLS2h6M. Acesso em: 22 nov. 2026.
