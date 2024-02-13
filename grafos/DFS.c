#include "dfs.h"

struct No {
    int vertice;
    struct No *prox;
};

struct Grafo {
    int num_vert;
    int *visitado;
    struct No **lista_adj;
};

no * criar_no (int vertice) {
    no *novo = malloc(sizeof(no));
    novo->vertice = vertice;
    novo->prox = NULL;
    return novo;
}

grafo * criar_grafo (int num_vertices) {
    int i = 0;
    grafo *g = malloc(sizeof(grafo));
    g->num_vert = num_vertices;
    g->lista_adj = malloc(num_vertices*sizeof(no*));
    g->visitado = calloc(num_vertices, sizeof(int));

    for (; i < num_vertices; i ++)
        g->lista_adj[i] = NULL;
    return g;
}

void adicionar_relacao (grafo *g, int origem, int destino) {
    no *novo = criar_no(destino);
    novo->prox = g->lista_adj[origem];
    g->lista_adj[origem] = novo;
    novo = criar_no(origem);
    novo->prox = g->lista_adj[destino];
    g->lista_adj[destino] = novo;
}

void dfs (grafo *g, int v) {
    g->visitado[v] = 1;
    printf("[%d] ", v);

    no *adj = g->lista_adj[v];
    no *aux = adj;

    while (aux != NULL) {
        int conectado = aux->vertice;

        if (g->visitado[conectado] == 0) {
            dfs(g, conectado);
        }
        aux = aux->prox;
    }
}


void imprimir_grafo(grafo *g) {
    int v;
    for (v = 0; v < g->num_vert; v++) {
        no* temp = g->lista_adj[v];
        printf("%d|  ", v);
        while (temp) {
            printf("%d -> ", temp->vertice);
            temp = temp->prox;
        }
        printf("\n");
    }
}

