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

O sistema utiliza uma matriz bidimensional para representar as vagas, uma estrutura `struct` para armazenar os dados dos veículos e um vetor dinâmico para gerenciar os registros.

A alocação e o redimensionamento de memória são realizados por meio de `malloc` e `realloc`. A organização do programa em funções permite separar as responsabilidades das operações.

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

A função `main` é responsável pela inicialização das estruturas de dados, pela alocação inicial de memória, pelo controle do menu principal e pelo encerramento do programa, incluindo a liberação da memória utilizada.

### Matriz do Estacionamento

O estacionamento é representado por uma matriz bidimensional de inteiros, com 4 linhas e 5 colunas, totalizando 20 vagas.

Cada posição da matriz representa uma vaga:

- `0`: vaga livre.
- `1`: vaga ocupada.

A matriz permite controlar a ocupação das vagas e visualizar a disposição dos veículos no estacionamento.

### Estrutura dos Veículos

Cada veículo é representado por uma estrutura `struct`, contendo informações como identificador, descrição, categoria e localização no estacionamento (linha e coluna).

### Vetor Dinâmico

Os veículos cadastrados são armazenados em um vetor dinâmico, inicialmente alocado para 2 elementos.

O sistema controla:

- **Quantidade:** número de veículos atualmente cadastrados.
- **Capacidade:** número de elementos que o vetor pode armazenar.

Quando a quantidade de veículos atinge a capacidade do vetor, a memória é redimensionada utilizando `realloc`, aumentando a capacidade de armazenamento.

O vetor possui limite máximo de 20 veículos, correspondente à capacidade total do estacionamento.

A memória é alocada inicialmente com `malloc` e liberada ao encerrar o programa utilizando `free`.

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

O trabalho foi desenvolvido individualmente, devido à dificuldade de encontrar uma dupla.

O desenvolvedor realizou a implementação das funcionalidades do sistema, organização do código, utilização das estruturas de dados, realização de testes, documentação e gerenciamento do repositório GitHub.

As responsabilidades pelas etapas do projeto foram assumidas pelo desenvolvedor.

## Controle de Versão

O projeto utiliza Git e GitHub para controle de versão, organização e registro do desenvolvimento.

A branch `Desenvolvimento-Individual` contém a versão consolidada do projeto.

O histórico de desenvolvimento também contém commits referentes às etapas de construção das funcionalidades.

**Observação:** o histórico das etapas foi organizado retrospectivamente após a conclusão do programa, com o objetivo de documentar a evolução das funcionalidades. Os commits correspondentes foram realizados posteriormente, não representando registros cronológicos originais de cada etapa de implementação.

## Etapas de Desenvolvimento

O histórico foi organizado em oito etapas:

1. Estrutura inicial e mapa do estacionamento.
2. Estrutura de veículo e validação de identificador.
3. Cadastro de veículos e controle de ocupação.
4. Implementação do vetor dinâmico e realocação de memória.
5. Implementação de consulta e atualização de veículos.
6. Implementação de movimentação e remoção de veículos.
7. Implementação de listagem e mapa identificado.
8. Relatório de ocupação e finalização do programa.

## Testes

Os testes foram realizados manualmente, por meio da execução do programa, verificando o funcionamento das funcionalidades implementadas e o tratamento de situações inválidas.

| Teste | Entrada / Operação | Resultado Esperado | Resultado Observado | Status |
|---|---|---|---|---|
| T01 – Estacionamento vazio | Iniciar o sistema sem veículos cadastrados. | O sistema deve apresentar o estacionamento vazio, com todas as vagas disponíveis. | O sistema iniciou corretamente, apresentando todas as vagas livres e nenhum veículo cadastrado. | Aprovado |
| T02 – Cadastro de veículo | Cadastrar um veículo com dados válidos e uma vaga disponível. | O veículo deve ser cadastrado com sucesso, ocupando a vaga escolhida. | O veículo foi cadastrado corretamente e a vaga passou a constar como ocupada. | Aprovado |
| T03 – Cadastro duplicado | Tentar cadastrar um veículo utilizando uma placa já registrada. | O sistema deve identificar a duplicidade e impedir o cadastro. | O sistema identificou a placa duplicada e impediu o novo cadastro. | Aprovado |
| T04 – Vaga inválida ou ocupada | Tentar cadastrar um veículo em uma vaga inválida ou já ocupada. | O sistema deve rejeitar a operação sem alterar os dados existentes. | O sistema recusou a operação e manteve os dados e a ocupação anteriores. | Aprovado |
| T05 – Expansão dinâmica | Cadastrar veículos até ultrapassar a capacidade inicial do vetor dinâmico. | O sistema deve ampliar a capacidade de armazenamento automaticamente, sem perda de dados. | A capacidade do vetor foi ampliada automaticamente e os registros anteriores foram preservados. | Aprovado |
| T06 – Atualização de cadastro | Selecionar um veículo cadastrado e alterar seus dados. | O sistema deve atualizar os dados do veículo corretamente. | Os dados do veículo foram atualizados com sucesso. | Aprovado |
| T07 – Movimentação de veículo | Transferir um veículo de uma vaga para outra vaga disponível. | O sistema deve liberar a vaga original e ocupar a nova vaga, mantendo a consistência dos dados. | A movimentação foi realizada corretamente, com atualização das vagas e dos dados do veículo. | Aprovado |
| T08 – Remoção de veículo | Remover um veículo previamente cadastrado. | O sistema deve excluir o registro, liberar a vaga e atualizar a quantidade de veículos. | O veículo foi removido corretamente, a vaga foi liberada e a quantidade de registros foi atualizada. | Aprovado |
| T09 – Lotação máxima | Cadastrar 20 veículos, ocupando todas as vagas, e tentar cadastrar o 21º veículo. | O sistema deve recusar o cadastro adicional, informar que o estacionamento está lotado e manter a quantidade de veículos em 20. | O sistema recusou o cadastro do 21º veículo, mantendo os 20 registros e todas as vagas ocupadas. | Aprovado |
| T10 – Liberação de memória | Encerrar o sistema após realizar operações de cadastro e remoção. | O sistema deve liberar corretamente a memória alocada dinamicamente. | A memória alocada dinamicamente foi liberada ao final da execução. | Aprovado |

## Uso de Inteligência Artificial

Utilizada inteligência artificial como ferramenta de apoio durante o desenvolvimento do trabalho.

A IA foi utilizada para:

- Auxiliar na compreensão de erros e na resolução.
- Auxiliar em partes do código que estava com dificuldade.
- Revisão final do código para garantir que estava correto.
- criação de commit no Git/GitHub.

### Exemplos de solicitações realizadas à IA

- Solicitação de auxílio para compreender e corrigir erros encontrados durante a compilação e execução.
- Solicitação de revisão do código por inteiro para garantir que estava correto.
- Solicitação de orientação para utilizar commits, branches e integração de alterações no GitHub Desktop.

## Referências

- Enunciado do trabalho disponibilizado na disciplina de Lógica de Programação e Algoritmos.
- KIPPER. *Aprenda Git e GitHub do zero – guia completo*. YouTube. Disponível em: https://youtu.be/pyM5QLS2h6M.
