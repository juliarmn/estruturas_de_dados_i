#ifndef EDI_DFS_H
#define EDI_DFS_H
#include <stdio.h>
#include <stdlib.h>
typedef struct Grafo grafo;
typedef struct No no;
no * criar_no (int vertice);
grafo * criar_grafo (int num_vertices);
void adicionar_relacao (grafo *g, int origem, int destino);
void dfs (grafo *g, int v);
void imprimir_grafo(grafo *g);

#endif //EDI_DFS_H
