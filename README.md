# 42-get_next_line

O projeto *get_next_line* tem como objetivo implementar a função `get_next_line`, que lê uma linha de um arquivo de texto e retorna essa linha. A função deve ser capaz de lidar com arquivos grandes e ler os dados de maneira eficiente, linha por linha.

## Objetivo

O principal desafio deste projeto é entender e implementar o conceito de leitura em buffers, manipulação de strings e alocação dinâmica de memória. A função deve retornar uma linha de cada vez de um arquivo até que não haja mais linhas para ler.

## Funcionalidades Implementadas

- **get_next_line**: Lê uma linha de um arquivo de texto e a retorna. A função deve ser capaz de lidar com arquivos de tamanho indefinido e utilizar buffers para otimizar a leitura.
- Suporte para múltiplos arquivos abertos simultaneamente, garantindo que a leitura seja feita de maneira independente para cada arquivo.
- O fim do arquivo é identificado corretamente, e a função retorna `NULL` quando não há mais dados a serem lidos.

## Como Compilar

1. Clone o repositório:
   ```bash
   git clone https://github.com/eliandrosergio/get_next_line.git
   cd get_next_line
