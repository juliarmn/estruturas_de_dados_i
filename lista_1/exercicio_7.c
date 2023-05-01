// Verificar se a árvore binária é cheia:
#include <stdbool.h>
#include <stdlib.h>
typedef struct Tree {
  int info;
  struct Tree *esq;
  struct Tree *dir;
}tree;
bool arv_cheia(tree *t) {
  if (!t) {
    return false;
  }
  if ((t->esq == NULL && t->dir != NULL) || (t->esq != NULL && t->dir == NULL)) {
    return false;
  }
  int altura_dir = calc_altura(t->dir);//Função que calcularia altura genérica
  int altura_esq = calc_altura(t->esq);//Função que calcularia altura genérica
  if (altura_dir != altura_esq) {
    return false;
  }
  if (t->esq == NULL && t->dir == NULL)
    return true;
  return arv_cheia(t->dir) && arv_cheia(t->esq);
}