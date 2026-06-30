# grafo-campus-darcy

Projeto em C que representa o Campus Darcy Ribeiro da Universidade de Brasilia como um grafo de rotas.

Os locais do campus sao vertices, os caminhos entre locais sao arestas e o peso de cada aresta representa uma distancia aproximada em metros. O programa carrega os dados dos arquivos CSV da pasta `data/` e permite consultar o grafo por meio de um menu interativo.

## Alunos

| Matrícula | Nome |
| -- | -- |
| 241025327 | Matheus Eiki Kimura |

## Vídeo de Apresentação

[[Link da Apresentação](https://youtu.be/eTUFxdjU850)]


## Modelagem

- Vertices: locais do campus, identificados por `id`, `sigla`, `nome` e `tipo`.
- Arestas: caminhos entre dois locais.
- Grafo nao direcionado: um caminho pode ser percorrido nos dois sentidos.
- Grafo ponderado: cada aresta possui um peso em metros.
- Lista de adjacencia: foi usada porque guarda apenas as conexoes existentes e facilita percorrer os vizinhos de cada local.

## Algoritmos implementados

- DFS: visita em profundidade, verifica existencia de caminho e testa conectividade.
- BFS: visita em largura e encontra o caminho com menor numero de arestas/paradas.
- Dijkstra: encontra o menor caminho considerando a soma das distancias em metros.

## Como compilar

```bash
make
```

Tambem e possivel compilar manualmente:

```bash
gcc -Wall -Wextra -std=c99 src/*.c -o campus
```

## Como executar

```bash
make run
```

O programa deve ser executado a partir da raiz do projeto, pois os caminhos dos dados sao:

```txt
data/vertices_darcy.csv
data/arestas_darcy.csv
```

## Exemplos de uso

No menu, use:

- `1` para listar os locais cadastrados.
- `2` para imprimir a lista de adjacencia.
- `3` para executar DFS a partir de uma sigla.
- `4` para executar BFS a partir de uma sigla.
- `5` para verificar se existe caminho entre duas siglas usando DFS.
- `6` para buscar o menor caminho em numero de paradas usando BFS.
- `7` para buscar o menor caminho em metros usando Dijkstra.

Exemplo de consulta:

```txt
Digite a sigla de origem: RU
Digite a sigla de destino: BCE
```

## Estrutura do repositorio

```txt
data/
  mapa_darcy_grafo.txt
  vertices_darcy.csv
  arestas_darcy.csv
src/
  main.c
  grafo.c
  grafo.h
  leitura.c
  leitura.h
  bfs.c
  bfs.h
  dfs.c
  dfs.h
  dijkstra.c
  dijkstra.h
docs/
  explicacao_grafo.md
  algoritmos.md
  exemplo_execucao.md
README.md
Makefile
.gitignore
```

## Fontes dos dados

Os dados-base usados pelo programa estao nos arquivos da pasta `data/`. Nenhuma fonte externa adicional e necessaria para a execucao.
