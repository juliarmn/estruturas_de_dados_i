// Essa  foi do carai

#include <stdlib.h>

typedef struct node {
  int info;
  struct node *esq;
  struct node *dir;
} no;

int *menores_valores (no *t, int num) {
  int tam = tam_arv(t);
  int *vet = malloc(tam * sizeof(int));
  int indice = 0;
  menores_valores_rec(t, vet, indice, num);
  return vet;
}

int *menores_valores_rec (no *t, int *vet, int indice, int num) {
  if (!t)
    return vet;
  menores_valores_rec(t->esq, vet, indice, num);
  if (t->info < num) {
    vet[indice] = t->info;
    indice ++;
  }
  menores_valores_rec(t->dir, vet, indice, num);
  return vet;
}

int tam_arv(no *t) {
  if (!t)
    return 0;
  return 1 + tam_arv(t->dir) + tam_arv(t->esq);
}