#include <stdio.h>
#include <limits.h>
#include "dijkstra.h"

void dijkstra(Grafo *g, const char origem[], const char destino[]) {
    int dist[MAX_VERTICES];
    int visitado[MAX_VERTICES];
    int anterior[MAX_VERTICES];
    int caminho[MAX_VERTICES];
    int i;
    int contador;
    int atual;
    int menorDistancia;
    int tamanhoCaminho = 0;
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
        dist[i] = INF;
        visitado[i] = 0;
        anterior[i] = -1;
    }

    dist[iOrigem] = 0;

    for (contador = 0; contador < g->qtdVertices; contador++) {
        atual = -1;
        menorDistancia = INF;

        for (i = 0; i < g->qtdVertices; i++) {
            if (!visitado[i] && dist[i] < menorDistancia) {
                menorDistancia = dist[i];
                atual = i;
            }
        }

        if (atual == -1) {
            break;
        }

        visitado[atual] = 1;

        if (atual == iDestino) {
            break;
        }

        aresta = g->vertices[atual].lista;
        while (aresta != NULL) {
            if (!visitado[aresta->destino] &&
                dist[atual] != INF &&
                dist[atual] + aresta->peso < dist[aresta->destino]) {
                dist[aresta->destino] = dist[atual] + aresta->peso;
                anterior[aresta->destino] = atual;
            }

            aresta = aresta->prox;
        }
    }

    if (dist[iDestino] == INF) {
        printf("Nao existe caminho entre %s e %s.\n", origem, destino);
        return;
    }

    atual = iDestino;
    while (atual != -1) {
        caminho[tamanhoCaminho++] = atual;
        atual = anterior[atual];
    }

    printf("Menor caminho em metros:\n");
    for (i = tamanhoCaminho - 1; i >= 0; i--) {
        printf("%s", g->vertices[caminho[i]].sigla);
        if (i > 0) {
            printf(" -> ");
        }
    }
    printf("\n");
    printf("Distancia total: %d metros\n", dist[iDestino]);
}
