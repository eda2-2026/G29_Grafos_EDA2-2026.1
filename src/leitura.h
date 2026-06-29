#ifndef LEITURA_H
#define LEITURA_H

#include "grafo.h"

void carregarVertices(Grafo *g, const char caminho[]);
void carregarArestas(Grafo *g, const char caminho[]);
void removerQuebraLinha(char str[]);

#endif
