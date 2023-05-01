#include<stdlib.h>

typedef struct no {
  char info;
  struct no *esq;
  struct no *dir;
}no;

//a)
int vazia (no *raiz) {
  if (!raiz) 
    return 1;
  return 0;
}

//b)
no *cria_no(char c, no *esq, no *dir) {
  no *novo = malloc(sizeof(no));
  if(!novo) {
    printf("Não tem memória suficiente\n");
    return NULL;
  }
  novo->info = c;
  novo->dir = dir;
  novo->esq = esq;
  return novo;
}

//c)
// Detalhe: essas funções do wallas funcionam no replit
// Mas no vscode ele aponta que há erros de ponteiro
no *libera_no(no *t) {
  no aux;
  if (!t)
    return NULL;
  if ((*t)->esq == NULL) {
    aux = *t;
    *t = (*t)->dir;
    free(aux);
    return t;
  } else if ((*t)->dir == NULL) {
    aux = *t;
    *t = (*t)->esq;
    free(aux);
    return t;
  } else {
    return substitui_menor_dir(t, &(*t)->dir);
  }
}

no *substitui_menor_dir(no *t, no*suc) {
  no aux;

  if ((*suc)->esq == NULL) {
    (*t)->info = (*suc)->info;

    aux = *suc;
    (*suc) = (*suc)->dir;
    free(aux);
    return suc;
  } else {
    suc = substitui_menor_dir(t, &(*suc)->esq);
  }
}

// d)
int insere_esq(no *pai, char elem) {
  if (!pai)
    return 0;
  pai->esq = malloc(sizeof(no));
  pai->esq->info = elem;
  pai->esq->dir = pai->esq->esq = NULL;
  return 1;
}

// e)
// Fiz in ordem porque ele disse que podemos escolher o percurso que quisermos
void imprime_arv (no *raiz) {
  if (!raiz)
    return;
  imprime_arv(raiz->esq);
  printf("%d ", raiz->info);
  imprime_arv(raiz->dir);
}