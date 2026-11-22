## Sistema de Controle de Estacionamento

## Descrição do Projeto

Sistema desenvolvido em linguagem C para controle de um estacionamento com capacidade para 20, distribuídos em 4 fileiras e 5 colunas.

O sistema permite cadastrar, consultar, atualizar, movimentar, remover e listar veículos, além de exibir o mapa do estacionamento e um relatório de ocupação.

## Funcionalidades

- Cadastro de veículos.
- Consulta de veículos por identificador.
- Atualização de descrição e categoria.
- Movimentação de veículos entre vagas.
- Remoção de veículos.
- Listagem de veículos cadastrados.
- Visualização do mapa do estacionamento.
- Relatório de ocupação.
- Controle de vagas disponíveis e ocupadas.

## Estruturas de Dados

O sistema utiliza:

- Estrutura struct para representar os veículos.
- Matriz para representar as vagas do estacionamento.
- Vetor dinâmico para armazenar os veículos cadastrados.
- Alocação dinâmica de memória utilizando malloc e reallocz.
- Funções para modularização das operações do sistema.

## Organização dos Arquivos

Estacionamento/
├── README.md
└── src/
    └── main.c

## Compilação

O programa pode ser compilado utilizando o GCC, com suporte ao padrão C11.

Comando de compilação:

---
bash
gcc -std=c11 -Wall -Wextra -pedantic src/main.c -o estacionamento
---

--Execução--

Após a compilação, execute o programa através do terminal.

No Windows:

---
cmd
estacionamento.exe
---

## Limitações

Os dados cadastrados permanecem disponíveis somente durante a execução do programa. Ao encerrar o sistema, os dados são perdidos.

O sistema possui capacidade máxima de 20 veículos, correspondente à quantidade de vagas disponíveis.

## Desenvolvimento

Projeto desenvolvido individualmente, devido à
dificuldade de encontrar uma dupla para realizar o trabalho.

## Controle de Versão

O projeto utiliza Git e GitHub para controle de versão,
organização e registro do desenvolvimento.

O desenvolvimento está sendo realizado na branch
`Desenvolvimento-Individual`.