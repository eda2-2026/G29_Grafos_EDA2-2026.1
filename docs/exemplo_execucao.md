# Exemplo de execucao

Ao executar `make run`, o programa carrega os arquivos CSV e mostra o menu:

```txt
Grafo carregado com 36 vertices e 52 arestas.

========= ROTAS CAMPUS DARCY =========

1 - Mostrar locais cadastrados
2 - Mostrar grafo
3 - Fazer busca em profundidade DFS
4 - Fazer busca em largura BFS
5 - Verificar se existe caminho entre dois locais usando DFS
6 - Buscar caminho com menor numero de paradas usando BFS
7 - Buscar menor caminho em metros usando Dijkstra
8 - Mostrar estatisticas do grafo
0 - Sair
```

## Listar locais

```txt
Opcao: 1
Locais cadastrados:
16 | RU                 | Restaurante Universitario | servico
17 | BCE                | Biblioteca Central        | servico
```

## Imprimir grafo

```txt
Opcao: 2
Lista de adjacencia:
RU: -> FE(320 m) -> ICC_CENTRO(120 m)
BCE: -> PMU_II(300 m) -> PMU_I(250 m) -> REITORIA(230 m)
```

## DFS

```txt
Opcao: 3
Digite a sigla de origem: RU
DFS a partir de RU:
RU FE UNBTV CDT_DPI_DPG PONTO_L3_CENTRO HUB ...
```

## BFS

```txt
Opcao: 4
Digite a sigla de origem: RU
BFS a partir de RU:
RU FE ICC_CENTRO UNBTV FT ICC_SUL ICC_NORTE ...
```

## Verificar caminho com DFS

```txt
Opcao: 5
Digite a sigla de origem: RU
Digite a sigla de destino: BCE
Existe caminho entre RU e BCE.
```

## Menor caminho por paradas

```txt
Opcao: 6
Digite a sigla de origem: RU
Digite a sigla de destino: BCE
Menor caminho em numero de paradas:
RU -> ICC_CENTRO -> ICC_SUL -> BCE
Quantidade de arestas: 3
Quantidade de paradas intermediarias: 2
```

## Menor caminho por distancia

```txt
Opcao: 7
Digite a sigla de origem: RU
Digite a sigla de destino: BCE
Menor caminho em metros:
RU -> ICC_CENTRO -> ICC_SUL -> BCE
Distancia total: 730 metros
```

## Sigla inexistente

```txt
Opcao: 7
Digite a sigla de origem: RU
Digite a sigla de destino: XYZ
Erro: sigla de destino nao encontrada: XYZ
```
