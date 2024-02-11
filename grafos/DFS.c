#include "dfs.h"

int tempo = 0;

struct No {
    int elem;
    struct No *prox;
    int visitado;
    int encontrado;
    int final;
};

struct Grafo {
    no **node;
    int num_vert;
};

no *inicializar_no_vazio() {
    no *n = malloc(sizeof(no));
    if (n == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para nó\n");
        exit(EXIT_FAILURE);
    }
    n->elem = 0;
    n->prox = NULL;
    n->visitado = 0; // 0 = branco
    n->encontrado = 0; // ainda nao foi encontrado
    n->final = 0;
    return n;
}

grafo *inicializar_grafo_vazio(int num_vertices) {
    grafo *g = malloc(sizeof(grafo));
    if (g == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para grafo\n");
        exit(EXIT_FAILURE);
    }
    g->node = malloc(num_vertices * sizeof(no *));
    for (int i = 0 ; i < num_vertices; i ++) {
        g->node[i] = malloc(sizeof(no));
    }
    if (g->node == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para nós do grafo\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_vertices; i++) {
        g->node[i]->elem = 0;
        g->node[i]->prox = NULL;
        g->node[i]->visitado = 0;
        g->node[i]->encontrado = 0;
        g->node[i]->final = 0;
    }
    g->num_vert = num_vertices;

    return g;
}

grafo *inserir_grafo(int v1, int v2, grafo *g) {
    no *novo_no = inicializar_no_vazio();
    novo_no->elem = v2;

    novo_no->prox = NULL; // Inicializando o ponteiro próximo como NULL

    if (g->node[v1-1]->prox == NULL) {
        g->node[v1-1]->prox = novo_no;
    } else {
        no *aux = g->node[v1-1]->prox;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo_no;
    }
    return g;
}

void dfs_visitado(no *node, grafo *g) {
    printf("%d", node->elem);
    node->visitado = 1; // cinza
    tempo++;
    node->encontrado = tempo;
    no *aux = node->prox;
    while (aux) {
        if (aux->visitado == 0) {
            aux->visitado = 1;
            dfs_visitado(aux, g); // Passando o ponteiro do grafo por referência
            tempo++;
        }
        aux = aux->prox;
    }
    node->visitado = 2; // preto
    node->final = tempo;
}

int *dfs(grafo *g) {
    int *visitado;
    visitado = malloc(g->num_vert * sizeof(int));
    if (visitado == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para vetor de visitados\n");
        exit(EXIT_FAILURE);
    }

    int indice = 0; 

    for (int i = 0; i < g->num_vert; i++) {
        if (g->node[i]->visitado == 0) {
            dfs_visitado(g->node[i], g);
        }
    }

    for (int i = 0; i < g->num_vert; i++) {
        if (g->node[i]->visitado == 2) {
            visitado[indice] = g->node[i]->elem;
            indice++;
        }
    }

    return visitado;
}

void imprimir_grafo(grafo *g) {
    for (int i = 0; i < g->num_vert; i++) {
        printf("Nó %d: ", i+1);
        no *atual = g->node[i]->prox;
        while (atual != NULL) {
            printf("%d ", atual->elem);
            atual = atual->prox;
        }
        printf("\n");
    }
}



