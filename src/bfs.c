#include <stdio.h>
#include "bfs.h"

void bfs(Grafo *g, const char origem[]) {
    int visitado[MAX_VERTICES] = {0};
    int fila[MAX_VERTICES];
    int inicio = 0;
    int fim = 0;
    int iOrigem = buscarIndicePorSigla(g, origem);
    int atual;
    Aresta *aresta;

    if (iOrigem == -1) {
        printf("Erro: sigla de origem nao encontrada: %s\n", origem);
        return;
    }

    visitado[iOrigem] = 1;
    fila[fim++] = iOrigem;

    printf("BFS a partir de %s:\n", origem);

    while (inicio < fim) {
        atual = fila[inicio++];
        printf("%s ", g->vertices[atual].sigla);

        aresta = g->vertices[atual].lista;
        while (aresta != NULL) {
            if (!visitado[aresta->destino]) {
                visitado[aresta->destino] = 1;
                fila[fim++] = aresta->destino;
            }

            aresta = aresta->prox;
        }
    }

    printf("\n");
}

void menorCaminhoParadasBFS(Grafo *g, const char origem[], const char destino[]) {
    int visitado[MAX_VERTICES] = {0};
    int anterior[MAX_VERTICES];
    int fila[MAX_VERTICES];
    int caminho[MAX_VERTICES];
    int inicio = 0;
    int fim = 0;
    int i;
    int atual;
    int tamanhoCaminho = 0;
    int qtdArestas;
    int paradasIntermediarias;
    int iOrigem = buscarIndicePorSigla(g, origem);
    int iDestino = buscarIndicePorSigla(g, destino);
    Aresta *aresta;

    if (iOrigem == -1) {
        printf("Erro: sigla de origem nao encontrada: %s\n", origem);
        return;
    }

    if (iDestino == -1) {
        printf("Erro: sigla de destino nao encontrada: %s\n", destino);
        return;
    }

    for (i = 0; i < MAX_VERTICES; i++) {
        anterior[i] = -1;
    }

    visitado[iOrigem] = 1;
    fila[fim++] = iOrigem;

    while (inicio < fim) {
        atual = fila[inicio++];

        if (atual == iDestino) {
            break;
        }

        aresta = g->vertices[atual].lista;
        while (aresta != NULL) {
            if (!visitado[aresta->destino]) {
                visitado[aresta->destino] = 1;
                anterior[aresta->destino] = atual;
                fila[fim++] = aresta->destino;
            }

            aresta = aresta->prox;
        }
    }

    if (!visitado[iDestino]) {
        printf("Nao existe caminho entre %s e %s.\n", origem, destino);
        return;
    }

    atual = iDestino;
    while (atual != -1) {
        caminho[tamanhoCaminho++] = atual;
        atual = anterior[atual];
    }

    printf("Menor caminho em numero de paradas:\n");
    for (i = tamanhoCaminho - 1; i >= 0; i--) {
        printf("%s", g->vertices[caminho[i]].sigla);
        if (i > 0) {
            printf(" -> ");
        }
    }
    printf("\n");

    qtdArestas = tamanhoCaminho - 1;
    paradasIntermediarias = qtdArestas > 0 ? qtdArestas - 1 : 0;

    printf("Quantidade de arestas: %d\n", qtdArestas);
    printf("Quantidade de paradas intermediarias: %d\n", paradasIntermediarias);
}
