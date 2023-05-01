#include <stdlib.h>

typedef struct node {
  int info;
  struct node *esq;
  struct node *dir;
} no;

no *busca(no *raiz, int elem) {
  if (!raiz) {
    return NULL;
  }
  if (raiz->info == elem)
    return raiz;
  else if (elem < raiz->info)
    raiz->esq = busca(raiz->esq, elem);
  else if (elem > raiz->info) 
    raiz->dir = busca(raiz->dir, elem);
}