// Função que retorna o maior elemento da árvore
// a)
// Opção 1: É ABB
#include <stdlib.h>

typedef struct no {
  int info;
  struct no *esq;
  struct no *dir;
} no;

int maior_valor(no *raiz) {
  if (!raiz)
    return 0;
  while (raiz->dir) {
    raiz = raiz->dir;
  }
  return raiz->info;
}

// Opção 2: Não é ABB
int maior_valor(no *raiz) {
  int maior, atual, esq, dir;
  atual = raiz->info;
  maior = atual;

  if (!raiz) {
    return 0;
  }

    if (raiz->esq != NULL) {
      esq = maior_valor(raiz->esq);
      if (esq > maior) {
        maior = esq;
      }
    } else if (raiz->dir != NULL) {
      dir = maior_valor(raiz->dir);
      if (dir >maior) {
        maior = dir;
      }
    }
  
  return maior;
}

// b)
int total_no_folha (no *raiz) {
  int num = 0;
  if (!raiz) {
    return 0;
  }
  if (raiz->esq != NULL && raiz->dir != NULL) {
    return 1;
  }
  num += total_no_folha(raiz->esq);
  num += total_no_folha(raiz->dir);
  return num;
}