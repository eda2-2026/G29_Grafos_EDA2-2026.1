#include <stdio.h>
#include "dfs.h"

static void marcarDFS(Grafo *g, int indice, int visitado[]) {
    Aresta *atual;

    visitado[indice] = 1;
    atual = g->vertices[indice].lista;

    while (atual != NULL) {
        if (!visitado[atual->destino]) {
            marcarDFS(g, atual->destino, visitado);
        }

        atual = atual->prox;
    }
}

static void imprimirDFS(Grafo *g, int indice, int visitado[]) {
    Aresta *atual;

    visitado[indice] = 1;
    printf("%s ", g->vertices[indice].sigla);

    atual = g->vertices[indice].lista;
    while (atual != NULL) {
        if (!visitado[atual->destino]) {
            imprimirDFS(g, atual->destino, visitado);
        }

        atual = atual->prox;
    }
}

void dfs(Grafo *g, const char origem[]) {
    int visitado[MAX_VERTICES] = {0};
    int iOrigem = buscarIndicePorSigla(g, origem);

    if (iOrigem == -1) {
        printf("Erro: sigla de origem nao encontrada: %s\n", origem);
        return;
    }

    printf("DFS a partir de %s:\n", origem);
    imprimirDFS(g, iOrigem, visitado);
    printf("\n");
}

int existeCaminhoDFS(Grafo *g, const char origem[], const char destino[]) {
    int visitado[MAX_VERTICES] = {0};
    int iOrigem = buscarIndicePorSigla(g, origem);
    int iDestino = buscarIndicePorSigla(g, destino);

    if (iOrigem == -1) {
        printf("Erro: sigla de origem nao encontrada: %s\n", origem);
        return 0;
    }

    if (iDestino == -1) {
        printf("Erro: sigla de destino nao encontrada: %s\n", destino);
        return 0;
    }

    marcarDFS(g, iOrigem, visitado);
    return visitado[iDestino];
}

int grafoConexoDFS(Grafo *g) {
    int visitado[MAX_VERTICES] = {0};
    int i;

    if (g->qtdVertices == 0) {
        return 0;
    }

    marcarDFS(g, 0, visitado);

    for (i = 0; i < g->qtdVertices; i++) {
        if (!visitado[i]) {
            return 0;
        }
    }

    return 1;
}
