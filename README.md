# Sistema de Controle de Estacionamento

## Descrição do Projeto

Sistema desenvolvido em linguagem C para controle de um estacionamento com capacidade para 20 veículos, distribuídos em 4 fileiras e 5 colunas.

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

- Estrutura `struct` para representar os veículos.
- Matriz para representar as vagas do estacionamento.
- Vetor dinâmico para armazenar os veículos cadastrados.
- Alocação dinâmica de memória utilizando `malloc` e `realloc`.
- Funções para modularização das operações do sistema.

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

## Desenvolvimento

Projeto desenvolvido individualmente, devido à dificuldade de encontrar uma dupla para realizar o trabalho.

## Controle de Versão

O projeto utiliza Git e GitHub para controle de versão, organização e registro do desenvolvimento.

O desenvolvimento está sendo realizado na branch `Desenvolvimento-Individual`.

## Testes

Os testes foram realizados manualmente, por meio da execução do programa,
verificando o funcionamento das funcionalidades implementadas e o tratamento
de situações inválidas.

| Teste | Descrição | Resultado Esperado | Resultado Obtido | Status |
|---|---|---|---|---|
| T01 | Inicialização do estacionamento vazio | Todas as 20 vagas devem estar livres | Sistema iniciado corretamente, com todas as vagas disponíveis | Aprovado |
| T02 | Cadastro de veículo | Veículo deve ser cadastrado na vaga escolhida | Cadastro realizado com sucesso | Aprovado |
| T03 | Cadastro com identificador duplicado | Cadastro deve ser recusado | Identificador duplicado recusado | Aprovado |
| T04 | Tentativa de ocupar vaga já ocupada | Operação deve ser recusada | Vaga ocupada identificada e operação recusada | Aprovado |
| T05 | Aumento da coleção dinâmica | Capacidade deve aumentar quando necessário | Coleção expandida corretamente | Aprovado |
| T06 | Atualização de veículo | Dados devem ser atualizados | Dados atualizados corretamente | Aprovado |
| T07 | Movimentação de veículo | Veículo deve ocupar nova vaga e liberar a anterior | Movimentação realizada corretamente | Aprovado |
| T08 | Remoção de veículo | Veículo removido e vaga liberada | Remoção realizada corretamente | Aprovado |
| T09 | Relatório de ocupação | Quantidade de vagas ocupadas e livres deve ser correta | Relatório apresentado corretamente | Aprovado |
| T10 | Encerramento do programa | Programa deve encerrar corretamente | Programa encerrado | Aprovado |
