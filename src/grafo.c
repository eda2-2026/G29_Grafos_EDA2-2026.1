#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

static void copiarTexto(char destino[], const char origem[], int tamanho) {
    if (tamanho <= 0) {
        return;
    }

    if (origem == NULL) {
        destino[0] = '\0';
        return;
    }

    strncpy(destino, origem, (size_t)tamanho - 1);
    destino[tamanho - 1] = '\0';
}

static Aresta *criarAresta(int destino, int peso) {
    Aresta *nova = (Aresta *)malloc(sizeof(Aresta));

    if (nova == NULL) {
        printf("Erro ao alocar memoria para aresta.\n");
        return NULL;
    }

    nova->destino = destino;
    nova->peso = peso;
    nova->prox = NULL;

    return nova;
}

void inicializarGrafo(Grafo *g) {
    int i;

    g->qtdVertices = 0;

    for (i = 0; i < MAX_VERTICES; i++) {
        g->vertices[i].id = 0;
        g->vertices[i].sigla[0] = '\0';
        g->vertices[i].nome[0] = '\0';
        g->vertices[i].tipo[0] = '\0';
        g->vertices[i].lista = NULL;
    }
}

int buscarIndicePorSigla(Grafo *g, const char sigla[]) {
    int i;

    for (i = 0; i < g->qtdVertices; i++) {
        if (strcmp(g->vertices[i].sigla, sigla) == 0) {
            return i;
        }
    }

    return -1;
}

int adicionarVertice(Grafo *g, int id, const char sigla[], const char nome[], const char tipo[]) {
    if (g->qtdVertices >= MAX_VERTICES) {
        printf("Erro: limite maximo de vertices atingido.\n");
        return 0;
    }

    if (buscarIndicePorSigla(g, sigla) != -1) {
        printf("Aviso: vertice com sigla %s ja existe e foi ignorado.\n", sigla);
        return 0;
    }

    g->vertices[g->qtdVertices].id = id;
    copiarTexto(g->vertices[g->qtdVertices].sigla, sigla, MAX_SIGLA);
    copiarTexto(g->vertices[g->qtdVertices].nome, nome, MAX_NOME);
    copiarTexto(g->vertices[g->qtdVertices].tipo, tipo, MAX_TIPO);
    g->vertices[g->qtdVertices].lista = NULL;

    g->qtdVertices++;

    return 1;
}

static void inserirArestaNaLista(Grafo *g, int origem, Aresta *nova) {
    nova->prox = g->vertices[origem].lista;
    g->vertices[origem].lista = nova;
}

void adicionarAresta(Grafo *g, const char origem[], const char destino[], int peso) {
    int iOrigem = buscarIndicePorSigla(g, origem);
    int iDestino = buscarIndicePorSigla(g, destino);
    Aresta *ida;
    Aresta *volta;

    if (iOrigem == -1 || iDestino == -1) {
        printf("Erro: nao foi possivel adicionar aresta %s -> %s. Sigla inexistente.\n",
               origem, destino);
        return;
    }

    ida = criarAresta(iDestino, peso);
    volta = criarAresta(iOrigem, peso);

    if (ida == NULL || volta == NULL) {
        free(ida);
        free(volta);
        return;
    }

    inserirArestaNaLista(g, iOrigem, ida);
    inserirArestaNaLista(g, iDestino, volta);
}

void listarVertices(Grafo *g) {
    int i;

    if (g->qtdVertices == 0) {
        printf("Nenhum local cadastrado.\n");
        return;
    }

    printf("Locais cadastrados:\n");
    for (i = 0; i < g->qtdVertices; i++) {
        printf("%2d | %-18s | %-70s | %s\n",
               g->vertices[i].id,
               g->vertices[i].sigla,
               g->vertices[i].nome,
               g->vertices[i].tipo);
    }
}

void imprimirGrafo(Grafo *g) {
    int i;
    Aresta *atual;

    if (g->qtdVertices == 0) {
        printf("Grafo vazio.\n");
        return;
    }

    printf("Lista de adjacencia:\n");
    for (i = 0; i < g->qtdVertices; i++) {
        printf("%s: ", g->vertices[i].sigla);

        atual = g->vertices[i].lista;

        while (atual != NULL) {
            printf("-> %s(%d m) ",
                   g->vertices[atual->destino].sigla,
                   atual->peso);
            atual = atual->prox;
        }

        printf("\n");
    }
}

int quantidadeArestas(Grafo *g) {
    int i;
    int total = 0;
    Aresta *atual;

    for (i = 0; i < g->qtdVertices; i++) {
        atual = g->vertices[i].lista;
        while (atual != NULL) {
            total++;
            atual = atual->prox;
        }
    }

    return total / 2;
}

void estatisticasGrafo(Grafo *g) {
    int i;
    int grau;
    int maiorGrau = 0;
    int indiceMaiorGrau = -1;
    int isolados = 0;
    Aresta *atual;

    for (i = 0; i < g->qtdVertices; i++) {
        grau = 0;
        atual = g->vertices[i].lista;

        while (atual != NULL) {
            grau++;
            atual = atual->prox;
        }

        if (grau == 0) {
            isolados++;
        }

        if (grau > maiorGrau) {
            maiorGrau = grau;
            indiceMaiorGrau = i;
        }
    }

    printf("Estatisticas do grafo:\n");
    printf("Quantidade de vertices: %d\n", g->qtdVertices);
    printf("Quantidade de arestas: %d\n", quantidadeArestas(g));
    printf("Vertices isolados: %d\n", isolados);

    if (indiceMaiorGrau != -1) {
        printf("Maior grau: %s com %d conexoes\n",
               g->vertices[indiceMaiorGrau].sigla,
               maiorGrau);
    }
}

void liberarGrafo(Grafo *g) {
    int i;
    Aresta *atual;
    Aresta *temp;

    for (i = 0; i < g->qtdVertices; i++) {
        atual = g->vertices[i].lista;

        while (atual != NULL) {
            temp = atual;
            atual = atual->prox;
            free(temp);
        }

        g->vertices[i].lista = NULL;
    }

    g->qtdVertices = 0;
}
