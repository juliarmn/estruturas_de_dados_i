
#include <stdlib.h>

typedef struct node {
  char c;
  struct node *esq;
  struct  node *dir; 
} no;
//ABB
no *libera_no (no *t) {
  no *aux;

  if (t->esq == NULL) {
    aux = t;
    *t = *(t)->dir;
    free(aux);
    return t;
  } else if (t->dir = NULL) {
    aux = t;
    *t = *(t)->esq;
    free(aux);
  } else {
    substitui_menor_dir(t, t->dir);
  }
}

void substitui_menor_dir(no *t, no *suc) {
  no *aux;
  if (suc->esq == NULL) {
    t->c = suc->c;
    aux = suc;
    *suc = *(suc)->dir
    free(aux);
  }
  else {
    substitui_menor_dir(t, aux->esq);
  }
}