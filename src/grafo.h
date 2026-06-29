#ifndef GRAFO_H
#define GRAFO_H

#define MAX_VERTICES 100
#define MAX_SIGLA 50
#define MAX_NOME 150
#define MAX_TIPO 50
#define INF 999999999

typedef struct Aresta {
    int destino;
    int peso;
    struct Aresta *prox;
} Aresta;

typedef struct {
    int id;
    char sigla[MAX_SIGLA];
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    Aresta *lista;
} Vertice;

typedef struct {
    Vertice vertices[MAX_VERTICES];
    int qtdVertices;
} Grafo;

void inicializarGrafo(Grafo *g);
int adicionarVertice(Grafo *g, int id, const char sigla[], const char nome[], const char tipo[]);
void adicionarAresta(Grafo *g, const char origem[], const char destino[], int peso);
int buscarIndicePorSigla(Grafo *g, const char sigla[]);
void listarVertices(Grafo *g);
void imprimirGrafo(Grafo *g);
void liberarGrafo(Grafo *g);
int quantidadeArestas(Grafo *g);
void estatisticasGrafo(Grafo *g);

#endif
