#include <stdio.h>
#include <stdlib.h>

#include "busca_tree.h"

struct dado {
  tipo_chave chave;
};

struct tree {
  struct tree* esq;
  struct tree* dir;
  tipo_dado dado;
};

int main() {
  t* raiz = malloc(sizeof(t));
  raiz = NULL;
  tipo_dado elem;
  elem.chave = 10;
  raiz = insere(raiz, elem);
  elem.chave = 8;
  raiz = insere(raiz, elem);
  elem.chave = 7;
  raiz = insere(raiz, elem);
  elem.chave = 9;
  raiz = insere(raiz, elem);
  elem.chave = 15;
  raiz = insere(raiz, elem);
  elem.chave = 14;
  raiz = insere(raiz, elem);
  elem.chave = 17;
  raiz = insere(raiz, elem);
  elem.chave = 16;
  raiz = insere(raiz, elem);
  elem.chave = 19;
  raiz = insere(raiz, elem);
  inOrder(raiz);
  elem.chave = 17;
  if (busca_nao_rec(raiz, elem))
    printf("\nACHOU: %d\n", busca_nao_rec(raiz, elem)->dado.chave);
  else
    printf("Não achou\n");
  elem.chave = 33;
  if (busca_nao_rec(raiz, elem))
      printf("ACHOU: %d\n", buscar_na_tree(raiz, elem)->dado.chave);
  else
    printf("Não achou\n");
  elem.chave = 17;
  raiz = remover(raiz, elem);
  inOrder(raiz);
  return 0;
}

t* criar_raiz(t* raiz, tipo_dado elem) {
    raiz = malloc(sizeof(t));
    raiz->dado = elem;
    raiz->esq = NULL;
    raiz->dir = NULL;
  return raiz;
}

t* insere(t* raiz, tipo_dado elem) {
  if (raiz == NULL) {
    raiz = criar_raiz(raiz, elem);
    return raiz;
  }
  if (elem.chave < raiz->dado.chave) {
    raiz->esq = insere(raiz->esq, elem);
  } else {
    raiz->dir = insere(raiz->dir, elem);
  }
  return raiz;
}

t* buscar_na_tree(t* raiz, tipo_dado elems) {
  if (!raiz) {
    return NULL;
  }
  if (raiz->dado.chave == elems.chave) {
    return raiz;
  }
  if (elems.chave < raiz->dado.chave) {
    return buscar_na_tree(raiz->esq, elems);
  } else {
    return buscar_na_tree(raiz->dir, elems);
  }
}

t* busca_nao_rec(t* raiz, tipo_dado elem) {
  t* aux = raiz;
  while (aux) {
    if (aux->dado.chave == elem.chave) {
      return aux;
    }
    if (elem.chave < aux->dado.chave) {
      aux = aux->esq;
    } else {
      aux = aux->dir;
    }
  }
  return aux;
}

t* remover(t* raiz, tipo_dado elem) {
  t* aux;
  if (!raiz) {
    return raiz;
  }
  if (elem.chave < raiz->dado.chave) {
    raiz->esq = remover(raiz->esq, elem);
  } else if (elem.chave > raiz->dado.chave) {
    raiz->dir = remover(raiz->dir, elem);
  } else if (elem.chave == raiz->dado.chave) {
    if (raiz->esq == NULL && raiz->dir == NULL) {
      free(raiz);
      return NULL;
    } else if (raiz->esq == NULL) {
      aux = raiz;
      raiz = raiz->dir;
      free(aux);
      return raiz;
    } else if (raiz->dir == NULL) {
      aux = raiz;
      raiz = raiz->esq;
      free(aux);
      return raiz;
    } else {
      aux = get_max(raiz->esq);
      raiz->dado = aux->dado;
      raiz->esq = remover(raiz->esq, aux->dado);
    }
  }
  return raiz;
}

t* get_max(t* raiz) {
  if (raiz->dir != NULL) {
    get_max(raiz->dir);
  }
  return raiz;
}

void inOrder(t* root) {
  if (root != NULL) {
    inOrder(root->esq);
    printf("\t[ %d ]\t", root->dado.chave);
    inOrder(root->dir);
  }
}

void purge(t* raiz) {
  if (!raiz) {
    if (raiz->esq != NULL) {
      purge(raiz->esq);
    }
    if (raiz->dir != NULL) {
      purge(raiz->dir);
    }
    free(raiz);
    raiz = NULL;  // Comentário bonito: reset pointer
  }
}