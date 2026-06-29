# Explicacao do grafo

O projeto modela o Campus Darcy Ribeiro como um grafo. Essa modelagem e adequada porque o campus possui locais definidos e caminhos que ligam esses locais.

## Vertices

Cada vertice representa um local do campus. No arquivo `data/vertices_darcy.csv`, cada local possui:

- `id`: identificador numerico.
- `sigla`: codigo curto usado nas consultas.
- `nome`: nome completo do local.
- `tipo`: categoria do local.

Exemplos de vertices sao `RU`, `BCE`, `ICC_CENTRO` e `REITORIA`.

## Arestas

Cada aresta representa um caminho entre dois vertices. No arquivo `data/arestas_darcy.csv`, cada conexao possui origem, destino, peso em metros e tipo do caminho.

Quando existe uma aresta entre `RU` e `ICC_CENTRO`, significa que o programa pode considerar esse trecho como uma rota possivel.

## Pesos

O peso de cada aresta representa uma distancia aproximada em metros. Esses pesos permitem calcular rotas mais curtas por distancia total, nao apenas pela quantidade de locais visitados.

## Grafo nao direcionado

O grafo e nao direcionado porque os caminhos do campus podem ser percorridos nos dois sentidos. Assim, ao carregar uma aresta `A -> B`, o programa tambem registra `B -> A`.

## Grafo ponderado

O grafo e ponderado porque as arestas possuem valores numericos. Esses valores sao usados pelo algoritmo de Dijkstra para encontrar o menor caminho em metros.

## Lista de adjacencia

A representacao por lista de adjacencia guarda, para cada vertice, apenas os seus vizinhos diretos. Essa escolha economiza espaco quando o grafo nao tem conexoes entre todos os pares de vertices e tambem facilita percorrer os caminhos disponiveis a partir de um local.
