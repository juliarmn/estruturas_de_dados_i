#ifndef BUSCA_TREE_H
#define BUSCA_TREE_H
#include <stdbool.h>
typedef int tipo_chave;
typedef struct dado tipo_dado;
typedef struct tree t;
t* criar_raiz(t *raiz, tipo_dado elem);
t* insere(t *raiz, tipo_dado elem);
t* buscar_na_tree(t* raiz, tipo_dado elems);
t* busca_nao_rec(t *raiz, tipo_dado elem);
t* remover(t* raiz, tipo_dado elem);
t* get_max(t* raiz);
void inOrder(t *root);
void purge(t *raiz);
#endif