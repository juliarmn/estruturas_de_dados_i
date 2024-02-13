#include "dfs.h"

int main () {
    grafo *g = criar_grafo(5);
    adicionar_relacao(g, 0, 1);
    adicionar_relacao(g, 0, 2);
    adicionar_relacao(g, 0, 3);
    adicionar_relacao(g, 1, 2);
    adicionar_relacao(g, 2, 4);

    imprimir_grafo(g);

    dfs(g, 0);

    return 0;
}
