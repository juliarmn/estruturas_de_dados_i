#include <iostream>
#include <list>
using namespace std;

class Grafo {
    int num_vertice;
    list<int> *vertice_adj;
    bool *visitados;

public:
    Grafo(int v);
    void dfs(int v);
    void adicionar_relacao(int origem, int destino);

};

Grafo::Grafo(int v) {
    num_vertice = v;
    vertice_adj = new list<int>[num_vertice];
    visitados = new bool[v];
}

void Grafo::adicionar_relacao (int origem, int destino) {
    vertice_adj[origem].push_front(destino);
}

void Grafo::dfs(int v) {
    visitados[v] = true;
    cout << v << " ";
    list <int> adj = vertice_adj[v];
    list <int>::iterator i;
    for (i = adj.begin(); i != adj.end(); ++i) {
        if (!visitados[*i])
            dfs(*i);
    }
}

int main() {
    Grafo g(5);
    g.adicionar_relacao(0, 1);
    g.adicionar_relacao(0, 2);
    g.adicionar_relacao(0, 3);
    g.adicionar_relacao(1, 2);
    g.adicionar_relacao(2, 4);

    g.dfs(0);

    return 0;
}
