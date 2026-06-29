#ifndef DFS_H
#define DFS_H

#include "grafo.h"

void dfs(Grafo *g, const char origem[]);
int existeCaminhoDFS(Grafo *g, const char origem[], const char destino[]);
int grafoConexoDFS(Grafo *g);

#endif
