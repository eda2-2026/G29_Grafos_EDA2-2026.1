# Algoritmos implementados

## DFS

DFS significa busca em profundidade. O algoritmo parte de um vertice inicial e segue um caminho o mais longe possivel antes de voltar para explorar alternativas.

- Objetivo: visitar vertices alcancaveis a partir de uma origem.
- Uso no projeto: listar a ordem de visita, verificar se existe caminho entre dois locais e testar se o grafo e conexo.
- Entrada: grafo e sigla de origem; em algumas funcoes, tambem a sigla de destino.
- Saida: vertices visitados, resposta sobre existencia de caminho ou resposta sobre conectividade.
- Complexidade aproximada: `O(V + E)`, em que `V` e a quantidade de vertices e `E` a quantidade de arestas.

## BFS

BFS significa busca em largura. O algoritmo visita primeiro os vizinhos mais proximos da origem, depois os vizinhos desses vizinhos, e assim por diante.

- Objetivo: visitar vertices por nivel.
- Uso no projeto: mostrar a busca em largura e encontrar o caminho com menor numero de arestas entre dois locais.
- Entrada: grafo e sigla de origem; para caminho minimo por paradas, tambem a sigla de destino.
- Saida: ordem de visita ou caminho com menor numero de paradas.
- Complexidade aproximada: `O(V + E)`.

## Dijkstra

Dijkstra encontra o menor caminho em um grafo ponderado com pesos nao negativos.

- Objetivo: calcular a menor distancia total entre origem e destino.
- Uso no projeto: buscar a rota mais curta em metros.
- Entrada: grafo, sigla de origem e sigla de destino.
- Saida: caminho reconstruido e distancia total em metros.
- Complexidade aproximada: `O(V^2 + E)` nesta implementacao, pois a escolha do proximo vertice e feita por varredura simples em vetor.
