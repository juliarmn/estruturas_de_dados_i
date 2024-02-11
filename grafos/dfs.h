#ifndef EDI_DFS_H
#define EDI_DFS_H
#include <stdio.h>
#include <stdlib.h>
typedef struct No no;
typedef struct Grafo grafo;
no * inicializar_no_vazio ();
grafo * inicializar_grafo_vazio (int num_vertices);
grafo * inserir_grafo (int v1, int v2, grafo *g);
void dfs_visitado(no *node, grafo *g);
int * dfs (grafo *g);
void imprimir_grafo(grafo *g);
#endif //EDI_DFS_H
