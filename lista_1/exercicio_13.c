// Achar o menor valor de uma ABB:
#include <stdlib.h>

typedef struct node {
  int info;
  struct node *esq;
  struct node *dir;
} no;

int menor_valor (no *t) {
  if (!t) {
    return 0;
  }
  while (!(t->esq)) {
    t = t->esq;
  }
  return t->info;
}

//Recursiva:
int menor_valor_rec(no *t) {
  if (!(t)->esq)
    return t->info;
  return menor_valor_rec(t->esq);
}