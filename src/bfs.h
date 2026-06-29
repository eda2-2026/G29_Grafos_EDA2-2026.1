#ifndef BFS_H
#define BFS_H

#include "grafo.h"

void bfs(Grafo *g, const char origem[]);
void menorCaminhoParadasBFS(Grafo *g, const char origem[], const char destino[]);

#endif
